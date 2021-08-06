class SCOAnimationDebug : SCameraOverlayAnimated {
	
	override void onInit(){
		setImage(SCOMasks.DEBUG);
		setMask(SCOMasks.DEBUG);
		setSize(0.2,0.2);
		setPriority(eSCOPriority.UI);
	}
	
	override void onAnimate(float deltaTime){		
		int mouseX, mouseY, sizeX, sizeY;
		float posX, posY;
		GetMousePos(mouseX,mouseY);
		GetScreenSize(sizeX, sizeY);
		getWidget().GetScreenPos(posX, posY);
		
		setRotation(
			-SMath.mapTo(mouseX, posX, sizeX, 0, 90),
			SMath.mapTo(mouseY, posY, sizeY, 0, 90),
			0);
		setMaskProgress(Math.AbsFloat(Math.Sin(getTime())));
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
	
	protected bool m_inventoryOpen;
	
	override void onInit(){
		setImage("MyMODS/sVisual/GUI/icons/logo/sUDE.paa");
		setSize(0.035, 0.06);
		setPosition(-0.48, -0.45);
		setPriority(eSCOPriority.UI);
		setHidesWithIngameHUD(true);
	}
	
	override void onAnimate(float deltaTime){
		if(m_inventoryOpen){
			setRotation(followCursor());
		}else{
			setRotation(Math.Sin(getTime()) * 360, 0, 0);
		}
	}
	
	protected vector followCursor(){
		int mouseX, mouseY, sizeX, sizeY;
		float posX, posY;
		GetMousePos(mouseX,mouseY);
		GetScreenSize(sizeX, sizeY);
		getWidget().GetScreenPos(posX, posY);
		
		return Vector(
			-SMath.mapTo(mouseX, posX, sizeX, 0, 90),
			SMath.mapTo(mouseY, posY, sizeY, 0, 90),
			0);
	}
	
	void onInventoryOpen(){
		m_inventoryOpen = true;
	}
	
	void onInventoryClose(){
		m_inventoryOpen = false;
		
	}
}