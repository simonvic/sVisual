modded class MissionGameplay{
	
	void MissionGameplay() {
		PPEManager.onInit();
		loadUserConfig();
	}
	
	void ~MissionGameplay(){
		PPEManager.deactivateAll();
		PPEManager.applyDefault();
	}
	
	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);
		PPEManager.onUpdate(timeslice);
	}
	
	protected void loadUserConfig(){
		SUserConfig userCfg = SUserConfig.load();
		HeadBobParams.multiplier = userCfg.module_visual.headbobIntensity;
		HeadLeanParams.leanAngle = userCfg.module_visual.headLeanAngle;
		PPEManager.setDDOFBlurStrength(userCfg.module_visual.ddofIntensity);
		PPEManager.setMotionBlurStrength(userCfg.module_visual.motionBlurIntensity);
		PPEManager.setBloomStrength(userCfg.module_visual.bloomIntensity);
	}
}