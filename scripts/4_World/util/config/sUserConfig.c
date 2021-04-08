class SUserConfig{
	
	static const string USER_CONFIG_PATH = "$saves:\\sVisual\\config\\config.json";
	static const string USER_CONFIG_PATH_DEBUG = "$saves:\\sVisual\\config\\config_debug.json";
	static const string DEFAULT_USER_CONFIG_PATH = "$saves:\\sVisual\\config\\default.json";
	
	private static ref JsonFileLoader<SUserConfig> jsonLoader = new JsonFileLoader<SUserConfig>();
	
	SUserConfigBaseBuilding module_baseBuilding;
	SUserConfigCaves module_caves;
	SUserConfigCharacter module_character;
	SUserConfigDriving module_driving;
	SUserConfigInventory module_inventory;
	SUserConfigLooting module_looting;
	SUserConfigMedical module_medical;
	SUserConfigPvP module_pvp;
	SUserConfigSoftSkills module_softSkills;
	SUserConfigSurvival module_survival;
	SUserConfigVisual module_visual;
	
	/**
	*	@brief Get a copy of user configuration file
	*	 @return SUserConfig
	*/
	static SUserConfig load(){
		// Check if it's ok to load the config
		if(!FileExist(USER_CONFIG_PATH) || !isValid(USER_CONFIG_PATH)){
			SFileHelper.touch(USER_CONFIG_PATH);
			if(FileExist(DEFAULT_USER_CONFIG_PATH) && isValid(DEFAULT_USER_CONFIG_PATH)){
				CopyFile(DEFAULT_USER_CONFIG_PATH, USER_CONFIG_PATH);
			}else{
				SLog.c("Couldn't load neither user config [ " + USER_CONFIG_PATH + " ] nor default config [ " + DEFAULT_USER_CONFIG_PATH + " ]");
				return null;
			}
		}

		// Load config
		SUserConfig config = new SUserConfig();
		jsonLoader.JsonLoadFile(USER_CONFIG_PATH, config);
		
		return config;
	}
	
	/**
	*	@brief Save the 
	*/
	void save(){
		jsonLoader.JsonSaveFile(USER_CONFIG_PATH, this);
	}
	
	/**
	*	@brief Check if the configuration file is isValid
	*	 @param path \p string - Path of file to validate
	*/
	static bool isValid(string path){
		return true; //to-do complete configuration file validation
	}

}

class SUserConfigBaseBuilding{}
class SUserConfigCaves{}
class SUserConfigCharacter{}
class SUserConfigDriving{}
class SUserConfigInventory{}
class SUserConfigLooting{}
class SUserConfigMedical{}
class SUserConfigPvP{}
class SUserConfigSoftSkills{}
class SUserConfigSurvival{}
class SUserConfigVisual{
	float ddofIntensity;
	float headbobIntensity;
	float motionBlurIntensity;
	float bloomIntensity;
	float headLeanAngle;
}
