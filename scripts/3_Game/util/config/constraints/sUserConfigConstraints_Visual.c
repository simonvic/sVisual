class SUserConfigConstraints_Visual : SUserConfigConstraintsBase {

	override string getPath() {
		return "$profile:\\sUDE\\config\\sVisual_constraints.json";
	}
	
	override void deserialize(string data, out string error){
		auto constraints = this;
		getSerializer().ReadFromString(constraints, data, error);
	}
	
	override string serialize(){
		string result;
		auto constraints = this;
		getSerializer().WriteToString(constraints, true, result);
		return result;
	}
	
	
	///////////////////////////////////////
	// these go in json
	protected ref SConstraintMinMaxNumeric  ddofIntensity        = new SConstraintMinMaxNumeric(0, 30);
	protected ref SConstraintSwitch         ddofEnabledIn3PP     = new SConstraintSwitch(false);
	protected ref SConstraintSwitch         ddofEnabledInVehicle = new SConstraintSwitch(true);
	protected ref SConstraintMinMaxNumeric  headbobIntensity     = new SConstraintMinMaxNumeric(0, 5);
	protected ref SConstraintSwitch         headbobEnabledIn3PP  = new SConstraintSwitch(true);
	protected ref SConstraintMinMaxNumeric  motionBlurIntensity  = new SConstraintMinMaxNumeric(0, 0.2);
	protected ref SConstraintMinMaxNumeric  bloomIntensity       = new SConstraintMinMaxNumeric(0, 5);
	protected ref SConstraintMinMaxNumeric  headLeanAngle        = new SConstraintMinMaxNumeric(0, 45);
	///////////////////////////////////////
	
	SConstraintMinMaxNumeric getDDOFIntensity() {
		return ddofIntensity;
	}
	
	SConstraintSwitch getDDOFEnabledIn3PP() {
		return ddofEnabledIn3PP;
	}
	
	SConstraintSwitch getDDOFEnabledInVehicle() {
		return ddofEnabledInVehicle;
	}
	
	SConstraintMinMaxNumeric getHeadbobIntensity() {
		return headbobIntensity;
	}
	
	SConstraintSwitch getHeadbobEnabledIn3PP() {
		return headbobEnabledIn3PP;
	}
		
	SConstraintMinMaxNumeric getMotionBlurIntensity() {
		return motionBlurIntensity;
	}	
	
	SConstraintMinMaxNumeric getBloomIntensity() {
		return bloomIntensity;
	}
	
	SConstraintMinMaxNumeric getHeadLeanAngle() {
		return headLeanAngle;
	}
		
}