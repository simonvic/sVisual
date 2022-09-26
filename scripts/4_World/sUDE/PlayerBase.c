modded class PlayerBase {
	
	protected ref PPEHitReceivedAnimation m_ppeHitAnim; //Used when being hit
	protected ref PPEBleedingAnimation m_ppeBleeding; //Used when bleeding
	protected ref PPEUnconscious m_ppeUnconscious;//Used when going uncoscious
	protected ref SCOAnimationBleeding m_coBleeding;
	protected ref SCOTimedSpawn m_coSpawn;
	protected ref SCOUnconscious m_coUnconscious;
	
	void PlayerBase() {
		if (!GetGame().IsClient()) return;
		m_ppeHitAnim = new PPEHitReceivedAnimation(SPPEConstants.HIT_RECEIVED_MIN_DURATION, true);
		m_ppeBleeding = new PPEBleedingAnimation();
		m_ppeUnconscious = new PPEUnconscious();
		m_coBleeding = new SCOAnimationBleeding();
		m_coSpawn = new SCOTimedSpawn();
		m_coUnconscious = new SCOUnconscious();
	}
	
	//@todo move to clothing
	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		

		Clothing clothing = Clothing.Cast(item);
		if (clothing && clothing.hasOverlays()) {
			SCameraOverlaysManager.getInstance().activate(clothing.getOverlayByCurrentHealth());
		}
		
		
	}
	
	//@todo move to clothing
	override void EEItemDetached(EntityAI item, string slot_name) {
		super.EEItemDetached(item, slot_name);
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		Clothing clothing = Clothing.Cast(item);
		if (clothing && clothing.hasOverlays()) {
			SCameraOverlaysManager.getInstance().deactivate(clothing.getOverlayByCurrentHealth());
		}
	}
		
	override void OnPlayerRecievedHit() {
		super.OnPlayerRecievedHit();	
		playHitReceivedPPE();
	}
	
	protected void playHitReceivedPPE() {
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		if (m_ppeHitAnim.isActive()) {
			m_ppeHitAnim.setDuration(m_ppeHitAnim.getDuration() * SPPEConstants.HIT_RECEIVED_DURATION_MULTIPLIER);
			m_ppeHitAnim.setHitStrength(m_ppeHitAnim.getHitStrength() * SPPEConstants.HIT_RECEIVED_STRENGTH_MULTIPLIER);
		} else {
			m_ppeHitAnim.setDuration(SPPEConstants.HIT_RECEIVED_MIN_DURATION);
			m_ppeHitAnim.setHitStrength(SPPEConstants.HIT_RECEIVED_MIN_STRENGTH);
			
			SPPEManager.activate(m_ppeHitAnim);
		}
	}
	
	override void OnPlayerLoaded() {
		super.OnPlayerLoaded();
		updateVisuals();
	}
	
	protected void updateVisuals() {
		if (GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
			
		/////////////////////////
		// PPEffects
		SPPEManager.deactivateAll();
		SPPEManager.applyDefault();
			
		checkForBleedingPPE();
		
		/////////////////////////
		// Overlays
		SCameraOverlaysManager.getInstance().deactivateAll();
		checkForClothingOverlays();
		playSpawnVisuals();
	}
	
	protected void playSpawnVisuals() {
		SCameraOverlaysManager.getInstance().activate(m_coSpawn);
	}
	
	protected void checkForBleedingPPE() {
		if (IsBleeding()) {
			updateBleedingEffect();
			SPPEManager.activate(m_ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	

	protected void checkForClothingOverlays() {
		for (int i=0; i<GetInventory().AttachmentCount(); i++ ) {
			Clothing clothing = Clothing.Cast(GetInventory().GetAttachmentFromIndex( i ));
			if (clothing && clothing.hasOverlays()) {
				SCameraOverlaysManager.getInstance().activate(clothing.getOverlayByCurrentHealth());
			}
		}
	}
	
	
	
	
	///////////////// UNCONSCIOUSNESS ///////////////////////////////
	override void OnUnconsciousStart() {
		super.OnUnconsciousStart();
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			SPPEManager.activate(m_ppeUnconscious);
			SCameraOverlaysManager.getInstance().activate(m_coUnconscious);
		}
	}
	
	override void OnUnconsciousStop(int pCurrentCommandID) {
		super.OnUnconsciousStop(pCurrentCommandID);
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			SPPEManager.deactivate(m_ppeUnconscious);
			SCameraOverlaysManager.getInstance().deactivate(m_coUnconscious);
		}
	}
	
	
	///////////////// BLEEDING ///////////////////////////////
	override void OnBleedingBegin() {
		super.OnBleedingBegin();
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			SPPEManager.activate(m_ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	
	override void OnBleedingEnd() {
		super.OnBleedingEnd();
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			SPPEManager.deactivate(m_ppeBleeding);
			SCameraOverlaysManager.getInstance().deactivate(m_coBleeding);
		}
	}
	
	override void OnBleedingSourceAdded() {
		super.OnBleedingSourceAdded();
		updateBleedingEffect();
		
	}
	
	override void OnBleedingSourceRemoved() {
		super.OnBleedingSourceRemoved();
		updateBleedingEffect();
	}
	
	protected void updateBleedingEffect() {
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			m_ppeBleeding.setBleedingBits(GetBleedingSourceCount());
			m_coBleeding.setBleedingBits(GetBleedingSourceCount());
		}
	}
	
	
	

	//////////////////////////////////////////////////////////////////// DEBUGGING ////////////////////////////////////////////////////////////////////
	/*
	protected ref PPEDebugAnimation m_ppeDebugAnimation = new PPEDebugAnimation();	
	protected ref SPPEffect m_ppeDebug = new SPPEffect();
	
	protected ref SCOAnimationDebug	m_coDebugAnim = new SCOAnimationDebug();
	protected ref SCOTimedDebug	m_coDebugTimed = new SCOTimedDebug();
	protected ref SCOAnimationLogo	m_coLogo = new SCOAnimationLogo();
	
	override void OnInventoryMenuOpen() {
		super.OnInventoryMenuOpen();
		//SPPEManager.toggle(m_ppeBleeding, !m_ppeBleeding.isActive());
		//SPPEManager.toggle(m_ppeDebug, !m_ppeDebug.isActive());
		//SCameraOverlaysManager.getInstance().activate(m_coDebug);
		//SCameraOverlaysManager.getInstance().activate(m_coDebugTimed);
	}
	
	override void OnInventoryMenuClose() {
		super.OnInventoryMenuClose();
		//SPPEManager.toggle(m_ppeDebugAnimation, !m_ppeDebugAnimation.isActive());
		//m_ppeDebug.setVignetteIntensity(1);
		//SPPEManager.toggle(m_ppeDebug, !m_ppeDebug.isActive());
		
		
		//SCameraOverlaysManager.getInstance().deactivate(m_coDebug);
	}
	
	override void OnJumpStart() {		
		super.OnJumpStart();
		
		if (GetGame().IsServer()) {
			SLog.d("onJumpStart()");
					
			SUserConfigConstraints.getInstance().syncWithEverybody();
			
			
			//GetGame().RPC(null, sUDE_RPC.SYNC_USER_CONFIG_CONSTRAINTS, toSync, true, null);
			
			if (false) {
				GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",100);
				GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",30);
				GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",25);
				GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",10);
				
				GetGame().CreateObject("MotoHelmet_Red",GetPosition()).SetHealth("","",100);
				GetGame().CreateObject("MotoHelmet_Red",GetPosition()).SetHealth("","",40);
				GetGame().CreateObject("MotoHelmet_Red",GetPosition()).SetHealth("","",25);
				GetGame().CreateObject("MotoHelmet_Red",GetPosition()).SetHealth("","",10);
				
			}
		}
		
	}
	*/
	//////////////////////////////////////////////////////////////////// END OF DEBUGGING ////////////////////////////////////////////////////////////////////

	
	

}
