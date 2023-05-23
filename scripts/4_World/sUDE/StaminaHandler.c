modded class StaminaHandler {
	
	protected SPPERequester_ExhaustedAnimation m_ppeExhaustAnim;
	
	void StaminaHandler(PlayerBase player) {
		Class.CastTo(m_ppeExhaustAnim, PPERequesterBank.GetRequester(SPPERequester_ExhaustedAnimation));
	}
	
	override void CheckStaminaState() {
		super.CheckStaminaState();
		if (m_Player.GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT) return;
		
		m_ppeExhaustAnim.setStamina(getStaminaPercentage());
		if (ppeShouldActivate()) {
			m_ppeExhaustAnim.activate();
		}
	}
	
	protected bool ppeShouldActivate() {
		return !m_ppeExhaustAnim.isActive() && m_StaminaDepleted;
	}
	
	private float getStaminaPercentage() {
		return m_Stamina * 100 / m_StaminaCap;
	}
}