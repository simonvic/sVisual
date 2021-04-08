modded class OptionsMenu {
	
	protected ref OptionsMenuSVisual m_sVisualTab;
	
	override Widget Init(){
		//super
		Widget temp = super.Init();
		
		// Add custom tab
		int newIndex = m_Tabber.GetTabCount(); //make it last so we son't have problem with possible future additions
		m_Tabber.AddTab(newIndex.ToString()); 		
		TextWidget.Cast( layoutRoot.FindAnyWidget( "Tab_Control_"+newIndex+"_Title" )).SetText("sVisual");
		m_sVisualTab = new OptionsMenuSVisual( layoutRoot.FindAnyWidget( "Tab_" + newIndex ), m_Details, this );
		
		return temp;

	}	
	
}
