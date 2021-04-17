modded class PPEffects{
	override static void SetVignette(float intensity, float R, float G, float B, float A){}
	
	override static void SetTunnelVignette(float value){}	
	
	override static void SetUnconsciousnessVignette(float value){}
	
	override static void SetVignetteEffectValue(int index, float intensity, float r, float g, float b, float a){}
	
	override static int RegisterVignetteEffect(){
		return 0;
	}
	
	override static void SetShockVignette(float value){}
		
	override static void SetMenuVignette(float value){}

	override static void ResetVignettes(){}
	
	override static void UpdateVignette(){}
}