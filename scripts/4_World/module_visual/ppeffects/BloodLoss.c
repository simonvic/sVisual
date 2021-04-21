modded class BloodLoss{
	
	protected ref PPEParams ppeBloodLoss = new PPEParams();
	
	override void OnUpdateClient(PlayerBase player, float deltatime){
		//super.OnUpdateClient(player, deltatime);
				
		//override saturation effect
		if( player.GetTransferValues() && player.GetTransferValues().GetBlood() != m_BloodSet ) { //better to rewrite this, so we don't break other mods
			m_BloodSet = player.GetTransferValues().GetBlood();
			ppeBloodLoss.setSaturation( player.GetTransferValues().GetBlood() );
			if(m_BloodSet < 1){
				if(!ppeBloodLoss.isActive()) {
					PPEManager.activate(ppeBloodLoss);
				}
			}else{
				PPEManager.deactivate(ppeBloodLoss);
			}
		}
	}

}