modded class StaminaHandler{
	
	protected ref PPEExhaustedAnimation ppeExhaustAnim = new PPEExhaustedAnimation();
		
	override protected void CheckStaminaState(){
		super.CheckStaminaState();
		ppeExhaustAnim.setStamina(m_Stamina);
		if(ppeShouldActivate()){
			PPEManager.activate(ppeExhaustAnim);
		}
		
		if(ppeShouldDeactivate()){
			PPEManager.deactivate(ppeExhaustAnim);
		}
	}
	
	protected bool ppeShouldActivate(){
		return m_StaminaDepleted;
	}
	
	protected bool ppeShouldDeactivate(){
		//to-do use m_StaminaSynced
		return ((m_Stamina * GameConstants.STAMINA_MAX / m_StaminaCap)  > PPEConstants.EXHAUSTED_DEACTIVATION_TRESHOLD);
	}
}