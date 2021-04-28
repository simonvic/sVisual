class SModuleConfig{
			
	string getModulePath(){
		return SConfig.getCfgName() + " " + getModuleName();
	}
	
	string getModuleName(){
		return "";
	}
	
	bool getIsEnabled(){
		bool temp;
		SConfig.get(getModulePath() + " enabled", temp); //@todo add check if module is not present
		return temp;
	}
}


/////////////////////////////////////////////
// Base building Module
/////////////////////////////////////////////
class SConfigBaseBuilding : SModuleConfig{	
	override string getModuleName(){
		return "BaseBuilding";
	}
}

/////////////////////////////////////////////
// Caves Module
/////////////////////////////////////////////
class SConfigCaves : SModuleConfig{	
	override string getModuleName(){
		return "Caves";
	}
}

/////////////////////////////////////////////
// Character Module
/////////////////////////////////////////////
class SConfigCharacter : SModuleConfig{
	override string getModuleName(){
		return "Character";
	}
}

/////////////////////////////////////////////
// Driving Module
/////////////////////////////////////////////
class SConfigDriving : SModuleConfig{	
	override string getModuleName(){
		return "Driving";
	}
}

/////////////////////////////////////////////
// Inventory Module
/////////////////////////////////////////////
class SConfigInventory : SModuleConfig{
	override string getModuleName(){
		return "Inventory";
	}
}

/////////////////////////////////////////////
// Looting Module
/////////////////////////////////////////////
class SConfigLooting : SModuleConfig{
	override string getModuleName(){
		return "Looting";
	}
}

/////////////////////////////////////////////
// Medical Module
/////////////////////////////////////////////
class SConfigMedical : SModuleConfig{
	override string getModuleName(){
		return "Medical";
	}
}

/////////////////////////////////////////////
// Gunplay Module
/////////////////////////////////////////////
class SConfigGunplay : SModuleConfig{	
	override string getModuleName(){
		return "Gunplay";
	}
}

/////////////////////////////////////////////
// Soft Skills Module
/////////////////////////////////////////////
class SConfigSoftSkills : SModuleConfig{
	override string getModuleName(){
		return "SoftSkills";
	}
}

/////////////////////////////////////////////
// Survival Module
/////////////////////////////////////////////
class SConfigSurvival : SModuleConfig{
	override string getModuleName(){
		return "Survival";
	}
}


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
