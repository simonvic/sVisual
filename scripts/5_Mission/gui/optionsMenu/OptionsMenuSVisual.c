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
	
		
	protected ref SliderWidget    m_dofSlider;
	protected ref CheckBoxWidget  m_dofSwitch3PP;
	protected ref CheckBoxWidget  m_dofSwitchVehicle;
	protected ref SliderWidget    m_headBobSlider;
	protected ref CheckBoxWidget  m_headbobSwitch3pp;	
	protected ref SliderWidget    m_motionBlurSlider;
	protected ref SliderWidget    m_bloomSlider;
	protected ref SliderWidget    m_headLeanSlider;
	
	override void onInit(){
		super.onInit();
		setUserConfig(SUserConfig.visual());
	}
	
	override void onBuild(){
		super.onBuild();

		initOptionWidget(m_dofSlider,        "sude_dof_setting_option",        getUserConfig().getOptionFloat("ddofIntensity"));
		initOptionWidget(m_dofSwitch3PP,     "sude_dof_switch_3pp_option",     getUserConfig().getOptionBool("ddofEnabledIn3PP"));
		initOptionWidget(m_dofSwitchVehicle, "sude_dof_switch_vehicle_option", getUserConfig().getOptionBool("ddofEnabledInVehicle"));
		initOptionWidget(m_headBobSlider,    "sude_headbob_setting_option",    getUserConfig().getOptionFloat("headbobIntensity"));
		initOptionWidget(m_headbobSwitch3pp, "sude_headbob_switch_3pp_option", getUserConfig().getOptionBool("headbobEnabledIn3PP"));
		initOptionWidget(m_motionBlurSlider, "sude_motionblur_setting_option", getUserConfig().getOptionFloat("motionBlurIntensity"));
		initOptionWidget(m_bloomSlider,      "sude_bloom_setting_option",      getUserConfig().getOptionFloat("bloomIntensity"));
		initOptionWidget(m_headLeanSlider,   "sude_roll_setting_option",       getUserConfig().getOptionFloat("headLeanAngle"));
	}

}