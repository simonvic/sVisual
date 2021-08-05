#define S_UDE
#define S_VISUAL

class CfgPatches {
	class sVisual {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Scripts"
		};
	};
};

class CfgMods {
	class sVisual {
		dir = "MyMODS/sVisual";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "sVisual";
		credits = "simonvic";
		author = "simonvic";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
		class defs {
			class gameScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/defines",
					"MyMODS/sVisual/scripts/3_Game"
				};
			};
			class worldScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/defines",
					"MyMODS/sVisual/scripts/4_World"
				};
			};
			
			class missionScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/defines",
					"MyMODS/sVisual/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles{
	class SCameraOverlay {
		image="";
		alpha=1.0;
		mask="";
		maskProgress=1.0;
		maskTransitionWidth=1.0;
		position[] = {0.0, 0.0};
		size[] = {1.0, 1.0};
		rotation[] = {0.0, 0.0, 0.0};
		priority = 0;
		targetCameras[] = {"DayZPlayerCamera"};
	};

	class SCameraOverlay_Eyewear : SCameraOverlay {
		priority = 2;
		targetCameras[] = {"DayZPlayerCamera1stPerson", "DayZPlayerCameraIronsights"};
	};

	class SCameraOverlay_Headgear : SCameraOverlay {
		priority = 1;
		targetCameras[] = {"DayZPlayerCamera1stPerson", "DayZPlayerCameraIronsights"};
	};


	class MotoHelmet_ColorBase {
		class sUDE {
			class CameraOverlays {

				class overlay_0 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_pristine.edds";
					alpha=0.05;
					size[] = {1.2, 1.2};
					rotation[] = {0.0, 0.0, 180.0};
				};

				class overlay_1 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_worn.edds";
					alpha=0.05;
					size[] = {1.2, 1.2};
					rotation[] = {0.0, 0.0, 180.0};
				};

				class overlay_2 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_damaged.edds";
					alpha=0.05;
					size[] = {1.2, 1.2};
					rotation[] = {0.0, 0.0, 180.0};
				};
				
				class overlay_3 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_badlydamaged.edds";
					alpha=0.05;
					size[] = {1.2, 1.2};
					rotation[] = {0.0, 0.0, 180.0};
				};
			};
		};
	};

	class SportGlasses_ColorBase {
		class sUDE {
			class CameraOverlays{
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_pristine.edds";
					alpha=0.05;
					priority=1;
				};

				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_worn.edds";
					alpha=0.1;
					priority=1;
				};

				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_damaged.edds";
					alpha=0.1;
					priority=1;
				};
				
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/generic_scratches_badlydamaged.edds";
					alpha=0.1;
					priority=1;
				};
			};
		};
	};

	class BurlapSackCover {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/burlap.edds";
					size[] = {1.1, 1.1};
					targetCameras[] = {"DayZPlayerCamera"};
				};
			};
		};
	};

	class GasMask {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/black_4x4.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/binoculars_inverted.edds";
					maskProgress=0.45;
					maskTransitionWidth=1.0;
					size[] = {1.1, 1.05};
				};
			};
		};
	};

	class GP5GasMask {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/black_4x4.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/binoculars_inverted.edds";
					maskProgress=0.8;
					maskTransitionWidth=0.5;
					size[] = {1.05, 1.1};
				};
			};
		};
	};

	class AirborneMask {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/black_4x4.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/binoculars_inverted.edds";
					maskProgress=0.45;
					maskTransitionWidth=1.0;
					size[] = {1.3, 1.3};
				};
			};
		};
	};
};

class Cfg_sUDE{
	class BaseBuilding{
		enabled = 0;
	};
	class Caves{
		enabled = 0;
	};
	class Character{
		enabled = 0;
	};
	class Driving{
		enabled = 0;
	};
	class Inventory{
		enabled = 0;
	};
	class Looting{
		enabled = 0;
	};
	class Medical{
		enabled = 0;
	};
	class Gunplay{
		enabled = 0;
	};
	class SoftSkills{
		enabled = 0;
	};
	class Survival{
		enabled = 0;
		class Cooking{
			class Recipes{
				minFluidity = 0;
				maxFluidity = 9999;
				class Liquids{
					minFluidity = 500;
					class Drinks{
						maxFluidity = 9999;
						class CoffeeRecipe{};
					};
					class Soups{
						maxFluidity = 1000;
						class MushroomSoupRecipe{};
					};
				};
				class Solids{
					minFluidity = 0;
					maxFluidity = 500;
					class CookedRiceRecipe{};
					class RiceAndMushroomsRecipe{};
				};
			};
		};
	};
	class Visual{
		enabled = 1;
		class Camera{
			peakMitigationEnabled = 1;
			class HeadBob{
				//                       yawStrenght, yawFrequency, pitchStrenght, pitchFrequency
				idle[] =                    { 0.0,        0.0,         1.1,            0.5 };
				erect_walking[] =           { 0.5,        5.75,        0.5,            11.5 };
				erect_jogging[] =           { 1.0,        9.0,         0.5,            18.0 };
				erect_running[] =           { 2.4,        11.5,        0.5,            23.0 };
				erect_raised_walking[] =    { 0.5,        1.75,        0.5,             6.5 };
				erect_raised_jogging[] =    { 1.0,        8.75,        0.5,            17.5 };
				crouch_walking[] =          { 0.5,        5.75,        0.5,            11.5 };
				crouch_running[] =          { 1.0,        9.0,         0.5,            18.0 };
				crouch_raised_walking[] =   { 0.5,        5.75,        0.5,            11.5 };
				prone_walking[] =           { 0.5,        5.75,        0.5,            11.5 };
			};
		};
		class PPEffects{
			class DefaultValues{
				saturation = 1.0;
				vignette_strength = 0.0;
				overlay_factor = 0.0;
				bloom_threshold = 0.01;
				bloom_steepness = 0.0;
				bloom_intensity = 0.5;
				lens_distort = 0.0;
				lens_center_x = 0.0;
				lens_center_y = 0.0;
				lens_chrom_aber = 0.0;
				motion_blur_power = 0.01;
				motion_blur_mindepth = 0.8;
				motion_blur_maxdepth = 0.9;
				motion_blur_min_angle_per_sec = 10.0;
				motion_blur_max_angle_per_sec = 100.0;
				gauss_blur_intensity = 0.0;
				radial_blur_power_x = 0.0;
				radial_blur_power_y = 0.0;
				radial_blur_offset_x = 0.0;
				radial_blur_offset_y = 0.0;
				chrom_aber_power_x = 0.0;
				chrom_aber_power_y = 0.0;
				film_grain_sharpness = 0.0;
				film_grain_grain_size = 0.0;
				godrays_sun_intensity = 0.8;
				godrays_sun_overburn_intensity = 0.25;
				godrays_sun_overburn_start = 0.025;
				godrays_sun_overburn_end = 0.175;
				godrays_sun_mask = 0.8;
				godrays_sun_size = 0.15;
				godrays_sun_v_intensity = 0.75;
				godrays_sun_d_intensity = 0.60;

				vignette_color[] = { 0.0, 0.0, 0.0, 0.0 };
				overlay_color[] = { 0.0, 0.0, 0.0, 0.0 };
				colorization[] = { 1.0, 1.0, 1.0, 1.0 };
			};
		};
	};
};