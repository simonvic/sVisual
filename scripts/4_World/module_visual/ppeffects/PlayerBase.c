modded class PlayerBase{
	
	protected ref PPEHitReceivedAnimation m_ppeHitAnim = new PPEHitReceivedAnimation(PPEConstants.HIT_RECEIVED_MIN_DURATION, true); //Used when being hit
	protected ref PPEEyegearPreset m_ppeEye = new PPEEyegearPreset();                            //Used when wearing AviatorGlasses
	protected ref PPEBleedingAnimation m_ppeBleeding = new PPEBleedingAnimation();               //Used when bleeding
	protected ref PPEUnconsciousAnimation m_ppeUnconscious = new PPEUnconsciousAnimation();    //Used when going uncoscious
	
	protected ref SCOAnimationBleeding m_coBleeding = new SCOAnimationBleeding();
	protected ref SCOTimedSpawn m_coSpawn = new SCOTimedSpawn();
	
	//Debug
/*	
	//protected ref PPEDebugAnimation m_ppeDebug = new PPEDebugAnimation();
	//protected ref SCOAnimationDebug m_coDebug = new SCOAnimationDebug();
	//protected ref SCOTimedDebug m_coDebugTimed = new SCOTimedDebug();
	
	
	override void OnInventoryMenuOpen(){
		super.OnInventoryMenuOpen();
		//PPEManager.toggle(m_ppeDebug, !m_ppeDebug.isActive());
		//SCameraOverlaysManager.getInstance().activate(m_coDebug);
		//SCameraOverlaysManager.getInstance().activate(m_coDebugTimed);
	}
	
	override void OnInventoryMenuClose(){
		super.OnInventoryMenuClose();
		//PPEManager.deactivate(m_ppeDebug);
		//SCameraOverlaysManager.getInstance().deactivate(m_coDebug);
	}
	
	override void OnJumpStart(){		
		super.OnJumpStart();
		
		if(GetGame().IsServer()){
			//GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",100);
			//GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",30);
			//GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",25);
			//GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",10);
		}
		
	}
	
*/
	
	override void EEItemAttached(EntityAI item, string slot_name){
		super.EEItemAttached(item, slot_name);
		if( GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) return;
		
		// Apply colored overlay when wearing AviatorGlasses
		if( slot_name == "Eyewear" && AviatorGlasses.Cast(item)){
			PPEManager.activate(m_ppeEye);
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
			PPEManager.deactivate(m_ppeEye);
		}
		
		Clothing clothing = Clothing.Cast(item);
		if(clothing && clothing.hasOverlays()){
			SCameraOverlaysManager.getInstance().deactivate(clothing.getOverlayByCurrentHealth());
		}
	}
		
	override void OnPlayerRecievedHit(){
		super.OnPlayerRecievedHit();	
		playHitReceivedPPE();
	}
	
	protected void playHitReceivedPPE(){
		SLog.d("playHitReceivedPPE");
		if( GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) return;
		
		if(m_ppeHitAnim.isActive()){
			m_ppeHitAnim.setDuration(m_ppeHitAnim.getDuration() * PPEConstants.HIT_RECEIVED_DURATION_MULTIPLIER);
			m_ppeHitAnim.setHitStrength(m_ppeHitAnim.getHitStrength() * PPEConstants.HIT_RECEIVED_STRENGTH_MULTIPLIER);
		}else{
			m_ppeHitAnim.setDuration(PPEConstants.HIT_RECEIVED_MIN_DURATION);
			m_ppeHitAnim.setHitStrength(PPEConstants.HIT_RECEIVED_MIN_STRENGTH);
			
			PPEManager.activate(m_ppeHitAnim);
		}
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
			
		checkForBleedingPPE();
		checkForGlassesPPE();
		
		/////////////////////////
		// Overlays
		SCameraOverlaysManager.getInstance().deactivateAll();
		checkForClothingOverlays();
		playSpawnVisuals();
	}
	
	protected void playSpawnVisuals(){
		SCameraOverlaysManager.getInstance().activate(m_coSpawn);
	}
	
	protected void checkForBleedingPPE(){
		if(IsBleeding()){
			updateBleedingEffect();
			PPEManager.activate(m_ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	
	protected void checkForGlassesPPE(){
		if ( AviatorGlasses.Cast( GetInventory().FindAttachment(InventorySlots.EYEWEAR)) ){
			PPEManager.activate(m_ppeEye);
		}
	}	
	
	protected void checkForClothingOverlays(){
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
			PPEManager.activate(m_ppeBleeding);
			SCameraOverlaysManager.getInstance().activate(m_coBleeding);
		}
	}
	
	override void OnBleedingEnd(){
		super.OnBleedingEnd();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.deactivate(m_ppeBleeding);
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
			m_ppeBleeding.setBleedingBits(GetBleedingSourceCount());
			m_coBleeding.setBleedingBits(GetBleedingSourceCount());
		}
	}
	
}
