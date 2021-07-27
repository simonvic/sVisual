class SCOBleedingAnimation : SCameraOverlayAnimated {
	
	protected int bleedingBits;
	
	override void onInit(){
		super.onInit();
		if(!getSuper()){
			setSuper(new SCameraOverlay("MyMODS/sVisual/GUI/textures/overlays/blood.edds"));
		}
		getSuper().setImage("MyMODS/sVisual/GUI/textures/overlays/blood.edds");
		getSuper().setMask("MyMODS/sVisual/GUI/textures/masks/blood.edds");
		getSuper().setMaskTransitionWidth(0.2);
	}
	
	override void onAnimate(float deltaTime){
		getSuper().setMaskProgress(Math.AbsFloat(Math.Sin(getTime() * bleedingBits)) * 0.4);
	}
	
	void setBleedingBits(int bits){
		bleedingBits = bits;
	}
}