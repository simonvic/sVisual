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

class CfgVehicles {

	class Clothing;
	class SCameraOverlay_Headgear;
	class SCameraOverlay_Eyewear;

	class BurlapSackCover : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/burlap.edds";
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
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
				};
			};
		};
	};

	class DarkMotoHelmet_ColorBase : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
					rotation[] = {0.0, 180.0, 0.0};
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
					rotation[] = {0.0, 180.0, 0.0};
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
					rotation[] = {0.0, 180.0, 0.0};
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
					rotation[] = {0.0, 180.0, 0.0};
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
					rotation[] = {0.0, 180.0, 0.0};
				};
			};
		};
	};

	class DarkMotoHelmet_YellowScarred : DarkMotoHelmet_ColorBase {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
					mask = "MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth = 0.3;
					maskProgress = 0.4;
				};
				class overlay_1 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/pristine.edds";
					mask = "MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth = 0.3;
					maskProgress = 0.4;
				};
				class overlay_2 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/worn.edds";
					mask = "MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth = 0.3;
					maskProgress = 0.4;
				};
				class overlay_3 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/damaged.edds";
					mask = "MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth = 0.3;
					maskProgress = 0.4;
				};
				class overlay_4 : SCameraOverlay_Headgear {
					image = "MyMODS/sVisual/GUI/textures/overlays/motohelmet/badlydamaged.edds";
					mask = "MyMODS/sVisual/GUI/textures/masks/yellowking_helmet.edds";
					maskTransitionWidth = 0.3;
					maskProgress = 0.4;
				};
			};
		};
	};

	/* TODO: https://feedback.bistudio.com/T177099
	class GasMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/ruined.edds";
				};
			};
		};
	};
	*/

	class GP5GasMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
					alpha = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
					alpha = 0.5;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
			};
		};
	};

	class AirborneMask : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
					alpha = 0.5;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/damaged.edds";
					alpha = 0.5;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/gasmask/badlydamaged.edds";
				};
			};
		};
	};

	class SportGlasses_ColorBase : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.25;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
			};
		};
	};

	class AviatorGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.25;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
			};
		};
	};

	class DesignerGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.25;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
			};
		};
	};

	class ThickFramesGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.25;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
			};
		};
	};

	class ThinFramesGlasses : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.25;
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.5;
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
				};
			};
		};
	};
	
	class TacticalGoggles : Clothing {
		class sUDE {
			class CameraOverlays {
				class overlay_0 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_1 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/pristine.edds";
					alpha = 0.5;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_2 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/worn.edds";
					alpha = 0.75;
					rotation[] = {180.0, 0.0, 0.0};
				};
				class overlay_3 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/damaged.edds";
					rotation[] = {180.0, 0.0, 0.0};
					alpha = 0.75;
				};
				class overlay_4 : SCameraOverlay_Eyewear {
					image = "MyMODS/sVisual/GUI/textures/overlays/glasses/badlydamaged.edds";
					rotation[] = {180.0, 0.0, 0.0};
					alpha = 0.75;
				};
			};
		};
	};

};

class Cfg_sUDE {
	class Visual {
		enabled = 1;
	};
};