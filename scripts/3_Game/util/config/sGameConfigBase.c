class SGameConfigBase{
			
	string getModulePath(){
		return SGameConfig.getCfgName() + " " + getModuleName();
	}
	
	string getModuleName(){
		return "";
	}
	
	bool getIsEnabled(){
		bool temp;
		SGameConfig.get(getModulePath() + " enabled", temp); //@todo add check if module is not present
		return temp;
	}
}