class PPEEyegearPreset : PPEMaterialPresetBase{
	override void init(){
		setOverlay(0.2, PPEManager.getPPEColor(0.1, 0.1, 0.3, 0));
		//setGodrays(...)
	}
}

class PPESpawnEffect : PPETimedParams{
	override void onInit(){
		setVignette(20, PPEManager.getPPEColor(0,0,0,0));
	}
}