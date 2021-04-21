class PPEDefaultVignettePreset : PPEVignettePreset{
	override void init(){
		initPreset(0, PPEManager.getPPEColor(0,0,0,0));
	}
}

class PPEEpinephrineVignettePreset : PPEVignettePreset{
	override void init(){
		initPreset(0.5, PPEManager.getPPEColor(0.1,0.1,0.1,0));
	}
}

class PPEFocusingVignettePreset : PPEVignettePreset{
	override void init(){
		initPreset(0, PPEManager.getPPEColor(0,0,0,0));
	}
}