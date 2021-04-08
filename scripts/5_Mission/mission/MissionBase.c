modded class MissionBase{
	override void OnInit(){
		super.OnInit();
		loadUserConfig();
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