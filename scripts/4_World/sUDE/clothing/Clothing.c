modded class Clothing {
	
	protected ref array<ref SCameraOverlay> m_overlays;
	
	protected void initOverlays() {
		m_overlays = loadCameraOverlaysList();
	}
	
	protected array<ref SCameraOverlay> loadCameraOverlaysList() {
		return SGameConfig.visual().getCameraOverlays(Type());
	}
	
	array<ref SCameraOverlay> getOverlaysList() {
		if (!m_overlays) initOverlays();
		return m_overlays;
	}
	
	bool hasOverlays() {
		return getOverlaysList() && m_overlays.Count() != 0;
	}
	
	
	SCameraOverlay getOverlayByCurrentHealth() {
		return getOverlayByHealth(GetHealthLevel());
	}
	
	SCameraOverlay getOverlayByHealth(int level) {
		array<ref SCameraOverlay> overlays = getOverlaysList();
		if (!overlays || overlays.Count() == 0) return null;
		return overlays[Math.Clamp(level, 0, m_overlays.Count() - 1)];
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		swapOverlayByHealthLevel(oldLevel, newLevel, zone);
	}
	
	protected void swapOverlayByHealthLevel(int oldLevel, int newLevel, string zone) {
		if (!GetGame().IsClient()) return;
		SCameraOverlay old = getOverlayByHealth(oldLevel);
		if (old && old.isActive()) {
			old.deactivate();
			SCameraOverlay newOverlay = getOverlayByHealth(newLevel);
			if (newOverlay) {
				newOverlay.activate();
			}
		}
	}
	
}