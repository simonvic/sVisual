class CfgPatches {
	class sVisual {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"sFramework",
			"DZ_Characters_Headgear",
			"DZ_Characters_Glasses"
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

		defines[] = {
			"S_VISUAL"
		};

		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
		class defs {
			class gameScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/3_Game"
				};
			};
			class worldScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/4_World"
				};
			};
			
			class missionScriptModule {
				value = "";
				files[] = {
					"MyMODS/sVisual/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles{

	class Clothing;
	class SCameraOverlay_Headgear;
	class SCameraOverlay_Eyewear;

	class BurlapSackCover : Clothing {
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

	class MotoHelmet_ColorBase : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/ruined.edds";
				};
			};
		};
	};

	class DarkMotoHelmet_ColorBase : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/ruined.edds";
				};
			};
		};
	};

	class DarkMotoHelmet_YellowScarred : DarkMotoHelmet_ColorBase {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth=0.3;
					maskProgress=0.4;
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth=0.3;
					maskProgress=0.4;
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth=0.3;
					maskProgress=0.4;
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth=0.3;
					maskProgress=0.4;
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image="MyMODS/sVisual/GUI/textures/overlays/motohelmet/ruined.edds";
					mask="MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth=0.3;
					maskProgress=0.4;
				};
			};
		};
	};

	/*
	class GasMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/ruined.edds";
				};
			};
		};
	};

	class GP5GasMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/ruined.edds";
				};
			};
		};
	};

	class AirborneMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/gasmask/ruined.edds";
				};
			};
		};
	};
	*/

	class SportGlasses_ColorBase : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
				};
			};
		};
	};

	class AviatorGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
				};
			};
		};
	};

	class DesignerGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
				};
			};
		};
	};

	class ThickFramesGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
				};
			};
		};
	};

	class ThinFramesGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
				};
			};
		};
	};
	
	class TacticalGoggles : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					opacity = 0.5;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					opacity = 0.5;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					opacity = 0.75;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
					rotation[] = {180.0, 0.0, 0.0};
					opacity = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image="MyMODS/sVisual/GUI/textures/overlays/glasses/ruined.edds";
					rotation[] = {180.0, 0.0, 0.0};
					opacity = 0.75;
				};
			};
		};
	};

};

class Cfg_sUDE{
	class Visual {
		enabled = 1;
		class NVG {
			undergroundEfficiency = 0.01;
		};
		class Camera {
			peakMitigationEnabled = 1;
			class HeadBob {
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
		class PPEffects {
			class DefaultValues {
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