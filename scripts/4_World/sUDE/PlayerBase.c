modded class PlayerBase {

	protected SPPERequester_HitReceived m_ppeHitAnim;
	protected ref SCOTimedSpawn m_coSpawn;
	protected ref SCOUnconscious m_coUnconscious;

	void PlayerBase() {
		if (!g_Game.IsClient()) return;
		Class.CastTo(m_ppeHitAnim, PPERequesterBank.GetRequester(SPPERequester_HitReceived));
		m_coSpawn = new SCOTimedSpawn();
		m_coUnconscious = new SCOUnconscious();
	}

	override void OnReceivedHit(ImpactEffectsData hitData) {
		super.OnReceivedHit(hitData);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		if (hitData.m_AmmoType == "Dummy_Light") return;
		if (hitData.m_AmmoType == "Dummy_Heavy") return;
		if (m_ppeHitAnim.isActive()) {
			// TODO: change intensity based on inSpeed
			m_ppeHitAnim.onHit();
		} else {
			m_ppeHitAnim.activate();
		}
	}

	override void OnPlayerLoaded() {
		super.OnPlayerLoaded();
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		PPERequesterBank.GetRequester(SPPERequester_Bloom).Start();
		PPERequesterBank.GetRequester(SPPERequester_MotionBlur).Start();
		SCameraOverlaysManager.getInstance().deactivateAll();
		initClothingOverlays();
		playSpawnVisuals();
	}

	/*!
	 * Activate visual effects on spawn
	 */
	protected void playSpawnVisuals() {
		m_coSpawn.activate();
	}

	/*!
	 * Iterate over player attachment and, if the attachment is Clothing and has overlays, update
	 * their visibility.
	 * This is invoked only OnPlayerLoaded and it's needed to handle overlays during player
	 * initialization phase
	 */
	protected void initClothingOverlays() {
		for (int i=0; i<GetInventory().AttachmentCount(); i++ ) {
			Clothing clothing = Clothing.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (clothing && clothing.hasOverlays()) {
				clothing.onPlayerLoad();
			}
		}
	}

	override void OnUnconsciousStart() {
		super.OnUnconsciousStart();
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		m_coUnconscious.activate();
	}

	override void OnUnconsciousStop(int pCurrentCommandID) {
		super.OnUnconsciousStop(pCurrentCommandID);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		m_coUnconscious.deactivate();
	}

}
