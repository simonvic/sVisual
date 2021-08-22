class OptionsMenuSVisual : SOptionsMenuBase{
	
	override string getName(){
		return "sVisual";
	}
	
	override string getLayout(){
		return "MyMODS/sVisual/GUI/layouts/optionsMenu/sVisual_tab.layout";	
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
		
		initOption(m_headBobSlider,    "sude_headbob_setting_",          m_sUserConfig.getHeadbobIntensity());
		initOption(m_headbobSwitch3pp, "sude_headbob_switch_3pp_option", m_sUserConfig.isHeadbobEnabledIn3pp());
		initOption(m_dofSlider,        "sude_dof_setting_",              m_sUserConfig.getDDOFIntensity());
		initOption(m_dofSwitch3PP,     "sude_dof_switch_3pp_option",     m_sUserConfig.isDDOFEnabledIn3PP());
		initOption(m_dofSwitchVehicle, "sude_dof_switch_vehicle_option", m_sUserConfig.isDDOFEnabledInVehicle());		
		initOption(m_motionBlurSlider, "sude_motionblur_setting_",       m_sUserConfig.getMotionBlurIntensity());
		initOption(m_bloomSlider,      "sude_bloom_setting_",            m_sUserConfig.getBloomIntensity());
		initOption(m_headLeanSlider,   "sude_roll_setting_",             m_sUserConfig.getHeadLeanAngle());
		
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
		m_headBobSlider.updateTextValue();
		m_sUserConfig.setHeadbobIntensity(newValue);
		onConfigChange();
	}
	
	protected void updateHeadbobSwitch3PP(bool checked){		
		m_sUserConfig.setHeadbobEnabledIn3pp(checked);
		onConfigChange();
	}	
	
	protected void updateDoFOption( float newValue ){
		m_dofSlider.updateTextValue();
		m_sUserConfig.setDDOFIntensity(newValue);
		PPEManager.setDDOFBlurStrength(newValue);
		onConfigChange();
	}
	
	protected void updateDOFSwitch3PP(bool checked){		
		m_sUserConfig.setDDOFEnabledIn3PP(checked);
		PPEManager.setDDOFEnabledIn3PP(checked);
		onConfigChange();
	}
	
	protected void updateDOFSwitchVehicle(bool checked){		
		m_sUserConfig.setDDOFEnabledInVehicle(checked);
		PPEManager.setDDOFEnabledInVehicle(checked);		
		onConfigChange();
	}
	
	protected void updateMotionBlurOption( float newValue ){
		m_motionBlurSlider.updateTextValue();		
		m_sUserConfig.setMotionBlurIntensity(newValue);
		PPEManager.setMotionBlurStrength(newValue);
		onConfigChange();
	}
	
	protected void updateBloomOption( float newValue ){
		m_bloomSlider.updateTextValue();
		m_sUserConfig.setBloomIntensity(newValue);
		PPEManager.setBloomStrength(newValue);
		onConfigChange();
	}
	
	protected void updateHeadLeanOption( float newValue){
		m_headLeanSlider.updateTextValue();		
		m_sUserConfig.setHeadLeanAngle(newValue);
		onConfigChange();
	}
	
	protected void onConfigChange(){ //@todo lol change this shit
		m_sUserConfig.save();
	}
	

}