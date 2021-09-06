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
		super.SetNVPostprocess(NVtype);
		switch (NVtype){
		case NVTypes.NONE:
			GetDayZGame().SetEVValue(0);
			GetDayZGame().NightVissionLightParams(1.0, 0.0);
			SPPEManager.deactivate(m_nightVisionPPE);
			break;
		
		case NVTypes.NV_OPTICS_ON:
			GetDayZGame().SetEVValue(6);
			GetDayZGame().NightVissionLightParams(3.0, 2.0);
			m_nightVisionPPE.setFilmGrain(5.0, 1.5);
			m_nightVisionPPE.setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));
			SPPEManager.activate(m_nightVisionPPE);
			break;
		
		case NVTypes.NV_OPTICS_OFF:
			GetDayZGame().SetEVValue(-10);
			GetDayZGame().NightVissionLightParams(1.0, 0.0);
			SPPEManager.deactivate(m_nightVisionPPE);
			break;
		
		case NVTypes.NV_GOGGLES:
			GetDayZGame().SetEVValue(6);
			GetDayZGame().NightVissionLightParams(2.0, 1.0);
			m_nightVisionPPE.setFilmGrain(5.0, 1.5);
			m_nightVisionPPE.setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));
			SPPEManager.activate(m_nightVisionPPE);
			break;

//dummy ifdef so workbench won't complain
#ifdef S_FRAMEWORK
		case NVTypes.NV_PUMPKIN:
			GetDayZGame().SetEVValue(5);
			GetDayZGame().NightVissionLightParams(1.0, 0.5);
			m_nightVisionPPE.setFilmGrain(1, 10);
			m_nightVisionPPE.setColorization(SColor.rgb(RGBColors.ORANGE_RED));
			SPPEManager.activate(m_nightVisionPPE);
			break;
#endif
		}
		
	}
	
}