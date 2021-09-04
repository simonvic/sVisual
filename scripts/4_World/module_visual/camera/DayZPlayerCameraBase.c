modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //@todo just a quick thing, change this absolutely	
	protected static ref PPENightVision m_nightVisionPPE = new PPENightVision(); // used with night vision optic/goggles
	protected static ref SCameraManager m_camManager;
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput){
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);

		if(isDDOFEnabled()) {
			SPPEManager.enableDDOF();
		}else{
			SPPEManager.disableDDOF();
			SPPEManager.resetDDOF(true);
		}
		
		SCameraOverlaysManager.getInstance().setActiveCameraType(this.Type());
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
	
	float getLeanRollAngle(){ //@todo report this. m_fLeaning doesn't reset when going prone while peeking (Q/E)
		return m_iPlayer.m_MovementState.m_fLeaning * m_camManager.getHeadLeanAngle();
	}
	
	override void SetNVPostprocess(int NVtype){
		//can't call super
		switch (NVtype){
			case NVTypes.NONE:
				PPEffects.SetEVValuePP(0);
				GetGame().NightVissionLightParams(1.0, 0.0);
				SPPEManager.deactivate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_OPTICS_ON:
				PPEffects.SetEVValuePP(6);
				GetGame().NightVissionLightParams(3.0, 2.0);
				SPPEManager.activate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_OPTICS_OFF:
				PPEffects.SetEVValuePP(-10);
				GetGame().NightVissionLightParams(1.0, 0.0);
				SPPEManager.deactivate(m_nightVisionPPE);
			break;
			
			case NVTypes.NV_GOGGLES:
				PPEffects.SetEVValuePP(6);
				GetGame().NightVissionLightParams(2.0, 1.0);
				SPPEManager.activate(m_nightVisionPPE);
			break;
		}
		
		if (PlayerBaseClient.Cast(m_pPlayer)){
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); 
		}

	}
	
}