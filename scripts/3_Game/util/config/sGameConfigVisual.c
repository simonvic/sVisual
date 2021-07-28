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
	
	TSCameraOverlaysList getCameraOverlays(typename type){
		TSCameraOverlaysList overlays = new TSCameraOverlaysList();
		string path = "cfgVehicles " + type + " sUDE CameraOverlays";
		int lastOverlay = -1;
		for(int i=0; i<GetGame().ConfigGetChildrenCount(path); i++){
			string className;
			GetGame().ConfigGetChildName(path, i, className);
			lastOverlay++;
			if(className == "overlay_"+lastOverlay){
				overlays.Insert(getCameraOverlay(path + " overlay_"+lastOverlay));
			}else{
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
			SGameConfig.getFloat(path + " maskTransitionWidth"),
			SGameConfig.getVector(path + " position"),
			SGameConfig.getVector(path + " size"),
			SGameConfig.getVector(path + " rotation"),
			SGameConfig.getInt(path + " priority"));
	}
	
}