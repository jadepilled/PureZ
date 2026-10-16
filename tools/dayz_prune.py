"""Prune an unpacked DayZ install, in place, down to what the PureZ wiki and map need.

    python dayz_prune.py <git folder>              # dry run: shows what would go, sizes only
    python dayz_prune.py <git folder> --apply      # delete, move, and write the sample set

<git folder> is the repository root that holds the unpacked game folders (DZ, Scripts, ...),
for example F:\\PureZ\\site\\PureZ. Only the unpacked game folders are touched; the repository's own
files (missions, tools, .git, .github) are never read or removed.

What happens to each file:

  KEEP   configs (config.cpp / config.bin / .hpp), scripts (.c), string tables (.csv), CE and mission
         data (.xml, .json), materials (.rvmat, .bisurf), UI layouts and image sets, inventory icon
         atlases (DZ/gui), and each world's satellite layer tiles (DZ/worlds/<world>/data/layers/s_*_lco.paa).
         Pushed to GitHub: this is what the wiki, map and renders are built from.
  MOVE   models (.p3d) and their textures (_co, _ca, _nohq, _smdi, _as .paa) for wiki-facing item folders,
         plus weapon sounds, into <git folder>\\..\\PureZ-render. Too big for GitHub, needed on your PC
         for the Blender render pipeline. Use --delete-render to delete them instead of moving.
  SAMPLE a handful of models with their textures is copied to <git folder>\\samples (small, pushed)
         so the ODOL model decoder can be finished against real files.
  DELETE everything else.

Files over 95 MB can't be pushed to GitHub without LFS; they are listed and moved to PureZ-render.
Paths are matched case-insensitively.
"""
import argparse, os, shutil, sys
from collections import defaultdict

DATA_EXT = {".cpp", ".bin", ".hpp", ".h", ".inc", ".c", ".csv", ".xml", ".json", ".rvmat", ".bisurf",
            ".layout", ".imageset", ".styles"}
DATA_SKIP_DIRS = ("/worlds/",)            # terrain data, except the satellite layers kept below
DATA_MAX_BYTES = 20 * 1024 * 1024         # giant generated files (navmesh xml etc.) are dropped
GITHUB_MAX = 95 * 1024 * 1024

RENDER_DIRS = ["weapons", "gear", "characters", "vehicles", "structures", "animals"]
TEX_SUFFIXES = ("_co", "_ca", "_nohq", "_smdi", "_as")
SOUND_EXT = {".ogg", ".wss", ".wav"}
SAMPLES = ["weapons/firearms/akm/akm.p3d", "gear/clothing/hoodie/hoodie.p3d", "gear/food/tunacan.p3d",
           "vehicles/wheeled/offroadhatchback/offroadhatchback.p3d", "structures/residential/house/house1w01.p3d",
           "weapons/firearms/m4a1/m4a1.p3d", "gear/containers/backpack_courier.p3d", "characters/heads/male/head.p3d"]
# game folders that may sit in the repository root after unpacking; anything else at root is left alone
GAME_ROOTS = {"dz", "scripts", "addons", "dta", "languagecore", "data", "mpmissions", "bliss", "worlds"}


def norm(p):
    return p.replace("\\", "/").lower()


def classify(rel, size):
    """'data', 'render' or None for a path relative to the git folder."""
    r = norm(rel)
    name = r.rsplit("/", 1)[-1]
    stem, ext = os.path.splitext(name)
    parts = r.split("/")
    top = parts[0]
    sub = parts[1] if top == "dz" and len(parts) > 2 else top

    if "/worlds/" in f"/{r}" and "/data/layers/" in r and name.startswith("s_") and name.endswith("_lco.paa"):
        return "data"
    if ext in DATA_EXT and not any(d in f"/{r}" for d in DATA_SKIP_DIRS) and size <= DATA_MAX_BYTES:
        return "data"
    if "/gui/" in f"/{r}" and ext in {".edds", ".paa", ".imageset"}:
        return "data"
    if ext in SOUND_EXT and "weapon" in r and "sound" in r:
        return "render"
    if sub in RENDER_DIRS:
        if ext == ".p3d":
            return "render"
        if ext == ".paa" and stem.endswith(TEX_SUFFIXES):
            return "render"
    return None


def human(n):
    for u in ("B", "KB", "MB", "GB"):
        if n < 1024:
            return f"{n:.0f} {u}"
        n /= 1024
    return f"{n:.1f} TB"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("root", help="git folder that holds the unpacked DZ, Scripts... folders")
    ap.add_argument("--apply", action="store_true", help="make the changes (default is a dry run)")
    ap.add_argument("--render-to", help="folder for models, textures and sounds (default: <root>\\..\\PureZ-render)")
    ap.add_argument("--delete-render", action="store_true", help="delete the render set instead of moving it")
    ap.add_argument("--roots", help="comma list of game folders to process (default: every known game folder found)")
    a = ap.parse_args()

    root = os.path.abspath(a.root)
    render_to = os.path.abspath(a.render_to or os.path.join(root, "..", "PureZ-render"))
    if a.roots:
        roots = [r.strip() for r in a.roots.split(",") if r.strip()]
    else:
        roots = [d for d in os.listdir(root) if d.lower() in GAME_ROOTS and os.path.isdir(os.path.join(root, d))]
    if not roots:
        sys.exit(f"No unpacked game folders found in {root} (looked for {', '.join(sorted(GAME_ROOTS))}).")
    print(f"Processing: {', '.join(roots)}" + ("" if a.apply else "   (dry run: nothing is changed)"))

    totals = defaultdict(lambda: [0, 0])
    plan = []           # (action, rel, size)
    samples = {}        # sample stem -> (dir rel, files)
    for top in roots:
        for dirpath, _, files in os.walk(os.path.join(root, top)):
            for f in files:
                path = os.path.join(dirpath, f)
                rel = os.path.relpath(path, root)
                try:
                    size = os.path.getsize(path)
                except OSError:
                    continue
                kind = classify(rel, size)
                if kind == "data" and size > GITHUB_MAX:
                    kind = "oversize"
                action = {"data": "keep", "render": "delete" if a.delete_render else "move", "oversize": "move", None: "delete"}[kind]
                totals[action][0] += 1
                totals[action][1] += size
                plan.append((action, rel, size))
                r = norm(rel)
                for s in SAMPLES:
                    if r.endswith(s) or (r.startswith(os.path.dirname(f"dz/{s}")) and r.endswith(tuple(f"{t}.paa" for t in TEX_SUFFIXES))):
                        samples.setdefault(s, []).append(rel)

    for action in ("keep", "move", "delete"):
        n, size = totals[action]
        print(f"  {action:7} {n:>7} files  {human(size):>9}")
    over = [p for p in plan if p[0] == "move" and p[2] > GITHUB_MAX]
    if over:
        print("  Over GitHub's file size limit, moved out of the repo:")
        for _, rel, size in over:
            print(f"    {rel}  {human(size)}")
    found = [s for s in SAMPLES if s in samples]
    print(f"  samples: {len(found)} of {len(SAMPLES)} found" + (f" ({', '.join(os.path.basename(s) for s in found)})" if found else ""))
    print(f"  render set -> {render_to}" if not a.delete_render else "  render set -> deleted")

    if not a.apply:
        print("\nRe-run with --apply to make these changes.")
        return

    # samples first (they're copies), then moves, then deletes, then empty folders
    sdir = os.path.join(root, "samples")
    for s, rels in samples.items():
        for rel in rels:
            dest = os.path.join(sdir, os.path.relpath(rel, "DZ") if norm(rel).startswith("dz/") else rel)
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            shutil.copy2(os.path.join(root, rel), dest)
    done = 0
    for action, rel, _ in plan:
        src = os.path.join(root, rel)
        if action == "move":
            dest = os.path.join(render_to, rel)
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            shutil.move(src, dest)
        elif action == "delete":
            os.remove(src)
        done += 1
        if done % 5000 == 0:
            print(f"  {done}/{len(plan)}")
    for top in roots:
        for dirpath, dirs, files in os.walk(os.path.join(root, top), topdown=False):
            if not dirs and not files and dirpath != root:
                try:
                    os.rmdir(dirpath)
                except OSError:
                    pass
    print("Done. Now: git add -A && git commit -m \"Game data\" && git push")


if __name__ == "__main__":
    main()
