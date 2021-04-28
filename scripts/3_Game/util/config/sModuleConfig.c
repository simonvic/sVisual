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