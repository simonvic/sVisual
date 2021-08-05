class SCOAnimationBleeding : SCameraOverlayAnimated {
	
	protected int bleedingBits;
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		setMask(SCOMasks.BLOOD);
		setMaskTransitionWidth(0.75);
		setPriority(eSCOPriority.EYE);
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress(Math.AbsFloat(Math.Sin(getTime() * bleedingBits * 0.75) * (0.45 + bleedingBits * 0.025)));
	}
	
	void setBleedingBits(int bits){
		bleedingBits = bits;
	}
}