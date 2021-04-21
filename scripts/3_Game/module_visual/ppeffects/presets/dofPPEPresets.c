class DDOFPreset : DoFPreset{
	override void init(){
		initPreset(20, 0, 150, 0.1, 1, 1, 150);
	}
}

class WeaponDOFPreset : DoFPreset{
	override void init(){
		initPreset(20, 60, 10, 20, 10, 0, 0);
	}
}