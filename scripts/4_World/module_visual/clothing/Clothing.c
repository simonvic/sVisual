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
	
	SCameraOverlay getOverlayByCurrentHealth(){
		return getOverlayByHealth(GetHealthLevel());
	}
	
	SCameraOverlay getOverlayByHealth(int level){
		if(m_overlays.Count() - 1 < level){
			return m_overlays[m_overlays.Count() - 1];
		}
		return m_overlays[level];
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone){
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		if( GetGame().IsClient() ){
			SCameraOverlay old = getOverlayByHealth(oldLevel);
			if(SCameraOverlaysManager.getInstance().isActive(old)){
				SCameraOverlaysManager.getInstance().deactivate(old);
				SCameraOverlaysManager.getInstance().activate(getOverlayByHealth(newLevel));
			}
		}
		
	}
	
}