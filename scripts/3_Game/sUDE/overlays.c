modded class SCameraOverlay {
	float getEffectsIntensity() {
		return SUserConfig.visual().getEffectsIntensity();
	}
}

/**
*	@brief A black vignette played when the player spawn to emulate 
*	       an eye-opening effect
*/
class SCOTimedSpawn : SCameraOverlayTimed {
	
	override void onInit() {
		setDuration(1.3);
		setDeactivateOnStop(true);
		setImage("MyMODS/sFramework/GUI/textures/overlays/black_4x4.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(1);
		setSize(1.5, 1);
		setPriority(eSCOPriority.EYE);
	}
	
	override void onAnimate(float deltaTime) {
		setMaskProgress(Math.Sin(getTime() + Math.PI_HALF));
	}
	
}


/**
*	@brief A black vignette played when the player goes unconscious.
*	       The vignette will slightly open to allow unconcsious player
*	       to gain minor information
*/
class SCOUnconscious : SCameraOverlayAnimated {
	
	protected static const float MIN_APERTURE = 0.8;
	protected static const float SPEED = 0.5;
	
	override void onInit() {
		setImage("MyMODS/sFramework/GUI/textures/overlays/black_4x4.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(1);
		setSize(1.5, 1);
		setPriority(eSCOPriority.EYE + 9);
	}
	
	override void onAnimate(float deltaTime) {
		setMaskProgress(Math.AbsFloat(1 + Math.Sin(getTime() * SPEED) + MIN_APERTURE));		
	}
}


/**
*	@brief A blood splatter, applied when the player is bleeding.
*	       The overlay will pulse faster as the bleeding cuts count increase
*/
class SCOBleeding : SCameraOverlayAnimated {
	
	protected int sourcesCount;
	
	override void onInit() {
		setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(0.69);
		setMaskProgress(0.6);
		setPriority(eSCOPriority.EYE);
		setSize(1.3);
		setRotation(0, 0, 180);
	}
	
	override void onAnimate(float deltaTime) {
		setSize(1.75 - getEffectsIntensity() * 0.25 * Math.AbsFloat(Math.Sin(getTime() * Math.Min(sourcesCount, 5) * 2)));
	}
	
	void setSourcesCount(int count) {
		sourcesCount = count;
	}
}