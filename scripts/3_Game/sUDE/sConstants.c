class HeadBobConstants{
	//                                            yawStrenght, yawFrequency, pitchStrenght, pitchFrequency
	static const ref array<float> IDLE =                     { 0.0,        0.0,         1.1,             0.5   };
	
	static const ref array<float> ERECT_WALKING =            { 0.5,        5.75,        0.75,            11.0  };
	static const ref array<float> ERECT_JOGGING =            { 0.9,        9.0,         1.0,             17.0  };
	static const ref array<float> ERECT_RUNNING =            { 1.5,        11.5,        1.0,             23.0  };
	static const ref array<float> ERECT_RAISED_WALKING =     { 0.5,        1.75,        0.5,             6.5   };
	static const ref array<float> ERECT_RAISED_JOGGING =     { 1.0,        8.75,        0.5,             17.5  };
	
	static const ref array<float> CROUCH_WALKING =           { 0.5,        5.75,        0.5,             11.5  };
	static const ref array<float> CROUCH_RUNNING =           { 1.0,        9.0,         0.5,             18.0  };
	static const ref array<float> CROUCH_RAISED_WALKING =    { 0.5,        5.75,        0.5,             11.5  };
	
	static const ref array<float> PRONE_WALKING =            { 0.5,        5.75,        0.5,             11.5  };
}