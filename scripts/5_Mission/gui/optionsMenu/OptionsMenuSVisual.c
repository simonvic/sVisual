class OptionsMenuSVisual : SOptionsMenuBase{
	
	override string getName(){
		return "sVisual";
	}
	
	override string getLayout(){
		return "MyMODS/sVisual/GUI/layouts/optionsMenu/sVisual_tab.layout";	
	}
	
	override string getInfoBoxRootContainer() {
		return "c_description_box_root";
	}
			
	protected ref SSliderWidget   m_headBobSlider;
	protected ref CheckBoxWidget  m_headbobSwitch3pp;	
	protected ref SSliderWidget   m_dofSlider;
	protected ref CheckBoxWidget  m_dofSwitch3PP;
	protected ref CheckBoxWidget  m_dofSwitchVehicle;	
	protected ref SSliderWidget   m_motionBlurSlider;
	protected ref SSliderWidget   m_bloomSlider;
	protected ref SSliderWidget   m_headLeanSlider;
	
	
	protected SUserConfigVisual m_sUserConfig;
	
	void OptionsMenuSVisual(){
		m_sUserConfig = SUserConfig.visual();
	}
	
	override void onBuild(){
		super.onBuild();
		
		m_sUserConfig.updateConstraints();
		
		initOption(m_headBobSlider, "sude_headbob_setting_", m_sUserConfig.getHeadbobIntensity(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION",
			m_sUserConfig.getConstraints().getHeadbobIntensity()));
		
		initOption(m_headbobSwitch3pp, "sude_headbob_switch_3pp_option", m_sUserConfig.isHeadbobEnabledIn3pp(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_SWITCH_3PP",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION",
			m_sUserConfig.getConstraints().getHeadbobEnabledIn3PP()));
		
		initOption(m_dofSlider, "sude_dof_setting_", m_sUserConfig.getDDOFIntensity(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION",
			m_sUserConfig.getConstraints().getDDOFIntensity()));
		
		initOption(m_dofSwitch3PP, "sude_dof_switch_3pp_option", m_sUserConfig.isDDOFEnabledIn3PP(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_3PP",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION",
			m_sUserConfig.getConstraints().getDDOFEnabledIn3PP()));
		
		initOption(m_dofSwitchVehicle, "sude_dof_switch_vehicle_option", m_sUserConfig.isDDOFEnabledInVehicle(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_SWITCH_VEHICLE",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION",
			m_sUserConfig.getConstraints().getDDOFEnabledInVehicle()));
		
		initOption(m_motionBlurSlider, "sude_motionblur_setting_", m_sUserConfig.getMotionBlurIntensity(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR_DESCRIPTION",
			m_sUserConfig.getConstraints().getMotionBlurIntensity()));
		
		initOption(m_bloomSlider, "sude_bloom_setting_", m_sUserConfig.getBloomIntensity(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM_DESCRIPTION",
			m_sUserConfig.getConstraints().getBloomIntensity()));
		
		initOption(m_headLeanSlider, "sude_roll_setting_", m_sUserConfig.getHeadLeanAngle(), new SUserConfigInfo(
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL",
			"#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL_DESCRIPTION",
			m_sUserConfig.getConstraints().getHeadLeanAngle()));
	
	}
	
	override bool onChange(SliderWidget w){
		switch(w){
			case m_headBobSlider.getSliderWidget():    updateHeadBobOption(w.GetCurrent()); break;
			case m_dofSlider.getSliderWidget():        updateDoFOption(w.GetCurrent()); break;
			case m_motionBlurSlider.getSliderWidget(): updateMotionBlurOption(w.GetCurrent()); break;
			case m_bloomSlider.getSliderWidget():      updateBloomOption(w.GetCurrent()); break;
			case m_headLeanSlider.getSliderWidget():   updateHeadLeanOption(w.GetCurrent()); break;
			//default: SLog.w("No slider widget name found.","OptionsMenuSVisual::onChange"); return false;
		}
		return true;
	}
	
	override bool onChange(CheckBoxWidget w){
		switch(w){
			case m_headbobSwitch3pp: updateHeadbobSwitch3PP(w.IsChecked()); break;
			case m_dofSwitch3PP:     updateDOFSwitch3PP(w.IsChecked()); break;
			case m_dofSwitchVehicle: updateDOFSwitchVehicle(w.IsChecked()); break;
			//default: SLog.w("No checkbox widget name found.","OptionsMenuSVisual::onChange"); return false;
		}
		return true;
	}
	
	
	
	protected void updateHeadBobOption( float newValue ){
		newValue = m_sUserConfig.getConstraints().getHeadbobIntensity().constrain(newValue);
		m_headBobSlider.setValue(newValue);
		m_sUserConfig.setHeadbobIntensity(newValue);
	}
	
	protected void updateHeadbobSwitch3PP(bool checked){
		checked = m_sUserConfig.getConstraints().getHeadbobEnabledIn3PP().constrain(checked);
		m_headbobSwitch3pp.SetChecked(checked);
		m_sUserConfig.setHeadbobEnabledIn3pp(checked);
	}	
	
	protected void updateDoFOption( float newValue ){
		newValue = m_sUserConfig.getConstraints().getDDOFIntensity().constrain(newValue);
		m_dofSlider.setValue(newValue);
		m_sUserConfig.setDDOFIntensity(newValue);
		SPPEManager.setDDOFBlurStrength(newValue);
	}
	
	protected void updateDOFSwitch3PP(bool checked){		
		checked = m_sUserConfig.getConstraints().getDDOFEnabledIn3PP().constrain(checked);
		m_dofSwitch3PP.SetChecked(checked);
		m_sUserConfig.setDDOFEnabledIn3PP(checked);
		SPPEManager.setDDOFEnabledIn3PP(checked);
	}
	
	protected void updateDOFSwitchVehicle(bool checked){		
		checked = m_sUserConfig.getConstraints().getDDOFEnabledInVehicle().constrain(checked);
		m_dofSwitchVehicle.SetChecked(checked);
		m_sUserConfig.setDDOFEnabledInVehicle(checked);
		SPPEManager.setDDOFEnabledInVehicle(checked);		
	}
	
	protected void updateMotionBlurOption( float newValue ){
		newValue = m_sUserConfig.getConstraints().getMotionBlurIntensity().constrain(newValue);
		m_motionBlurSlider.setValue(newValue);
		m_sUserConfig.setMotionBlurIntensity(newValue);
		SPPEManager.setMotionBlurStrength(newValue);
	}
	
	protected void updateBloomOption( float newValue ){
		newValue = m_sUserConfig.getConstraints().getBloomIntensity().constrain(newValue);
		m_bloomSlider.setValue(newValue);
		m_sUserConfig.setBloomIntensity(newValue);
		SPPEManager.setBloomStrength(newValue);
	}
	
	protected void updateHeadLeanOption( float newValue){
		newValue = m_sUserConfig.getConstraints().getHeadLeanAngle().constrain(newValue);
		m_headLeanSlider.setValue(newValue);
		m_sUserConfig.setHeadLeanAngle(newValue);
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
		if ( button == MouseState.LEFT ) {
			onConfigChange();
		}
		return true;
	}
	
	protected void onConfigChange(){ //@todo lol change this shit
		m_sUserConfig.save();
	}
	

}