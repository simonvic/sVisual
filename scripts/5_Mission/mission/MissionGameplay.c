modded class MissionGameplay{
	
	void MissionGameplay() {
		PPEManager.onInit();
		
		SUserConfigVisual userVisualCfg = SUserConfig.visual();
		
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