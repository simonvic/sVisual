modded class SUserConfig {

	static SUserConfigVisual visual(bool reload = false) {
		return SUserConfigVisual.Cast(getInstance().load(SUserConfigVisual, reload));
	}

	override void onPreload() {
		super.onPreload();
		SUserConfig.visual();
	}

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
