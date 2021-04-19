modded class MissionGameplay{
		
	void ~MissionGameplay(){
		PPEManager.deactivateAll();
	}
	
	override void OnInit(){
		super.OnInit();
		// @todo add ppeffects here?
	}
}