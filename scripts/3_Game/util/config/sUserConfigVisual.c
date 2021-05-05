class SUserConfigVisual : SUserModuleConfig{
		
	override string getPath(){
		return "$saves:\\sUDE\\config\\sVisual.json";
	}
	
	override string getDefaultPath(){
		return "$profile:\\sUDE\\config\\sVisual_default.json";
	}
	
	///////////////////////////////////////
	// these go in json
	protected float ddofIntensity = 20.0;
	protected bool ddofEnabledIn3PP = false;
	protected bool ddofEnabledInVehicle = true;
	protected float headbobIntensity = 1.0;
	protected bool headbobEnabledIn3PP = false;
	protected float motionBlurIntensity = 0.01;
	protected float bloomIntensity = 0;
	protected float headLeanAngle = 15;
	///////////////////////////////////////

	float getDDOFIntensity(){
		return ddofIntensity;
	}
	
	void setDDOFIntensity(float intensity){
		ddofIntensity = intensity;
	}
	
	bool isDDOFEnabledIn3PP(){
		return ddofEnabledIn3PP;
	}
	
	void setDDOFEnabledIn3PP(bool enabled){
		ddofEnabledIn3PP = enabled;
	}
	
	bool isDDOFEnabledInVehicle(){
		return ddofEnabledInVehicle;
	}
	
	void setDDOFEnabledInVehicle(bool enabled){
		ddofEnabledInVehicle = enabled;
	}
	
	float getHeadbobIntensity(){
		return headbobIntensity;
	}
	
	void setHeadbobIntensity(float intensity){
		headbobIntensity = intensity;
	}
	
	bool isHeadbobEnabledIn3pp(){
		return headbobEnabledIn3PP;
	}
	
	void setHeadbobEnabledIn3pp(bool enabled){
		headbobEnabledIn3PP = enabled;
	}
	
	float getMotionBlurIntensity(){
		return motionBlurIntensity;
	}
	
	void setMotionBlurIntensity(float intensity){
		motionBlurIntensity = intensity;
	}
	
	float getBloomIntensity(){
		return bloomIntensity;
	}
	
	void setBloomIntensity(float intensity){
		bloomIntensity = intensity;
	}
	
	float getHeadLeanAngle(){
		return headLeanAngle;
	}
	
	void setHeadLeanAngle(float angle){
		headLeanAngle = angle;
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
		SFileHelper.touch(getPath());
		json.JsonSaveFile(getPath(), this);
	}
	
	void createDefault(JsonFileLoader<SUserConfigVisual> json){
		SFileHelper.touch(getDefaultPath());
		json.JsonSaveFile(getDefaultPath(), this);
	}
}