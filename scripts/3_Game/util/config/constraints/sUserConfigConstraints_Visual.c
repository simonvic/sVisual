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
	protected ref SConstraintRange  ddofIntensity        = new SConstraintRange(0, 30, 0.5);
	protected ref SConstraintSwitch ddofEnabledIn3PP     = new SConstraintSwitch(false);
	protected ref SConstraintSwitch ddofEnabledInVehicle = new SConstraintSwitch(true);
	protected ref SConstraintRange  headbobIntensity     = new SConstraintRange(0, 5, 0.05);
	protected ref SConstraintSwitch headbobEnabledIn3PP  = new SConstraintSwitch(true);
	protected ref SConstraintRange  motionBlurIntensity  = new SConstraintRange(0, 0.2, 0.005);
	protected ref SConstraintRange  bloomIntensity       = new SConstraintRange(0, 5, 0.1);
	protected ref SConstraintRange  headLeanAngle        = new SConstraintRange(0, 45, 1);
	///////////////////////////////////////
	
	SConstraintRange getDDOFIntensity() {
		return ddofIntensity;
	}
	
	SConstraintSwitch getDDOFEnabledIn3PP() {
		return ddofEnabledIn3PP;
	}
	
	SConstraintSwitch getDDOFEnabledInVehicle() {
		return ddofEnabledInVehicle;
	}
	
	SConstraintRange getHeadbobIntensity() {
		return headbobIntensity;
	}
	
	SConstraintSwitch getHeadbobEnabledIn3PP() {
		return headbobEnabledIn3PP;
	}
		
	SConstraintRange getMotionBlurIntensity() {
		return motionBlurIntensity;
	}	
	
	SConstraintRange getBloomIntensity() {
		return bloomIntensity;
	}
	
	SConstraintRange getHeadLeanAngle() {
		return headLeanAngle;
	}
		
}