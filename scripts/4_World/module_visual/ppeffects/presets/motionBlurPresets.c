class PPEDefaultMotionBlurPreset : PPEMotionBlurPreset {
	override void init(){		
		initPreset(0.01, 0.1, 0.8, 0.9);
	}
}

class PPEDebugMotionBlurPreset : PPEMotionBlurPreset {
	override void init(){
		initPreset(0.01, 0.1, 0.8, 0.9);
	}
}