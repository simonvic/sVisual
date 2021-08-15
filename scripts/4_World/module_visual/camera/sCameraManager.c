modded class SCameraManager {
		
	protected SUserConfigVisual m_sUserConfigVisual;

	protected float m_yawVel[1];
	protected float m_pitchVel[1];
	
	override void onInit(){
		super.onInit();
		m_sUserConfigVisual = SUserConfig.visual();
	}
	
	override void onUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.onUpdate(pDt, pOutResult);
		//Convert camera transformation matrix to yaw pitch roll angles
		vector camAngles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		
		updateCamAngles(pDt, camAngles);
		
		//Apply the transformation to the camera
		Math3D.YawPitchRollMatrix(camAngles, pOutResult.m_CameraTM);
			
	}
	
	protected void updateCamAngles(float pDt, out vector camAngles){
		if(m_camera.isHeadbobEnabled()){
			applyHeadBob(pDt, camAngles);
		}
		
		if( canApplyHeadLean() ){
			applyHeadLean(pDt, camAngles);
		}
	}
	
	protected bool canApplyHeadLean(){
		return m_camera.isHeadLeanEnabled() && !m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE);
	}
	
	protected void applyHeadBob(float pDt, out vector angles){
		TFloatArray headbobParams = getHeadbobParameters(); //@todo use player speed modifier		
		float yawStrenght = headbobParams[0];
		float yawFrequency = headbobParams[1];
		float pitchStrenght = headbobParams[2];
		float pitchFrequency = headbobParams[3];
		
		yawStrenght *= getHeadbobIntensity();
		pitchStrenght *= getHeadbobIntensity();
		
		//@todo smooth the transition using movSpeed
		
		angles[0] = Math.SmoothCD(angles[0], angles[0] + yawStrenght * Math.Sin(m_time * yawFrequency), m_yawVel, 0.2, 1000, pDt);
		angles[1] = Math.SmoothCD(angles[1], angles[1] + pitchStrenght * Math.Sin(m_time * pitchFrequency), m_pitchVel, 0.2, 1000, pDt); 
	}
	
	protected void applyHeadLean(float pDt, out vector angles){
		angles[2] = angles[2] + m_camera.getLeanRollAngle();
	}
	
	override float getHeadLeanAngle(){
		return m_sUserConfigVisual.getHeadLeanAngle();
	}
	
	float getHeadbobIntensity(){
		return m_sUserConfigVisual.getHeadbobIntensity();
	}
	
	bool isHeadbobEnabledIn3pp(){
		return m_sUserConfigVisual.isHeadbobEnabledIn3pp();
	}
	
	bool isDDOFEnabledIn3pp(){
		return m_sUserConfigVisual.isDDOFEnabledIn3PP();
	}
	
	bool isDDOFEnabledInVehicle(){
		return m_sUserConfigVisual.isDDOFEnabledInVehicle();
	}
	
	/**
	* @brief GOD PLEASE FORGIVE ME!!!
	*/
	TFloatArray getHeadbobParameters(){
		TFloatArray headbobParams = new TFloatArray;
		
		switch(m_player.m_MovementState.m_iMovement){ 
			case 0:	//idle
			headbobParams.Init(HeadBobConstants.IDLE);
			break;

			case 1:	//walking
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)) {
				headbobParams.Init(HeadBobConstants.ERECT_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
				headbobParams.Init(HeadBobConstants.ERECT_RAISED_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
				headbobParams.Init(HeadBobConstants.CROUCH_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH)){
				headbobParams.Init(HeadBobConstants.CROUCH_RAISED_WALKING);
			} else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)){
				headbobParams.Init(HeadBobConstants.PRONE_WALKING);
			}
			break;

			case 2:	//jogging
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
				headbobParams.Init(HeadBobConstants.ERECT_JOGGING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
				headbobParams.Init(HeadBobConstants.ERECT_RAISED_JOGGING);
			}
			break;

			case 3: //running
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
				headbobParams.Init(HeadBobConstants.ERECT_RUNNING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
				headbobParams.Init(HeadBobConstants.CROUCH_RUNNING);
			}
			break;
			
			default: //flying? lol
			headbobParams.Init(HeadBobConstants.IDLE);
		}
		return headbobParams;
	}
	
}
