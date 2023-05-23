class SGameConfigVisual : SGameConfigBase{
	
	override string getModuleName() {
		return "Visual";
	}
	
	array<ref SCameraOverlay> getCameraOverlays(typename type) {
		array<ref SCameraOverlay> overlays = new array<ref SCameraOverlay>();
		string path = "cfgVehicles " + type + " sUDE CameraOverlays";
		int lastOverlay = -1;
		for (int i=0; i<GetGame().ConfigGetChildrenCount(path); i++) {
			string className;
			GetGame().ConfigGetChildName(path, i, className);
			lastOverlay++;
			if (className == "overlay_"+lastOverlay) {
				overlays.Insert(getCameraOverlay(path + " overlay_"+lastOverlay));
			} else {
				lastOverlay--;
			}
		}
		return overlays;
	}
	
	SCameraOverlay getCameraOverlay(string path) {
		SCameraOverlay o = new SCameraOverlay();
		o.setImage(SGameConfig.getString(path + " image"));
		o.setAlpha(SGameConfig.getFloat(path + " alpha"));
		o.setMask(SGameConfig.getString(path + " mask"));
		o.setMaskProgress(SGameConfig.getFloat(path + " maskProgress"));
		o.setMaskTransitionWidth(SGameConfig.getFloat(path + " maskTransitionWidth"));
		o.setPosition(SGameConfig.getVector(path + " position"));
		o.setSize(SGameConfig.getVector(path + " size"));
		o.setRotation(SGameConfig.getVector(path + " rotation"));
		o.setPriority(SGameConfig.getInt(path + " priority"));
		o.setTargetCameras(SGameConfig.getTypenameArray(path + " targetCameras"));
		o.setHidesWithIngameHUD(SGameConfig.getBool(path + "hidesWithIngameHUD"));
		return o;
	}
	
}