class PPEDefaultChromAberPreset : PPEChromAberPreset{
	override void init(){
		initPreset(0.0, 0.0);
	}
}

class PPEDebugChromAberPreset : PPEChromAberPreset{
	override void init(){
		initPreset(0.5, 0.1);
	}
}