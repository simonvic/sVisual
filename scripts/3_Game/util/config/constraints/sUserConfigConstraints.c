modded class SUserConfigConstraints{
	
	static SUserConfigConstraints_Visual visual(bool reload = false){
		getInstance().load(SUserConfigConstraints_Visual, reload);
		return SUserConfigConstraints_Visual.Cast(getInstance().getLoadedModules().Get(SUserConfigConstraints_Visual));
	}
	
}

modded class SyncSUserConfigConstraintsRPC {
	override void onSetup(ParamsWriteContext ctx) {
		ctx.Write(SUserConfigConstraints.visual());
		super.onSetup(ctx);
	}
}