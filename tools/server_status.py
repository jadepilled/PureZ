"""Query every live PureZ server over Steam A2S and update status.json.

Usage: python server_status.py servers.json status.json
servers.json is the site's server list; status.json is read (if present) and rewritten
with the latest result per server plus a rolling 7-day player-count history.
"""
import json, re, socket, struct, sys, time

HISTORY_SECONDS = 7 * 24 * 3600
TIMEOUT = 3.0
ATTEMPTS = 3

A2S_INFO = b"\xff\xff\xff\xffTSource Engine Query\x00"


def _cstr(buf, i):
    end = buf.index(b"\x00", i)
    return buf[i:end].decode("utf-8", "replace"), end + 1


def parse_info(buf):
    if buf[:5] != b"\xff\xff\xff\xffI":
        raise ValueError("not an A2S_INFO reply")
    i = 6  # header + protocol byte
    name, i = _cstr(buf, i)
    map_, i = _cstr(buf, i)
    _folder, i = _cstr(buf, i)
    _game, i = _cstr(buf, i)
    i += 2  # app id
    players, max_players, _bots = buf[i], buf[i + 1], buf[i + 2]
    i += 6  # players, max, bots, type, environment, visibility
    i += 1  # vac
    version, i = _cstr(buf, i)
    keywords = ""
    if i < len(buf):
        edf = buf[i]
        i += 1
        if edf & 0x80:
            i += 2  # game port
        if edf & 0x10:
            i += 8  # steam id
        if edf & 0x40:
            i += 2  # spectator port
            _, i = _cstr(buf, i)
        if edf & 0x20:
            keywords, i = _cstr(buf, i)
    info = {"name": name, "map": map_, "players": players, "maxPlayers": max_players, "version": version}
    # DayZ puts the in-game time ("HH:MM") and login queue ("lqs<n>") in the keywords
    for tag in keywords.split(","):
        if re.fullmatch(r"\d{1,2}:\d{2}", tag):
            info["time"] = tag
        elif re.fullmatch(r"lqs\d+", tag):
            info["queue"] = int(tag[3:])
    return info


def query(host, port):
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.settimeout(TIMEOUT)
        s.sendto(A2S_INFO, (host, port))
        data, _ = s.recvfrom(4096)
        if data[:5] == b"\xff\xff\xff\xffA":  # challenge: resend with it appended
            s.sendto(A2S_INFO + data[5:9], (host, port))
            data, _ = s.recvfrom(4096)
        return parse_info(data)


def main(servers_path, status_path):
    with open(servers_path, encoding="utf-8") as f:
        servers = json.load(f)
    try:
        with open(status_path, encoding="utf-8") as f:
            status = json.load(f)
    except (OSError, ValueError):
        status = {}
    now = int(time.time())
    out = {"updated": now, "servers": {}}
    for srv in servers:
        if srv.get("status") != "live":
            continue
        sid = srv["id"]
        prev = status.get("servers", {}).get(sid, {})
        entry = {"online": False}
        for _ in range(ATTEMPTS):
            try:
                entry = {"online": True, **query(srv["ip"], int(srv["queryPort"]))}
                break
            except (OSError, ValueError, IndexError, struct.error):
                continue
        history = [p for p in prev.get("history", []) if now - p[0] <= HISTORY_SECONDS]
        history.append([now, entry["players"] if entry["online"] else None])
        entry["history"] = history
        out["servers"][sid] = entry
        print(sid, "online" if entry["online"] else "offline", entry.get("players", ""), "/", entry.get("maxPlayers", ""))
    with open(status_path, "w", encoding="utf-8") as f:
        json.dump(out, f, separators=(",", ":"))


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
