enum UISettingsID{
	HEADBOB = 0,
	DDOF,
	MOTION_BLUR,
	BLOOM,
	HEAD_LEAN
}

class OptionsMenuSVisual extends ScriptedWidgetEventHandler{
	
	protected ref SUserConfigVisual m_sUserConfig;
		
	static const string HEADBOB_WIDGET_NAME = "sude_headbob_setting_";
	static const string DOF_WIDGET_NAME = "sude_dof_setting_";
	static const string MOTIONBLUR_WIDGET_NAME = "sude_motionblur_setting_";
	static const string BLOOM_WIDGET_NAME = "sude_bloom_setting_";
	static const string DEADZONE_WIDGET_NAME = "sude_deadzone_setting_";
	static const string LENSZOOM_WIDGET_NAME = "sude_lensZoom_setting_";
	static const string ROLL_WIDGET_NAME = "sude_roll_setting_";
	
	///////////////// DEBUG /////////////////
	static const string DEBUG_DEADZONE_HIPFIRE_WIDGET_NAME = "sude_debug_deadzone_setting_";
	static const string DEBUG_BODYCLIP_ALLCONTACT_WIDGET_NAME = "sude_body_clip_all_contact_setting_";
	static const string DEBUG_BODYCLIP_CONTACTPOS_WIDGET_NAME = "sude_body_clip_contact_pos_setting_";
	static const string DEBUG_CROSSHAIR_WIDGET_NAME = "sude_crosshair_setting_";
	static const string DEBUG_PEAKMITIGATION_WIDGET_NAME = "sude_peakMitigation_setting_";
	//////////////////////////////////
	
	protected Widget						m_Root;
	
	protected Widget						m_DetailsRoot;
	protected TextWidget					m_DetailsLabel;
	protected RichTextWidget				m_DetailsText;
	
	protected Widget						m_SettingsRoot;

	////////////////// CAMERA ////////////////////////
	protected ref SliderWidget				m_HeadBobSlider;
	protected ref TextWidget				m_HeadBobValue;
	
	protected ref SliderWidget				m_DoFSlider;
	protected ref TextWidget				m_DoFValue;
	
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
		m_HeadBobSlider = SliderWidget.Cast(m_Root.FindAnyWidget( HEADBOB_WIDGET_NAME+"option" ));
		m_HeadBobSlider.SetCurrent(HeadBobParams.multiplier);
		m_HeadBobValue = TextWidget.Cast(m_Root.FindAnyWidget( HEADBOB_WIDGET_NAME+"value" ));
		m_HeadBobValue.SetText(m_HeadBobSlider.GetCurrent().ToString());
		
		m_DoFSlider = SliderWidget.Cast(m_Root.FindAnyWidget( DOF_WIDGET_NAME+"option" ));
		m_DoFSlider.SetCurrent(PPEManager.getDDOFStrength());
		m_DoFValue = TextWidget.Cast(m_Root.FindAnyWidget( DOF_WIDGET_NAME+"value" ));
		m_DoFValue.SetText(m_DoFSlider.GetCurrent().ToString());
		
		m_MotionBlurSlider = SliderWidget.Cast(m_Root.FindAnyWidget( MOTIONBLUR_WIDGET_NAME+"option" ));
		m_MotionBlurSlider.SetCurrent(PPEManager.getMotionBlurStrength());
		m_MotionBlurValue = TextWidget.Cast(m_Root.FindAnyWidget( MOTIONBLUR_WIDGET_NAME+"value" ));
		m_MotionBlurValue.SetText(m_MotionBlurSlider.GetCurrent().ToString());
		
		m_BloomSlider = SliderWidget.Cast(m_Root.FindAnyWidget( BLOOM_WIDGET_NAME+"option" ));
		m_BloomSlider.SetCurrent(PPEManager.getBloomStrength());
		m_BloomValue = TextWidget.Cast(m_Root.FindAnyWidget( BLOOM_WIDGET_NAME+"value" ));
		m_BloomValue.SetText(m_BloomSlider.GetCurrent().ToString());
		
		m_RollSlider = SliderWidget.Cast(m_Root.FindAnyWidget( ROLL_WIDGET_NAME+"option" ));
		m_RollSlider.SetCurrent(HeadLeanParams.leanAngle);
		m_RollValue = TextWidget.Cast(m_Root.FindAnyWidget( ROLL_WIDGET_NAME+"value" ));
		m_RollValue.SetText(m_RollSlider.GetCurrent().ToString());
				
		
		
		////////////////// TOOLTIP ////////////////////////
		m_TextMap = new map<int, ref Param2<string, string>>;
		addDescriptionTooltip(m_HeadBobSlider, UISettingsID.HEADBOB, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_HEADBOB_DESCRIPTION");
		addDescriptionTooltip(m_DoFSlider, UISettingsID.DDOF, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_DOF_DESCRIPTION");
		addDescriptionTooltip(m_MotionBlurSlider, UISettingsID.MOTION_BLUR, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_MOTIONBLUR_DESCRIPTION");
		addDescriptionTooltip(m_BloomSlider, UISettingsID.BLOOM, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_BLOOM_DESCRIPTION");
		addDescriptionTooltip(m_RollSlider, UISettingsID.HEAD_LEAN, "#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL","#STR_SUDE_LAYOUT_OPTIONS_CAMERA_ROLL_DESCRIPTION");
		
		////////////////// CAMERA ////////////////////////
		m_HeadBobSlider.SetHandler(this);
		m_DoFSlider.SetHandler(this);
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
					case HEADBOB_WIDGET_NAME+"option":{
						UpdateHeadBobOption(s.GetCurrent());
						break;
					}
					case DOF_WIDGET_NAME+"option":{
						UpdateDoFOption(s.GetCurrent());
						break;
					}
					case MOTIONBLUR_WIDGET_NAME+"option":{
						UpdateMotionBlurOption(s.GetCurrent());
						break;
					}
					case BLOOM_WIDGET_NAME+"option":{
						UpdateBloomOption(s.GetCurrent());
						break;
					}
					case ROLL_WIDGET_NAME+"option":{
						UpdateRollOption(s.GetCurrent());
						break;
					}
					default: SLog.w("No slider widget name found.","OptionsMenuSVisual::OnChange");
				}
					
			}else if(w.IsInherited( CheckBoxWidget )){
				CheckBoxWidget c = CheckBoxWidget.Cast(w);
				
				switch(c.GetName()){
					/*
					case ROLL_WIDGET_NAME+"option":{
						UpdateRollOption(c.IsChecked());
						break;
					}
					*/
					default: SLog.w("No checkbox  widget name found.","OptionsMenuSVisual::OnChange");
				}
					
			}
		}
		return true;
		
	}
	
	
	void UpdateHeadBobOption( float new_value ){
		HeadBobParams.multiplier = new_value;
		m_HeadBobValue.SetText(new_value.ToString());
		
		m_sUserConfig.setHeadbobIntensity(new_value);
		onConfigChange();
	}
	
	void UpdateDoFOption( float new_value ){
		PPEManager.setDDOFBlurStrength(new_value);
		m_DoFValue.SetText(new_value.ToString());
		
		m_sUserConfig.setDDOFIntensity(new_value);
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
		HeadLeanParams.leanAngle = new_value;
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