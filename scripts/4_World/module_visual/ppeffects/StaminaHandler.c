modded class StaminaHandler{
	
	protected ref PPEExhaustedAnimation ppeExhaustAnim = new PPEExhaustedAnimation(6);
	
	override protected void CheckStaminaState(){
		super.CheckStaminaState();
		if(m_StaminaDepleted){
			ppeExhaustAnim.setDuration(6);
			PPEManager.activate(ppeExhaustAnim);
		}
	}
}