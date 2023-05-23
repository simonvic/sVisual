// - Remove 90% of current active bloom

modded class PPERequester_GlassesAviator {
	override protected void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_GenericBlackGlassesBase {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_GlassesSportBlue {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_GlassesSportGreen	 {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_GlassesSportOrange {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_GlassesAviator {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_TacticalGoggles {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_WeldingMask {
	override void OnStart(Param par = null) {
		super.OnStart(par);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMSTEEPNESS, true, 0.90, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT_RELATIVE);
	}
}

modded class PPERequester_BurlapSackEffects {
	override void OnStart(Param par = null)	{
		super.OnStart(par);
		ClearRequesterData();
	}
}