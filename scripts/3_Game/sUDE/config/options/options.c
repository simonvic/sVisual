/**
*	@brief Overall intensity of the effects
*/
class SUCOption_EffectsIntensity : SUserConfigOption<float> {
		
	void SUCOption_EffectsIntensity(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_EFFECTS_INTENSITY", "#STR_SUDE_LAYOUT_OPTIONS_EFFECTS_INTENSITY_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setEffectsIntensity(newValue);
	}
}

/**
*	@brief Dynamic Depth of Field option
*/
class SUCOption_DDOFIntensity : SUserConfigOption<float> {
		
	void SUCOption_DDOFIntensity(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setDDOFIntensity(newValue);
		SPPEManager.setDDOFBlurStrength(newValue);
	}
}



/**
*	@brief Dynamic Depth of Field switch for third person camera option
*/
class SUCOption_DDOFSwitch3PP : SUserConfigOption<bool> {
	
	void SUCOption_DDOFSwitch3PP(bool value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_3PP", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")
		}
	}
	
	override void onValueChange(bool previousValue, bool newValue) {
		SUserConfig.visual().setDDOFEnabledIn3PP(newValue);
	}
}



/**
*	@brief Dynamic Depth of Field switch for vehicle camera option
*/
class SUCOption_DDOFSwitchVehicle : SUserConfigOption<bool> {
	
	void SUCOption_DDOFSwitchVehicle(bool value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_VEHICLE", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION")
		}
	}
	
	override void onValueChange(bool previousValue, bool newValue) {
		SUserConfig.visual().setDDOFEnabledInVehicle(newValue);
	}
}



/**
*	@brief Headbob intensity option
*/
class SUCOption_HeadbobIntensity : SUserConfigOption<float> {
	void SUCOption_HeadbobIntensity(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setHeadbobIntensity(newValue);
	}
}



/**
*	@brief Headbob switch for third person camera option
*/
class SUCOption_HeadbobSwitch3PP : SUserConfigOption<bool> {
	void SUCOption_HeadbobSwitch3PP(bool value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_SWITCH_3PP", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION")
		}
	}
	
	override void onValueChange(bool previousValue, bool newValue) {
		SUserConfig.visual().setHeadbobEnabledIn3pp(newValue);
	}
}



/**
*	@brief Motion blur intensity option
*/
class SUCOption_MotionBlurIntensity : SUserConfigOption<float> {
	
	void SUCOption_MotionBlurIntensity(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setMotionBlurIntensity(newValue);
		SPPEManager.setMotionBlurStrength(newValue);
	}
	
}



/**
*	@brief Bloom intensity option
*/
class SUCOption_BloomIntensity : SUserConfigOption<float> {
	
	void SUCOption_BloomIntensity(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setBloomIntensity(newValue);
		SPPEManager.setBloomStrength(newValue);
	}
	
}



/**
*	@brief Head lean angle option
*/
class SUCOption_HeadleanAngle : SUserConfigOption<float> {
	
	void SUCOption_HeadleanAngle(float value, SConstraintBase constraint = null, SUserConfigOptionInfo info = null) {
		if (!info) {
			m_info = new SUserConfigOptionInfo("#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL", "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL_DESCRIPTION")
		}
	}
	
	override void onValueChange(float previousValue, float newValue) {
		SUserConfig.visual().setHeadLeanAngle(newValue);
	}
}