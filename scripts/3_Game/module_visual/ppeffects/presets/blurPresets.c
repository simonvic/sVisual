class PPEDefaultBlurPreset : PPEBlurPreset{
	override void init(){
		initPreset(0.0);
	}
}

class PPEDebugBlurPreset : PPEBlurPreset{
	override void init(){
		initPreset(1.0);
	}
}