modded class DayZPlayerCamera1stPerson{	
	
	void DayZPlayerCamera1stPerson(DayZPlayer pPlayer, HumanInputController pInput){
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		
		if( PPEManager.isDDOFEnabled() && !isADS() ){
			updateDoF(pDt);
		}
		
		if( PPEManager.isMotionBlurEnabled() && !isInventoryOpen() ){
			updateMotionBlur(pDt);	
		}
		
	}
	
	override bool isHeadbobEnabled(){
		return true;
	}
	
	override bool isHeadLeanEnabled(){
		return true;
	}
		
	
	override float getLeanRollAngle(){
		//this is needed to change the roll angle based on freelook
		return m_iPlayer.m_MovementState.m_fLeaning * Math.Lerp(HeadLeanParams.leanAngle,- HeadLeanParams.leanAngle, Math.AbsFloat(m_fLeftRightAngle) / ( CONST_LR_MAX / 2) );
	}	
	
	
	protected bool isADS(){
		return m_iPlayer.IsInOptics() || m_iPlayer.IsInIronsights();
		//return m_iPlayer.GetInputController().WeaponADS(); // is this broken? (doesn't set m_bAds to false when releasing mouse button)
	}
	
	protected bool isInventoryOpen(){ //to-do definitely find a better way of doing this
		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		return menu && ( menu.GetID() == MENU_INVENTORY || menu.GetID() == MENU_INSPECT );
	}
	
}

