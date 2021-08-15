class SCOTimedSpawn : SCameraOverlayTimed {
	
	override void onInit(){
		setImage("MyMODS/sFramework/GUI/textures/overlays/black_4x4.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(1);
		setDuration(1.3);
		setSize(1.5, 1);
		setPriority(eSCOPriority.EYE);
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress(Math.Sin(getTime() + Math.PI_HALF));
	}
}