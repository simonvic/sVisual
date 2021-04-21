modded class MissionGameplay{
		
	void ~MissionGameplay(){
		PPEManager.deactivateAll();
	}
	
	override void OnInit(){
		super.OnInit();
		// @todo add ppeffects here?
	}

	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);
		PPEManager.onUpdate(timeslice);
	}
}