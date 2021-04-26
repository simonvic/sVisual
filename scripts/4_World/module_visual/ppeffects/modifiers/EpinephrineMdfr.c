modded class EpinephrineMdfr{
	
	protected ref PPEAnimatedParams m_ppeAnimation = new PPEEpinephrineAnimation();
	
	//@todo this also get called only on server :(
	override void OnActivate(PlayerBase player){
		super.OnActivate(player);
		//activatePPE();
	}
	
	override void OnDeactivate(PlayerBase player){
		super.OnDeactivate(player);
		//deactivatePPE();
	}
	
	
	override void activatePPE(){
		//@todo send rpc
		PPEManager.activate(m_ppeAnimation);
	}
	
	override void deactivatePPE(){
		PPEManager.deactivate(m_ppeAnimation);
	}
}