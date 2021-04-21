class PPEDefaultFilmGrainPreset : PPEFilmGrainPreset{
	override void init(){
		initPreset(0.0, 0.0);
	}
}

class PPEDebugFilmGrainPreset : PPEFilmGrainPreset{
	override void init(){
		initPreset(1.0, 1.0);
	}
}