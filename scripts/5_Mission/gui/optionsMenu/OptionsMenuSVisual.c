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
	
		
	protected ref SSliderWidget   m_dofSlider;
	protected ref CheckBoxWidget  m_dofSwitch3PP;
	protected ref CheckBoxWidget  m_dofSwitchVehicle;
	protected ref SSliderWidget   m_headBobSlider;
	protected ref CheckBoxWidget  m_headbobSwitch3pp;	
	protected ref SSliderWidget   m_motionBlurSlider;
	protected ref SSliderWidget   m_bloomSlider;
	protected ref SSliderWidget   m_headLeanSlider;

	protected SUserConfigVisual m_sUserConfig;
	
	void OptionsMenuSVisual(){
		m_sUserConfig = SUserConfig.visual();
	}
	
	override void onBuild(){
		super.onBuild();

		initOptionWidget(m_dofSlider,        "sude_dof_setting_",              m_sUserConfig.getOptionFloat("ddofIntensity"));
		initOptionWidget(m_dofSwitch3PP,     "sude_dof_switch_3pp_option",     m_sUserConfig.getOptionBool("ddofEnabledIn3PP"));
		initOptionWidget(m_dofSwitchVehicle, "sude_dof_switch_vehicle_option", m_sUserConfig.getOptionBool("ddofEnabledInVehicle"));
		initOptionWidget(m_headBobSlider,    "sude_headbob_setting_",          m_sUserConfig.getOptionFloat("headbobIntensity"));
		initOptionWidget(m_headbobSwitch3pp, "sude_headbob_switch_3pp_option", m_sUserConfig.getOptionBool("headbobEnabledIn3PP"));
		initOptionWidget(m_motionBlurSlider, "sude_motionblur_setting_",       m_sUserConfig.getOptionFloat("motionBlurIntensity"));
		initOptionWidget(m_bloomSlider,      "sude_bloom_setting_",            m_sUserConfig.getOptionFloat("bloomIntensity"));
		initOptionWidget(m_headLeanSlider,   "sude_roll_setting_",             m_sUserConfig.getOptionFloat("headLeanAngle"));
	}
	
	override bool onChange(SliderWidget w){
		SUserConfigOption<float> option = SUserConfigOption<float>.Cast(m_optionsWidgets.Get(w));
		option.set(w.GetCurrent());
		w.SetCurrent(option.get());
		/*
		switch (w) {
			case m_headBobSlider.getSliderWidget():    updateHeadBobOption(w.GetCurrent()); break;
			case m_dofSlider.getSliderWidget():        updateDoFOption(w.GetCurrent()); break;
			case m_motionBlurSlider.getSliderWidget(): updateMotionBlurOption(w.GetCurrent()); break;
			case m_bloomSlider.getSliderWidget():      updateBloomOption(w.GetCurrent()); break;
			case m_headLeanSlider.getSliderWidget():   updateHeadLeanOption(w.GetCurrent()); break;
			//default: SLog.w("No slider widget name found.","OptionsMenuSVisual::onChange"); return false;
		}
		*/
		return true;
	}
	
	override bool onChange(CheckBoxWidget w){
		SUserConfigOption<bool> option = SUserConfigOption<bool>.Cast(m_optionsWidgets.Get(w));
		option.set(w.IsChecked());
		w.SetChecked(option.get());
		/*
		switch(w){
			case m_headbobSwitch3pp: updateHeadbobSwitch3PP(w.IsChecked()); break;
			case m_dofSwitch3PP:     updateDOFSwitch3PP(w.IsChecked()); break;
			case m_dofSwitchVehicle: updateDOFSwitchVehicle(w.IsChecked()); break;
			//default: SLog.w("No checkbox widget name found.","OptionsMenuSVisual::onChange"); return false;
		}
		*/
		return true;
	}
	
	
	
	protected void updateHeadBobOption( float newValue ){
		m_sUserConfig.setHeadbobIntensity(newValue);
		m_headBobSlider.setValue(m_sUserConfig.getHeadbobIntensity());
	}
	
	protected void updateHeadbobSwitch3PP(bool checked){
		m_headbobSwitch3pp.SetChecked(checked);
		m_sUserConfig.setHeadbobEnabledIn3pp(checked);
	}	
	
	protected void updateDoFOption( float newValue ){
		m_sUserConfig.setDDOFIntensity(newValue);
		m_dofSlider.setValue(m_sUserConfig.getDDOFIntensity());
		SPPEManager.setDDOFBlurStrength(newValue); //@todo move to onValueChange
	}
	
	protected void updateDOFSwitch3PP(bool checked){		
		m_sUserConfig.setDDOFEnabledIn3PP(checked);
		m_dofSwitch3PP.SetChecked(m_sUserConfig.isDDOFEnabledIn3PP());
		SPPEManager.setDDOFEnabledIn3PP(checked); //@todo move to onValueChange
	}
	
	protected void updateDOFSwitchVehicle(bool checked){		
		m_sUserConfig.setDDOFEnabledInVehicle(checked);
		m_dofSwitchVehicle.SetChecked(m_sUserConfig.isDDOFEnabledInVehicle());
		SPPEManager.setDDOFEnabledInVehicle(checked); //@todo move to onValueChange
	}
	
	protected void updateMotionBlurOption( float newValue ){
		m_sUserConfig.setMotionBlurIntensity(newValue);
		m_motionBlurSlider.setValue(m_sUserConfig.getMotionBlurIntensity());
		SPPEManager.setMotionBlurStrength(newValue); //@todo move to onValueChange
	}
	
	protected void updateBloomOption( float newValue ){
		m_sUserConfig.setBloomIntensity(newValue);
		m_bloomSlider.setValue(m_sUserConfig.getBloomIntensity());
		SPPEManager.setBloomStrength(newValue); //@todo move to onValueChange
	}
	
	protected void updateHeadLeanOption( float newValue){
		m_sUserConfig.setHeadLeanAngle(newValue);
		m_headLeanSlider.setValue(m_sUserConfig.getHeadLeanAngle());
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