////////////////////////////////
// EPINEPHRINE
class PPEEpinephrineAnimation : PPELoopedParams {
	override void onInit(){
		setVignetteColor(SPPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){	
		float power = Math.AbsFloat(Math.Sin(getTime() * 10)) * 0.05;
		setRadialBlur(power, power);
		setVignetteIntensity(power * 5);
	}
}


////////////////////////////////
// EXHAUSTED
class PPEExhaustedAnimation : PPELoopedParams {	
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


//////////////////////////////// 
// OPTIC CHANGE
class PPEOpticZoomChangeAnimation : PPETimedParams {	
	override void onAnimate(float deltaTime){
		float color = Math.Lerp(1, -1, Math.Sin(getTime() * 10));
		setColorization(SPPEManager.getPPEColor(color,color,color,0));		
	}
}


////////////////////////////////
// HIT RECEIVED
class PPEHitReceivedAnimation : PPETimedParams {		
	protected float hitStrength = SPPEConstants.HIT_RECEIVED_MIN_STRENGTH;
	
	override void onInit(){
		setVignetteColor(SPPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * hitStrength * Math.AbsFloat(SMath.mapTo(getRemaining(), 0.01, SPPEConstants.HIT_RECEIVED_MAX_DURATION));
		float chromAberPower = Math.Clamp(power * 0.001, 0, SPPEConstants.HIT_RECEIVED_MAX_CHROM_ABER);
		float vignettePower  = Math.Clamp(power * 0.08, 0, SPPEConstants.HIT_RECEIVED_MAX_VIGNETTE);
		
		setChromAber(chromAberPower, chromAberPower);
		setVignetteIntensity(vignettePower);
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


////////////////////////////////
// UNCONSCIOUS
class PPEUnconsciousAnimation : PPELoopedParams {
	
	override void onInit(){
		setRadialBlur(0.5, 0.5);
		setVignetteColor(SPPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		setVignetteIntensity(Math.Sin(Math.Pow(getTime(), 1.2) * 0.1 + 5) + 2.5);
	}
}

////////////////////////////////
// BLEEDING
class PPEBleedingAnimation : PPELoopedParams {
	private int bleedingBits = 0;
	
	override void onAnimate(float deltaTime){
		setChromAber(0.005 * (Math.AbsFloat(Math.Sin(getTime() * bleedingBits * 0.5)) + bleedingBits * 0.1));
	}
		
	void setBleedingBits(int cuts){
		this.bleedingBits = cuts;
	}
}
