modded class MissionGameplay{
	
	void MissionGameplay() {	
		SUserConfigVisual userVisualCfg = SUserConfig.visual();
		PPEManager.setDDOFBlurStrength(userVisualCfg.getDDOFIntensity());
		PPEManager.setMotionBlurStrength(userVisualCfg.getMotionBlurIntensity());
		PPEManager.setBloomStrength(userVisualCfg.getBloomIntensity());
	}
	
	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);
		PPEManager.onUpdate(timeslice);
	}
	
}