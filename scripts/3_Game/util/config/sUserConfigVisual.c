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
		registerOption("ddofIntensity",        new SUCOption_DDOFIntensity(ddofIntensity));
		registerOption("ddofEnabledIn3PP",     new SUCOption_DDOFSwitch3PP(ddofEnabledIn3PP));
		registerOption("ddofEnabledInVehicle", new SUCOption_DDOFSwitchVehicle(ddofEnabledInVehicle));
		registerOption("headbobIntensity",     new SUCOption_HeadbobIntensity(headbobIntensity));
		registerOption("headbobEnabledIn3PP",  new SUCOption_HeadbobSwitch3PP(headbobEnabledIn3PP));
		registerOption("motionBlurIntensity",  new SUCOption_MotionBlurIntensity(motionBlurIntensity));
		registerOption("bloomIntensity",       new SUCOption_BloomIntensity(bloomIntensity));
		registerOption("headLeanAngle",        new SUCOption_HeadleanAngle(headLeanAngle));
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
	
	float getDDOFIntensity() {
		return ddofIntensity;
	}
	
	void setDDOFIntensity(float intensity) {
		ddofIntensity = intensity;
	}
	
	bool isDDOFEnabledIn3PP() {
		return ddofEnabledIn3PP;
	}
	
	void setDDOFEnabledIn3PP(bool enabled) {
		ddofEnabledIn3PP = enabled;
	}
	
	bool isDDOFEnabledInVehicle() {
		return ddofEnabledInVehicle;
	}
	
	void setDDOFEnabledInVehicle(bool enabled) {
		ddofEnabledInVehicle = enabled;
	}
	
	float getHeadbobIntensity() {
		return headbobIntensity;
	}
	
	void setHeadbobIntensity(float intensity) {
		headbobIntensity = intensity;
	}
	
	bool isHeadbobEnabledIn3pp() {
		return headbobEnabledIn3PP;
	}
	
	void setHeadbobEnabledIn3pp(bool enabled) {
		headbobEnabledIn3PP = enabled;
	}
	
	float getMotionBlurIntensity() {
		return motionBlurIntensity;
	}
	
	void setMotionBlurIntensity(float intensity) {
		motionBlurIntensity = intensity;
	}
	
	float getBloomIntensity() {
		return bloomIntensity;
	}
	
	void setBloomIntensity(float intensity) {
		bloomIntensity = intensity;
	}
	
	float getHeadLeanAngle() {
		return headLeanAngle;
	}
	
	void setHeadLeanAngle(float angle) {
		headLeanAngle = angle;
	}
	
	
}