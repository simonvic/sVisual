modded class DayZPlayerCamera1stPerson{	
	
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
		return m_iPlayer.m_MovementState.m_fLeaning * Math.Lerp(m_camManager.getHeadLeanAngle(),- m_camManager.getHeadLeanAngle(), Math.AbsFloat(m_fLeftRightAngle) / ( CONST_LR_MAX / 2) );
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		super.OnUpdate(pDt, pOutResult);
		if (m_camManager.canUpdateFrom(this)) {
			m_camManager.onUpdate(pDt, pOutResult);
		}
	}
	
	
}

