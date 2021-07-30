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
		return m_overlays[Math.Clamp(level, 0, m_overlays.Count() - 1)];
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