class SUserConfigConstraints_Visual : SUserConfigConstraintsBase {

	override string getPath() {
		return "$profile:\\sUDE\\config\\sVisual_constraints.json";
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
	protected ref SConstraintPrimitiveMinMaxNumeric  effectsIntensity     = new SConstraintPrimitiveMinMaxNumeric(0, 2);
	protected ref SConstraintPrimitiveMinMaxNumeric  ddofIntensity        = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintSwitch                  ddofEnabledIn3PP     = new SConstraintSwitch(false);
	protected ref SConstraintSwitch                  ddofEnabledInVehicle = new SConstraintSwitch(true);
	protected ref SConstraintMinMaxArrayNumeric      headbobIntensity     = new SConstraintMinMaxArrayNumeric({0.0, 0.0, 0.0, 0.0}, {2.0, 2.0, 2.0, 2.0});
	protected ref SConstraintSwitch                  headbobEnabledIn3PP  = new SConstraintSwitch(true);
	protected ref SConstraintPrimitiveMinMaxNumeric  motionBlurIntensity  = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintPrimitiveMinMaxNumeric  bloomIntensity       = new SConstraintPrimitiveMinMaxNumeric(0, 1);
	protected ref SConstraintPrimitiveMinMaxNumeric  headLeanAngle        = new SConstraintPrimitiveMinMaxNumeric(0, 45);
	protected ref SConstraintSwitch                  showClothingOverlays = new SConstraintSwitch(true);
	protected ref SConstraintSwitch                  showBleedingOverlay  = new SConstraintSwitch(true);
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

	SConstraintMinMaxArrayNumeric getHeadbobIntensity() {
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

	SConstraintSwitch getShowClothingOverlays() {
		return showClothingOverlays;
	}

	SConstraintSwitch getShowBleedingOverlay() {
		return showBleedingOverlay;
	}

}
