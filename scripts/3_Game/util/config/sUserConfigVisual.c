class SUserConfigVisual : SUserModuleConfig{
		
	///////////////////////////////////////
	// these go in json
	float ddofIntensity = 20.0;
	float headbobIntensity = 1.0;
	float motionBlurIntensity = 0.01;
	float bloomIntensity = 0;
	float headLeanAngle = 15;
	///////////////////////////////////////
	
	override string getPath(){
		return "$saves:\\sUDE\\config\\sVisual.json";
	}
	
	override string getDefaultPath(){
		return "$profile:\\sUDE\\config\\sVisual_default.json";
	}
	
	override bool isValid(){
		return true;
	}
	
	override void load(){
		JsonFileLoader<SUserConfigVisual> json = new JsonFileLoader<SUserConfigVisual>;
		load(json);
		delete json;
	}
	
	override void save(){
		JsonFileLoader<SUserConfigVisual> json = new JsonFileLoader<SUserConfigVisual>;
		save(json);
		delete json;
	}
	
	override void createDefault(){
		JsonFileLoader<SUserConfigVisual> json = new JsonFileLoader<SUserConfigVisual>;
		createDefault(json);
		delete json;
	}
	
	void load(JsonFileLoader<SUserConfigVisual> json){
		json.JsonLoadFile(getPath(), this);
	}
	
	void save(JsonFileLoader<SUserConfigVisual> json){
		json.JsonSaveFile(getPath(), this);
	}
	
	void createDefault(JsonFileLoader<SUserConfigVisual> json){
		json.JsonSaveFile(getDefaultPath(), this);
	}
}