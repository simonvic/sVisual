class SCOBleedingAnimation : SCameraOverlayAnimated {
	
	protected int bleedingBits;
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		setMask("MyMODS/sVisual/GUI/textures/masks/blood.edds");
		setMaskTransitionWidth(0.2);
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress(Math.AbsFloat(Math.Sin(getTime() * bleedingBits)) * 0.4);
	}
	
	void setBleedingBits(int bits){
		bleedingBits = bits;
	}
}