modded class Clothing {

	//! Lazily initialized list of camera overlays
	protected ref array<ref SCameraOverlay> m_overlays;

	//! True when the clothing item is attacched to the current player, false otherwise
	protected bool m_isAttachedToPlayer;

	/*!
	 * Initialize the clothing overlays
	 */
	protected void initOverlays() {
		m_overlays = loadCameraOverlaysList();
	}

	/*!
	 * Load clothing overlays from the config
	 * @return list of overlays
	 */
	protected array<ref SCameraOverlay> loadCameraOverlaysList() {
		return SGameConfig.visual().getCameraOverlays(Type());
	}

	/*!
	 * Get the overlays (and initialize if not initialized)
	 * @return list of overlays
	 */
	array<ref SCameraOverlay> getOverlaysList() {
		if (!m_overlays) initOverlays();
		return m_overlays;
	}

	/*!
	 * Check if the clothing has overlays
	 * @return true if has overlays, false otherwise
	 */
	bool hasOverlays() {
		return getOverlaysList() && m_overlays.Count() != 0;
	}

	/*!
	 * Get the overlay linked to the current item health level
	 * @return camera overlay
	 */
	SCameraOverlay getOverlayByCurrentHealth() {
		return getOverlayByHealth(GetHealthLevel());
	}

	/*!
	 * Get overlay linked to a specific health level
	 * @param health level (pristine, worn, damaged etc.)
	 * @return camera overlay
	 */
	SCameraOverlay getOverlayByHealth(int level) {
		array<ref SCameraOverlay> overlays = getOverlaysList();
		if (!overlays || overlays.Count() == 0) return null;
		return overlays[Math.Clamp(level, 0, m_overlays.Count() - 1)];
	}

	/*!
	 * Callback when the user option gets changed.
	 * This is responsible for updating the overlay visibiliy
	 * @param previousValue
	 * @param newValue
	 */
	protected void onClothingOverlayOptionToggle(bool previousValue, bool newValue) {
		SCameraOverlay overlay = getOverlayByCurrentHealth();
		if (overlay) {
			if (newValue) {
				overlay.activate();
			} else {
				overlay.deactivate();
			}
		}
	}

	/*!
	 * Update the visibility of the overlay
	 */
	protected void updateOverlayVisibility() {
		SCameraOverlay overlay = getOverlayByCurrentHealth();
		if (overlay) {
			if (m_isAttachedToPlayer) {
				overlay.activate();
			} else {
				overlay.deactivate();
			}
		}
	}

	/*!
	 * Swap the overlay linked to a health level to one linked to another health level
	 * @param oldLevel item health level
	 * @param newlevel item health level
	 * @param zone
	 */
	protected void swapOverlayByHealthLevel(int oldLevel, int newLevel, string zone) {
		SCameraOverlay old = getOverlayByHealth(oldLevel);
		if (old && old.isActive()) {
			old.deactivate();
			SCameraOverlay newOverlay = getOverlayByHealth(newLevel);
			if (newOverlay) {
				newOverlay.activate();
			}
		}
	}

	/*!
	 * Invoked on PlayerBase::OnPlayerLoaded
	 * @see PlayerBase::OnPlayerLoaded
	 */
	void onPlayerLoad() {
		m_isAttachedToPlayer = true;
		SUserConfigVisual userCfg = SUserConfig.visual();
		userCfg.getOption("showClothingOverlays").getOnValueChange().Insert(this.onClothingOverlayOptionToggle);
		if (userCfg.isShowClothingOverlaysEnabled()) {
			updateOverlayVisibility();
		}
	}

	// NOTE: OnWasAttached and OnWasDetached don't handle player initizalization phase.

	override void OnWasAttached(EntityAI parent, int slot_id) {
		super.OnWasAttached(parent, slot_id);
		if (!g_Game.IsClient()) return;
		if (parent != g_Game.GetPlayer()) return;
		m_isAttachedToPlayer = true;
		if (hasOverlays()) {
			SUserConfigVisual userCfg = SUserConfig.visual();
			userCfg.getOption("showClothingOverlays").getOnValueChange().Insert(this.onClothingOverlayOptionToggle);
			if (userCfg.isShowClothingOverlaysEnabled()) {
				updateOverlayVisibility();
			}
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id) {
		super.OnWasDetached(parent, slot_id);
		if (!g_Game.IsClient()) return;
		if (parent != g_Game.GetPlayer()) return;
		m_isAttachedToPlayer = false;
		if (hasOverlays()) {
			SUserConfigVisual userCfg = SUserConfig.visual();
			userCfg.getOption("showClothingOverlays").getOnValueChange().Remove(this.onClothingOverlayOptionToggle);
			if (userCfg.isShowClothingOverlaysEnabled()) {
				updateOverlayVisibility();
			}
		}
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		if (!g_Game.IsClient()) return;
		if (m_isAttachedToPlayer) {
			swapOverlayByHealthLevel(oldLevel, newLevel, zone);
		}
	}

}
