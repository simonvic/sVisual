class PPEConstants{
	static const float RESET_SPEED = 0.95; //how slow post process effects will return to normal. (0.0 = immediate | 0.5 = almost immediate | 0.95 = normal | 0.999 very slow)
	static const float EPSILON = 1e-3; //used when comparing two float values (PPEffects.equals())
	
	static const float FOCUS_VIGNETTE_MULTIPLIER = 1; // multiplier for vignette effect when focusing
	
}