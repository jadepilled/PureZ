# Model and render pipeline

Turns DayZ models into transparent product renders and web 3D models for the wiki.

```
render folder (from dayz_trim.py)          pipeline/work/<category>/<Class>/       media/
  DZ/weapons/firearms/akm/akm.p3d   ──►      model.glb  (textures embedded)   ──►    renders/<category>/<Class>.webp
  DZ/.../data/akm_co.paa                     item.json                               models/<Class>.glb
           layout.py (+ p3d.py, paa.py)                 blender_render.py
```

## Requirements

- Python 3.10+ with `pip install pillow numpy` (`python-lzo` optional, for speed)
- Blender 4.2 or newer

## Steps

1. **Trim the game data** (once per game update), from the PureZ repo:
   `python tools/dayz_trim.py <unpacked DayZ> <out> --apply`
2. **Extract configs** so the pipeline knows each item's model and colour textures:
   `python extract/configs.py --dz <out>/data --out data/configs.json`
3. **Convert models** into the work tree:
   `python pipeline/layout.py --render <out>/render` (wiki pages only), or add `--all` for every item.
4. **Render** (Windows example):
   `"C:\Program Files\Blender Foundation\Blender 4.2\blender.exe" -b -P pipeline/blender_render.py -- --work pipeline/work --out media --gpu`
5. Commit `media/`. Pages show the render and 3D model automatically.

Useful options: `--only AKM` to redo one item, `--samples 64` for faster drafts, `--size 1600x1200`.

## Notes

- Camera angles are set per category in `PRESETS` at the top of `blender_render.py`.
- Colour variants share a model and swap textures via the config's `hiddenSelectionsTextures`. `layout.py` applies these, so `BaseballCap_Red` renders red.
- Models can be MLOD or ODOL. The game ships binarised ODOL. ODOL decoding is being finished against real sample files. Until then those items are listed as `odol` in the layout summary.
- Textures: `_co`/`_ca` colour, `_nohq` normal map, `_smdi` gloss (converted to glTF roughness).
