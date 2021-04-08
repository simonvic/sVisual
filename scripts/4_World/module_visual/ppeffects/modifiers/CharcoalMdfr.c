modded class CharcoalMdfr {
	
	protected ref PPEAnimatedParams m_ppeAnimation = new PPEDebugAnimation();
	
	override void OnActivate(PlayerBase player){
		super.OnActivate(player);
		activatePPE();
	}
	
	override void OnDeactivate(PlayerBase player){
		super.OnDeactivate(player);
		deactivatePPE();
	}
	
	
	override void activatePPE(){
		PPEManager.activate(m_ppeAnimation);
	}
	
	override void deactivatePPE(){
		PPEManager.deactivate(m_ppeAnimation);
	}
}