class SUserConfigConstraints_Visual : SUserConfigConstraintsBase {

	override string getPath() {
		return "$profile:\\sUDE\\config\\sVisual_constraints.json";
	}
	
	override void deserialize(string data, out string error) {
		auto constraints = this;
		getSerializer().ReadFromString(constraints, data, error);
	}
	
	override string serialize() {
		string result;
		auto constraints = this;
		getSerializer().WriteToString(constraints, true, result);
		return result;
	}
	
	
	///////////////////////////////////////
	// these go in json
	protected ref SConstraintPrimitiveMinMaxNumeric  effectsIntensity     = new SConstraintPrimitiveMinMaxNumeric(0, 2);
	protected ref SConstraintPrimitiveMinMaxNumeric  ddofIntensity        = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintSwitch                  ddofEnabledIn3PP     = new SConstraintSwitch(false);
	protected ref SConstraintSwitch                  ddofEnabledInVehicle = new SConstraintSwitch(true);
	protected ref SConstraintPrimitiveMinMaxNumeric  headbobIntensity     = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintSwitch                  headbobEnabledIn3PP  = new SConstraintSwitch(true);
	protected ref SConstraintPrimitiveMinMaxNumeric  motionBlurIntensity  = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintPrimitiveMinMaxNumeric  bloomIntensity       = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintPrimitiveMinMaxNumeric  headLeanAngle        = new SConstraintPrimitiveMinMaxNumeric(0, 45);
	///////////////////////////////////////
	
	SConstraintPrimitiveMinMaxNumeric getEffectsIntensity() {
		return effectsIntensity;
	}
	
	SConstraintPrimitiveMinMaxNumeric getDDOFIntensity() {
		return ddofIntensity;
	}
	
	SConstraintSwitch getDDOFEnabledIn3PP() {
		return ddofEnabledIn3PP;
	}
	
	SConstraintSwitch getDDOFEnabledInVehicle() {
		return ddofEnabledInVehicle;
	}
	
	SConstraintPrimitiveMinMaxNumeric getHeadbobIntensity() {
		return headbobIntensity;
	}
	
	SConstraintSwitch getHeadbobEnabledIn3PP() {
		return headbobEnabledIn3PP;
	}
		
	SConstraintPrimitiveMinMaxNumeric getMotionBlurIntensity() {
		return motionBlurIntensity;
	}	
	
	SConstraintPrimitiveMinMaxNumeric getBloomIntensity() {
		return bloomIntensity;
	}
	
	SConstraintPrimitiveMinMaxNumeric getHeadLeanAngle() {
		return headLeanAngle;
	}
		
}