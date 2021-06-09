modded class StaminaHandler{
	
	protected ref PPEExhaustedAnimation ppeExhaustAnim = new PPEExhaustedAnimation();
	
	override protected void CheckStaminaState(){
		super.CheckStaminaState();
		
		//if(GetGame().IsServer()) return;
		
		ppeExhaustAnim.setStamina(getStaminaPercentage());
		if(ppeShouldActivate()){
			PPEManager.activate(ppeExhaustAnim);
		}		
		
		if(ppeShouldDeactivate()){
			PPEManager.deactivate(ppeExhaustAnim);
		}
	}
	
	protected bool ppeShouldActivate(){
		return !ppeExhaustAnim.isActive() && m_StaminaDepleted;
	}
	
	protected bool ppeShouldDeactivate(){
		return ppeExhaustAnim.isActive() && (getStaminaPercentage() >= PPEConstants.EXHAUSTED_DEACTIVATION_TRESHOLD);
	}
	
	private float getStaminaPercentage(){
		return (m_Stamina * 100 / m_StaminaCap);
	}
}