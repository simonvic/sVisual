modded class DayZPlayerCamera3rdPerson {
	
	void DayZPlayerCamera3rdPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	void ~DayZPlayerCamera3rdPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		
		//need to also update here because vanilla doesn't call super
		m_camManager.onUpdate(pDt, pOutResult);
		
		if(canRequestDDOF()) {
			updateDDOF(pDt);
		}
		
	}
	
	override bool isHeadbobEnabled(){
		return m_camManager.isHeadbobEnabledIn3pp();
	}
	
	override bool isHeadLeanEnabled(){
		return false;
	}
	
	override bool isDDOFEnabled(){
		return m_camManager.isDDOFEnabledIn3pp();
	}
	
}