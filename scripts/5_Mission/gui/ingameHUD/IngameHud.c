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
		
		if(SClothingOverlaysManager.getInstance().overlaysHaveChanged()){
			SClothingOverlaysManager.getInstance().updateOn(m_overlaysRoot);
		}
		
		
		
		/*
		ImageWidget img = ImageWidget.Cast(m_overlaysRoot.FindWidget("img_debug"));
		img.LoadImageFile(0, "set:dayz_crosshairs image:cross_32x32");
		img.Show(false);
		*/
		
	}
	

}