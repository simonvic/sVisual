class PPEBloodLoss : SPPEffect{}

modded class BloodLoss{
	
	protected ref PPEBloodLoss ppeBloodLoss = new PPEBloodLoss();
	
	override void OnUpdateClient(PlayerBase player, float deltatime) {
			
		if (player.IsPlayerSelected() && player.GetTransferValues() && player.GetTransferValues().GetBlood() != m_BloodSet) { 	
			//the super is called after. Setting bloodset = new value will make vanilla code not change the saturation
			//m_BloodSet = player.GetTransferValues().GetBlood();
			
			ppeBloodLoss.setSaturation( player.GetTransferValues().GetBlood());
			if (player.GetTransferValues().GetBlood() < 1) {
				if (!ppeBloodLoss.isActive()) {
					SPPEManager.activate(ppeBloodLoss);
				}
			} else {
				SPPEManager.deactivate(ppeBloodLoss);
			}
			
		}
		
		super.OnUpdateClient(player, deltatime);
				
		
	}

}