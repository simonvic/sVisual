modded class Clothing{
	
	protected ref TClothingOverlaysList m_overlays = {};
	
	void Clothing(){
		initOverlays();
	}
	
	protected void initOverlays(){
		m_overlays = loadOverlaysList();
	}
	
	protected TClothingOverlaysList loadOverlaysList(){
		return SGameConfig.visual().getOverlaysList(Type());
	}
	
	TClothingOverlaysList getOverlaysList(){
		return m_overlays;
	}
	
}