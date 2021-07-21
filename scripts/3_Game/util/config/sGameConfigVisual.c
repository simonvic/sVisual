typedef array<string> TClothingOverlaysList;

/////////////////////////////////////////////
// Visual Module
/////////////////////////////////////////////
class SGameConfigVisual : SGameConfigBase{
	
	override string getModuleName(){
		return "Visual";
	}
	
	float getDefaultPPEFloat(string ppeName){
		return SGameConfig.getFloat(getModulePath() + " PPEffects DefaultValues " + ppeName);
	}
	
	TPPEColor getDefaultPPEColor(string ppeName){
		TFloatArray c = SGameConfig.getfloatArray(getModulePath() + " PPEffects DefaultValues " + ppeName);
		return PPEManager.getPPEColor(c[0], c[1], c[2], c[3]);
	}
	
	TClothingOverlaysList getOverlaysList(typename type){
		return SGameConfig.getStringArray("cfgVehicles " + type + " sUDE clothingOverlays");
	}
	
}