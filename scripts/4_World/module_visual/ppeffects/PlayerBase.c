modded class PlayerBase{
	
	protected ref PPESpawnEffect ppeSpawn = new PPESpawnEffect(5, true);                       //Used when spawning	
	protected ref PPEHitReceivedAnimation ppeHitAnim = new PPEHitReceivedAnimation(PPEConstants.HIT_RECEIVED_MIN_DURATION, true); //Used when being hit
	protected ref PPEEyegearPreset ppeEye = new PPEEyegearPreset();                            //Used when wearing AviatorGlasses
	protected ref PPEBleedingAnimation ppeBleeding = new PPEBleedingAnimation();               //Used when bleeding
	protected ref PPEUnconsciousAnimation m_ppeUnconscious = new PPEUnconsciousAnimation();    //Used when going uncoscious
	
	//Debug
	protected ref PPEAnimatedParams ppeDebug = new PPEDebugAnimation();
	
	override void OnInventoryMenuOpen(){
		super.OnInventoryMenuOpen();
		//PPEManager.toggle(ppeDebug, !ppeDebug.isActive());
	}
	
	override void OnInventoryMenuClose(){
		super.OnInventoryMenuClose();
		//PPEManager.deactivate(ppeDebug);
		array<string> temp = {
			"set:sUDE_clothing_overlays image:pristine",
			"set:sUDE_clothing_overlays image:worn",
			"set:sUDE_clothing_overlays image:damaged",
			"set:sUDE_clothing_overlays image:badly_damaged"
		};
		//SClothingOverlaysManager.getInstance().removeAll();
	}
	
	override void EEItemAttached(EntityAI item, string slot_name){
		super.EEItemAttached(item, slot_name);
		
		// Apply colored overlay when wearing AviatorGlasses
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && slot_name == "Eyewear" && AviatorGlasses.Cast(item)){
			PPEManager.activate(ppeEye);
		}

		if(Clothing.Cast(item)){
			SClothingOverlaysManager.getInstance().add(Clothing.Cast(item).getCurrentHealthOverlay());
		}
		
		
	}
	
	override void EEItemDetached(EntityAI item, string slot_name){
		super.EEItemDetached(item, slot_name);
		
		// Remove colored overlay when removing AviatorGlasses
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && slot_name == "Eyewear" && AviatorGlasses.Cast(item)){		
			PPEManager.deactivate(ppeEye);
		}
		
		if(Clothing.Cast(item)){
			SClothingOverlaysManager.getInstance().remove(Clothing.Cast(item).getCurrentHealthOverlay());
		}
	}
		
	override void OnJumpStart(){		
		super.OnJumpStart();
		map<string, ref ImageWidget> temp = SClothingOverlaysManager.getInstance().getActiveOverlayWidgets();
		foreach(string image, auto widg : temp){
			widg.SetAlpha(widg.GetAlpha() + 0.1);
		}
		/*
		GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",100);
		GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",30);
		GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",25);
		GetGame().CreateObject("AviatorGlasses",GetPosition()).SetHealth("","",10);
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
				
		//Proceed only if client
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ){
			
			//Remove all ppeffects
			PPEManager.deactivateAll();
			PPEManager.applyDefault();
			
			playSpawnPPE();		
			checkForGlassesPPE();
			checkForBleedingPPE();		
		}
	}
	
	protected void playSpawnPPE(){
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
