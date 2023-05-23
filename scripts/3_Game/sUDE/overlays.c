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
		setImage("MyMODS/sFramework/GUI/textures/overlays/black_4x4.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(1);
		setDuration(1.3);
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
		setPriority(eSCOPriority.EYE + 1);
	}
	
	override void onAnimate(float deltaTime) {
		setMaskProgress(Math.AbsFloat(1 + Math.Sin(getTime() * SPEED) + MIN_APERTURE));		
	}
}


/**
*	@brief A blood splatter, applied when the player is bleeding.
*	       The overlay will pulse faster as the bleeding cuts count increase
*/
class SCOAnimationBleeding : SCameraOverlayAnimated {
	
	protected int bleedingBits;
	
	override void onInit() {
		setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		setMask("MyMODS/sVisual/GUI/textures/masks/blood.edds");
		setMaskTransitionWidth(0.75);
		setPriority(eSCOPriority.EYE);
		setSize(1.3);
	}
	
	override void onAnimate(float deltaTime) {
		setMaskProgress( 0.2 * (Math.AbsFloat(Math.Sin(getTime() * bleedingBits * 0.5)) + bleedingBits * 0.1));
	}
	
	void setBleedingBits(int bits) {
		bleedingBits = bits;
	}
}