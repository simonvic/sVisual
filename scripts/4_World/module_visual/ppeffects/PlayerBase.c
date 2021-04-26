modded class PlayerBase{
	
	protected ref PPETimedParams ppeSpawn = new PPETimedParams(5, true);                       //Used when spawning	
	protected ref PPEHitReceivedAnimation ppeHitAnim = new PPEHitReceivedAnimation(4.5, true); //Used when being hit
	protected ref PPEEyegearPreset ppeEye = new PPEEyegearPreset();                            //Used when wearing AviatorGlasses
	protected ref PPEBleedingAnimation ppeBleeding = new PPEBleedingAnimation();               //Used when bleeding
	protected ref PPEUnconsciousAnimation m_ppeUnconscious = new PPEUnconsciousAnimation();    //Used when going uncoscious
	
	//Debug
	protected ref PPEAnimatedParams ppeDebug = new PPEDebugAnimation();
	
	override void OnInventoryMenuOpen(){
		super.OnInventoryMenuOpen();
		//PPEManager.activate(ppeDebug);	
	}
	
	override void OnInventoryMenuClose(){
		super.OnInventoryMenuClose();
		//PPEManager.deactivate(ppeDebug);	
	}
	
	override void EEItemAttached(EntityAI item, string slot_name){
		super.EEItemAttached(item, slot_name);
		
		//@todo quick fix for main menu eyewear
		// Apply colored overlay when wearing AviatorGlasses
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && slot_name == "Eyewear" && AviatorGlasses.Cast(item)){
			PPEManager.activate(ppeEye);
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name){
		super.EEItemDetached(item, slot_name);
		
		// Remove colored overlay when removing AviatorGlasses
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && slot_name == "Eyewear" && AviatorGlasses.Cast(item)){		
			PPEManager.deactivate(ppeEye);
		}
	}
		
	override void OnJumpStart(){		
		super.OnJumpStart();
	}
	
	
	override void SpawnDamageDealtEffect(){
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			if(ppeHitAnim.isActive()){
				ppeHitAnim.setDuration(ppeHitAnim.getDuration() * 2);
				ppeHitAnim.setHitStrength(ppeHitAnim.getHitStrength() * 1.5);
			}else{
				ppeHitAnim.setDuration(4.5);
				ppeHitAnim.setHitStrength(1);
				
				PPEManager.activate(ppeHitAnim);
			}
		}
		super.SpawnDamageDealtEffect();
		
	}
			
	//@todo don't use on select player
	override void OnSelectPlayer(){
		super.OnSelectPlayer();
				
		//Proceed to only if client
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			
			//Remove all ppeffects
			PPEManager.deactivateAll();
			PPEManager.applyDefault();
			
			//@todo complete activation/deactivation on connection/disconnection	
			playSpawnPPE();		
			checkForGlassesPPE();
			checkForBleedingPPE();		
		}
	}
	
	protected void playSpawnPPE(){
		ppeSpawn.setVignette(20, PPEManager.getPPEColor(0,0,0,0));
		PPEManager.activate(ppeSpawn);
	}
	
	protected void checkForBleedingPPE(){
		if(IsBleeding()){
			updateBleedingEffect();
			PPEManager.activate(ppeBleeding);
		}
	}
	
	protected void checkForGlassesPPE(){
		if ( AviatorGlasses.Cast( GetInventory().FindAttachment(InventorySlots.EYEWEAR)) ){
			PPEManager.activate(ppeEye);
		}
	}	
	
	
	
	
	///////////////// UNCONSCIOUSNESS ///////////////////////////////
	override void OnUnconsciousStart(){
		super.OnUnconsciousStart();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.activate(m_ppeUnconscious);
		}
	}
	
	override void OnUnconsciousStop(int pCurrentCommandID){
		super.OnUnconsciousStop(pCurrentCommandID);
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.deactivate(m_ppeUnconscious);
		}
	}
	
	
	///////////////// BLEEDING ///////////////////////////////
	override void OnBleedingBegin(){
		super.OnBleedingBegin();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.activate(ppeBleeding);
		}
	}
	
	override void OnBleedingEnd(){
		super.OnBleedingEnd();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			PPEManager.deactivate(ppeBleeding);
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
		}
	}
	
}
