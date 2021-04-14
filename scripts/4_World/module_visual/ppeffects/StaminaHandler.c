modded class StaminaHandler{
	
	protected ref PPEExhaustedAnimation ppeExhaustAnim = new PPEExhaustedAnimation();
		
	override protected void CheckStaminaState(){
		super.CheckStaminaState();
		ppeExhaustAnim.setStamina(getStaminaPercentage());
		if(ppeShouldActivate()){
			PPEManager.activate(ppeExhaustAnim);
		}		
		
		if(ppeShouldDeactivate()){
			PPEManager.deactivate(ppeExhaustAnim);
		}
	}
	
	protected bool ppeShouldActivate(){
		return ( getStaminaPercentage() <= PPEConstants.EXHAUSTED_DEACTIVATION_TRESHOLD && !ppeExhaustAnim.isActive();
	}
	
	protected bool ppeShouldDeactivate(){
		return ( getStaminaPercentage() > PPEConstants.EXHAUSTED_DEACTIVATION_TRESHOLD);
	}
	
	private float getStaminaPercentage(){
		//to-do use m_StaminaSynced
		return (m_Stamina * 100 / m_StaminaCap);
	}
}