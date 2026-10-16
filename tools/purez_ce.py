"""Apply PureZ central economy changes to a vanilla-format mission, editing text in place
so formatting and comments in untouched blocks are preserved."""
import math, re, sys
import xml.etree.ElementTree as ET

M = sys.argv[1].rstrip("/") + "/"

def rnd(x):
    return int(math.floor(x + 0.5))

def read(p):
    with open(M + p, encoding="utf-8") as f:
        return f.read()

def write(p, s):
    with open(M + p, "w", encoding="utf-8", newline="") as f:
        f.write(s)

LOOT_MULT = 1.3
ZOMBIE_MULT = 1.2
LOOT_CATS = {"tools", "food", "clothes", "weapons", "containers"}
HOARDERS = {"Barrel_Blue", "Barrel_Green", "Barrel_Red", "Barrel_Yellow", "CarTent", "LargeTent",
            "MediumTent", "MediumTent_Green", "MediumTent_Orange", "PartyTent", "PartyTent_Blue",
            "PartyTent_Brown", "PartyTent_Lunapark", "SeaChest", "SmallProtectorCase",
            "UndergroundStash", "WoodenCrate"}

PISTOLS = {"MakarovIJ70", "MKII", "CZ75", "Glock19", "Glock19_Tan", "Glock_Tan", "FNX45", "Colt1911",
           "Engraved1911", "Deagle", "Deagle_Gold", "P1", "CZ61", "Longhorn", "Magnum", "Magnum_Gold",
           "Derringer_Black", "Derringer_Grey", "Derringer_Pink", "Luger"}
LONGGUNS = {
    "AK101", "AK101_Black", "AK101_Green", "AK74", "AK74_Black", "AK74_Green", "AKM", "AKM_Gold",
    "AKS74U", "AKS74U_Black", "AKS74U_Green", "ASVAL", "Aug", "AugShort", "B95",
    "CZ527", "CZ527_Black", "CZ527_Desert", "CZ527_Winter", "CZ527_Woodland", "CZ550",
    "FAL", "FAMAS", "Izh18", "Izh18Shotgun", "Izh43Shotgun", "LeeEnfield", "M16A2",
    "M4A1", "M4A1_Black", "M4A1_Green", "MP18", "MP5K", "Mosin9130", "Mosin9130_Black",
    "Mosin9130_Camo", "Mosin9130_Green", "Mosin9130_Desert", "Mosin9130_Winter", "Mosin9130_Woodland",
    "Mp133Shotgun", "PM73Rak", "PP19", "R12", "Repeater", "Ruger1022", "SCARH", "SCARH_Black",
    "SCARL", "SCARL_Black", "SKS", "SKS_Black", "SKS_Desert", "SKS_Winter", "SKS_Woodland",
    "SSG82", "SVD", "SVD_Wooden", "Saiga", "Scout", "Scout_Chernarus", "Scout_Livonia",
    "UMP45", "VSS", "Vikhr", "Winchester70",
    "SawedoffB95", "SawedoffFAMAS", "SawedoffIzh18", "SawedoffIzh18Shotgun", "SawedoffIzh43Shotgun",
    "SawedoffMagnum", "SawedoffMagnum_Gold", "SawedoffMosin9130", "SawedoffMosin9130_Black",
    "SawedoffMosin9130_Camo", "SawedoffMosin9130_Green"}
FIREARMS = PISTOLS | LONGGUNS
FIREARMS_LC = {n.lower() for n in FIREARMS}

# cfgspawnabletypes names that differ in case from types.xml
CASE_FIX = {"CZ527_desert": "CZ527_Desert", "CZ527_winter": "CZ527_Winter",
            "MP133Shotgun": "Mp133Shotgun", "LongHorn": "Longhorn"}

# Vanilla firearms present in types.xml with no cfgspawnabletypes entry: (mags, optics)
NEW_WEAPON_ENTRIES = {
    "Izh18": [], "Izh18Shotgun": [], "Izh43Shotgun": [], "Repeater": [],
    "Magnum": [], "Magnum_Gold": [], "Derringer_Grey": [],
    "Luger": [["Mag_Luger_8Rnd"]],
    "MP18": [["Mag_MP18_Drum32Rnd"]],
}

OPTIC_LONG = 0.65     # optics are a common attachment
OPTIC_PISTOL = 0.35
SUPPRESSOR = 0.05     # suppressors are rare
# Suppressor groups for weapons whose vanilla entry has none
ADD_SUPPRESSOR = {"AK101": "AK_Suppressor", "M4A1": "M4_Suppressor"}

WEAPON_DAMAGE = ('<damage min="0.15" max="0.45" />')  # pristine or worn only

# ---------------------------------------------------------------- types.xml
def tag_val(block, tag):
    m = re.search(rf"<{tag}>(-?[\d.]+)</{tag}>", block)
    return m and m.group(1)

def set_tag(block, tag, v):
    return re.sub(rf"<{tag}>-?[\d.]+</{tag}>", f"<{tag}>{v}</{tag}>", block, count=1)

def ammo_quant(qmin, qmax):
    nmax = min(100, qmax * 2)
    nmin = min(qmin * 3, rnd(nmax * 0.6))
    return nmin, nmax

stats = {}
def bump(k): stats[k] = stats.get(k, 0) + 1

def edit_type(m):
    block = m.group(0)
    name = m.group(1)
    cat = re.search(r'<category name="([^"]+)"', block)
    cat = cat and cat.group(1)
    nom, mn = int(tag_val(block, "nominal")), int(tag_val(block, "min"))
    qmin, qmax = int(tag_val(block, "quantmin")), int(tag_val(block, "quantmax"))

    if cat in LOOT_CATS and name not in HOARDERS and nom > 0:
        nnom = max(nom, rnd(nom * LOOT_MULT))
        nmin = min(nnom, rnd(mn * LOOT_MULT))
        if (nnom, nmin) != (nom, mn):
            block = set_tag(set_tag(block, "nominal", nnom), "min", nmin)
            bump("types: nominal/min raised")

    if name.startswith("Mag_"):
        block = set_tag(set_tag(block, "quantmin", 75), "quantmax", 100)
        bump("types: magazine fill 75-100")
    elif name.lower() in FIREARMS_LC:
        block = set_tag(set_tag(block, "quantmin", 75), "quantmax", 100)
        bump("types: firearm ammo 75-100")
    elif name.startswith("Ammo_") and 0 < qmin and qmax < 100:
        a, b = ammo_quant(qmin, qmax)
        block = set_tag(set_tag(block, "quantmin", a), "quantmax", b)
        bump("types: ammo pile size raised")
    return block

s = read("db/types.xml")
s = re.sub(r'<type name="([^"]+)">.*?</type>', edit_type, s, flags=re.S)
write("db/types.xml", s)

types_cat = {}
for t in ET.fromstring(s):
    c = t.find("category")
    types_cat[t.get("name")] = c.get("name") if c is not None else None

# ---------------------------------------------------------------- cfgspawnabletypes.xml
def kind(item):
    if item.startswith("Mag_"): return "mag"
    if "Optic" in item: return "optic"
    if "Suppressor" in item: return "supp"
    if "Compensator" in item: return "comp"
    if "Light" in item: return "light"
    return "furn"

def fmt(c):
    return f"{c:.2f}"

def render_type(name, damage, groups, other_lines):
    out = [f'\t<type name="{name}">']
    if damage:
        out.append(f"\t\t{damage}")
    out += other_lines
    for tag, chance, items in groups:
        out.append(f'\t\t<{tag} chance="{fmt(chance)}">')
        for iname, ich in items:
            out.append(f'\t\t\t<item name="{iname}" chance="{fmt(ich)}" />')
        out.append(f"\t\t</{tag}>")
    out.append("\t</type>")
    return "\n".join(out)

def weapon_groups(name, groups):
    pistol = name.lower() in {p.lower() for p in PISTOLS}
    new = []
    for tag, chance, items in groups:
        if tag != "attachments":
            new.append((tag, chance, items)); continue
        kinds = {kind(i) for i, _ in items}
        if len(kinds) > 1:  # split mixed groups (e.g. Scout optics + suppressor)
            total = sum(c for _, c in items)
            for k in ["optic", "mag", "supp", "comp", "light", "furn"]:
                sub = [(i, c) for i, c in items if kind(i) == k]
                if not sub:
                    continue
                share = sum(c for _, c in sub) / total
                sub_chance = chance if k in ("optic", "mag") else chance * share
                if len(sub) == 1:
                    sub = [(sub[0][0], 1.0)]
                new += weapon_groups(name, [(tag, sub_chance, sub)])
            continue
        k = kinds.pop()
        if k == "mag":
            chance = 1.0
        elif k == "optic":
            chance = max(chance, OPTIC_PISTOL if pistol else OPTIC_LONG)  # keep always-on base sights
        elif k == "supp":
            chance = SUPPRESSOR
        elif k == "comp":
            chance = min(max(chance, chance * 2), max(chance, 0.40))
        elif k == "light":
            chance = min(max(chance, chance * 2), max(chance, 0.50))
        else:
            chance = 1 - (1 - chance) * 0.6
        if len(items) == 1 and k in ("mag", "optic"):
            items = [(items[0][0], 1.0)]
        new.append((tag, round(chance, 2), items))
    return new

VEHICLE_PARTS = set()

def edit_spawnable(m):
    block = m.group(0)
    name = m.group(1)
    fixed = CASE_FIX.get(name, name)
    t = ET.fromstring(block)
    damage_el = t.find("damage")
    damage = None if damage_el is None else f'<damage min="{damage_el.get("min")}" max="{damage_el.get("max")}" />'
    groups, has_other = [], False
    for ch in t:
        if ch.tag in ("attachments", "cargo") and ch.get("preset") is None:
            groups.append((ch.tag, float(ch.get("chance", 1)),
                           [(i.get("name"), float(i.get("chance", 1))) for i in ch.findall("item")]))
        elif ch.tag != "damage":
            has_other = True  # hoarder, tag or preset group
    rebuild = fixed.lower() in FIREARMS_LC or fixed in VEHICLES
    if rebuild and has_other:
        raise SystemExit(f"{fixed}: unexpected preset/hoarder/tag, refusing to rebuild")

    if fixed.lower() in FIREARMS_LC:
        bump("spawnable: firearm condition/attachments")
        if fixed in ADD_SUPPRESSOR and not any(kind(i) == "supp" for _, _, its in groups for i, _ in its):
            groups.append(("attachments", SUPPRESSOR, [(ADD_SUPPRESSOR[fixed], 1.0)]))
        return render_type(fixed, WEAPON_DAMAGE, weapon_groups(fixed, groups), [])
    if fixed in VEHICLES:
        bump("spawnable: vehicle pristine + all parts")
        for _, _, items in groups:
            VEHICLE_PARTS.update(i for i, _ in items)
        groups = [(tag, 1.0, [(i, 1.0) for i, _ in items]) for tag, _, items in groups]
        return render_type(fixed, '<damage min="0.0" max="0.0" />', groups, [])
    return block if fixed == name else block.replace(f'name="{name}"', f'name="{fixed}"', 1)

ev = ET.fromstring(read("db/events.xml"))
VEHICLES = {c.get("type") for e in ev if e.get("name", "").startswith("Vehicle")
            for c in e.findall("children/child")}

s = read("cfgspawnabletypes.xml")
s = re.sub(r'\t<type name="([^"]+)">.*?</type>|\t<type name="([^"]+)"\s*/>',
           lambda m: edit_spawnable(m) if m.group(1) else m.group(0), s, flags=re.S)

existing = {n.lower() for n in re.findall(r'<type name="([^"]+)"', s)}
add = []
for name, mags in NEW_WEAPON_ENTRIES.items():
    if name.lower() in existing or name not in types_cat:
        continue
    groups = [("attachments", 1.0, [(g[0], 1.0)]) for g in mags]
    add.append(render_type(name, WEAPON_DAMAGE, groups, []))
    bump("spawnable: firearm entry added")

# vehicle parts pristine: set damage on existing entries or add new ones
def part_damage(m):
    name = m.group(1)
    part = PARTS_LC.get(name.lower())
    if part is None:
        return m.group(0)
    block = m.group(0)
    VEHICLE_PARTS_DONE.add(part)
    bump("spawnable: vehicle part pristine")
    if "<damage" in block:
        return re.sub(r"<damage[^>]*/>", '<damage min="0.0" max="0.0" />', block, count=1)
    return block.replace(f'<type name="{name}">', f'<type name="{name}">\n\t\t<damage min="0.0" max="0.0" />', 1)

VEHICLE_PARTS_DONE = set()
PARTS_LC = {p.lower(): p for p in VEHICLE_PARTS}
s = re.sub(r'\t<type name="([^"]+)">.*?</type>', part_damage, s, flags=re.S)
types_lc = {n.lower() for n in types_cat}
for p in sorted(VEHICLE_PARTS - VEHICLE_PARTS_DONE):
    if p.lower() not in types_lc:
        continue
    add.append(f'\t<type name="{p}">\n\t\t<damage min="0.0" max="0.0" />\n\t</type>')
    bump("spawnable: vehicle part pristine")

if add:
    s = s.replace("</spawnabletypes>", "\t<!-- PureZ -->\n" + "\n".join(add) + "\n</spawnabletypes>")
write("cfgspawnabletypes.xml", s)

# ---------------------------------------------------------------- cfgrandompresets.xml
def preset(m):
    name, chance = m.group(2), float(m.group(1))
    if name.startswith("Xmas_") or name in ("grenades", "ContaminatedCargo"):
        return m.group(0)
    bump("presets: cargo chance raised")
    return m.group(0).replace(f'chance="{m.group(1)}"', f'chance="{fmt(min(1.0, chance * LOOT_MULT))}"', 1)

# Zombie gear presets: add the map's other spawning colour variants of each item, plus
# role-matched vanilla families. Each family keeps its original share of the preset's weight.
GEAR_ADD = {
    "hatsFarm": ["CowboyHat", "Bandana"],
    "hatsVillage": ["CowboyHat", "Bandana"],
    "hatsCity": ["Bandana"],
    "hatsIndustrial": ["WeldingMask"],
    "hatsArmy": ["MilitaryCap", "BoonieHat_Desert", "BoonieHat_DPM", "BoonieHat_Flecktran",
                 "BoonieHat_Olive", "BoonieHat_Tan", "PilotkaCap"],
    "vestsArmy": ["HighCapacityVest_Black", "HighCapacityVest_Olive"],
    "bagsArmy": ["CoyoteBag"],
    "bagsCity": ["ChildBag"],
    "bagsVillage": ["ChildBag"],
}
GEAR_PRESETS = set(GEAR_ADD) | {"bagsHunter", "vestsHunter", "hatsCitySkate", "hatsMedic", "hatsFirefighter",
                                "hatsMotorbike", "vestsPress", "headtorches", "hatsPolice", "hatsPrisoner",
                                "vestsPolice", "vestsIndustrial"}
types_nom = {t.get("name"): int(t.find("nominal").text) for t in ET.fromstring(read("db/types.xml"))}
spawning = {n.lower(): n for n, v in types_nom.items() if v > 0}
canon = {n.lower(): n for n in types_nom}

def family_of(item):
    return item.split("_")[0] if "_" in item else item

def members(base, exact=False):
    if exact or "_" in base:
        return [spawning[base.lower()]] if base.lower() in spawning else []
    return sorted(n for l, n in spawning.items() if l == base.lower() or l.startswith(base.lower() + "_"))

def gear_preset(m):
    name, head, body = m.group(2), m.group(1), m.group(3)
    if name not in GEAR_PRESETS:
        return m.group(0)
    items = re.findall(r'<item name="([^"]+)" chance="([\d.]+)"', body)
    fams = {}
    for i, c in items:
        i = canon.get(i.lower(), i)
        fams.setdefault(family_of(i), {})[i] = float(c)
    weights = {}
    for fam, its in fams.items():
        total = sum(its.values())
        group = set(its) | set(members(fam))
        for i in group:
            weights[i] = weights.get(i, 0) + total / len(group)
    avg = sum(sum(v.values()) for v in fams.values()) / len(fams)
    added = {}
    for add in GEAR_ADD.get(name, []):
        for g in members(add, exact="_" in add):
            if g not in weights:
                added.setdefault(family_of(g), []).append(g)
    for group in added.values():
        for i in group:
            weights[i] = avg / len(group)
    if len(weights) == len(items):
        return m.group(0)
    bump("presets: zombie gear variety widened")
    lines = "".join(f'\t\t\t\t<item name="{i}" chance="{w:.3f}" />\n' for i, w in weights.items())
    return f"{head}\n{lines}\t\t</attachments>"

s = read("cfgrandompresets.xml")
s = re.sub(r'<cargo chance="([\d.]+)" name="([^"]+)">', preset, s)
s = re.sub(r'(\t\t<attachments chance="[\d.]+" name="([^"]+)">)\n(.*?)\t\t</attachments>', gear_preset, s, flags=re.S)
write("cfgrandompresets.xml", s)

# ---------------------------------------------------------------- events.xml
VEH_NOMINAL = {"VehicleCivilianSedan": 12, "VehicleHatchback02": 12, "VehicleOffroadHatchback": 12,
               "VehicleSedan02": 12, "VehicleTruck01": 9, "VehicleOffroad02": 8, "VehicleMotorbike": 40}
EVENT_NOMINAL = {"StaticHeliCrash": 10, "StaticHeliCrashBig": 5}

def event(m):
    name, block = m.group(1), m.group(0)
    if name in VEH_NOMINAL:
        n = VEH_NOMINAL[name]
        k = n / int(tag_val(block, "nominal"))  # keep each event's own min/max ratios
        block = set_tag(block, "min", rnd(int(tag_val(block, "min")) * k))
        block = set_tag(block, "max", rnd(int(tag_val(block, "max")) * k))
        block = set_tag(block, "nominal", n)
        bump("events: vehicle count raised")
    elif name in EVENT_NOMINAL:
        block = set_tag(block, "nominal", EVENT_NOMINAL[name])
        bump("events: heli crash count raised")
    return block

s = read("db/events.xml")
s = re.sub(r'<event name="([^"]+)">.*?</event>', event, s, flags=re.S)
write("db/events.xml", s)

# ---------------------------------------------------------------- globals.xml
s = read("db/globals.xml")
s = s.replace('name="LootDamageMax" type="1" value="0.82"', 'name="LootDamageMax" type="1" value="0.65"')
s = s.replace('name="ZombieMaxCount" type="0" value="1000"', 'name="ZombieMaxCount" type="0" value="1200"')
for var in ("TimeLogin", "TimeHopping", "TimePenalty"):  # no wait before login
    s = re.sub(rf'(name="{var}" type="0" value=")\d+(")', r"\g<1>0\2", s)
write("db/globals.xml", s)

# ---------------------------------------------------------------- zombie_territories.xml
def zone(m):
    z = m.group(0)
    dmin, dmax = int(m.group(1)), int(m.group(2))
    bump("zombies: zone density raised")
    return z.replace(f'dmin="{dmin}" dmax="{dmax}"', f'dmin="{rnd(dmin * ZOMBIE_MULT)}" dmax="{rnd(dmax * ZOMBIE_MULT)}"')

s = read("env/zombie_territories.xml")
s = s.replace('name="InfedctedReligious"', 'name="InfectedReligious"')
s = re.sub(r'<zone [^>]*dmin="(\d+)" dmax="(\d+)"[^>]*/>', zone, s)
write("env/zombie_territories.xml", s)

for k, v in sorted(stats.items()):
    print(f"{v:5d}  {k}")
print("vehicle parts:", ", ".join(sorted(VEHICLE_PARTS)))
