modded class Clothing{
	
	protected ref TSCameraOverlaySet m_overlays = new TSCameraOverlaySet();
	
	void Clothing(){
		initOverlays();
	}
	
	protected void initOverlays(){
		m_overlays = loadCameraOverlaysList();
	}
	
	protected TSCameraOverlaySet loadCameraOverlaysList(){
		return SGameConfig.visual().getCameraOverlays(Type());
	}
	
	TSCameraOverlaySet getOverlaysList(){
		return m_overlays;
	}
	
	SCameraOverlay getCurrentHealthOverlay(){
		if(m_overlays.Count() - 1 < GetHealthLevel()){
			return m_overlays[m_overlays.Count() - 1];
		}
		return m_overlays[GetHealthLevel()];
	}
	
}