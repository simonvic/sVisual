/////////////////////////////////////////////
// Visual Module
/////////////////////////////////////////////
class SGameConfigVisual : SGameConfigBase{
	
	override string getModuleName(){
		return "Visual";
	}
	
	float getDefaultPPEFloat(string ppeName){
		return SGameConfig.getFloat(getModulePath() + " PPEffects DefaultValues " + ppeName);
	}
	
	TPPEColor getDefaultPPEColor(string ppeName){
		TFloatArray c = SGameConfig.getfloatArray(getModulePath() + " PPEffects DefaultValues " + ppeName);
		return PPEManager.getPPEColor(c[0], c[1], c[2], c[3]);
	}
	
	TSCameraOverlaySet getCameraOverlays(typename type){
		TSCameraOverlaySet overlays = new TSCameraOverlaySet();
		string path = "cfgVehicles " + type + " sUDE CameraOverlays";
		SLog.d("Getting overlays of " + path);
		int lastOverlay = -1;
		for(int i=0; i<GetGame().ConfigGetChildrenCount(path); i++){
			string className;
			GetGame().ConfigGetChildName(path, i, className);
			lastOverlay++;
			if(className == "overlay_"+lastOverlay){
				SLog.d("Found " + className,"",1);
				overlays.Insert(getCameraOverlay(path + " overlay_"+lastOverlay));
				getCameraOverlay(path + " overlay_"+lastOverlay).debugPrint(2);
			}else{
				SLog.d("Ignoring: " + className,"",1);
				lastOverlay--;
			}
		}
		return overlays;
	}
	
	SCameraOverlay getCameraOverlay(string path){
		return new SCameraOverlay(
			SGameConfig.getString(path + " image"),
			SGameConfig.getFloat(path + " alpha"),
			SGameConfig.getString(path + " mask"),
			SGameConfig.getFloat(path + " maskProgress"),
			SGameConfig.getFloat(path + " maskTransitionWidth"));
	}
	
}