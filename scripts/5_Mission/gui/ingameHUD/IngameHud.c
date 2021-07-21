modded class IngameHud {

	protected SClothingOverlaysManager m_clothingOverlaysManager;	
	protected Widget sRoot;

	void IngameHud(){
		sRoot = GetGame().GetWorkspace().CreateWidgets( getOverlayLayoutName(), m_HudPanelWidget );
		
	}
	
	string getOverlayLayoutName(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/ingameHUD/overlay.layout";
	}
	
	override void Update( float timeslice ){
		super.Update( timeslice );
		
		if(m_clothingOverlaysManager.getInstance().overlaysHaveChanged()){
			m_clothingOverlaysManager.getInstance().displayOn(sRoot);
		}
				
		
	}

}