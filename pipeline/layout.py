"""Prepare the render work tree: one folder per wiki item with its converted model.

    python pipeline/layout.py --render <trimmed render folder> [--all] [--only AKM]

Creates pipeline/work/<category>/<Class>/model.glb + item.json for every wiki page with a
`class` (or, with --all, every public config class that has a model), applying the class's
hiddenSelectionsTextures so colour variants render correctly. Then run blender_render.py.
"""
import argparse, glob, json, os, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import p3d  # noqa: E402

# Wiki category from a model's game path, for --all
PATH_CATEGORIES = [
    (r"dz/weapons/(attachments|optics)", "attachments"), (r"dz/weapons/ammunition", "ammunition"),
    (r"dz/weapons/", "weapons"), (r"dz/characters/", "clothing"), (r"dz/vehicles/", "vehicles"),
    (r"dz/gear/medical", "medical"), (r"dz/gear/(food|drinks)", "food"), (r"dz/", "gear"),
]


def front_matter(path):
    with open(path, encoding="utf-8") as f:
        text = f.read()
    meta = {}
    if text.startswith("---"):
        for line in text[3:text.find("\n---", 3)].strip().splitlines():
            if ":" in line:
                k, v = line.split(":", 1)
                meta[k.strip()] = v.strip()
    return meta


def wiki_items():
    out = {}
    for path in glob.glob(os.path.join(ROOT, "content", "**", "*.md"), recursive=True):
        meta = front_matter(path)
        if meta.get("class"):
            cat = meta.get("category") or os.path.relpath(path, os.path.join(ROOT, "content")).split(os.sep)[0]
            out[meta["class"]] = {"category": cat, "model": meta.get("model")}
    return out


def configs():
    path = os.path.join(ROOT, "data", "configs.json")
    if not os.path.exists(path):
        return {}
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    merged = {}
    for sec in ("weapons", "magazines", "vehicles"):
        merged.update(data.get(sec, {}))
    return merged


def category_for(model):
    m = (model or "").replace("\\", "/").lower().lstrip("/")
    return next((cat for rx, cat in PATH_CATEGORIES if re.search(rx, m)), "gear")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--render", required=True, help="render folder from dayz_trim.py (contains DZ/)")
    ap.add_argument("--work", default=os.path.join(HERE, "work"))
    ap.add_argument("--all", action="store_true", help="every public config class with a model")
    ap.add_argument("--only")
    a = ap.parse_args()

    cfg = configs()
    items = wiki_items()
    if a.all:
        for cls, c in cfg.items():
            if c.get("model") and cls not in items:
                items[cls] = {"category": category_for(c["model"]), "model": None}
    if a.only:
        items = {k: v for k, v in items.items() if k == a.only}

    files = p3d.Files(a.render)
    stats = {"converted": 0, "odol": 0, "no model": 0, "missing file": 0, "failed": 0}
    for cls, it in sorted(items.items()):
        c = cfg.get(cls, {})
        model = it.get("model") or c.get("model")
        if not model:
            stats["no model"] += 1
            continue
        src = files.find(model) or files.find(model + ".p3d")
        if not src:
            stats["missing file"] += 1
            print(f"missing  {cls}: {model}")
            continue
        out_dir = os.path.join(a.work, it["category"], cls)
        hidden = dict(zip([s.lower() for s in c.get("hiddenSelections") or []], c.get("hiddenSelectionsTextures") or []))
        mats = dict(zip([s.lower() for s in c.get("hiddenSelections") or []], c.get("hiddenSelectionsMaterials") or []))
        try:
            lod = p3d.best_lod(p3d.read_p3d(src))
            if not lod:
                raise ValueError("no visual LOD")
            info = p3d.export(lod, os.path.join(out_dir, "model.glb"), files, hidden, mats)
            with open(os.path.join(out_dir, "item.json"), "w", encoding="utf-8") as f:
                json.dump({"class": cls, "category": it["category"], "model": model, "hidden": hidden, **info}, f, indent=1)
            stats["converted"] += 1
            print(f"ok       {it['category']}/{cls} ({info['faces']} faces)")
        except NotImplementedError as e:
            stats["odol"] += 1
            print(f"odol     {cls}: {e}")
        except Exception as e:
            stats["failed"] += 1
            print(f"failed   {cls}: {e}")
    print(stats)


if __name__ == "__main__":
    main()
