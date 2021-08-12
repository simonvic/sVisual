class SCOAnimationBleeding : SCameraOverlayAnimated {
	
	protected int bleedingBits;
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		setMask(SCOMasks.BLOOD);
		setMaskTransitionWidth(0.75);
		setPriority(eSCOPriority.EYE);
		setSize(1.3);
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress( 0.2 * (Math.AbsFloat(Math.Sin(getTime() * bleedingBits * 0.5)) + bleedingBits * 0.1));
	}
	
	void setBleedingBits(int bits){
		bleedingBits = bits;
	}
}