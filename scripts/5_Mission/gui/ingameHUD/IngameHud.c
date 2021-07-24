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
		
		if(SCameraOverlaysManager.getInstance().overlaysHaveChanged()){
			SCameraOverlaysManager.getInstance().updateOn(m_overlaysRoot);
		}
		
		/*
		TSCameraOverlaySet overlays = SCameraOverlaysManager.getInstance().getActive();
		foreach(SCameraOverlay overlay : overlays){
			//w.LoadImageFile(0, "MyMODS/sVisual/GUI/textures/overlays/generic_scratches_damaged.edds");
			//overlay.getWidget().SetSize(1,1);
			overlay.getWidget().SetAlpha(0.2);
			//overlay.getWidget().LoadMaskTexture("gui/textures/cardial_small_mask.edds");
			float t = Math.AbsFloat(Math.Sin(m_time * 0.5));
			//overlay.getWidget().SetMaskProgress(t);
			//overlay.getWidget().SetMaskTransitionWidth(0.1);
		}
		*/
		/*
		ImageWidget img = ImageWidget.Cast(m_overlaysRoot.FindWidget("img_debug"));
		img.LoadImageFile(0, "set:dayz_crosshairs image:cross_32x32");
		img.Show(false);
		*/
		
	}
	

}