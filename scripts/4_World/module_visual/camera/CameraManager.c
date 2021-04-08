class CameraManager : PluginBase{
	
	
	void CameraManager(){
	}
	
	void ~CameraManager(){
	}
	
	override void OnInit(){
	}
	
	override void OnUpdate(float delta_time){

	}
	
	override void OnDestroy(){
	}
		
	/**
	@brief GOD PLEASE FORGIVE ME!!!
	*/
	static TFloatArray getHeadbobParameters(DayZPlayerImplement player ){
		TFloatArray headbobParams = new TFloatArray;
		
		switch(player.m_MovementState.m_iMovement){ 
			case 0:	//idle
				headbobParams.Init(HeadBobConstants.IDLE);
				break;
			case 1:	//walking
				if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
					headbobParams.Init(HeadBobConstants.ERECT_WALKING);
				}else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
					headbobParams.Init(HeadBobConstants.ERECT_RAISED_WALKING);
				}else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
					headbobParams.Init(HeadBobConstants.CROUCH_WALKING);
				}else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDCROUCH)){
					headbobParams.Init(HeadBobConstants.CROUCH_RAISED_WALKING);
				} else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)){
					headbobParams.Init(HeadBobConstants.PRONE_WALKING);
				}
				break;
			case 2:	//jogging
				if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
					headbobParams.Init(HeadBobConstants.ERECT_JOGGING);
				}else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)){
					headbobParams.Init(HeadBobConstants.ERECT_RAISED_JOGGING);
				}
				break;
			case 3: //running
				if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT)){
					headbobParams.Init(HeadBobConstants.ERECT_RUNNING);
				}else if(player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH)){
					headbobParams.Init(HeadBobConstants.CROUCH_RUNNING);
				}
				break;
			default: //flying? lol
				headbobParams.Init(HeadBobConstants.IDLE);
		}
		return headbobParams;
	}
	
}