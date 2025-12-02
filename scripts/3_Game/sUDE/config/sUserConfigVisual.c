class SUserConfigVisual : SUserConfigBase {
		
	override string getPath() {
		return "$saves:\\sUDE\\config\\sVisual.json";
	}
	
	override bool deserialize(string data, out string error) {
		auto thiz = this;
		return getSerializer().ReadFromString(thiz, data, error);
	}

	override bool serialize(out string result) {
		auto thiz = this;
		return getSerializer().WriteToString(thiz, true, result);
	}
		
	///////////////////////////////////////
	// these go in json
	protected float effectsIntensity = 1.0;
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
		registerOption("effectsIntensity",     new SUCOption_EffectsIntensity(effectsIntensity));
		registerOption("ddofIntensity",        new SUCOption_DDOFIntensity(ddofIntensity));
		registerOption("ddofEnabledIn3PP",     new SUCOption_DDOFSwitch3PP(ddofEnabledIn3PP));
		registerOption("ddofEnabledInVehicle", new SUCOption_DDOFSwitchVehicle(ddofEnabledInVehicle));
		registerOption("headbobIntensity",     new SUCOption_HeadbobIntensity(headbobIntensity));
		registerOption("headbobEnabledIn3PP",  new SUCOption_HeadbobSwitch3PP(headbobEnabledIn3PP));
		registerOption("motionBlurIntensity",  new SUCOption_MotionBlurIntensity(motionBlurIntensity));
		registerOption("bloomIntensity",       new SUCOption_BloomIntensity(bloomIntensity));
		registerOption("headLeanAngle",        new SUCOption_HeadleanAngle(headLeanAngle));
	}
	
	override void applyConstraints(SUserConfigConstraintsBase constraints) {
		SUserConfigConstraints_Visual c = SUserConfigConstraints_Visual.Cast(constraints);
		if (!c) return;
		
		getOption("effectsIntensity").setConstraint(c.getEffectsIntensity());
		getOption("ddofIntensity").setConstraint(c.getDDOFIntensity());
		getOption("ddofEnabledIn3PP").setConstraint(c.getDDOFEnabledIn3PP());
		getOption("ddofEnabledInVehicle").setConstraint(c.getDDOFEnabledInVehicle());
		getOption("headbobIntensity").setConstraint(c.getHeadbobIntensity());
		getOption("headbobEnabledIn3PP").setConstraint(c.getHeadbobEnabledIn3PP());
		getOption("motionBlurIntensity").setConstraint(c.getMotionBlurIntensity());
		getOption("bloomIntensity").setConstraint(c.getBloomIntensity());
		getOption("headLeanAngle").setConstraint(c.getHeadLeanAngle());
	}
	
	float getEffectsIntensity() {
		return effectsIntensity;
	}
	
	void setEffectsIntensity(float intensity) {
		effectsIntensity = intensity;
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
