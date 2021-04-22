class PPEConstants{
	static const float RESET_SPEED = 0.95; //how slow post process effects will return to normal. (0.0 = immediate | 0.5 = almost immediate | 0.95 = normal | 0.999 very slow)
	static const float EPSILON = 1e-3; //used when comparing two float values (PPEffects.equals())
	
	static const float EXHAUSTED_DEACTIVATION_TRESHOLD = 50; //[0% - 100%] treshold for Exhausted PPEffect. Percentage of stamina available [0 - m_StaminaCap]
	
	static const float HIT_RECEIVED_MAX_CHROM_ABER = 0.5; //Maximum value of chromatic aberration applied when being hit
	static const float HIT_RECEIVED_MAX_VIGNETTE = 1.0; //Maximum value of vignette intensity applied when being hit
	static const float HIT_RECEIVED_MAX_DURATION = 30.0; //Maximum duration (seconds) of the animation
	static const float HIT_RECEIVED_MAX_STRENGTH = 10.0; //Maximum value of hit strength
	
	static const float FOCUS_VIGNETTE_MULTIPLIER = 1; // multiplier for vignette effect when focusing
	
}