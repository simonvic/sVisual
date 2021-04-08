modded class DayZPlayerImplement{
	
	override void SimulateDeath(bool state){
		
		//remove all ppeffects
		PPEManager.deactivateAll();
		
		super.SimulateDeath(state);
	}
}