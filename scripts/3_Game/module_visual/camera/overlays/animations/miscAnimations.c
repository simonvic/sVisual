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

class SCOUnconscious : SCameraOverlayAnimated {
	
	override void onInit(){
		setImage("MyMODS/sFramework/GUI/textures/overlays/black_4x4.edds");
		setMask(SCOMasks.CIRCULAR);
		setMaskTransitionWidth(1);
		setSize(1.5, 1);
		setPriority(eSCOPriority.EYE + 1);
	}
	
	override void onAnimate(float deltaTime){
		float minHeight = 0.8;
		float speed = 0.5;
		setMaskProgress(Math.AbsFloat(1 + Math.Sin(getTime() * speed) + minHeight));		
	}
}