class VanillaWrappedSPPE : SPPEffect {}

modded class PPERequesterBase{
	protected ref VanillaWrappedSPPE m_sPPE;
	
	void PPERequesterBase(int requester_IDX) {
		m_sPPE = new VanillaWrappedSPPE();
		initSPPE();
	}
	
	
	protected void initSPPE();
	
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SPPEManager.activate(m_sPPE);
	}
	
	override void OnStop(Param par = null) {
		super.OnStop(par);
		//SLog.d(m_sPPE, ""+this+"::OnStop");
		SPPEManager.deactivate(m_sPPE);
	}
	
	VanillaWrappedSPPE getSPPE() {
		return m_sPPE;
	}
	
	
}






////////////////////////////////////////////////////////////////////////
// GLASSES

modded class PPERequester_GenericBlackGlassesBase {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBABABAff));
	}
}

modded class PPERequester_GlassesSportBlue {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBBBBEEff));
	}
}

modded class PPERequester_GlassesSportGreen {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xBBEEBDff));
	}
}


modded class PPERequester_GlassesSportOrange {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xF2DAA9ff));
	}
}


modded class PPERequester_GlassesAviator {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0xCDBFEEff));
	}
}


modded class PPERequester_TacticalGoggles {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
	}
}


modded class PPERequester_WeldingMask {
	override void initSPPE() {
		getSPPE().init(new PPEEyegearPreset());
		getSPPE().setColorization(SColor.rgba(0x505050ff));
	}
}

////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// MISC

modded class PPERequester_FlashbangEffects {
	override void initSPPE() {
		getSPPE().setGausBlur(2.0);
		getSPPE().setOverlayFactor(1.5);
		getSPPE().setOverlayColor(SColor.rgba(0xFFFFFF00));
	}
}


modded class PPERequester_TunnelVisionEffects {
	override void initSPPE() {
		getSPPE().setVignetteColor(SPPEManager.getPPEColor(0, 0, 0, 0));
		getSPPE().setRadialBlurOffset(0.25);
	}
	
	override void OnStart(Param par = null) {
		super.OnStart(par);
		getSPPE().setVignetteIntensity(m_Intensity);
		getSPPE().setRadialBlurPower(Math.Clamp(m_Intensity * 0.05, 0, 1));
	}
}

modded class PPERequester_DeathDarkening {

	override void OnStart(Param par = null) {
		super.OnStart(par);
		getSPPE().setRadialBlurPower(Math.Clamp(-m_Value * 0.1, 0, 1));
		getSPPE().setChromAber(Math.Clamp(-m_Value * 0.075, 0, 1));
		GetDayZGame().SetEVValue(m_Value);
	}
	
	override void OnStop(Param par = null) {
		super.OnStop(par);
		// 0 is default registered value. I can't get the actual registered value, hopefully no one change it :sweat:
		GetDayZGame().SetEVValue(0);
	}
}

/*
modded class PPERequester_InventoryBlur {
	override void initSPPE() {
		getSPPE().setGausBlur(0.7);
	}
}
*/

modded class PPERUndergroundAcco {
	override void SetEyeAccommodation(float value) {
		super.SetEyeAccommodation(value);
		GetGame().GetWorld().SetEyeAccom(value);
		
	}

	override void OnStop(Param par = null) {
		super.OnStop(par);
		GetGame().GetWorld().SetEyeAccom(1.0);
	}
}

modded class PPERequester_CameraNV {
	
	protected float m_ugAccomCoeff = 1;
		
	override void OnStart(Param par = null) {
		super.OnStart(par);
	}
	
	override void OnStop(Param par = null) {
		super.OnStop(par);
		GetDayZGame().SetEVValue(0);
		GetDayZGame().NightVissionLightParams(1.0, 0.0);
	}
	
	void setUndergroundAccomCoeff(float coeff) {
		m_ugAccomCoeff = coeff;
	}
	
	override void SetNVMode(int mode) {
		super.SetNVMode(mode);
		
		GetGame().GetWorld().SetEyeAccom(m_ugAccomCoeff);
		
		getSPPE().clear();
		
		switch (mode) {
			case NV_NO_BATTERY: //battery off
			getSPPE().setColorization(SPPEManager.getPPEColor(0.0, 0.0, 0.0, 1.0));
			GetDayZGame().SetEVValue(-10);
			GetDayZGame().NightVissionLightParams(1.0, 0.0);
			break;
						
			case NV_DEFAULT_OPTICS: //optic on
			GetDayZGame().SetEVValue(7);
			GetDayZGame().NightVissionLightParams(3.0, 2.0);
			getSPPE().setFilmGrainSharpness(5.0);
			getSPPE().setFilmGrainSize(2.5);
			getSPPE().setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));
			break;
			
			case NV_DAYTIME_OPTICS: //NV optic in daytime mode
			GetDayZGame().SetEVValue(2);
			GetDayZGame().NightVissionLightParams(3.0, 1.0);
			getSPPE().setFilmGrainSharpness(5.0);
			getSPPE().setFilmGrainSize(2.5);
			getSPPE().setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));
			break;
			
			case NV_DEFAULT_GLASSES: //goggles on
			GetDayZGame().SetEVValue(7);
			GetDayZGame().NightVissionLightParams(2.0, 1.0);
			getSPPE().setFilmGrainSharpness(5.0);
			getSPPE().setFilmGrainSize(2.5);
			getSPPE().setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));
			break;
			
			case NV_PUMPKIN: //pumpkin-o-vision
			GetDayZGame().SetEVValue(5);
			GetDayZGame().NightVissionLightParams(1.0, 0.5);
			getSPPE().setFilmGrainSharpness(1.0);
			getSPPE().setFilmGrainSize(6.9);
			getSPPE().setColorization(SColor.rgb(RGBColors.ORANGE_RED));
			break;
			
			case NV_TRANSITIVE: //camera transition
			GetDayZGame().SetEVValue(0);
			break;
		}
	}
}