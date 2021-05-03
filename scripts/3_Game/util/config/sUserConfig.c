typedef map<typename, ref SUserModuleConfig> TSUserModuleConfigs;

/*
*	@Singleton
*/
class SUserConfig{
	
	private static ref SUserConfig INSTANCE = new SUserConfig();
	private void SUserConfig(){}
	static SUserConfig getInstance(){
		return INSTANCE;
	}
	
	protected ref TSUserModuleConfigs modulesConfigs = new TSUserModuleConfigs;
		
	/**
	*	@brief Load a module config file
	*	 @param moduleType typename - Typename of the module to load
	*	 @param reload bool - Choose to load even if it's been already loaded
	*/
	void load(typename moduleType, bool reload = false){
		
		if(isModuleLoaded(moduleType) && !reload) return;
		
		//Check if correct typename
		SUserModuleConfig moduleCfg = SUserModuleConfig.Cast(moduleType.Spawn());
		if(!moduleCfg){
			SLog.e("Error while loading < " + moduleType + " > Maybe not a module type?. Ignoring....","SUserConfig::load");
			return;
		}

		SLog.i("Loading " + moduleType,"SUserConfig::load");
		validateModuleCfgFile(moduleCfg);
		
		// Load config
		moduleCfg.load();
		modulesConfigs.Set(moduleType, moduleCfg);
		SLog.i("Done","",1);
	}
	
	/**
	*	@brief Validate a module config file. Copy the default if not present; create default file if also not present
	*	 @param moduleCfg SUserModuleConfig - Module to validate
	*/
	protected void validateModuleCfgFile(SUserModuleConfig moduleCfg){
		string path = moduleCfg.getPath();
		
		if(!FileExist(path)){
			SFileHelper.touch(path);
			string defaultPath = moduleCfg.getDefaultPath();
			if(FileExist(defaultPath)){
				CopyFile(defaultPath, path);
			}else{
				SLog.w("Couldn't load neither user config [ " + path + " ] nor default config [ " + defaultPath + " ]", "SUserConfig");
				SLog.i("Creating " + moduleCfg.Type() + " default config file : " + defaultPath,"SUserConfig",1);
				SFileHelper.touch(defaultPath);
				moduleCfg.createDefault();
				SLog.i("Done","",2);
				SLog.i("Creating " + moduleCfg.Type() + " config file : " + path,"SUserConfig",1);
				moduleCfg.save();
				SLog.i("Done","",2);				
			}
		}
	}
	
	protected bool isModuleLoaded(typename module){
		return modulesConfigs.Contains(module);
	}
	
	/**
	*	@brief Save modules configuration
	*/
	void save(){
		foreach(SUserModuleConfig module : modulesConfigs){
			module.save();
		}
	}
	
	
	bool isValid(){
		foreach(SUserModuleConfig module : modulesConfigs){
			if(!module.isValid()) return false;
		}
		return true;
	}
	
	void printLoadedModules(){
		foreach(SUserModuleConfig module : modulesConfigs){
			SLog.d(module);
		}
	}
	
	
	
	
	
	
	SUserConfigVisual visual(bool reload = false){
		load(SUserConfigVisual, reload);
		return SUserConfigVisual.Cast(modulesConfigs.Get(SUserConfigVisual));
	}

}