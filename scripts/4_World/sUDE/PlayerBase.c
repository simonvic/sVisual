modded class PlayerBase {

	protected SPPERequester_HitReceived m_ppeHitAnim;
	protected SPPERequester_BloodLoss m_ppeBleeding;
	protected ref SCOTimedSpawn m_coSpawn;
	protected ref SCOUnconscious m_coUnconscious;
	protected ref SCOBleeding m_coBleeding;

	void PlayerBase() {
		if (!g_Game.IsClient()) return;
		Class.CastTo(m_ppeHitAnim, PPERequesterBank.GetRequester(SPPERequester_HitReceived));
		Class.CastTo(m_ppeBleeding, PPERequesterBank.GetRequester(SPPERequester_BloodLoss));
		m_coSpawn = new SCOTimedSpawn();
		m_coUnconscious = new SCOUnconscious();
		m_coBleeding = new SCOBleeding();
		SUserConfig.visual().getOption("showBleedingOverlay").getOnValueChange().Insert(this.onBleedingOverlayOptionToggle, EScriptInvokerInsertFlags.UNIQUE);
	}

	protected void onBleedingOverlayOptionToggle(bool prevValue, bool newValue) {
		if (newValue) {
			if (IsBleeding()) {
				m_coBleeding.setSourcesCount(m_BleedingSourceCount);
				m_coBleeding.activate();
				m_ppeBleeding.activate(); // NOTE: reactivate ppe as well to sync the animations
			}
		} else {
			m_coBleeding.deactivate();
		}
	}

	override void OnBleedingBegin() {
		super.OnBleedingBegin();
		if (g_Game.IsDedicatedServer()) return;
		if (!IsControlledPlayer()) return;
		m_ppeBleeding.activate();
		if (SUserConfig.visual().isShowBleedingOverlayEnabled()) {
			m_coBleeding.activate();
		}
	}

	override void OnBleedingEnd() {
		super.OnBleedingEnd();
		if (g_Game.IsDedicatedServer()) return;
		if (!IsControlledPlayer()) return;
		m_ppeBleeding.deactivate();
		m_coBleeding.deactivate();
	}

	override void OnBleedingSourceAdded(){
		super.OnBleedingSourceAdded();
		if (g_Game.IsDedicatedServer()) return;
		if (!IsControlledPlayer()) return;
		m_ppeBleeding.setSourcesCount(m_BleedingSourceCount);
		m_coBleeding.setSourcesCount(m_BleedingSourceCount);
	}

	override void OnBleedingSourceRemoved(){
		super.OnBleedingSourceRemoved();
		if (g_Game.IsDedicatedServer()) return;
		if (!IsControlledPlayer()) return;
		m_ppeBleeding.setSourcesCount(m_BleedingSourceCount);
		m_coBleeding.setSourcesCount(m_BleedingSourceCount);
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
