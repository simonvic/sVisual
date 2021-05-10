class OptionsMenuSVisual extends ScriptedWidgetEventHandler{
	
	protected ref SUserConfigVisual m_sUserConfig;
		
	static const string WN_HEADBOB = "sude_headbob_setting_";
	static const string WN_HEADBOB_SWITCH_3PP = "sude_headbob_switch_3pp_";
	static const string WN_DOF = "sude_dof_setting_";
	static const string WN_DOF_SWITCH_3PP = "sude_dof_switch_3pp_";
	static const string WN_DOF_SWITCH_VEHICLE = "sude_dof_switch_vehicle_";
	static const string WN_MOTIONBLUR = "sude_motionblur_setting_";
	static const string WN_BLOOM = "sude_bloom_setting_";
	static const string WN_HEADLEAN = "sude_roll_setting_";
		
	protected Widget						m_Root;
	
	protected Widget						m_DetailsRoot;
	protected TextWidget					m_DetailsLabel;
	protected RichTextWidget				m_DetailsText;
	
	protected Widget						m_SettingsRoot;

	////////////////// CAMERA ////////////////////////
	protected ref SliderWidget				m_HeadBobSlider;
	protected ref TextWidget				m_HeadBobValue;
	protected ref CheckBoxWidget            m_headbobSwitch3pp;
	
	protected ref SliderWidget				m_DoFSlider;
	protected ref TextWidget				m_DoFValue;
	protected ref CheckBoxWidget            m_dofSwitch3PP;
	protected ref CheckBoxWidget            m_dofSwitchVehicle;
	
	protected ref SliderWidget				m_MotionBlurSlider;
	protected ref TextWidget				m_MotionBlurValue;
	
	protected ref SliderWidget				m_BloomSlider;
	protected ref TextWidget				m_BloomValue;
	
	protected ref SliderWidget				m_RollSlider;
	protected ref TextWidget				m_RollValue;
	
	
	protected OptionsMenu					m_Menu;
	
	protected ref map<int, ref Param2<string, string>> m_TextMap;
	
	void OptionsMenuSVisual( Widget parent, Widget details_root, OptionsMenu menu ){
		
		//////////////// USER CONFIG ///////////////////
		m_sUserConfig = SUserConfig.getInstance().visual();
		
		//////////////// UI ///////////////////
		m_Root = GetGame().GetWorkspace().CreateWidgets( GetLayoutName(), parent );			
		
		m_DetailsRoot				= details_root;
		m_DetailsLabel				= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_label" ) );
		m_DetailsText				= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_content" ) );
		
		m_Menu = menu;

		////////////////// CAMERA ////////////////////////
		m_HeadBobSlider = SliderWidget.Cast(m_Root.FindAnyWidget( WN_HEADBOB+"option" ));
		m_HeadBobSlider.SetCurrent(m_sUserConfig.getHeadbobIntensity());
		m_HeadBobValue = TextWidget.Cast(m_Root.FindAnyWidget( WN_HEADBOB+"value" ));
		m_HeadBobValue.SetText(m_HeadBobSlider.GetCurrent().ToString());
		
		m_headbobSwitch3pp = CheckBoxWidget.Cast(m_Root.FindAnyWidget( WN_HEADBOB_SWITCH_3PP+"option" ));
		m_headbobSwitch3pp.SetChecked(m_sUserConfig.isHeadbobEnabledIn3pp());
		
		
		m_DoFSlider = SliderWidget.Cast(m_Root.FindAnyWidget( WN_DOF+"option" ));
		m_DoFSlider.SetCurrent(m_sUserConfig.getDDOFIntensity());
		m_DoFValue = TextWidget.Cast(m_Root.FindAnyWidget( WN_DOF+"value" ));
		m_DoFValue.SetText(m_DoFSlider.GetCurrent().ToString());
		
		
		m_dofSwitch3PP = CheckBoxWidget.Cast(m_Root.FindAnyWidget( WN_DOF_SWITCH_3PP+"option" ));
		m_dofSwitch3PP.SetChecked(m_sUserConfig.isDDOFEnabledIn3PP());
		
		m_dofSwitchVehicle = CheckBoxWidget.Cast(m_Root.FindAnyWidget( WN_DOF_SWITCH_VEHICLE+"option" ));
		m_dofSwitchVehicle.SetChecked(m_sUserConfig.isDDOFEnabledInVehicle());
		
		
		m_MotionBlurSlider = SliderWidget.Cast(m_Root.FindAnyWidget( WN_MOTIONBLUR+"option" ));
		m_MotionBlurSlider.SetCurrent(m_sUserConfig.getMotionBlurIntensity());
		m_MotionBlurValue = TextWidget.Cast(m_Root.FindAnyWidget( WN_MOTIONBLUR+"value" ));
		m_MotionBlurValue.SetText(m_MotionBlurSlider.GetCurrent().ToString());
		
		m_BloomSlider = SliderWidget.Cast(m_Root.FindAnyWidget( WN_BLOOM+"option" ));
		m_BloomSlider.SetCurrent(m_sUserConfig.getBloomIntensity());
		m_BloomValue = TextWidget.Cast(m_Root.FindAnyWidget( WN_BLOOM+"value" ));
		m_BloomValue.SetText(m_BloomSlider.GetCurrent().ToString());
		
		m_RollSlider = SliderWidget.Cast(m_Root.FindAnyWidget( WN_HEADLEAN+"option" ));
		m_RollSlider.SetCurrent(m_sUserConfig.getHeadLeanAngle());
		m_RollValue = TextWidget.Cast(m_Root.FindAnyWidget( WN_HEADLEAN+"value" ));
		m_RollValue.SetText(m_RollSlider.GetCurrent().ToString());
				
		
		
		////////////////// TOOLTIP ////////////////////////
		m_TextMap = new map<int, ref Param2<string, string>>;
		int uid = 0;
		addDescriptionTooltip(m_HeadBobSlider,    ++uid, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION");
		addDescriptionTooltip(m_DoFSlider,        ++uid, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION");
		addDescriptionTooltip(m_MotionBlurSlider, ++uid, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR_DESCRIPTION");
		addDescriptionTooltip(m_BloomSlider,      ++uid, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM_DESCRIPTION");
		addDescriptionTooltip(m_RollSlider,       ++uid, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL_DESCRIPTION");
		
		////////////////// CAMERA ////////////////////////
		m_HeadBobSlider.SetHandler(this);
		m_headbobSwitch3pp.SetHandler(this);
		m_DoFSlider.SetHandler(this);
		m_dofSwitch3PP.SetHandler(this);
		m_dofSwitchVehicle.SetHandler(this);
		m_MotionBlurSlider.SetHandler(this);
		m_BloomSlider.SetHandler(this);
		m_RollSlider.SetHandler(this);
		
		m_Root.SetHandler( this );
		
	}
	
	void ~OptionsMenuSVisual(){
		
	}
	
	string GetLayoutName(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/newui/options/sVisual_tab.layout";
	}
	
	
	override bool OnChange(Widget w, int x, int y, bool finished){
		
		if(w){
			if(w.IsInherited( SliderWidget )){
				SliderWidget s = SliderWidget.Cast(w);
				
				switch(s.GetName()){
					case WN_HEADBOB+"option":{
						UpdateHeadBobOption(s.GetCurrent());
						break;
					}
					case WN_DOF+"option":{
						UpdateDoFOption(s.GetCurrent());
						break;
					}
					case WN_MOTIONBLUR+"option":{
						UpdateMotionBlurOption(s.GetCurrent());
						break;
					}
					case WN_BLOOM+"option":{
						UpdateBloomOption(s.GetCurrent());
						break;
					}
					case WN_HEADLEAN+"option":{
						UpdateRollOption(s.GetCurrent());
						break;
					}
					default: SLog.w("No slider widget name found.","OptionsMenuSVisual::OnChange");
				}
					
			}else if(w.IsInherited( CheckBoxWidget )){
				CheckBoxWidget c = CheckBoxWidget.Cast(w);
				
				switch(c.GetName()){
					case WN_HEADBOB_SWITCH_3PP+"option":
						updateHeadbobSwitch3PP(c.IsChecked());
						break;
					case WN_DOF_SWITCH_3PP+"option":
						updateDOFSwitch3PP(c.IsChecked());
						break;
					case WN_DOF_SWITCH_VEHICLE+"option":
						updateDOFSwitchVehicle(c.IsChecked());
						break;
					default: SLog.w("No checkbox  widget name found.","OptionsMenuSVisual::OnChange");
				}
					
			}
		}
		return true;
		
	}
	
	
	void UpdateHeadBobOption( float new_value ){
		m_HeadBobValue.SetText(new_value.ToString());
		
		m_sUserConfig.setHeadbobIntensity(new_value);
		onConfigChange();
	}
	
	void updateHeadbobSwitch3PP(bool checked){		
		m_sUserConfig.setHeadbobEnabledIn3pp(checked);
		onConfigChange();
	}
	
	
	void UpdateDoFOption( float new_value ){
		PPEManager.setDDOFBlurStrength(new_value);
		m_DoFValue.SetText(new_value.ToString());
		
		m_sUserConfig.setDDOFIntensity(new_value);
		onConfigChange();
	}
	
	void updateDOFSwitch3PP(bool checked){		
		m_sUserConfig.setDDOFEnabledIn3PP(checked);
		PPEManager.setDDOFEnabledIn3PP(checked);
		onConfigChange();
	}
	
	void updateDOFSwitchVehicle(bool checked){		
		m_sUserConfig.setDDOFEnabledInVehicle(checked);
		PPEManager.setDDOFEnabledInVehicle(checked);
		onConfigChange();
	}
	
	void UpdateMotionBlurOption( float new_value ){
		PPEManager.setMotionBlurStrength(new_value);
		m_MotionBlurValue.SetText(new_value.ToString());
		
		m_sUserConfig.setMotionBlurIntensity(new_value);
		onConfigChange();
	}
	
	void UpdateBloomOption( float new_value ){
		PPEManager.setBloomStrength(new_value);
		m_BloomValue.SetText(new_value.ToString());
		
		m_sUserConfig.setBloomIntensity(new_value);
		onConfigChange();
	}
	
	void UpdateRollOption( float new_value){
		m_RollValue.SetText(new_value.ToString());
		
		m_sUserConfig.setHeadLeanAngle(new_value);
		onConfigChange();
	}
	
	private void onConfigChange(){ //@todo lol change this shit
		m_sUserConfig.save();
	}
	
	override bool OnFocus( Widget w, int x, int y ){		
		if( w ){
			Param2<string, string> p = m_TextMap.Get( w.GetUserID() );
			if( p ){
				
				m_DetailsRoot.Show( true );
				m_DetailsLabel.SetText( p.param1 );
				m_DetailsText.SetText( p.param2 );
								
				m_DetailsText.Update();
				m_DetailsLabel.Update();
				m_DetailsRoot.Update();
				return true;
			}	
		}
		m_DetailsRoot.Show( false );
		return ( w != null );
	}
	
	private void addDescriptionTooltip(Widget w, int userID, string title, string description){
		w.SetUserID(userID);
		m_TextMap.Insert(userID, new Param2<string, string>(title, description));
	}

}