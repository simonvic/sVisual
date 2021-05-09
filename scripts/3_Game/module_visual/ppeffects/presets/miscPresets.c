class PPEEyegearPreset : PPEMaterialPresetBase{
	override void init(){
		setBloomSteepness(0);
		setOverlay(0.6, PPEManager.getPPEColor(0.01, 0.01, 0.015, 0));
		//setGodrays(...)
	}
}

class PPESpawnEffect : PPETimedParams{
	override void onInit(){
		setVignette(20, PPEManager.getPPEColor(0,0,0,0));
	}
}

class PPENightVision : PPEMaterialPresetBase{
	override void init(){
		setFilmGrain(5.0, 1.5);
		setColorization(PPEManager.getPPEColor( -0.5, 0.5, -0.5, 0.0));
		setVignette(1.2, PPEManager.getPPEColor(0, 0, 0, 0));
	}
}