class CameraManager {
	
	protected float m_time;	
	
	protected float m_yawVel[1];
	protected float m_pitchVel[1];
	
	protected PlayerBase m_player;
	protected DayZPlayerCameraBase m_camera;
	
	protected SUserConfigVisual m_sUserConfigVisual;
	
	void CameraManager(DayZPlayerCameraBase camera, PlayerBase player){
		m_camera = camera;
		m_player = player;
		m_sUserConfigVisual = SUserConfig.getInstance().visual();
		onInit();
	}
	
	void ~CameraManager(){
		onDestroy();
	}
	
	void onInit(){
	}

	void onDestroy(){
	}
	
	void onUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		m_time += pDt;
		
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
		
		if(m_camera.isHeadLeanEnabled()){
			applyHeadLean(pDt, camAngles);
		}
	}
	
	protected void applyHeadBob(float pDt, out vector angles){
		TFloatArray headbobParams = getHeadbobParameters(); //@todo use player speed modifier		
		float yawStrenght = headbobParams[0];
		float yawFrequency = headbobParams[1];
		float pitchStrenght = headbobParams[2];
		float pitchFrequency = headbobParams[3];
		
		yawStrenght *= HeadBobParams.multiplier;
		pitchStrenght *= HeadBobParams.multiplier;
		
		//@todo smooth the transition using movSpeed
		
		angles[0] = Math.SmoothCD(angles[0], angles[0] + yawStrenght * Math.Sin(m_time * yawFrequency), m_yawVel, 0.2, 1000, pDt);
		angles[1] = Math.SmoothCD(angles[1], angles[1] + pitchStrenght * Math.Sin(m_time * pitchFrequency), m_pitchVel, 0.2, 1000, pDt); 
	}
	
	protected void applyHeadLean(float pDt, out vector angles){
		angles[2] = angles[2] + m_camera.getLeanRollAngle();
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
			headbobParams.Init(HeadBobParams.IDLE);
			break;

			case 1:	//walking
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)) {
				headbobParams.Init(HeadBobParams.ERECT_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
				headbobParams.Init(HeadBobParams.ERECT_RAISED_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
				headbobParams.Init(HeadBobParams.CROUCH_WALKING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH)){
				headbobParams.Init(HeadBobParams.CROUCH_RAISED_WALKING);
			} else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)){
				headbobParams.Init(HeadBobParams.PRONE_WALKING);
			}
			break;

			case 2:	//jogging
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
				headbobParams.Init(HeadBobParams.ERECT_JOGGING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
				headbobParams.Init(HeadBobParams.ERECT_RAISED_JOGGING);
			}
			break;

			case 3: //running
			if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
				headbobParams.Init(HeadBobParams.ERECT_RUNNING);
			}else if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
				headbobParams.Init(HeadBobParams.CROUCH_RUNNING);
			}
			break;
			
			default: //flying? lol
			headbobParams.Init(HeadBobParams.IDLE);
		}
		return headbobParams;
	}
	
}


class HeadLeanParams {
	static float leanAngle = 15;
}

class HeadBobParams {
	static bool enabled = true;
	static float multiplier = 0.5;	
	
	//                                            yawStrenght, yawFrequency, pitchStrenght, pitchFrequency
	static const float IDLE[4] =                     { 0.0,        0.0,         1.1,             0.5   };
	
	static const float ERECT_WALKING[4] =            { 0.5,        5.75,        0.5,             11.5  };
	static const float ERECT_JOGGING[4] =            { 1.0,        9.0,         0.5,             18.0  };
	static const float ERECT_RUNNING[4] =            { 2.4,        11.5,        0.5,             23.0  };
	static const float ERECT_RAISED_WALKING[4] =     { 0.5,        1.75,        0.5,             6.5   };
	static const float ERECT_RAISED_JOGGING[4] =     { 1.0,        8.75,        0.5,             17.5  };
	
	static const float CROUCH_WALKING[4] =           { 0.5,        5.75,        0.5,             11.5  };
	static const float CROUCH_RUNNING[4] =           { 1.0,        9.0,         0.5,             18.0  };
	static const float CROUCH_RAISED_WALKING[4] =    { 0.5,        5.75,        0.5,             11.5  };
	
	static const float PRONE_WALKING[4] =            { 0.5,        5.75,        0.5,             11.5  };
	
}