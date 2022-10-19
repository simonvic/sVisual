modded class StaminaHandler {
	
	protected ref PPEExhaustedAnimation ppeExhaustAnim;
	
	void StaminaHandler(PlayerBase player) {
		if (GetGame().IsClient()) {
			ppeExhaustAnim = new PPEExhaustedAnimation();
		}
	}
	
	override void CheckStaminaState() {
		super.CheckStaminaState();
		if (m_Player.GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		ppeExhaustAnim.setStamina(getStaminaPercentage());
		if (ppeShouldActivate()) {
			SPPEManager.activate(ppeExhaustAnim);
		}		
		
		if (ppeShouldDeactivate()) {
			SPPEManager.deactivate(ppeExhaustAnim);
		}
	}
	
	protected bool ppeShouldActivate() {
		return !ppeExhaustAnim.isActive() && m_StaminaDepleted;
	}
	
	protected bool ppeShouldDeactivate() {
		return ppeExhaustAnim.isActive() && (getStaminaPercentage() >= SPPEConstants.EXHAUSTED_DEACTIVATION_TRESHOLD);
	}
	
	private float getStaminaPercentage() {
		return m_Stamina * 100 / m_StaminaCap;
	}
}