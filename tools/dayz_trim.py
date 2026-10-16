"""Trim an unpacked DayZ install down to what PureZ needs. Copies only; never deletes.

    python dayz_trim.py <unpacked DayZ folder> <output folder>            # dry run: sizes only
    python dayz_trim.py <unpacked DayZ folder> <output folder> --apply    # copy files

Output:
  <out>/data/    configs, scripts, string tables, materials, UI layouts, mission XML.
                 Small; push this to GitHub (the wiki and override mods are built from it).
  <out>/render/  models (.p3d), their textures and weapon sounds for wiki-facing items.
                 Large; keep it on your PC for the Blender pipeline. Do not push it.

Works with config.cpp or binarised config.bin. Paths are matched case-insensitively,
so it runs the same on Windows (P: drive layout) and Linux.
"""
import argparse, os, shutil, sys
from collections import defaultdict

# --- data set: always kept wherever they appear -------------------------------------------
DATA_EXT = {
    ".cpp", ".bin", ".hpp", ".h", ".inc",         # configs (config.bin is rapified config.cpp)
    ".c",                                          # Enforce scripts
    ".csv",                                        # stringtables: display names/descriptions
    ".xml", ".json",                               # CE/mission/gameplay data
    ".rvmat", ".bisurf",                           # materials: map model faces to textures
    ".layout", ".imageset", ".styles",             # UI definitions for UI/script mods
}
# Folders whose files are never useful for configs, scripts or wiki renders
DATA_SKIP_DIRS = ("worlds/",)                      # terrain layers, navmeshes, wrp data
DATA_MAX_BYTES = 20 * 1024 * 1024                  # skip giant generated files (navmesh xml etc.)

# --- render set: wiki-facing model trees -------------------------------------------------
# Top-level DZ folders whose models are shown on the wiki. Toggle with --render-dirs.
RENDER_DIRS = ["weapons", "gear", "characters", "vehicles", "structures", "animals"]
TEX_SUFFIXES = ("_co", "_ca", "_nohq", "_smdi", "_as")   # colour, alpha colour, normal, specular, AO
SOUND_EXT = {".ogg", ".wss", ".wav"}
GUI_DIRS = ("gui/",)                               # inventory/status icons (.edds/.paa)


def norm(path):
    return path.replace("\\", "/").lower()


def classify(rel):
    """Return 'data', 'render' or None for a path relative to the dump root."""
    r = norm(rel)
    name = r.rsplit("/", 1)[-1]
    stem, ext = os.path.splitext(name)
    parts = r.split("/")
    dz = parts[1] if parts[0] == "dz" and len(parts) > 2 else (parts[0] if len(parts) > 1 else "")

    if ext in DATA_EXT and not any(f"/{d}" in f"/{r}" for d in DATA_SKIP_DIRS):
        return "data"
    if any(f"/{d}" in f"/{r}" for d in GUI_DIRS) and ext in {".edds", ".paa", ".imageset"}:
        return "data"
    if ext in SOUND_EXT and "weapon" in r and "sound" in r:
        return "render"
    if dz in RENDER_DIRS:
        if ext == ".p3d":
            return "render"
        if ext == ".paa" and stem.endswith(TEX_SUFFIXES):
            return "render"
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src")
    ap.add_argument("out")
    ap.add_argument("--apply", action="store_true", help="copy files (default is a dry run)")
    ap.add_argument("--render-dirs", default=",".join(RENDER_DIRS),
                    help=f"comma list of DZ folders to keep models for (default: {','.join(RENDER_DIRS)})")
    ap.add_argument("--no-render", action="store_true", help="only build the data set")
    args = ap.parse_args()

    RENDER_DIRS[:] = [d.strip().lower() for d in args.render_dirs.split(",") if d.strip()]
    src = os.path.abspath(args.src)
    out = os.path.abspath(args.out)
    if out.startswith(src + os.sep):
        sys.exit("Output folder must be outside the source folder.")

    totals = defaultdict(lambda: [0, 0])            # bucket -> [files, bytes]
    by_top = defaultdict(lambda: defaultdict(int))  # top folder -> bucket -> bytes
    manifest = {"data": [], "render": []}
    for root, dirs, files in os.walk(src):
        dirs.sort()
        for f in sorted(files):
            full = os.path.join(root, f)
            rel = os.path.relpath(full, src)
            try:
                size = os.path.getsize(full)
            except OSError:
                continue
            bucket = classify(rel)
            if bucket == "data" and size > DATA_MAX_BYTES:
                bucket = None
            if bucket == "render" and args.no_render:
                bucket = None
            key = bucket or "dropped"
            totals[key][0] += 1
            totals[key][1] += size
            top = "/".join(norm(rel).split("/")[:2])
            by_top[top][key] += size
            if bucket:
                manifest[bucket].append(rel)
                if args.apply:
                    dst = os.path.join(out, bucket, rel)
                    os.makedirs(os.path.dirname(dst), exist_ok=True)
                    shutil.copy2(full, dst)

    gb = lambda b: f"{b / 1024**3:8.2f} GB" if b >= 1024**3 else f"{b / 1024**2:8.1f} MB"
    print(f"{'folder':40s} {'data':>11s} {'render':>11s} {'dropped':>11s}")
    for top in sorted(by_top, key=lambda t: -sum(by_top[t].values()))[:40]:
        b = by_top[top]
        print(f"{top[:40]:40s} {gb(b['data'])} {gb(b['render'])} {gb(b['dropped'])}")
    print()
    for k in ("data", "render", "dropped"):
        print(f"{k:8s} {totals[k][0]:8d} files {gb(totals[k][1])}")
    if args.apply:
        os.makedirs(out, exist_ok=True)
        for k, files in manifest.items():
            with open(os.path.join(out, f"{k}_manifest.txt"), "w", encoding="utf-8") as fh:
                fh.write("\n".join(files))
        print(f"\nCopied to {out}")
    else:
        print("\nDry run. Add --apply to copy.")


if __name__ == "__main__":
    main()
