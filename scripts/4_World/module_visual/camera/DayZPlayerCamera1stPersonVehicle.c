modded class DayZPlayerCamera1stPersonVehicle{
	
	void DayZPlayerCamera1stPersonVehicle(DayZPlayer pPlayer, HumanInputController pInput){
		PPEManager.resetDOF();
	}
	
	override bool isDDOFEnabled(){
		return m_camManager.isDDOFEnabledInVehicle();
	}
}