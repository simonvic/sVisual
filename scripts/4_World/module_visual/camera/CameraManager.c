class CameraManager {
	
	protected float m_time;	
	
	protected PlayerBase m_player;
	protected DayZPlayerCameraBase m_camera;
	
	void CameraManager(DayZPlayerCameraBase camera, PlayerBase player){
		m_camera = camera;
		m_player = player;
		onInit();
	}
	
	void ~CameraManager(){
		onDestroy();
	}
	
	void onInit(){
	}
	
	void onUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		m_time += pDt;
		
		vector rotation = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		if(m_camera.isHeadbobEnabled()){
			TFloatArray headbobParams = getHeadbobParameters(); //to-do use player speed modifier		
			float yawStrenght = headbobParams[0];
			float yawFrequency = headbobParams[1];
			float pitchStrenght = headbobParams[2];
			float pitchFrequency = headbobParams[3];
			
			yawStrenght *= HeadBobParams.multiplier;
			pitchStrenght *= HeadBobParams.multiplier;
						
			
			//to-do smooth the transition using movSpeed
			rotation[0] = rotation[0] + yawStrenght * Math.Sin(m_time * yawFrequency);
			rotation[1] = rotation[1] + pitchStrenght * Math.Sin(m_time * pitchFrequency); 
		}
		
		if(m_camera.isHeadLeanEnabled()){
			rotation[2] = rotation[2] + m_camera.getLeanRollAngle();
		}
		
		Math3D.YawPitchRollMatrix(rotation, pOutResult.m_CameraTM);
	}
	
	void onDestroy(){
	}
		
	/**
	@brief GOD PLEASE FORGIVE ME!!!
	*/
	TFloatArray getHeadbobParameters(){
		TFloatArray headbobParams = new TFloatArray;
		
		switch(m_player.m_MovementState.m_iMovement){ 
			case 0:	//idle
				headbobParams.Init(HeadBobParams.IDLE);
				break;
			case 1:	//walking
				if(m_player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
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
	
	protected void updateHeadLean(float pDt, out DayZPlayerCameraResult pOutResult){
		vector angles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		angles[2] = angles[2] + m_camera.getLeanRollAngle();
		Math3D.YawPitchRollMatrix(angles, pOutResult.m_CameraTM);		
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