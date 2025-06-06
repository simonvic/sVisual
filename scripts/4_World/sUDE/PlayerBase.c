modded class PlayerBase {
	
	protected SPPERequester_HitReceived m_ppeHitAnim;
	protected ref SCOTimedSpawn m_coSpawn;
	protected ref SCOUnconscious m_coUnconscious;
	
	void PlayerBase() {
		if (!GetGame().IsClient()) return;
		Class.CastTo(m_ppeHitAnim, PPERequesterBank.GetRequester(SPPERequester_HitReceived));
		m_coSpawn = new SCOTimedSpawn();
		m_coUnconscious = new SCOUnconscious();
	}
	
	// TODO: move to clothing
	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		Clothing clothing = Clothing.Cast(item);
		if (clothing && clothing.hasOverlays()) {
			SCameraOverlay overlay = clothing.getOverlayByCurrentHealth();
			if (overlay) {
				overlay.activate();
			}
		}
	}
	
	// TODO: move to clothing
	override void EEItemDetached(EntityAI item, string slot_name) {
		super.EEItemDetached(item, slot_name);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		Clothing clothing = Clothing.Cast(item);
		if (clothing && clothing.hasOverlays()) {
			SCameraOverlay overlay = clothing.getOverlayByCurrentHealth();
			if (overlay) {
				overlay.deactivate();
			}
		}
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

	override void OnSelectPlayer() {
		super.OnSelectPlayer();
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		PPERequesterBank.GetRequester(SPPERequester_Bloom).Start();
		PPERequesterBank.GetRequester(SPPERequester_MotionBlur).Start();
	}
	
	override void OnPlayerLoaded() {
		super.OnPlayerLoaded();
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		SCameraOverlaysManager.getInstance().deactivateAll();
		checkForClothingOverlays();
		playSpawnVisuals();
	}
	
	protected void playSpawnVisuals() {
		m_coSpawn.activate();
	}
	
	protected void checkForClothingOverlays() {
		for (int i=0; i<GetInventory().AttachmentCount(); i++ ) {
			Clothing clothing = Clothing.Cast(GetInventory().GetAttachmentFromIndex( i ));
			if (clothing && clothing.hasOverlays()) {
				SCameraOverlay overlay = clothing.getOverlayByCurrentHealth();
				if (overlay) {
					overlay.activate();
				}
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
