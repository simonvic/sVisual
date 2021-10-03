modded class MissionServer {
	
	override void OnEvent(EventType eventTypeId, Param params) {
		super.OnEvent(eventTypeId, params);		
		switch (eventTypeId) {
			case ClientNewEventTypeID:						
			case ClientReadyEventTypeID:
			SLog.d("Player connected","MissionServer::OnEvent");
			ClientReadyEventParams readyParams = ClientReadyEventParams.Cast(params);
			if (readyParams) {
				syncSUserConfigConstraints(PlayerBase.Cast(readyParams.param2));
			} else {
				SLog.c("Cannot read ClientReadyEventParams! Can't sync SUserConfigConstraints!","MissionServer::OnEvent");
			}
			break;
		}
	}
	
	void syncSUserConfigConstraints(PlayerBase player) {
		if ( !player ) {
			SLog.c("Player not instantiated! Can't sync SUserConfigConstraints!","MissionServer::syncSUserConfigConstraints");
			return;
		}

		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(SUserConfigConstraints.visual());
		rpc.Send( null, sVisual_RPC.SYNC_USER_CONFIG_CONSTRAINTS_VISUAL, true, player.GetIdentity() );
		//GetGame().RPCSingleParam(null, sVisual_RPC.SYNC_USER_CONFIG_CONSTRAINTS_VISUAL, new Param1<SUserConfigConstraints_Visual>(constraints), true, player.GetIdentity());
	}
}