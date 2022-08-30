modded class SUserConfig{

	static SUserConfigVisual visual(bool reload = false) {
		getInstance().load(SUserConfigVisual, reload);
		return SUserConfigVisual.Cast(getInstance().getLoadedModules().Get(SUserConfigVisual));
	}

}