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
		
		if( PPEManager.isPeakMitigationEnabled() ){
			updateDoF(pDt);
		}
	}
	
	override bool isHeadbobEnabled(){
		return false;
	}
	
	override bool isHeadLeanEnabled(){
		return false;
	}
	
}