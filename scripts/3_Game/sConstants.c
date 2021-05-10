class PPEConstants{
	static const float RESET_SPEED = 0.95; //how slow post process effects will return to normal. (0.0 = immediate | 0.5 = almost immediate | 0.95 = normal | 0.999 very slow)
	static const float VANILLA_COEFF = 0.91; //coefficient used when merging with vanilla values. (0.1 = very high | 0.5 = high | 0.90 normal | 0.999 very low)
	
	static const float EPSILON = 1e-3; //used when comparing two float values (PPEffects.equals())
	
	static const float EXHAUSTED_DEACTIVATION_TRESHOLD = 50; //[0% - 100%] treshold for Exhausted PPEffect. Percentage of stamina available [0 - m_StaminaCap]
	
	static const float HIT_RECEIVED_MIN_DURATION = 4.5;        //How long (seconds) the animation will last at least
	static const float HIT_RECEIVED_MAX_DURATION = 30.0;       //Maximum duration (seconds) of the animation
	static const float HIT_RECEIVED_DURATION_MULTIPLIER = 2;   //How much the duration will increment when being hit multiple time
	static const float HIT_RECEIVED_MIN_STRENGTH = 1;          //Minimum strength of the effects
	static const float HIT_RECEIVED_STRENGTH_MULTIPLIER = 1.5; //How much the effect strength will increment when being hit multiple time
	static const float HIT_RECEIVED_MAX_CHROM_ABER = 0.5;      //Maximum value of chromatic aberration applied when being hit
	static const float HIT_RECEIVED_MAX_VIGNETTE = 1.0;        //Maximum value of vignette intensity applied when being hit
	
	static const float HIT_RECEIVED_MAX_STRENGTH = 10.0; //Maximum value of hit strength
	
	static const float FOCUS_VIGNETTE_MULTIPLIER = 1; // multiplier for vignette effect when focusing
	
}

class HeadBobConstants{
	//                                            yawStrenght, yawFrequency, pitchStrenght, pitchFrequency
	static const float IDLE[4] =                     { 0.0,        0.0,         1.1,             0.5   };
	
	static const float ERECT_WALKING[4] =            { 0.5,        5.75,        0.5,             11.5  };
	static const float ERECT_JOGGING[4] =            { 1.0,        9.0,         0.5,             18.0  };
	static const float ERECT_RUNNING[4] =            { 2.4,        11.5,        0.5,             23.0  };
	static const float ERECT_RAISED_WALKING[4] =     { 0.5,        1.75,        0.5,             6.5   };
	static const float ERECT_RAISED_JOGGING[4] =     { 1.0,        8.75,        0.5,             17.5  };
	
	static const float CROUCH_WALKING[4] =           { 0.5,        5.75,        0.5,             11.5  };
	static const float CROUCH_RUNNING[4] =           { 1.0,        9.0,         0.5,             18.0  };
	static const float CROUCH_RAISED_WALKING[4] =    { 0.5,        5.75,        0.5,             11.5  };
	
	static const float PRONE_WALKING[4] =            { 0.5,        5.75,        0.5,             11.5  };
}

enum PPEMergeFlags {
	SIMPLE = 1,
	MAX = 2,
	MIN = 4,
	ADDITIVE = 8,
	INTERPOLATE = 16,
	
	COUNT
}