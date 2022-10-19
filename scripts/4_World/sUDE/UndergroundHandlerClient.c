modded class UndergroundHandlerClient {
	
	protected static float UNDERGROUND_NVG_EFFICIENCY;
	
	void UndergroundHandlerClient(PlayerBase player) {
		UNDERGROUND_NVG_EFFICIENCY = SGameConfig.getFloat("Cfg_sUDE Visual NVG undergroundEfficiency");
	}
	
	override void ProcessEyeAcco(float timeSlice) {
		super.ProcessEyeAcco(timeSlice);
		m_NVRequester.setUndergroundAccomCoeff(Math.Max(m_EyeAcco, UNDERGROUND_NVG_EFFICIENCY));
	}
}