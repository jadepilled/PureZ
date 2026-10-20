class CfgPatches
{
	class DZ_Vehicles_Singletrack
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Vehicles_Wheeled"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Motorbike;
	class CarWheel;
	class MotorbikeWheel: CarWheel
	{
	};
	class MotorbikeScript: Motorbike
	{
		rotationFlags=64;
		storageCategory=4;
		debug_ItemCategory=8;
		displayWeight=0;
		insideSoundCoef=0.89999998;
		fuelCapacity=50;
		brakeFluidCapacity=1;
		oilCapacity=4;
		coolantCapacity=6;
		brakeFluidLeakDebit[]={0,0};
		oilLeakDebit[]={0,0};
		coolantLeakDebit[]={0,0};
		brakeFluidForceCoef[]={0,1,1,1};
		damageFromOil[]={0,0,1,0};
		damageFromCoolant[]={0,0,1,0};
		engineBeltSlot="EngineBelt";
		batterySlot="CarBattery";
		electricPowerResName="power";
		electricConsumptionIgnition=3001;
		electricConsumptionEngine=0;
		electricConsumptionLights=0;
		electricOutputEngine=5;
		selectionDashboard="light_dashboard";
		selectionLightFrontL="light_left";
		selectionLightFrontR="light_right";
		selectionBrakeLights="light_break";
		hasHistory=1;
		class Crew
		{
			class Driver
			{
				actionSel="seat_driver";
				proxyPos="crewDriver";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
				isDriver=1;
			};
			class CoDriver: Driver
			{
				actionSel="seat_driver";
				proxyPos="crewCoDriver";
				getInPos="pos_codriver";
				getInDir="pos_codriver_dir";
				isDriver=1;
			};
		};
		class SimulationModule
		{
			class Wheels
			{
				class Front
				{
					inventorySlot="";
					animTurn="turnfront";
					animRotation="wheelfront";
					animDamper="damperfront";
					wheelHub="wheel_1_damper_land";
				};
				class Rear
				{
					inventorySlot="";
					animTurn="turnback";
					animRotation="wheelback";
					animDamper="damperback";
					wheelHub="wheel_2_damper_land";
				};
			};
		};
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1"
		};
		hiddenSelections[]=
		{
			""
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		hiddenSelectionsMaterials[]=
		{
			""
		};
		class AnimationSources
		{
			class HideDestroyed_1_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_1_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class AnimHitWheel_1
			{
				source="Hit";
				hitpoint="HitWheel_1";
				raw=1;
			};
			class AnimHitWheel_2: AnimHitWheel_1
			{
				hitpoint="HitWheel_2";
			};
		};
		class NoiseCarHorn
		{
			strength=30;
			type="sound";
		};
	};
	class Motorbike_01_Wheel_1: MotorbikeWheel
	{
		scope=2;
		displayName="$STR_MotorbikeWheel0";
		descriptionShort="$STR_MotorbikeWheel1";
		model="\DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_wheel_1.p3d";
		inventorySlot[]=
		{
			"Motorbike_01_Wheel_1"
		};
		rotationFlags=8;
		radius=0.28999999;
		width=0.059999999;
		tyreType=1;
		tyreOffroadResistance=0.69999999;
		tyreRollResistance=0.0099999998;
		tyreGrip=0.85000002;
		tyreRoughness=1;
		tyreLongitudinalFriction=0.85000002;
		tyreLateralFriction=3;
	};
	class Motorbike_01_Wheel_1_Ruined: Motorbike_01_Wheel_1
	{
		model="\DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_wheel_1_ruined.p3d";
		radius=0.22;
		width=0.2;
		tyreOffroadResistance=0.02;
		tyreRollResistance=0.69999999;
		tyreGrip=0.25;
		tyreRoughness=1;
		tyreLongitudinalFriction=0.5;
		tyreLateralFriction=0.5;
	};
	class Motorbike_01_Wheel_2: MotorbikeWheel
	{
		scope=2;
		displayName="$STR_MotorbikeWheel0";
		descriptionShort="$STR_MotorbikeWheel1";
		model="\DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_wheel_2.p3d";
		inventorySlot[]=
		{
			"Motorbike_01_Wheel_2"
		};
		rotationFlags=8;
		radius=0.28999999;
		width=0.14;
		tyreType=1;
		tyreOffroadResistance=0.69999999;
		tyreRollResistance=0.0080000004;
		tyreGrip=0.85000002;
		tyreRoughness=1;
		tyreLongitudinalFriction=0.85000002;
		tyreLateralFriction=6;
	};
	class Motorbike_01_Wheel_2_Ruined: Motorbike_01_Wheel_2
	{
		model="\DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_wheel_2_ruined.p3d";
		radius=0.22;
		width=0.2;
		tyreOffroadResistance=0.02;
		tyreRollResistance=0.80000001;
		tyreGrip=0.34999999;
		tyreRoughness=0.5;
		tyreLongitudinalFriction=0.5;
		tyreLateralFriction=0.5;
	};
	class Motorbike_01_ColorBase: MotorbikeScript
	{
		scope=1;
		displayName="$STR_Motorbike1";
		model="\DZ\vehicles\singletrack\Motorbike_01\Motorbike_01.p3d";
		attachments[]=
		{
			"SparkPlug",
			"Reflector_1_1",
			"Motorbike_01_Wheel_1",
			"Motorbike_01_Wheel_2"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo_fender",
			"lights_brake",
			"lights_front",
			"lights_rear"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_blue_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_blue_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender.rvmat",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_nolight.rvmat",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_nolight.rvmat",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_nolight.rvmat"
		};
		fuelCapacity=3.5;
		fuelConsumption=1.8;
		speedGeomActivation=0.28999999;
		speedGeoms[]=
		{
			"geotohide"
		};
		class SimulationModule: SimulationModule
		{
			neutralGearMaxSpeed=1.3;
			class Steering
			{
				tipoverAngle=50;
				maxSteeringAngle[]={1,40,5,40,15,20,30,5,40,3,80,1};
				maxLeanAngle[]={1,0,5,8,15,10,30,17,40,22,80,30};
				steerIncreaseSpeed[]={0,80,40,60,80,40,120,20};
				steerDecreaseSpeed[]={0,80,40,60,80,40,120,20};
				steerCenteringSpeed[]={0,40,40,25,80,15,120,10};
				leanAngleMultiplier[]={0,1,120,1};
				leanTargetResponsiveness[]={0,2,120,2};
				leanVelocityResponsiveness[]={0,8,120,8};
				directControl[]={0,1,5,1,30,0.60000002,60,0.2,80,0};
			};
			class Throttle
			{
				reactionTime=0.15000001;
				defaultThrust=0.81999999;
				gentleThrust=0.30000001;
				turboCoef=1.5;
				gentleCoef=0.80000001;
				slopeCoef=0.75;
			};
			class Brakes
			{
				class Front
				{
					input=1;
					pressureBySpeed[]={0,0.85000002,10,0.69999999,40,0.60000002,60,0.5,80,0.5};
					gentleCoef=0.5;
					minPressure=0.15000001;
					reactionTime=0.25;
					driverless=0.2;
				};
				class Rear
				{
					input=0;
					pressureBySpeed[]={0,0.94999999,10,0.1,20,0.1,40,0.1,50,0.1};
					gentleCoef=0.5;
					minPressure=0.050000001;
					reactionTime=0.25;
					driverless=0.2;
				};
			};
			class Aerodynamics
			{
				frontalArea=0.80000001;
				dragCoefficient=0.85000002;
				downforceCoefficient=0;
				downforceOffset[]={0,0.2,0.5};
			};
			class Engine
			{
				torqueCurve[]={400,0,1100,4,2500,7,4500,8,5500,7,6000,5,7000,0};
				inertia=0.029999999;
				frictionTorque=1;
				rollingFriction=0.1;
				viscousFriction=0.5;
				rpmIdle=1200;
				rpmMin=1400;
				rpmClutch=1500;
				rpmRedline=6000;
			};
			class Clutch
			{
				maxTorqueTransfer=30;
				uncoupleTime=0.2;
				coupleTime=0.60000002;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=2.9400001;
				ratios[]={3.9300001,2.4300001,0.82999998};
			};
			class Wheels: Wheels
			{
				class Front: Front
				{
					maxBrakeTorque=800;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					casterOffset=0;
					casterAngle=25;
					class Suspension
					{
						stiffness=5500;
						compression=600;
						damping=1150;
						travelMaxUp=0.066;
						travelMaxDown=0.066;
					};
					animDamper="damperfront";
					inventorySlot="Motorbike_01_Wheel_1";
				};
				class Rear: Rear
				{
					maxBrakeTorque=1200;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					driveRatio=10.2789;
					class Suspension
					{
						stiffness=7000;
						compression=750;
						damping=1350;
						travelMaxUp=0.057999998;
						travelMaxDown=0.043000001;
					};
					animDamper="damperback";
					inventorySlot="Motorbike_01_Wheel_2";
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class damper_1
			{
				source="user";
				initPhase=0.63999999;
				animPeriod=1;
			};
			class damper_2
			{
				source="user";
				initPhase=0.60699999;
				animPeriod=1;
			};
			class SeatDriver
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					displayName="$STR_CfgVehicleDmg_Chassis0";
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]={};
				};
				class Fender
				{
					displayName="$STR_CfgVehicleDmg_Fender0";
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fender"
					};
					class Health
					{
						hitpoints=200;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class Engine
				{
					displayName="$STR_CfgVehicleDmg_Engine0";
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=1;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]=
					{
						"SparkPlug"
					};
					inventorySlotsCoefs[]={0.029999999};
				};
				class Front
				{
					displayName="$STR_Motorbike_Front0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front"
					};
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Engine",
						"Fender",
						"Chassis"
					};
					transferToZonesCoefs[]={0.75,0.60000002,0.80000001};
					inventorySlots[]=
					{
						"Motorbike_01_Wheel_1"
					};
					inventorySlotsCoefs[]={0.5};
				};
				class Reflector_1_1
				{
					displayName="$STR_CfgVehicleDmg_Reflector0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=10;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_glass.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_glass.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_glass_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_destruct.rvmat",
									"hidden"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front"
					};
					transferToZonesCoefs[]={1};
					inventorySlots[]=
					{
						"Reflector_1_1"
					};
					inventorySlotsCoefs[]={1};
				};
				class Back
				{
					displayName="$STR_Motorbike_Back0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
							"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_noncolorized_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_wheel_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_rear_brake_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Engine",
						"FuelTank"
					};
					transferToZonesCoefs[]={0.050000001,0.30000001};
					inventorySlots[]=
					{
						"Motorbike_01_Wheel_2"
					};
					inventorySlotsCoefs[]={0.1};
				};
				class FuelTank
				{
					displayName="$STR_CfgVehicleDmg_FuelTank0";
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=400;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
			class GUIInventoryAttachmentsProps
			{
				class Engine
				{
					name="$STR_attachment_Engine0";
					description="";
					icon="set:dayz_inventory image:cat_vehicle_engine";
					attachmentSlots[]=
					{
						"SparkPlug"
					};
				};
				class Body
				{
					name="$STR_attachment_Body0";
					description="";
					icon="set:dayz_inventory_additional image:motorcycle_body";
					attachmentSlots[]=
					{
						"Reflector_1_1"
					};
				};
				class Chassis
				{
					name="$STR_attachment_Chassis0";
					description="";
					icon="set:dayz_inventory_additional image:motorcycle_chassis";
					attachmentSlots[]=
					{
						"Motorbike_01_Wheel_1",
						"Motorbike_01_Wheel_2"
					};
				};
			};
		};
	};
	class Motorbike_01_Blue: Motorbike_01_ColorBase
	{
		scope=2;
	};
	class Motorbike_01_Yellow: Motorbike_01_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_yellow_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_yellow_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa"
		};
	};
	class Motorbike_01_Red: Motorbike_01_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_colorized_red_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_fender_red_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_01\data\motorbike_01_lights_co.paa"
		};
	};
	class Motorbike_02_Wheel_1: MotorbikeWheel
	{
		scope=2;
		displayName="$STR_MotorbikeWheel0";
		descriptionShort="$STR_MotorbikeWheel1";
		model="\DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_1.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_Wheel_1"
		};
		rotationFlags=8;
		radiusByDamage[]={0,0.34,0.30000001,0.30000001,0.99980003,0.25,0.99989998,0.2};
		radius=0.315;
		width=0.046;
		tyreType=1;
		tyreOffroadResistance=0.85000002;
		tyreRollResistance=0.0080000004;
		tyreGrip=0.94999999;
		tyreLongitudinalFriction=1.8;
		tyreLateralFriction=3.5;
	};
	class Motorbike_02_Wheel_1_Ruined: Motorbike_02_Wheel_1
	{
		model="\DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_1_ruined.p3d";
		radius=0.27000001;
		width=0.074000001;
		tyreOffroadResistance=0.02;
		tyreRollResistance=0.69999999;
		tyreGrip=0.25;
		tyreLongitudinalFriction=0.5;
		tyreLateralFriction=0.5;
	};
	class Motorbike_02_Wheel_2: MotorbikeWheel
	{
		scope=2;
		displayName="$STR_MotorbikeWheel0";
		descriptionShort="$STR_MotorbikeWheel1";
		model="\DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_2.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_Wheel_2"
		};
		rotationFlags=8;
		radiusByDamage[]={0,0.34,0.30000001,0.30000001,0.99980003,0.25,0.99989998,0.2};
		radius=0.315;
		width=0.068000004;
		tyreType=1;
		tyreOffroadResistance=0.85000002;
		tyreRollResistance=0.0080000004;
		tyreGrip=0.94999999;
		tyreLongitudinalFriction=1.8;
		tyreLateralFriction=7;
	};
	class Motorbike_02_Wheel_2_Ruined: Motorbike_02_Wheel_2
	{
		model="\DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_2_ruined.p3d";
		radius=0.27000001;
		width=0.092;
		tyreOffroadResistance=0.02;
		tyreRollResistance=0.69999999;
		tyreGrip=0.25;
		tyreLongitudinalFriction=0.5;
		tyreLateralFriction=0.5;
	};
	class Motorbike_02_ShieldFront_ColorBase: Inventory_Base
	{
		scope=0;
		displayName="$STR_Motorbike_Shield0";
		descriptionShort="$STR_Motorbike_Shield1";
		model="dz\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_windshield.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldFront"
		};
		rotationFlags=8;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_windshield.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_windshield_red_co.paa"
		};
		itemBehaviour=0;
		physLayer="item_small";
		itemSize[]={4,3};
		weight=500;
		lockType=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_windshield.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_windshield.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_windshield_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_windshield_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_windshield_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Motorbike_02_ShieldFront_Red: Motorbike_02_ShieldFront_ColorBase
	{
		scope=2;
	};
	class Motorbike_02_ShieldFront_Green: Motorbike_02_ShieldFront_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_windshield_green_co.paa"
		};
	};
	class Motorbike_02_ShieldFront_Yellow: Motorbike_02_ShieldFront_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_windshield_yellow_co.paa"
		};
	};
	class Motorbike_02_ShieldFront_Blue: Motorbike_02_ShieldFront_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_windshield_blue_co.paa"
		};
	};
	class Motorbike_02_ShieldLeft_ColorBase: Motorbike_02_ShieldFront_ColorBase
	{
		scope=0;
		displayName="$STR_Motorbike_Shield0";
		descriptionShort="$STR_Motorbike_Shield1";
		model="dz\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_shieldleft.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldLeft"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\Motorbike_02_shieldleft.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldleft_red_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldleft.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldleft.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldleft_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldleft_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldleft_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Motorbike_02_ShieldLeft_Red: Motorbike_02_ShieldLeft_ColorBase
	{
		scope=2;
	};
	class Motorbike_02_ShieldLeft_Green: Motorbike_02_ShieldLeft_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldleft_green_co.paa"
		};
	};
	class Motorbike_02_ShieldLeft_Yellow: Motorbike_02_ShieldLeft_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldleft_yellow_co.paa"
		};
	};
	class Motorbike_02_ShieldLeft_Blue: Motorbike_02_ShieldLeft_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldleft_blue_co.paa"
		};
	};
	class Motorbike_02_ShieldRight_ColorBase: Motorbike_02_ShieldFront_ColorBase
	{
		scope=0;
		displayName="$STR_Motorbike_Shield0";
		descriptionShort="$STR_Motorbike_Shield1";
		model="dz\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_shieldright.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldRight"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\Motorbike_02_shieldright.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldright_red_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldright.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldright.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldright_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldright_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\vehicles\singletrack\Motorbike_02\data\Motorbike_02_shieldright_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Motorbike_02_ShieldRight_Red: Motorbike_02_ShieldRight_ColorBase
	{
		scope=2;
	};
	class Motorbike_02_ShieldRight_Green: Motorbike_02_ShieldRight_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldright_green_co.paa"
		};
	};
	class Motorbike_02_ShieldRight_Yellow: Motorbike_02_ShieldRight_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldright_yellow_co.paa"
		};
	};
	class Motorbike_02_ShieldRight_Blue: Motorbike_02_ShieldRight_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_shieldright_blue_co.paa"
		};
	};
	class Motorbike_02_ColorBase: MotorbikeScript
	{
		scope=1;
		displayName="$STR_Motorbike2";
		model="\DZ\vehicles\singletrack\Motorbike_02\Motorbike_02.p3d";
		attachments[]=
		{
			"SparkPlug",
			"Reflector_1_1",
			"Motorbike_02_Wheel_1",
			"Motorbike_02_Wheel_2",
			"Motorbike_02_ShieldFront",
			"Motorbike_02_ShieldLeft",
			"Motorbike_02_ShieldRight"
		};
		hiddenSelections[]=
		{
			"camo",
			"camo_exhaust",
			"camo_fenderfront",
			"camo_fenderrear",
			"light_1_1",
			"light_1_2",
			"light_brake_1_2"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_exhaust.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_nolight.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_nolight.rvmat",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_nolight.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_red_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_exhaust_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa"
		};
		fuelCapacity=13.5;
		fuelConsumption=3.5;
		speedGeomActivation=0.27000001;
		speedGeoms[]=
		{
			"geotohide"
		};
		class SimulationModule: SimulationModule
		{
			neutralGearMaxSpeed=0.80000001;
			class Steering
			{
				tipoverAngle=60;
				maxSteeringAngle[]={1,40,5,40,10,35,30,12,60,3,120,1};
				maxLeanAngle[]={1,0,5,8,10,12,30,20,60,30,120,40};
				steerIncreaseSpeed[]={0,80,40,40,80,20,120,1};
				steerDecreaseSpeed[]={0,80,40,60,80,45,120,35};
				steerCenteringSpeed[]={0,60,40,30,80,20,120,15};
				leanAngleMultiplier[]={0,1.5,120,1.5};
				leanTargetResponsiveness[]={0,2,120,2};
				leanVelocityResponsiveness[]={0,8,120,8};
				directControl[]={0,1,5,1,30,0.60000002,60,0.2,80,0};
			};
			class Throttle
			{
				reactionTime=0.15000001;
				defaultThrust=0.81999999;
				gentleThrust=0.30000001;
				turboCoef=2;
				gentleCoef=0.80000001;
				slopeCoef=0.75;
			};
			class Brakes
			{
				class Front
				{
					input=1;
					pressureBySpeed[]={0,0.52999997,10,0.68000001,20,0.5,40,0.55000001,80,0.62,120,0.77999997};
					gentleCoef=0.60000002;
					minPressure=0.2;
					reactionTime=0.25;
					driverless=0.1;
				};
				class Rear
				{
					input=0;
					pressureBySpeed[]={0,0.63,10,0.1,20,0.1,40,0.1,80,0.1,120,0.1};
					gentleCoef=0.60000002;
					minPressure=0.050000001;
					reactionTime=0.25;
					driverless=0.1;
				};
			};
			class Aerodynamics
			{
				frontalArea=1.25;
				dragCoefficient=0.25;
				downforceCoefficient=0;
				downforceOffset[]={0,0.40000001,0.5};
			};
			class Engine
			{
				torqueCurve[]={400,4,1500,15,2500,25,3000,30,3830,36,5142,36,6000,25,7000,0};
				inertia=0.050000001;
				frictionTorque=1;
				rollingFriction=0.1;
				viscousFriction=0.5;
				rpmIdle=1300;
				rpmMin=1400;
				rpmClutch=1700;
				rpmRedline=6000;
			};
			class Clutch
			{
				maxTorqueTransfer=100;
				uncoupleTime=0.30000001;
				coupleTime=0.2;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=2.9400001;
				ratios[]={2.5,1.3,0.94999999,0.55000001};
			};
			class Wheels: Wheels
			{
				class Front: Front
				{
					maxBrakeTorque=2800;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					casterOffset=0.037999999;
					casterAngle=27;
					class Suspension
					{
						stiffness=5150;
						compression=900;
						damping=1900;
						travelMaxUp=0.25;
						travelMaxDown=0.0099999998;
					};
					animDamper="damperfront";
					inventorySlot="Motorbike_02_Wheel_1";
				};
				class Rear: Rear
				{
					maxBrakeTorque=3800;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					driveRatio=10.2789;
					class Suspension
					{
						stiffness=1650;
						compression=600;
						damping=800;
						travelMaxUp=0.31299999;
						travelMaxDown=0.18700001;
					};
					animDamper="damperback";
					inventorySlot="Motorbike_02_Wheel_2";
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class damper_1
			{
				source="user";
				initPhase=0.63999999;
				animPeriod=1;
			};
			class damper_2
			{
				source="user";
				initPhase=0.60699999;
				animPeriod=1;
			};
			class coolant
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					displayName="$STR_CfgVehicleDmg_Chassis0";
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_rear_brake_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]={};
				};
				class Front
				{
					displayName="$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_destruct.rvmat",
									"hidden",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Engine",
						"FenderFront"
					};
					transferToZonesCoefs[]={0.80000001,0.1};
					inventorySlots[]=
					{
						"Motorbike_02_Wheel_1",
						"Motorbike_02_ShieldFront"
					};
					inventorySlotsCoefs[]={0.15000001,0.15000001};
				};
				class FenderFront
				{
					displayName="$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgzone_fenderfront"
					};
					componentNames[]=
					{
						"dmgzone_fenderfront"
					};
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Engine"
					};
					transferToZonesCoefs[]={0.5};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class Reflector_1_1
				{
					displayName="$STR_CfgVehicleDmg_Reflector0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints=10;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_destruct.rvmat",
									"hidden"
								}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front"
					};
					transferToZonesCoefs[]={1};
					inventorySlots[]=
					{
						"Reflector_1_1"
					};
					inventorySlotsCoefs[]={1};
				};
				class Back
				{
					displayName="$STR_Motorbike_Back0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back"
					};
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_destruct.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_wheel_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					inventorySlots[]=
					{
						"Motorbike_02_Wheel_2",
						"Motorbike_02_ShieldLeft",
						"Motorbike_02_ShieldRight"
					};
					inventorySlotsCoefs[]={0.15000001,0.15000001,0.15000001};
				};
				class FenderRear
				{
					displayName="$STR_CfgVehicleDmg_Fender0";
					fatalInjuryCoef=-1;
					memoryPoints[]=
					{
						"dmgzone_fenderrear"
					};
					componentNames[]=
					{
						"dmgzone_fenderrear"
					};
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_destruct.rvmat"
								}
							}
						};
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
				class Engine
				{
					displayName="$STR_CfgVehicleDmg_Engine0";
					fatalInjuryCoef=0.001;
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\Motorbike_02\data\motorbike_02_body_destruct.rvmat"
								}
							}
						};
					};
					inventorySlots[]=
					{
						"SparkPlug"
					};
					inventorySlotsCoefs[]={0.029999999};
				};
				class FuelTank
				{
					displayName="$STR_CfgVehicleDmg_FuelTank0";
					fatalInjuryCoef=-1;
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints=400;
						transferToGlobalCoef=0;
						RefTexsMats[]=
						{
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
							"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_damage.rvmat",
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_glass_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_destruct.rvmat",
									"hidden"
								}
							}
						};
					};
					inventorySlots[]={};
					inventorySlotsCoefs[]={};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="set:dayz_inventory image:cat_vehicle_engine";
				attachmentSlots[]=
				{
					"SparkPlug"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="set:dayz_inventory_additional image:motorcycle_body";
				attachmentSlots[]=
				{
					"Reflector_1_1",
					"Motorbike_02_ShieldFront",
					"Motorbike_02_ShieldLeft",
					"Motorbike_02_ShieldRight"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="set:dayz_inventory_additional image:motorcycle_chassis";
				attachmentSlots[]=
				{
					"Motorbike_02_Wheel_1",
					"Motorbike_02_Wheel_2"
				};
			};
		};
	};
	class Motorbike_02_Red: Motorbike_02_ColorBase
	{
		scope=2;
	};
	class Motorbike_02_Yellow: Motorbike_02_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_yellow_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_exhaust_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa"
		};
	};
	class Motorbike_02_Blue: Motorbike_02_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_blue_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_exhaust_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa"
		};
	};
	class Motorbike_02_Green: Motorbike_02_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_body_green_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_exhaust_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderfront_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_fenderrear_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa",
			"dz\vehicles\singletrack\motorbike_02\data\motorbike_02_lights_co.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyVehiclePart;
	class ProxyMotorbike_01_wheel_1: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_Wheel_1.p3d";
		inventorySlot[]=
		{
			"Motorbike_01_Wheel_1"
		};
	};
	class ProxyMotorbike_01_wheel_2: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_01\proxy\Motorbike_01_wheel_2.p3d";
		inventorySlot[]=
		{
			"Motorbike_01_Wheel_2"
		};
	};
	class ProxyMotorbike_02_wheel_1: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_1.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_Wheel_1"
		};
	};
	class ProxyMotorbike_02_wheel_2: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_wheel_2.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_Wheel_2"
		};
	};
	class ProxyMotorbike_02_windshield: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_windshield.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldFront"
		};
	};
	class ProxyMotorbike_02_shieldleft: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_shieldleft.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldLeft"
		};
	};
	class ProxyMotorbike_02_shieldright: ProxyVehiclePart
	{
		model="DZ\vehicles\singletrack\Motorbike_02\proxy\Motorbike_02_shieldright.p3d";
		inventorySlot[]=
		{
			"Motorbike_02_ShieldRight"
		};
	};
};
