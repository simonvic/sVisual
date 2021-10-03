modded class SUserConfigConstraints{
		
	static SUserConfigConstraints_Visual visual(bool reload = false){
		getInstance().load(SUserConfigConstraints_Visual, reload);
		return SUserConfigConstraints_Visual.Cast(getInstance().modulesCfgConstraints.Get(SUserConfigConstraints_Visual));
	}
	

}