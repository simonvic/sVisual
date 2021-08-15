modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //@todo just a quick thing, change this absolutely	
	protected ref PPENightVision m_nightVisionPPE = new PPENightVision(); // used with night vision optic/goggles
	
	
	//=========== Depth of Field ==============
	protected int m_ddofStartBoneIdx = -1;
	protected ref SRaycast m_sRaycast;
	
	
	//======================================
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput){
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);
		m_ddofStartBoneIdx = pPlayer.GetBoneIndexByName("Head");
		
		m_sRaycast = new SRaycast("0 0 0", "0 0 0", 0.05, ObjIntersectView, CollisionFlags.NEARESTCONTACT);

		if(isDDOFEnabled()) {
			PPEManager.enableDDOF();
		}else{
			PPEManager.disableDDOF();
			PPEManager.resetDDOF(true);
		}
		
		SCameraOverlaysManager.getInstance().setActiveCameraType(this.Type());
	}
	
	protected bool canRequestDDOF(){
		return isDDOFEnabled() && !m_iPlayer.IsCameraBlending())
	}
	
	protected void updateDDOF(float pDt){
		PPEManager.requestDDOF(getFocusDistance());
	}
	
	protected float getFocusDistance(){
		vector from = m_pPlayer.GetBonePositionWS(m_ddofStartBoneIdx);		
		m_sRaycast.init(
			from,
			from + (GetGame().GetCurrentCameraDirection() * PPEManager.getDDOFMaxDistance()));
		
		m_sRaycast.ignore(m_pPlayer, m_pPlayer.GetDrivingVehicle());
		
		return vector.Distance( from, m_sRaycast.launch().getContactPosition() ); // calculate distance between you and the point
	}
	
	protected void updateMotionBlur(float pDt){
		//@todo smooth motion blur value here
	}
	
	bool useSimonvicCam(){
		return false;
	}
	
	bool isHeadbobEnabled(){
		return false;
	}
	
	bool isHeadLeanEnabled(){
		return false;
	}
	
	bool isDDOFEnabled(){
		return false;
	}
	
	float getLeanRollAngle(){
		//@todo report this. m_fLeaning doesn't reset when going prone while peeking (Q/E)
		return m_iPlayer.m_MovementState.m_fLeaning * SCameraManager.getInstance().getHeadLeanAngle();
	}
	
	override void SetNVPostprocess(int NVtype){
		//can't call super
		switch (NVtype){
			case NVTypes.NONE:
				PPEffects.SetEVValuePP(0);
				GetGame().NightVissionLightParams(1.0, 0.0);
				PPEManager.deactivate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_OPTICS_ON:
				PPEffects.SetEVValuePP(6);
				GetGame().NightVissionLightParams(3.0, 2.0);
				PPEManager.activate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_OPTICS_OFF:
				PPEffects.SetEVValuePP(-10);
				GetGame().NightVissionLightParams(1.0, 0.0);
				PPEManager.deactivate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_GOGGLES:
				PPEffects.SetEVValuePP(6);
				GetGame().NightVissionLightParams(2.0, 1.0);
				PPEManager.activate(m_nightVisionPPE);
			break;
		}
		
		if (PlayerBaseClient.Cast(m_pPlayer)){
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); 
		}

	}
	
}