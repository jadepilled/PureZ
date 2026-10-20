class CfgPatches
{
	class DZ_Weapons_Firearms_SCARH
	{
		units[]=
		{
			"SCARH"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Firearms"
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class Rifle_Base;
	class SCARH_Base: Rifle_Base
	{
		scope=0;
		weight=3700;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={1,0.5,20,170,4,10};
		WeaponLength=0.94999999;
		ObstructionDistance=0.69999999;
		barrelArmor=2.5999999;
		initSpeedMultiplier=0.92500001;
		chamberSize=1;
		chamberedRound="";
		chamberableFrom[]=
		{
			"Ammo_308Win",
			"Ammo_308WinTracer"
		};
		magazines[]=
		{
			"Mag_SCARH_20Rnd",
			"Mag_SCARH_20Rnd_Black"
		};
		magazineSwitchTime=0.44999999;
		ejectType=1;
		recoilModifier[]={1,1,1};
		swayModifier[]={2.0999999,2.3,0.85000002};
		simpleHiddenSelections[]=
		{
			"hide_barrel"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		class NoiseShoot
		{
			strength=100;
			type="shot";
		};
		modes[]=
		{
			"SemiAuto",
			"FullAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"Scar_Shot_1st_SoundSet",
				"Scar_Shot_1st_iterior_SoundSet",
				"Scar_Tail_SoundSet",
				"Scar_InteriorTail_SoundSet",
				"Scar_Slapback_SoundSet",
				"Scar_Tail_2D_SoundSet"
			};
			soundSetShotExt[]=
			{
				
				{
					"Scar_1st_silencerHomeMade_SoundSet",
					"Scar_silencerHomeMadeTail_SoundSet",
					"Scar_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			reloadTime=0.12;
			recoil="recoil_fal";
			recoilProne="recoil_fal_prone";
			dispersion=0.0020000001;
			magazineSlot="magazine";
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot1st[]=
			{
				"Scar_Shot_1st_SoundSet",
				"Scar_Shot_1st_iterior_SoundSet"
			};
			soundSetShot[]=
			{
				"Scar_Shot_SoundSet",
				"Scar_Shot_iterior_SoundSet",
				"Scar_Tail_SoundSet",
				"Scar_InteriorTail_SoundSet",
				"Scar_Slapback_SoundSet",
				"Scar_Tail_2D_SoundSet"
			};
			soundSetShotExt1st[]=
			{
				
				{
					"Scar_1st_silencerHomeMade_SoundSet"
				}
			};
			soundSetShotExt[]=
			{
				
				{
					"Scar_silencerHomeMade_SoundSet",
					"Scar_silencerHomeMadeTail_SoundSet",
					"Scar_silencerInteriorHomeMadeTail_SoundSet"
				}
			};
			reloadTime=0.097999997;
			recoil="recoil_fal";
			recoilProne="recoil_fal_prone";
			dispersion=0.0020000001;
			magazineSlot="magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=25;
			distanceZoomMax=25;
		};
		class InventorySlotsOffsets
		{
			class Shoulder
			{
				position[]={-0.050000001,0,0.02};
				orientation[]={0,0,0};
			};
			class Melee
			{
				position[]={-0.050000001,0,-0.050000001};
				orientation[]={0,0,0};
			};
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_mosin9130_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					positionOffset[]={0,0,0};
				};
				class MuzzleFlashStar
				{
					overrideParticle="weapon_shot_Flame_3D_4star";
					ignoreIfSuppressed=1;
					overrideDirectionVector[]={0,45,0};
					positionOffset[]={0.0099999998,0,0};
				};
				class ChamberSmoke
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
					overrideDirectionPoint="Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=8;
				shotsToStartOverheating=4;
				overheatingDecayInterval=0.69999999;
				class SmokingBarrel1
				{
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,0.5};
					positionOffset[]={0.2,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrel2
				{
					overrideParticle="smoking_barrel";
					onlyWithinOverheatLimits[]={0.5,0.69999999};
					positionOffset[]={0.2,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrel3
				{
					overrideParticle="smoking_barrel_heavy";
					onlyWithinOverheatLimits[]={0.69999999,1};
					positionOffset[]={0.2,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle="smoking_barrel_steam";
					positionOffset[]={0.1,0,0};
					onlyWithinRainLimits[]={0.2,1};
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
				};
			};
		};
		weaponStateAnim="dz\anims\anm\player\reloads\SCAR\w_SCAR_states.anm";
		class AnimationSources
		{
			class opticAttached
			{
				source="user";
				initPhase=0;
				animPeriod=0.30000001;
			};
		};
	};
	class SCARH: SCARH_Base
	{
		scope=2;
		displayName="$STR_cfgWeapons_SCARH0";
		descriptionShort="$STR_cfgWeapons_SCARH1";
		model="\DZ\weapons\firearms\SCARH\ScarH.p3d";
		attachments[]=
		{
			"weaponButtstockSCAR",
			"weaponWrap",
			"weaponOptics",
			"suppressorImpro",
			"Scarh_FrontSight",
			"weaponFlashlight"
		};
		itemSize[]={8,3};
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\firearms\scarh\data\scarh_mat1_co.paa",
			"dz\weapons\firearms\scarh\data\scarh_mat2_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\scarh\data\scarh_mat1.rvmat",
			"dz\weapons\firearms\scarh\data\scarh_mat2.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_damage.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_damage.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_destruct.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SCARH_Black: SCARH
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\firearms\scarh\data\scarh_mat1_black_co.paa",
			"dz\weapons\firearms\scarh\data\scarh_mat2_black_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\firearms\scarh\data\scarh_mat1_black.rvmat",
			"dz\weapons\firearms\scarh\data\scarh_mat2_black.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					RefTexsMats[]=
					{
						"dz\weapons\firearms\scarh\data\scarh_mat1.rvmat",
						"dz\weapons\firearms\scarh\data\scarh_mat2.rvmat"
					};
					hitpoints=300;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_black.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_black.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_black.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_black.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_black_damage.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_black_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_black_damage.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_black_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\weapons\firearms\scarh\data\scarh_mat1_black_destruct.rvmat",
								"dz\weapons\firearms\scarh\data\scarh_mat2_black_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Scarh_Front_Sight: Inventory_Base
	{
		scope=2;
		model="\DZ\weapons\firearms\SCARH\proxy\ScarH_FrontSight.p3d";
		weight=1;
		inventorySlot[]=
		{
			"Scarh_FrontSight"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\firearms\SCARH\data\scar_frontsight.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\firearms\SCARH\data\scar_frontsight.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\firearms\SCARH\data\scar_frontsight_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\firearms\SCARH\data\scar_frontsight_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\firearms\SCARH\data\scar_frontsight_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyScarH_FrontSight: ProxyAttachment
	{
		scope=0;
		inventorySlot="Scarh_FrontSight";
		model="\dz\weapons\firearms\scarh\proxy\ScarH_FrontSight.p3d";
	};
};
