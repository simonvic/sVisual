class PPEDefaultCameraEffectPreset : PPECameraEffectPreset{
	override void init(){
		initPreset(1, PPEManager.getPPEColor(1,1,1,0));
		
	}
}

class PPEDebugCameraEffectPreset : PPECameraEffectPreset{
	override void init(){
		initPreset(2, PPEManager.getPPEColor(10,1,1,0));
	}
}