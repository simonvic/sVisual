modded class PPERequesterBase{
	protected ref SPPEffect m_sPPE;
	
	void PPERequesterBase(int requester_IDX){
		m_sPPE = new SPPEffect();
		initSPPE();
	}
	
	protected void initSPPE();
	
	override void OnStart(Param par = null){
		super.OnStart(par);
		SPPEManager.activate(m_sPPE);
	}
	
	override void OnStop(Param par = null){
		super.OnStop(par);
		SPPEManager.deactivate(m_sPPE);
	}
	
	SPPEffect getSPPE(){
		return m_sPPE;
	}
	
	
}






////////////////////////////////////////////////////////////////////////
// GLASSES

modded class PPERequester_GenericBlackGlassesBase {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBABABAff));
	}
}

modded class PPERequester_GlassesSportBlue {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBBBBEEff));
	}
}

modded class PPERequester_GlassesSportGreen {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBBEEBDff));
	}
}


modded class PPERequester_GlassesSportOrange {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xF2DAA9ff));
	}
}


modded class PPERequester_GlassesAviator {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xCDBFEEff));
	}
}


modded class PPERequester_TacticalGoggles {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
	}
}


modded class PPERequester_WeldingMask {
	override void initSPPE(){
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0x505050ff));
	}
}

////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// MISC

modded class PPERequester_FlashbangEffects {
	override void initSPPE(){
		getSPPE().setGausBlur(2.0);
		getSPPE().setOverlayFactor(1.5);
		getSPPE().setOverlayColor(SColor.rgba(0xFFFFFF00));
	}
}


modded class PPERequester_TunnelVisionEffects {
	override void initSPPE(){
		getSPPE().setVignetteColor(SPPEManager.getPPEColor(0, 0, 0, 0));
		getSPPE().setRadialBlurOffset(0.25);
	}
	
	override void OnStart(Param par = null){
		super.OnStart(par);
		getSPPE().setVignetteIntensity(m_Intensity);
		getSPPE().setRadialBlurPower(m_Intensity * 0.05);
	}
}

modded class PPERequester_DeathDarkening {

	override void OnStart(Param par = null){
		super.OnStart(par);
		getSPPE().setRadialBlurPower(-m_Value * 0.1);
		getSPPE().setChromAber(-m_Value * 0.075);
		GetDayZGame().SetEVValue(m_Value);
	}
	
	override void OnStop(Param par = null){
		super.OnStop(par);
		GetDayZGame().SetEVValue(m_Value);
	}
}

/*
modded class PPERequester_InventoryBlur {
	override void initSPPE(){
		getSPPE().setGausBlur(0.7);
	}
}
*/