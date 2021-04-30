modded class MissionGameplay{
	
	void MissionGameplay() {
		PPEManager.onInit();
		
		//@todo load only enabled modules from config.cpp
		SUserConfigVisual userVisualCfg = SUserConfig.getInstance().visual();
		HeadBobParams.multiplier = userVisualCfg.getHeadbobIntensity();
		HeadLeanParams.leanAngle = userVisualCfg.getHeadLeanAngle();
		PPEManager.setDDOFBlurStrength(userVisualCfg.getDDOFIntensity());
		PPEManager.setMotionBlurStrength(userVisualCfg.getMotionBlurIntensity());
		PPEManager.setBloomStrength(userVisualCfg.getBloomIntensity());
		
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