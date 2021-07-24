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
		foreach(SCameraOverlay o : overlays){
			o.setAlpha(1.0);
			float t = Math.AbsFloat(Math.Sin(m_time * 0.5));
			ImageWidget w = o.getWidget();
			//w.LoadImageFile(0, "MyMODS/sVisual/GUI/textures/overlays/generic_scratches_damaged.edds");
			w.SetSize(2,2);
			w.SetPos(0.0,0.0);
			w.SetRotation(0, 0, 0);
			//w.SetAlpha(0.2);
			o.setMask("gui/textures/cardial_small_mask.edds");
			o.setMaskProgress(0.5);
			o.setMaskTransitionWidth(0.1);
			
		}
		*/
		/*
		ImageWidget img = ImageWidget.Cast(m_overlaysRoot.FindWidget("img_debug"));
		img.LoadImageFile(0, "set:dayz_crosshairs image:cross_32x32");
		img.Show(false);
		*/
		
	}
	

}