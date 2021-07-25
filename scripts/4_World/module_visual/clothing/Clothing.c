modded class Clothing{
	
	protected ref TSCameraOverlaysList m_overlays = new TSCameraOverlaysList();
	
	void Clothing(){
		initOverlays();
	}
	
	void ~Clothing(){
	}
	
	protected void initOverlays(){
		m_overlays = loadCameraOverlaysList();
	}
	
	protected TSCameraOverlaysList loadCameraOverlaysList(){
		return SGameConfig.visual().getCameraOverlays(Type());
	}
	
	TSCameraOverlaysList getOverlaysList(){
		return m_overlays;
	}
	
	bool hasOverlays(){
		return m_overlays.Count() != 0;
	}
	
	SCameraOverlay getCurrentHealthOverlay(){
		if(m_overlays.Count() - 1 < GetHealthLevel()){
			return m_overlays[m_overlays.Count() - 1];
		}
		return m_overlays[GetHealthLevel()];
	}
	
}