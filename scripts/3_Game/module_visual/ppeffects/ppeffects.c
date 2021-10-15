////////////////////////////////////////////////////////////////////////
// NON-ANIMATED

/**
*	@brief Played when player goes unconscious. Obstruct the vision
*/
class PPEUnconscious : SPPEffect {
	override void onInit(){
		setRadialBlur(0.5, 0.5);
	}
}


/**
*	@brief Used to emulate sun glasses.
*	       Lower bloom and godrays intensity
*/
class PPEEyegearPreset : SPPEffect{
	override void onInit(){
		setBloomSteepness(0);
		setGodraysIntensity(0.0);
	}
}


/**
*	@brief Night vision base effect
*/
class PPENightVision : SPPEffect{
	override void onInit(){
		setFilmGrain(5.0, 1.5);
		setColorization(SPPEManager.getPPEColor( -0.5, 0.5, -0.5, 1.0));		
	}
}

////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// ANIMATED

/**
*	@brief Effect to emulate adrenaline increase
*	       (unused)
*/
class PPEEpinephrineAnimation : SPPEffectAnimated {
	override void onInit(){
		setVignetteColor(SPPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){	
		float power = Math.AbsFloat(Math.Sin(getTime() * 10)) * 0.05;
		setRadialBlur(power, power);
		setVignetteIntensity(power * 5);
	}
}


/**
*	@brief Effect to alert the player that he has reached the
*	       exhaustion state (when stamina bar becomes gray), 
*	       hence he has to wait for the stamina to refill
*/
class PPEExhaustedAnimation : SPPEffectAnimated {	
	protected float stamina = 100;
	
	override void onInit(){
		setVignetteColor(SPPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * 2.5) / Math.Clamp(stamina, 60, 100));
		setRadialBlur(power, power);
		setVignetteIntensity(power * 20);
	}
	
	void setStamina(float stamina){
		this.stamina = stamina;
	}
}


/**
*	@brief Effect to alert player he has been hit and that he
*	       has to get in a safe position.
*	       Being hit multiple time consecutively in a short amount of time
*	       will increase the cooldown timer, making the effect last longer
*/
class PPEHitReceivedAnimation : SPPEffectTimed {		
	protected float hitStrength = SPPEConstants.HIT_RECEIVED_MIN_STRENGTH;
	
	override void onInit(){
		setOverlayColor(SPPEManager.getPPEColor(0.1, 0.0, 0.0, 0.0));
	}
	
	override void onAnimate(float deltaTime){
		setChromAber(Math.Clamp(
			0.0005 * (Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * hitStrength * Math.AbsFloat(SMath.mapTo(getRemaining(), 0.01, SPPEConstants.HIT_RECEIVED_MAX_DURATION))),
			0,
			SPPEConstants.HIT_RECEIVED_MAX_CHROM_ABER));
		
		setOverlayFactor(Math.Max(1 - getTime() * SPPEConstants.HIT_RECEIVED_RED_SPEED, 0));
	}
	
	override void setDuration(float duration){
		m_time = 0;
		m_duration = Math.Clamp(duration, 0.1, SPPEConstants.HIT_RECEIVED_MAX_DURATION);
	}
	
	float getHitStrength(){
		return hitStrength;
	}
	
	void setHitStrength(float strength){
		hitStrength = Math.Clamp(strength, 0, SPPEConstants.HIT_RECEIVED_MAX_STRENGTH);
	}
}


/**
*	@brief Effect to emulate pain, applied when the player is bleeding.
*	       The effect will pulse faster as the bleeding cuts count increase
*	       
*	       NOTE: can be disabled by setting `PostProcessing Effect` quality to `Low`
*/
class PPEBleedingAnimation : SPPEffectAnimated {
	private int bleedingBits = 0;
	
	override void onAnimate(float deltaTime){
		setChromAber(0.005 * (Math.AbsFloat(Math.Sin(getTime() * bleedingBits * 0.5)) + bleedingBits * 0.1));
	}
		
	void setBleedingBits(int cuts){
		this.bleedingBits = cuts;
	}
}



////////////////////////////////////////////////////////////////////////


/**
*	@brief Contains all default values
*/
modded class PPEDefaultPreset {
	override void onInit(){
		
		SGameConfigVisual cfg = SGameConfig.visual();
		
		//////////////////////////////////////////
		// Float params
		setSaturation(cfg.getDefaultPPEFloat("saturation"));
		setVignetteIntensity(cfg.getDefaultPPEFloat("vignette_strength"));
		setOverlayFactor(cfg.getDefaultPPEFloat("overlay_factor"));
		
		setBloomTreshold(cfg.getDefaultPPEFloat("bloom_threshold"));
		setBloomSteepness(cfg.getDefaultPPEFloat("bloom_steepness"));
		setBloomIntensity(cfg.getDefaultPPEFloat("bloom_intensity"));
		
		setMotionBlurPower(cfg.getDefaultPPEFloat("motion_blur_power"));
		setMotionBlurMinDepth(cfg.getDefaultPPEFloat("motion_blur_mindepth"));
		setMotionBlurMaxDepth(cfg.getDefaultPPEFloat("motion_blur_maxdepth"));
		setMotionBlurMinAnglePerSec(cfg.getDefaultPPEFloat("motion_blur_min_angle_per_sec"));
		setMotionBlurMaxAnglePerSec(cfg.getDefaultPPEFloat("motion_blur_max_angle_per_sec"));
		
		setGausBlur(cfg.getDefaultPPEFloat("gauss_blur_intensity"));
																						       
		setRadialBlurPowerX(cfg.getDefaultPPEFloat("radial_blur_power_x"));
		setRadialBlurPowerY(cfg.getDefaultPPEFloat("radial_blur_power_y"));
		setRadialBlurOffsetX(cfg.getDefaultPPEFloat("radial_blur_offset_x"));
		setRadialBlurOffsetY(cfg.getDefaultPPEFloat("radial_blur_offset_y"));
		
		setChromAberPowerX(cfg.getDefaultPPEFloat("chrom_aber_power_x"));
		setChromAberPowerY(cfg.getDefaultPPEFloat("chrom_aber_power_y"));
		
		setFilmGrainSharpness(cfg.getDefaultPPEFloat("film_grain_sharpness"));
		setFilmGrainSize(cfg.getDefaultPPEFloat("film_grain_grain_size"));
		
		
		setGodraysIntensity(cfg.getDefaultPPEFloat("godrays_sun_intensity"));
		setGodraysOverburn(cfg.getDefaultPPEFloat("godrays_sun_overburn_intensity"));
		setGodraysOverburnStart(cfg.getDefaultPPEFloat("godrays_sun_overburn_start"));
		setGodraysOverburnEnd(cfg.getDefaultPPEFloat("godrays_sun_overburn_end"));
		
		/* Updating this causes the flickering of the sun
		setGodraysMask(cfg.getDefaultPPEFloat("godrays_sun_mask"));
		setGodraysSize(cfg.getDefaultPPEFloat("godrays_sun_size"));
		setGodraysVerticalIntensity(cfg.getDefaultPPEFloat("godrays_sun_v_intensity"));
		setGodraysDiagonalIntensity(cfg.getDefaultPPEFloat("godrays_sun_d_intensity"));
		*/
		
		//////////////////////////////////////////
		// Color params
		setVignetteColor(cfg.getDefaultPPEColor("vignette_color"));
		setOverlayColor(cfg.getDefaultPPEColor("overlay_color"));
		setColorization(cfg.getDefaultPPEColor("colorization"));		
	}
}
