modded class MissionGameplay{
	
	void MissionGameplay() {
		PPEManager.onInit();
		
		//@todo load only enabled modules from config.cpp
		SUserConfigVisual userVisualCfg = SUserConfig.getInstance().visual();
		HeadBobParams.multiplier = userVisualCfg.headbobIntensity;
		HeadLeanParams.leanAngle = userVisualCfg.headLeanAngle;
		PPEManager.setDDOFBlurStrength(userVisualCfg.ddofIntensity);
		PPEManager.setMotionBlurStrength(userVisualCfg.motionBlurIntensity);
		PPEManager.setBloomStrength(userVisualCfg.bloomIntensity);
		
	}
	
	void ~MissionGameplay(){
		PPEManager.deactivateAll();
		PPEManager.applyDefault();
	}
	
	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);
		PPEManager.onUpdate(timeslice);
	}
}