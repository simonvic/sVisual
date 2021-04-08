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

class PPEExhaustedAnimation : PPETimedParams {	
	override void onAnimate(float deltaTime){
		float power = Math.AbsFloat(Math.Sin(getTime() * 2.5)) * 0.01;
		setRadialBlur(power * 5, power * 5);
		setVignette(power * 50, PPEManager.getPPEColor(0,0,0,0));
	}
}

class PPEOpticZoomChangeAnimation : PPETimedParams {	
	override void onAnimate(float deltaTime){
		float color = Math.Lerp(1, -1, Math.Sin(getTime() * 10));
		setColorization(PPEManager.getPPEColor(color,color,color,0));		
	}
}



class PPEHitReceivedAnimation : PPETimedParams {		
	protected float hitStrength = 50;
	
	override void onAnimate(float deltaTime){		
		float power = Math.AbsFloat(Math.Sin(getTime() * Math.PI)) * 0.001 * hitStrength;
		setChromAber(power * 1.5, power * 1.5);
		setVignette(power * 5, PPEManager.getPPEColor(0.5,0,0,0));
	}
	
	float getHitStrength(){
		return hitStrength;
	}
	
	void setHitStrength(float strength){
		hitStrength = strength;
	}
}

class PPEUnconsciousAnimation : PPELoopedParams {
	override void onAnimate(float deltaTime){
		setRadialBlur(0.5, 0.5);
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