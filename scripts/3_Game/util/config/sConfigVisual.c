/////////////////////////////////////////////
// Visual Module
/////////////////////////////////////////////
class SConfigVisual : SModuleConfig{
	
	override string getModuleName(){
		return "Visual";
	}
	
	float getDefaultPPEFloat(string ppeName){
		float temp;
		SConfig.get(getModulePath() + " PPEffects DefaultValues " + ppeName, temp);
		return temp;
	}
	
	TPPEColor getDefaultPPEColor(string ppeName){
		TFloatArray c = new TFloatArray;
		SConfig.get(getModulePath() + " PPEffects DefaultValues " + ppeName, c);
		return PPEManager.getPPEColor(c[0], c[1], c[2], c[3]);
	}
	
}