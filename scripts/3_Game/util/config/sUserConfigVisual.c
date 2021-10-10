class SUserConfigVisual : SUserConfigBase{
		
	override string getPath(){
		return "$saves:\\sUDE\\config\\sVisual.json";
	}
	
	override string getDefaultPath(){
		return "$profile:\\sUDE\\config\\sVisual_default.json";
	}
	
	override void deserialize(string data, out string error){
		auto cfg = this;
		getSerializer().ReadFromString(cfg, data, error);
	}
	
	override string serialize(){
		string result;
		auto cfg = this;
		getSerializer().WriteToString(cfg, true, result);
		return result;
	}
	
	override string serializeDefault(){
		string result;
		auto cfg = new SUserConfigGunplay();
		getSerializer().WriteToString(cfg, true, result);
		return result;
	}
		
	///////////////////////////////////////
	// these go in json
	protected float ddofIntensity = 0.0;
	protected bool ddofEnabledIn3PP = false;
	protected bool ddofEnabledInVehicle = true;
	protected float headbobIntensity = 0.0;
	protected bool headbobEnabledIn3PP = false;
	protected float motionBlurIntensity = 0.0;
	protected float bloomIntensity = 0.0;
	protected float headLeanAngle = 0.0;
	///////////////////////////////////////
	
	
	override void registerOptions() {
		super.registerOptions();
		registerOption("ddofIntensity",        new SUserConfigOption<float>(ddofIntensity,        null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")));
		registerOption("ddofEnabledIn3PP",     new SUserConfigOption<bool>(ddofEnabledIn3PP,      null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_3PP", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")));
		registerOption("ddofEnabledInVehicle", new SUserConfigOption<bool>(ddofEnabledInVehicle,  null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_VEHICLE", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")));
		registerOption("headbobIntensity",     new SUserConfigOption<float>(headbobIntensity,     null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION")));
		registerOption("headbobEnabledIn3PP",  new SUserConfigOption<bool>(headbobEnabledIn3PP,   null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_SWITCH_3PP", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION")));
		registerOption("motionBlurIntensity",  new SUserConfigOption<float>(motionBlurIntensity,  null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR_DESCRIPTION")));
		registerOption("bloomIntensity",       new SUserConfigOption<float>(bloomIntensity,       null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM_DESCRIPTION")));
		registerOption("headLeanAngle",        new SUserConfigOption<float>(headLeanAngle,        null, new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL_DESCRIPTION")));
	}
	
	override void onRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.onRPC(sender, target, rpc_type, ctx);
		
		if (rpc_type == sVisual_RPC.SYNC_USER_CONFIG_CONSTRAINTS_VISUAL) {
			SUserConfigConstraints_Visual constraints;
			if (ctx.Read(constraints)) {
				applyConstraints(constraints);
			}
		}
	}
	
	override void applyConstraints(SUserConfigConstraintsBase constraints) {
		SUserConfigConstraints_Visual c = SUserConfigConstraints_Visual.Cast(constraints);
		if (!c) return;
		
		getOption("ddofIntensity").setConstraint(c.getDDOFIntensity());
		getOption("ddofEnabledIn3PP").setConstraint(c.getDDOFEnabledIn3PP());
		getOption("ddofEnabledInVehicle").setConstraint(c.getDDOFEnabledInVehicle());
		getOption("headbobIntensity").setConstraint(c.getHeadbobIntensity());
		getOption("headbobEnabledIn3PP").setConstraint(c.getHeadbobEnabledIn3PP());
		getOption("motionBlurIntensity").setConstraint(c.getMotionBlurIntensity());
		getOption("bloomIntensity").setConstraint(c.getBloomIntensity());
		getOption("headLeanAngle").setConstraint(c.getHeadLeanAngle());
	}
	
	float getDDOFIntensity(){
		return ddofIntensity;
	}
	
	void setDDOFIntensity(float intensity) {
		ddofIntensity = updateOptionValue("ddofIntensity", intensity);
	}
	
	bool isDDOFEnabledIn3PP(){
		return ddofEnabledIn3PP;
	}
	
	void setDDOFEnabledIn3PP(bool enabled){
		ddofEnabledIn3PP = updateOptionValue("ddofEnabledIn3PP", enabled);
	}
	
	bool isDDOFEnabledInVehicle(){
		return ddofEnabledInVehicle;
	}
	
	void setDDOFEnabledInVehicle(bool enabled){
		ddofEnabledInVehicle = updateOptionValue("ddofEnabledInVehicle", enabled);
	}
	
	float getHeadbobIntensity(){
		return headbobIntensity;
	}
	
	void setHeadbobIntensity(float intensity){
		headbobIntensity = updateOptionValue("headbobIntensity", intensity);
	}
	
	bool isHeadbobEnabledIn3pp(){
		return headbobEnabledIn3PP;
	}
	
	void setHeadbobEnabledIn3pp(bool enabled){
		headbobEnabledIn3PP = updateOptionValue("headbobEnabledIn3PP", enabled);
	}
	
	float getMotionBlurIntensity(){
		return motionBlurIntensity;
	}
	
	void setMotionBlurIntensity(float intensity){
		motionBlurIntensity = updateOptionValue("motionBlurIntensity", intensity);
	}
	
	float getBloomIntensity(){
		return bloomIntensity;
	}
	
	void setBloomIntensity(float intensity){
		bloomIntensity = updateOptionValue("bloomIntensity", intensity);
	}
	
	float getHeadLeanAngle(){
		return headLeanAngle;
	}
	
	void setHeadLeanAngle(float angle){
		headLeanAngle = updateOptionValue("headLeanAngle", angle);
	}
	
	
}