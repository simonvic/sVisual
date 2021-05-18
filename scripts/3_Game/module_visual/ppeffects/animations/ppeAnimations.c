class PPEDebugAnimation : PPELoopedParams{	
	override void onAnimate(float deltaTime){
		//setGausBlur(1);
		//setOverlay(Math.Cos(getTime() * 2), PPEManager.getPPEColor(Math.AbsFloat(Math.Sin(getTime())),0,0,0));
		//setCameraEffects(Math.Sin(getTime() * 2), PPEManager.getPPEColor(Math.AbsFloat(Math.Sin(getTime() * 5)),1,1,0));
		//resetAllToDefault();
		//setVignetteIntensity(0.9);
		//setVignetteColor(SColor.rgb(0xFF0000));
	}
}


////////////////////////////////
// EPINEPHRINE
class PPEEpinephrineAnimation : PPELoopedParams {
	override void onInit(){
		setVignetteColor(PPEManager.getPPEColor(0,0,0,0));
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
		setVignetteColor(PPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * 2.5) / Math.Clamp(stamina, 40, 100));
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
		setColorization(PPEManager.getPPEColor(color,color,color,0));		
	}
}


////////////////////////////////
// HIT RECEIVED
class PPEHitReceivedAnimation : PPETimedParams {		
	protected float hitStrength = PPEConstants.HIT_RECEIVED_MIN_STRENGTH;
	
	override void onInit(){
		setVignetteColor(PPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * hitStrength * Math.AbsFloat(SMath.mapTo(getRemaining(), 0.01, PPEConstants.HIT_RECEIVED_MAX_DURATION));
		float chromAberPower = Math.Clamp(power * 0.005, 0, PPEConstants.HIT_RECEIVED_MAX_CHROM_ABER);
		float vignettePower  = Math.Clamp(power * 0.08, 0, PPEConstants.HIT_RECEIVED_MAX_VIGNETTE);
		
		setChromAber(chromAberPower, chromAberPower);
		setVignetteIntensity(vignettePower);
	}
	
	override void setDuration(float duration){
		m_time = 0;
		m_duration = Math.Clamp(duration, 0.1, PPEConstants.HIT_RECEIVED_MAX_DURATION);
	}
	
	float getHitStrength(){
		return hitStrength;
	}
	
	void setHitStrength(float strength){
		hitStrength = Math.Clamp(strength, 0, PPEConstants.HIT_RECEIVED_MAX_STRENGTH);
	}
}


////////////////////////////////
// UNCONSCIOUS
class PPEUnconsciousAnimation : PPELoopedParams {
	
	override void onInit(){
		setRadialBlur(0.5, 0.5);
		setVignetteColor(PPEManager.getPPEColor(0,0,0,0));
	}
	
	override void onAnimate(float deltaTime){
		setVignetteIntensity(Math.Sin(Math.Pow(getTime(), 1.2) * 0.1 + 5) + 2.5);
	}
}

////////////////////////////////
// BLEEDING
class PPEBleedingAnimation : PPELoopedParams {
	private int bleedingBits = 0;
	
	override void onInit(){
		setVignetteColor(PPEManager.getPPEColor(0.005, -0.1, -0.1, 0));
	}
	
	override void onAnimate(float deltaTime){
		float temp = Math.AbsFloat(Math.Sin(getTime() * bleedingBits));
		float chrom = temp * bleedingBits / 100;
		setChromAber(chrom, chrom);
		setVignetteIntensity(temp * 0.4);
	}
		
	void setBleedingBits(int cuts){
		this.bleedingBits = cuts;
	}
}
