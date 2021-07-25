modded class IngameHud {

	protected Widget m_overlaysRoot;
	protected float m_time;

	void IngameHud(){
		m_overlaysRoot = GetGame().GetWorkspace().CreateWidgets( getOverlayLayoutName(), m_HudPanelWidget );
		
	}
	
	string getOverlayLayoutName(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/ingameHUD/overlay.layout";
	}
	
	override void Update( float timeslice ){
		super.Update( timeslice );
		m_time += timeslice;
		
		SCameraOverlaysManager.getInstance().onUpdate(timeslice, m_overlaysRoot);
		
		
		/*
		TSCameraOverlaySet overlays = SCameraOverlaysManager.getInstance().getActive();
		foreach(SCameraOverlay o : overlays){
			float t = Math.AbsFloat(Math.Sin(Math.Sin(m_time) * 0.5)) + 0.15;
			o.setImage("MyMODS/sVisual/GUI/textures/overlays/black_4x4.edds");
			o.setSize(1.5,1.5);
			//o.setPosition(0.0,0.0);
			//o.setRotation("0 0 0");
			o.setAlpha(1);
			o.setMask("MyMODS/sVisual/GUI/textures/masks/binoculars_inverted.edds");
			o.setMaskProgress(0.8);
			o.setMaskTransitionWidth(0.5);
			
		}
		
		/*
		ImageWidget img = ImageWidget.Cast(m_overlaysRoot.FindWidget("img_debug"));
		img.LoadImageFile(0, "set:dayz_crosshairs image:cross_32x32");
		img.Show(false);
		*/
		
	}
	

}