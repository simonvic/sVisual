modded class DayZPlayerCamera1stPerson{	
	
	void DayZPlayerCamera1stPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	void ~DayZPlayerCamera1stPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		
		if( PPEManager.isMotionBlurEnabled() ){
			updateMotionBlur(pDt);	
		}
		
		if(canRequestDDOF()) {
			updateDDOF(pDt);
		}
		
	}
	
	override bool isHeadbobEnabled(){
		return true;
	}
	
	override bool isHeadLeanEnabled(){
		return true;
	}
	
	override bool isDDOFEnabled(){
		return true;
	}
	
	
	override float getLeanRollAngle(){
		//this is needed to change the roll angle based on freelook
		return m_iPlayer.m_MovementState.m_fLeaning * Math.Lerp(HeadLeanParams.leanAngle,- HeadLeanParams.leanAngle, Math.AbsFloat(m_fLeftRightAngle) / ( CONST_LR_MAX / 2) );
	}	
	
	
}

