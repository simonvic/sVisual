class OptionsMenuSVisual : SOptionsMenuBase{
	
	override string getName() {
		return "sVisual";
	}
	
	override string getLayout() {
		return "MyMODS/sVisual/GUI/layouts/optionsMenu/sVisual_tab.layout";	
	}
	
	override string getInfoBoxRootContainer() {
		return "c_description_box_root";
	}
	
		
	protected ref SliderWidget    m_effectsIntensitySlider;
	protected ref SliderWidget    m_dofSlider;
	protected ref CheckBoxWidget  m_dofSwitch3PP;
	protected ref CheckBoxWidget  m_dofSwitchVehicle;
	protected ref SliderWidget    m_headBobSlider;
	protected ref CheckBoxWidget  m_headbobSwitch3pp;	
	protected ref SliderWidget    m_motionBlurSlider;
	protected ref SliderWidget    m_bloomSlider;
	protected ref SliderWidget    m_headLeanSlider;
	
	override void onInit() {
		super.onInit();
		setUserConfig(SUserConfig.visual());
	}
	
	override void onBuild() {
		super.onBuild();

		initOptionWidget(m_effectsIntensitySlider,  "effectsIntensity",  getUserConfig().getOptionFloat("effectsIntensity"));
		initOptionWidget(m_dofSlider,               "ddof",              getUserConfig().getOptionFloat("ddofIntensity"));
		initOptionWidget(m_dofSwitch3PP,            "ddof3pp",           getUserConfig().getOptionBool("ddofEnabledIn3PP"));
		initOptionWidget(m_dofSwitchVehicle,        "ddofVehicle",       getUserConfig().getOptionBool("ddofEnabledInVehicle"));
		initOptionWidget(m_headBobSlider,           "headbob",           getUserConfig().getOptionFloat("headbobIntensity"));
		initOptionWidget(m_headbobSwitch3pp,        "headbob3pp",        getUserConfig().getOptionBool("headbobEnabledIn3PP"));
		initOptionWidget(m_motionBlurSlider,        "motionblur",        getUserConfig().getOptionFloat("motionBlurIntensity"));
		initOptionWidget(m_bloomSlider,             "bloom",             getUserConfig().getOptionFloat("bloomIntensity"));
		initOptionWidget(m_headLeanSlider,          "headLean",          getUserConfig().getOptionFloat("headLeanAngle"));
	}

}