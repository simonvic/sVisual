modded class MissionGameplay{
		
	void MissionGameplay(){
	}
	
	void ~MissionGameplay(){
		PPEManager.deactivateAll();
		PPEManager.applyDefault();
	}
	
	override void OnInit(){
		super.OnInit();
		PPEManager.onInit();
		// @todo add ppeffects here?
	}

	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);
		PPEManager.onUpdate(timeslice);
	}
}