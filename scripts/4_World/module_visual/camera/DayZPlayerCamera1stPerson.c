modded class DayZPlayerCamera1stPerson{
	
	protected float m_time;	
	
	
	void DayZPlayerCamera1stPerson(DayZPlayer pPlayer, HumanInputController pInput){
		
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		
		if( PPEManager.isDDOFEnabled() && !isADS() ){
			updateDoF(pDt);
		}
		
		if( PPEManager.isMotionBlurEnabled() && !isInventoryOpen() ){
			updateMotionBlur(pDt);	
		}
		
		if( HeadBobParams.enabled ){
			updateHeadBob(pDt, pOutResult);
		}

		if( HeadLeanParams.leanAngle > 0 ){
			updateHeadLean(pDt, pOutResult);
		}
		
	}
		
	
	
	protected void updateHeadBob(float pDt, out DayZPlayerCameraResult pOutResult){
		m_time += pDt;
		vector rotation = "0 0 0";

		if ( HeadBobParams.enabled ) {
			
			TFloatArray headbobParams = CameraManager.getHeadbobParameters(m_iPlayer); //to-do use player speed modifier
			
			float yawStrenght = headbobParams[0];
			float yawFrequency = headbobParams[1];
			float pitchStrenght = headbobParams[2];
			float pitchFrequency = headbobParams[3];
			
			yawStrenght *= HeadBobParams.multiplier;
			pitchStrenght *= HeadBobParams.multiplier;
						
			
			//to-do smooth the transition using movSpeed
			rotation[0] = m_fLeftRightAngle + yawStrenght * Math.Sin(m_time * yawFrequency);
			rotation[1] = m_CurrentCameraPitch + pitchStrenght * Math.Sin(m_time * pitchFrequency); 
		}else{
			rotation[0] = m_fLeftRightAngle;
			rotation[1] = m_CurrentCameraPitch;
		}
		rotation[2] = 0; //to-do merge head lean here for performance
		
		Math3D.YawPitchRollMatrix(rotation, pOutResult.m_CameraTM);
	}
	
	override float getLeanRollAngle(){
		//this is needed to change the roll angle based on freelook
		return m_iPlayer.m_MovementState.m_fLeaning * Math.Lerp(HeadLeanParams.leanAngle,- HeadLeanParams.leanAngle, Math.AbsFloat(m_fLeftRightAngle) / ( CONST_LR_MAX / 2) );
	}	
	
	
	protected bool isADS(){
		return m_iPlayer.IsInOptics() || m_iPlayer.IsInIronsights();
		//return m_iPlayer.GetInputController().WeaponADS(); // is this broken? (doesn't set m_bAds to false when releasing mouse button)
	}
	
	protected bool isInventoryOpen(){ //to-do definitely find a better way of doing this
		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		return menu && ( menu.GetID() == MENU_INVENTORY || menu.GetID() == MENU_INSPECT );
	}
	
}

