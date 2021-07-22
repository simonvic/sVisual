modded class Clothing{
	
	protected ref TStringArray m_overlays = {};
	
	void Clothing(){
		initOverlays();
	}
	
	protected void initOverlays(){
		m_overlays = loadOverlaysList();
	}
	
	protected TStringArray loadOverlaysList(){
		return SGameConfig.visual().getOverlaysList(Type());
	}
	
	TStringArray getOverlaysList(){
		return m_overlays;
	}
	
	string getCurrentHealthOverlay(){
		if(m_overlays.Count() - 1 < GetHealthLevel()){
			return m_overlays[m_overlays.Count() - 1];
		}
		return m_overlays[GetHealthLevel()];
	}
	
}