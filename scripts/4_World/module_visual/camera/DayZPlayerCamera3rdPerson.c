modded class DayZPlayerCamera3rdPerson {
	
	void DayZPlayerCamera3rdPerson(DayZPlayer pPlayer, HumanInputController pInput){
		if(PPEManager.isPeakMitigationEnabled()){
			PPEManager.enableDDOF();
		}else{
			PPEManager.disableDDOF();	
		}
	}
	
	void ~DayZPlayerCamera3rdPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		m_camManager.onUpdate(pDt, pOutResult);
		
		if( PPEManager.isPeakMitigationEnabled() || isDDOFEnabled()){
			updateDoF(pDt);
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