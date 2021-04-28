class SUserConfig{
	
	static const string USER_CONFIG_PATH = "$saves:\\sVisual\\config\\config.json";
	static const string DEFAULT_USER_CONFIG_PATH = "$profile:\\sVisual\\config\\default.json";
	
	private static ref JsonFileLoader<SUserConfig> jsonLoader = new JsonFileLoader<SUserConfig>();
	
	ref SUserConfigBaseBuilding module_baseBuilding = new SUserConfigBaseBuilding;
	ref SUserConfigCaves module_caves               = new SUserConfigCaves;
	ref SUserConfigCharacter module_character       = new SUserConfigCharacter;
	ref SUserConfigDriving module_driving           = new SUserConfigDriving;
	ref SUserConfigInventory module_inventory       = new SUserConfigInventory;
	ref SUserConfigLooting module_looting           = new SUserConfigLooting;
	ref SUserConfigMedical module_medical           = new SUserConfigMedical;
	ref SUserConfigGunplay module_gunplay           = new SUserConfigGunplay;
	ref SUserConfigSoftSkills module_softSkills     = new SUserConfigSoftSkills;
	ref SUserConfigSurvival module_survival         = new SUserConfigSurvival;
	ref SUserConfigVisual module_visual             = new SUserConfigVisual;
	
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
				SLog.c("Couldn't load neither user config [ " + USER_CONFIG_PATH + " ] nor default config [ " + DEFAULT_USER_CONFIG_PATH + " ]", "SUserConfig");
				return createDefault(true);
			}
		}

		// Load config
		SUserConfig config = new SUserConfig();
		jsonLoader.JsonLoadFile(USER_CONFIG_PATH, config);
		
		return config;
	}
	
	/**
	*	@brief Save the configuration
	*/
	void save(){
		jsonLoader.JsonSaveFile(USER_CONFIG_PATH, this);
	}
	
	/**
	*	@brief Create the default configuration file
	*	 @param verbose \p bool - Be verbose with logs
	*/
	private static SUserConfig createDefault(bool verbose = false){
		SLog.i("Creating new default config file...", "SUserConfig", 1, verbose);
		SUserConfig newDefault = new SUserConfig();
		SFileHelper.touch(DEFAULT_USER_CONFIG_PATH);
		jsonLoader.JsonSaveFile(DEFAULT_USER_CONFIG_PATH, newDefault);
		SLog.i("Done", "", 2, verbose);
		
		SLog.i("Creating new config file...", "SUserConfig", 1, verbose);
		newDefault.save();
		SLog.i("Done", "", 2, verbose);
		
		return newDefault;
	}
	
	/**
	*	@brief Check if the configuration file is isValid
	*	 @param path \p string - Path of file to validate
	*/
	static bool isValid(string path){
		return true; //@todo complete configuration file validation
	}

}

class SUserConfigBaseBuilding{}
class SUserConfigCaves{}
class SUserConfigCharacter{}
class SUserConfigDriving{}
class SUserConfigInventory{}
class SUserConfigLooting{}
class SUserConfigMedical{}
class SUserConfigGunplay{}
class SUserConfigSoftSkills{}
class SUserConfigSurvival{}
class SUserConfigVisual{
	float ddofIntensity = 20.0;
	float headbobIntensity = 1.0;
	float motionBlurIntensity = 0.01;
	float bloomIntensity = 0;
	float headLeanAngle = 15;
}
