modded class BloodLoss {
	
	protected SPPERequester_BloodLoss m_ppeBleeding;
	protected ref SCOBleeding m_coBleeding;
	
	override void OnInit() {
		super.OnInit();
		if (!GetGame().IsDedicatedServer()) {
			Class.CastTo(m_ppeBleeding, PPERequesterBank.GetRequester(SPPERequester_BloodLoss));	
			m_coBleeding = new SCOBleeding();
		}
	}

	override void OnUpdateClient(PlayerBase player, float deltatime) {
		super.OnUpdateClient(player, deltatime);
		if (player.IsPlayerSelected() && player.IsBleeding()) {
			if (!m_ppeBleeding.isActive()) {
				m_ppeBleeding.activate();
			}
			if (!m_coBleeding.isActive()) {
				m_coBleeding.activate();
			}
			m_ppeBleeding.setSourcesCount(player.GetBleedingSourceCount());
			m_coBleeding.setSourcesCount(player.GetBleedingSourceCount());
		} else {
			if (m_ppeBleeding.isActive()) {
				m_ppeBleeding.deactivate();
			}
			if (m_coBleeding.isActive()) {
				m_coBleeding.deactivate();
			}
		}
	}
}