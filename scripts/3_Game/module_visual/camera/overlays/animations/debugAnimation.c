class SCODebugAnimation : SCameraOverlayAnimated {
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/textures/masks/misc.edds");
		setMask("MyMODS/sVisual/GUI/textures/masks/misc.edds");
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress(Math.Sin(getTime() * 2));
	}
}

class SCODebugTimed : SCameraOverlayTimed {
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/textures/masks/misc.edds");
		setMask("MyMODS/sVisual/GUI/textures/masks/misc.edds");
		setDuration(3);
	}
	
	override void onAnimate(float deltaTime){
		setMaskProgress(Math.Sin(getTime() * Math.PI2));
	}
}