class SCOAnimationDebug : SCameraOverlayAnimated {
	
	override void onInit(){
		setImage(SCOMasks.DEBUG);
		setMask(SCOMasks.DEBUG);
		setSize(0.2,0.2);
		setPriority(eSCOPriority.UI);
	}
	
	override void onAnimate(float deltaTime){		
		int x,y;
		GetMousePos(x,y);
		setRotation(-SMath.mapTo(x, 0, 1920, -90, 90), SMath.mapTo(y, 0, 1080, -90, 90), 0);
		setMaskProgress(Math.AbsFloat(Math.Sin(getTime()) * 1));
	}
}

class SCOTimedDebug : SCameraOverlayTimed {
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/icons/logo/sVisual.paa");
		setMask(SCOMasks.CIRCULAR);
		setDuration(60);
	}
	
	override void onAnimate(float deltaTime){
		float revolution = Math.AbsFloat(Math.Sin(getTime())) * 360;
		setImage("MyMODS/sVisual/GUI/icons/logo/sVisual.paa");
		setSize(0.075, 0.1);
		setPosition(-0.45, -0.35);
		setRotation(revolution, 0, 0);
	}
}



class SCOAnimationLogo : SCameraOverlayAnimated {
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/icons/logo/sVisual.paa");
		setSize(0.04, 0.06);
		setPosition(-0.48, -0.45);
		setPriority(eSCOPriority.UI);
	}
	
	override void onAnimate(float deltaTime){
		float revolution = Math.AbsFloat(Math.Sin(getTime())) * 360;
		setRotation(revolution, 0, 0);
		
	}
}