modded class Clothing{
	
	protected ref TSCameraOverlaysList m_overlays = new TSCameraOverlaysList();
	
	void Clothing() {
		initOverlays();
	}
	
	void ~Clothing() {
	}
	
	protected void initOverlays() {
		m_overlays = loadCameraOverlaysList();
	}
	
	protected TSCameraOverlaysList loadCameraOverlaysList() {
		return SGameConfig.visual().getCameraOverlays(Type());
	}
	
	TSCameraOverlaysList getOverlaysList() {
		return m_overlays;
	}
	
	bool hasOverlays() {
		return m_overlays.Count() != 0;
	}
	
	/*
	override void OnWasAttached( EntityAI parent, int slot_id ) {
		super.OnWasAttached( parent, slot_id );
		if (!GetGame().IsClient() && GetGame().IsMultiplayer()) return;

		if (parent.IsInherited(PlayerBase) && hasOverlays()) {
			SCameraOverlaysManager.getInstance().activate(getOverlayByCurrentHealth());
		}
	}
	
	override void OnWasDetached( EntityAI parent, int slot_id ) {
		super.OnWasDetached( parent, slot_id );
		if (!GetGame().IsClient() && GetGame().IsMultiplayer()) return;
		
		if (parent.IsInherited(PlayerBase) && hasOverlays()) {
			SCameraOverlaysManager.getInstance().deactivate(getOverlayByCurrentHealth());
		}
	}
	*/
	
	SCameraOverlay getOverlayByCurrentHealth() {
		return getOverlayByHealth(GetHealthLevel());
	}
	
	SCameraOverlay getOverlayByHealth(int level) {
		return m_overlays[Math.Clamp(level, 0, m_overlays.Count() - 1)];
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		swapOverlayByHealthLevel(oldLevel, newLevel, zone);
	}
	
	protected void swapOverlayByHealthLevel(int oldLevel, int newLevel, string zone) {
		if (GetGame().IsClient()) {
			SCameraOverlay old = getOverlayByHealth(oldLevel);
			if (SCameraOverlaysManager.getInstance().isActive(old)) {
				SCameraOverlaysManager.getInstance().deactivate(old);
				SCameraOverlaysManager.getInstance().activate(getOverlayByHealth(newLevel));
			}
		}
	}
	
}