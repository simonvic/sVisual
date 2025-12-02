modded class SUserConfig{

	static SUserConfigVisual visual(bool reload = false) {
		getInstance().load(SUserConfigVisual, reload);
		return SUserConfigVisual.Cast(getInstance().getLoadedModules().Get(SUserConfigVisual));

	override void onConstraintsReceived(ParamsReadContext ctx) {
		super.onConstraintsReceived(ctx);
		SUserConfigConstraints_Visual constraints;
		if (!ctx.Read(constraints)) {
			SLOG.c(""+this, "Can't read constraints, ignoring...");
			return;
		}
		visual().applyConstraints(constraints);
	}

}