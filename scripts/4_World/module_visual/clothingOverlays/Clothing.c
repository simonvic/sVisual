typedef array<string> TClothingOverlaysList;

modded class Clothing{
	
	protected ref TClothingOverlaysList m_overlays = {};
	
	void Clothing(){
		initOverlays();
	}
	
	protected void initOverlays(){
		m_overlays = loadOverlaysList();
	}
	
	protected TClothingOverlaysList loadOverlaysList(){
		return SGameConfig.getStringArray("cfgVehicles " + GetType() + " sUDE clothingOverlays");
	}
	
	TClothingOverlaysList getOverlaysList(){
		return m_overlays;
	}
	
}