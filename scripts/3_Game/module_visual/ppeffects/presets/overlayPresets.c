class PPEDefaultOverlayPreset : PPEOverlayPreset{
	override void init(){
		initPreset(0.0, PPEManager.getPPEColor(0,0,0,0));
	}
}

class PPEDebugOverlayPreset : PPEOverlayPreset{
	override void init(){
		initPreset(0.5, PPEManager.getPPEColor(1,0,0,0));
	}
}