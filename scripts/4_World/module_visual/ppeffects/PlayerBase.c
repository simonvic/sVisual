modded class PlayerBase{
	
	protected ref PPESpawnEffect ppeSpawn = new PPESpawnEffect(5, true);                       //Used when spawning	
	protected ref PPEHitReceivedAnimation ppeHitAnim = new PPEHitReceivedAnimation(PPEConstants.HIT_RECEIVED_MIN_DURATION, true); //Used when being hit
	protected ref PPEEyegearPreset ppeEye = new PPEEyegearPreset();                            //Used when wearing AviatorGlasses
	protected ref PPEBleedingAnimation ppeBleeding = new PPEBleedingAnimation();               //Used when bleeding
	protected ref PPEUnconsciousAnimation m_ppeUnconscious = new PPEUnconsciousAnimation();    //Used when going uncoscious
	
	protected ref SCOBleedingAnimation m_coBleeding = new SCOBleedingAnimation();    //Used when bleeding
	
	//Debug
	protected ref PPEDebugAnimation ppeDebug = new PPEDebugAnimation();
	protected ref SCODebugAnimation m_coDebug = new SCODebugAnimation();
	protected ref SCODebugTimed m_coDebugTimed = new SCODebugTimed();
	
	override void OnInventoryMenuOpen(){
		super.OnInventoryMenuOpen();
		//PPEManager.toggle(ppeDebug, !ppeDebug.isActive());
		//SCameraOverlaysManager.getInstance().activate(m_coDebug);
		//SCameraOverlaysManager.getInstance().activate(m_coDebugTimed);
	}
	
	override void OnInventoryMenuClose(){
		super.OnInventoryMenuClose();
		//PPEManager.deactivate(ppeDebug);
		//SCameraOverlaysManager.getInstance().deactivate(m_coDebug);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name){
		super.EEItemAttached(item, slot_name);
		if( GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) return;
		
		// Apply colored overlay when wearing AviatorGlasses
		if( slot_name == "Eyewear" && AviatorGlasses.Cast(item)){
			PPEManager.activate(ppeEye);
		}

		Clothing clothing = Clothing.Cast(item);
		if(clothing && clothing.hasOverlays()){
			SCameraOverlaysManager.getInstance().activate(clothing.getOverlayByCurrentHealth());
		}
		
		
	}
	
	override void EEItemDetached(EntityAI item, string slot_name){
		super.EEItemDetached(item, slot_name);
		if( GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) return;
		
		// Remove colored overlay when removing AviatorGlasses
		if( slot_name == "Eyewear" && AviatorGlasses.Cast(item) ){
			PPEManager.deactivate(ppeEye);
		}
		
		Clothing clothing = Clothing.Cast(item);
		if(clothing && clothing.hasOverlays()){
			SCameraOverlaysManager.getInstance().deactivate(clothing.getOverlayByCurrentHealth());
		}
	}
		
	override void OnJumpStart(){		
		super.OnJumpStart();
		/*
		if(GetGame().IsServer()){
			GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",100);
			GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",30);
			GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",25);
			GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",10);
		}
		*/
	}
	
	override void SpawnDamageDealtEffect(){
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			if(ppeHitAnim.isActive()){
				ppeHitAnim.setDuration(ppeHitAnim.getDuration() * PPEConstants.HIT_RECEIVED_DURATION_MULTIPLIER);
				ppeHitAnim.setHitStrength(ppeHitAnim.getHitStrength() * PPEConstants.HIT_RECEIVED_STRENGTH_MULTIPLIER);
			}else{
				ppeHitAnim.setDuration(PPEConstants.HIT_RECEIVED_MIN_DURATION);
				ppeHitAnim.setHitStrength(PPEConstants.HIT_RECEIVED_MIN_STRENGTH);
				
				PPEManager.activate(ppeHitAnim);
			}
		}
		super.SpawnDamageDealtEffect();
		
	}
	
	override void OnSelectPlayer(){
		super.OnSelectPlayer();
	}
	
	override void OnPlayerLoaded(){
		super.OnPlayerLoaded();
		updateVisuals();
	}
	
	protected void updateVisuals(){
		//Proceed only if client
		if( GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) return;
			
		/////////////////////////
		// PPEffects
		PPEManager.deactivateAll();
		PPEManager.applyDefault();
			
		playSpawnPPE();
		checkForBleedingPPE();
		checkForGlassesPPE();
		
		/////////////////////////
		// Overlays
		SCameraOverlaysManager.getInstance().deactivateAll();
		checkForOverlays();
	}
	
	protected void playSpawnPPE(){
		PPEManager.activate(ppeSpawn);
	}
	
	protected void checkForBleedingPPE(){
		if(IsBleeding()){
			updateBleedingEffect();
			PPEManager.activate(ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	
	protected void checkForGlassesPPE(){
		if ( AviatorGlasses.Cast( GetInventory().FindAttachment(InventorySlots.EYEWEAR)) ){
			PPEManager.activate(ppeEye);
		}
	}	
	
	protected void checkForOverlays(){
		for ( int i=0; i<GetInventory().AttachmentCount(); i++ ){
			Clothing clothing = Clothing.Cast(GetInventory().GetAttachmentFromIndex( i ));
			if(clothing && clothing.hasOverlays()){
				SCameraOverlaysManager.getInstance().activate(clothing.getOverlayByCurrentHealth());
			}
		}
	}
	
	
	
	
	///////////////// UNCONSCIOUSNESS ///////////////////////////////
	override void OnUnconsciousStart(){
		super.OnUnconsciousStart();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.activate(m_ppeUnconscious);
			SCameraOverlaysManager.getInstance().hideAll();
		}
	}
	
	override void OnUnconsciousStop(int pCurrentCommandID){
		super.OnUnconsciousStop(pCurrentCommandID);
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.deactivate(m_ppeUnconscious);
			SCameraOverlaysManager.getInstance().showAll();
		}
	}
	
	
	///////////////// BLEEDING ///////////////////////////////
	override void OnBleedingBegin(){
		super.OnBleedingBegin();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.activate(ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	
	override void OnBleedingEnd(){
		super.OnBleedingEnd();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.deactivate(ppeBleeding);
			SCameraOverlaysManager.getInstance().deactivate(m_coBleeding);
		}
	}
	
	override void OnBleedingSourceAdded(){
		super.OnBleedingSourceAdded();
		updateBleedingEffect();
		
	}
	
	override void OnBleedingSourceRemoved(){
		super.OnBleedingSourceRemoved();
		updateBleedingEffect();
	}
	
	protected void updateBleedingEffect(){
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			ppeBleeding.setBleedingBits(GetBleedingSourceCount());
			m_coBleeding.setBleedingBits(GetBleedingSourceCount());
		}
	}
	
}
