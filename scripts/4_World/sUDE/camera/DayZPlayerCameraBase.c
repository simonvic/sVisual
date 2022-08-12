modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //@todo just a quick thing, change this absolutely	
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
	
}