modded class SPPEffect {
	float getEffectsIntensity() {
		return SUserConfig.visual().getEffectsIntensity();
	}
}

/**
*	@brief Register custom ppeffects
*/
modded class PPERequesterRegistrations {
	void PPERequesterRegistrations() {
		PPERequesterBank.RegisterRequester(SPPERequester_MotionBlur);
		PPERequesterBank.RegisterRequester(SPPERequester_Bloom);
		PPERequesterBank.RegisterRequester(SPPERequester_DDOF);
		PPERequesterBank.RegisterRequester(SPPERequester_ExhaustedAnimation);
		PPERequesterBank.RegisterRequester(SPPERequester_HitReceivedAnimation);
		PPERequesterBank.RegisterRequester(SPPERequester_BloodLoss);
	}
}

class SPPERequester_MotionBlur : SPPEffect {
	
	override void onInit() {
		normalized(true);
		op(PPOperators.HIGHEST);
	}
	
	override void onActivate() {
		setIntensity(SUserConfig.visual().getMotionBlurIntensity());
	}
	
	void setIntensity(float intensity) {
		setMotionBlurPower(intensity);
		if (intensity == 0) {
			deactivate();
		} else if (!isActive()) {
			activate();
		}
	}
}

class SPPERequester_Bloom : SPPEffect {
	
	override void onActivate() {
		normalized(true);
		op(PPOperators.SUBSTRACT);
		setBloomTreshold(0.9);
		
		op(PPOperators.ADD);
		setBloomIntensity(1);
		setIntensity(SUserConfig.visual().getBloomIntensity());
	}
	
	void setIntensity(float intensity) {
		priority(PPEGlow.L_23_GLASSES - 1);
		op(PPOperators.ADD);
		setBloomSteepness(intensity);
	}
}

class SPPERequester_DDOF : SPPEffectAnimated {
	
	protected float m_distance;
	protected float m_distanceTarget;
	protected float m_focusVel[1];
	protected float m_intensity;
	
	override void onInit() {
		priority(PPEDOF.L_0_ADS - 1); // PPERequester_CameraADS DoF takes priority
		op(PPOperators.SET);
		setIntensity(SUserConfig.visual().getDDOFIntensity());
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_ENABLE, true);
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_FOCUS_LEN, 150.0);
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_FOCUS_LEN_NEAR, 10.0);
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_FOCUS_DEPTH_OFFSET, 10.0);
	}
	
	override void onActivate() {
	}
	
	override void onAnimate(float deltaTime) {
		m_distance = Math.SmoothCD(m_distance, m_distanceTarget, m_focusVel, 0.15, 1000, deltaTime);
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_FOCUS_DIST, m_distance);
		setParam(PPEExceptions.DOF, PPEDOF.PARAM_BLUR, m_intensity * 30);
	}
	
	void setIntensity(float intensity) {
		m_intensity = intensity;
	}
	
	void focusAt(float distance) {
		m_distanceTarget = distance;
	}
}


/**
*	@brief Effect to alert the player that he has reached the
*	       exhaustion state (when stamina bar becomes gray), 
*	       hence he has to wait for the stamina to refill
*/
class SPPERequester_ExhaustedAnimation : SPPEffectTimed {	
	
	static const float DEACTIVATION_TRESHOLD = 25; //[0% - 100%] treshold for Exhausted PPEffect. Percentage of stamina available [0 - m_StaminaCap]
	
	protected float m_stamina = 100;
	
	override void onInit() {
		priority(eSPPEPriority.STAMINA);
		setDuration(Math.PI2);
		op(PPOperators.LOWEST);
		setVignetteColor(SColor.rgb(0x000000));
	}
	
	override void onAnimate(float deltaTime) {
		float power = getEffectsIntensity() * SMath.map(getRemaining(), 0, getDuration(), 0, 0.05) * Math.AbsFloat(Math.Sin(getTime() * Math.PI));
		op(PPOperators.ADD);
		setRadialBlurPower(power);
		setVignetteIntensity(power * 10);
	}
	
	void setStamina(float stamina) {
		m_stamina = stamina;
	}
}


/**
*	@brief Effect to alert player he has been hit and that he
*	       has to get in a safe position.
*	       Being hit multiple time consecutively in a short amount of time
*	       will increase the cooldown timer, making the effect last longer
*/
class SPPERequester_HitReceivedAnimation : SPPEffectTimed {	
	static const float MIN_DURATION = 4.5;        //How long (seconds) the animation will last at least
	static const float MAX_DURATION = 15.0;       //Maximum duration (seconds) of the animation
	static const float DURATION_MULTIPLIER = 2;   //How much the duration will increment when being hit multiple time
	static const float INTENSITY_MULTIPLIER = 1.5; //How much the effect strength will increment when being hit multiple time
	static const float RED_SPEED = 5.0;           //How fast the red overlay will dissipate
	static const float MIN_INTENSITY = 1;          //Minimum strength of the effects
	static const float MAX_INTENSITY = 5.0;      //Maximum value of hit strength
	
	protected float hitIntensity = MIN_INTENSITY;
	
	override void onInit() {
		priority(eSPPEPriority.PAIN);
		setDuration(MIN_DURATION);
		setOverlayColor(SColor.rgb(0x250000));
	}
	
	override void onAnimate(float deltaTime) {
		op(PPOperators.ADD);
		setChromAber(getEffectsIntensity() * 0.00314 * (Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * hitIntensity * Math.AbsFloat(SMath.mapTo(getRemaining(), 0.01, MAX_DURATION))));
		
		op(PPOperators.SET);		
		setOverlayFactor(Math.Max(1 - getTime() * RED_SPEED, 0));
	}
	
	void onHit() {
		m_time = 0;
		setDuration(Math.Clamp(getDuration() * DURATION_MULTIPLIER, MIN_DURATION, MAX_DURATION));
		hitIntensity = Math.Clamp(hitIntensity * INTENSITY_MULTIPLIER, MIN_INTENSITY, MAX_INTENSITY);
	}
}


/**
*	@brief Effect to emulate pain, applied when the player is bleeding.
*	       The effect will pulse faster as the bleeding cuts count increase
*	       
*	       NOTE: can be disabled by setting `PostProcessing Effect` quality to `Low`
*/
class SPPERequester_BloodLoss : SPPEffectAnimated {
	private int sourcesCount = 0;
	
	override void onInit() {
		op(PPOperators.ADD);
		priority(eSPPEPriority.BLEEDING);
	}
	
	override void onAnimate(float deltaTime) {
		setChromAber(getEffectsIntensity() * 0.005 * Math.AbsFloat(Math.Sin(getTime() * Math.Min(sourcesCount, 5) * 2)));
	}
		
	void setSourcesCount(int count) {
		this.sourcesCount = count;
	}
}
