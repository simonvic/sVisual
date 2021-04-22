class PPEDebugAnimation : PPELoopedParams{	
	override void onAnimate(float deltaTime){
		//setGausBlur(1);
		setOverlay(Math.Cos(getTime() * 2), PPEManager.getPPEColor(Math.AbsFloat(Math.Sin(getTime())),0,0,0));
		setCameraEffects(Math.Sin(getTime() * 2), PPEManager.getPPEColor(Math.AbsFloat(Math.Sin(getTime() * 5)),1,1,0));
	}
}


class PPEEpinephrineAnimation : PPELoopedParams {	
	override void onAnimate(float deltaTime){	
		float power = Math.AbsFloat(Math.Sin(getTime() * 10)) * 0.05;		
		setRadialBlur(power, power);
		setVignette(power * 5, PPEManager.getPPEColor(0,0,0,0));		
	}
}

class PPEExhaustedAnimation : PPELoopedParams {	
	protected float stamina = 100;
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * 2.5) / Math.Clamp(stamina, 10, 100) * 1.3 );
		setRadialBlur(power, power);
		setVignette(power * 10, PPEManager.getPPEColor(0,0,0,0));
	}
	
	void setStamina(float stamina){
		this.stamina = stamina;
	}
}

class PPEOpticZoomChangeAnimation : PPETimedParams {	
	override void onAnimate(float deltaTime){
		float color = Math.Lerp(1, -1, Math.Sin(getTime() * 10));
		setColorization(PPEManager.getPPEColor(color,color,color,0));		
	}
}



class PPEHitReceivedAnimation : PPETimedParams {		
	protected float hitStrength = 1;
	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * hitStrength * Math.AbsFloat(SMath.mapTo(getRemaining(), 0.01, PPEConstants.HIT_RECEIVED_MAX_DURATION));
		float chromAberPower = Math.Clamp(power * 0.005, 0, PPEConstants.HIT_RECEIVED_MAX_CHROM_ABER);
		float vignettePower  = Math.Clamp(power * 0.08, 0, PPEConstants.HIT_RECEIVED_MAX_VIGNETTE);
		
		setChromAber(chromAberPower, chromAberPower);
		setVignette(vignettePower, PPEManager.getPPEColor(0.05,0,0,0));
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

class PPEUnconsciousAnimation : PPELoopedParams {
	override void onInit(){
		setRadialBlur(0.5, 0.5);
	}
	
	override void onAnimate(float deltaTime){
		setVignette(Math.Sin(Math.Pow(getTime(), 1.2) * 0.1 + 5) + 2.5, PPEManager.getPPEColor(0,0,0,0));		
	}
}

class PPEBleedingAnimation : PPELoopedParams {
	
	private int bleedingBits = 0;
	
	override void onAnimate(float deltaTime){
		float temp = Math.AbsFloat(Math.Sin(getTime() * bleedingBits));
		float red = -(temp * 0.2) + 1;
		float chrom = temp * bleedingBits / 100;
		setChromAber(chrom, chrom);
		setColorization(PPEManager.getPPEColor(1, red, red, 0));
	}
	
	void setBleedingBits(int cuts){
		this.bleedingBits = cuts;
	}
}