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
		
		if(SCameraOverlayManager.getInstance().overlaysHaveChanged()){
			SCameraOverlayManager.getInstance().updateOn(m_overlaysRoot);
		}
		
		map<string, ref ImageWidget> widgets = SCameraOverlayManager.getInstance().getActiveOverlayWidgets();
		foreach(string i, ImageWidget w : widgets){
			//w.LoadImageFile(0, "MyMODS/sVisual/GUI/textures/overlays/generic_scratches_damaged.edds");
			w.SetSize(1,1);
			w.SetAlpha(0.05);
			w.LoadMaskTexture("gui/textures/cardial_small_mask.edds");
			float t = Math.AbsFloat(Math.Sin(m_time * 0.5));
			w.SetMaskProgress(t);
			w.SetMaskTransitionWidth(0.1);
		}
		
		/*
		ImageWidget img = ImageWidget.Cast(m_overlaysRoot.FindWidget("img_debug"));
		img.LoadImageFile(0, "set:dayz_crosshairs image:cross_32x32");
		img.Show(false);
		*/
		
	}
	

}