modded class BurlapSackCover {

	// NOTE: we handle this manually

	override void OnRemovedFromHead(PlayerBase player) {
		super.OnRemovedFromHead(player);
		if (!g_Game.IsClient()) return;
		m_isAttachedToPlayer = false;
		updateOverlayVisibility();
	}

	override void HandleAttachedToHead() {
		super.HandleAttachedToHead();
		if (!g_Game.IsClient()) return;
		m_isAttachedToPlayer = true;
		updateOverlayVisibility();
	}

	override bool hasOverlays() {
		return false;
	}

}

