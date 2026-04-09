modded class SUserConfigConstraints{

	static SUserConfigConstraints_Visual visual(bool reload = false) {
		return SUserConfigConstraints_Visual.Cast(getInstance().load(SUserConfigConstraints_Visual, reload));
	}

	override void onPreload() {
		super.onPreload();
		SUserConfigConstraints.visual();
	}

}

modded class SyncSUserConfigConstraintsRPC {
	override void onSetup(ParamsWriteContext ctx) {
		super.onSetup(ctx);
		ctx.Write(SUserConfigConstraints.visual());
	}
}
