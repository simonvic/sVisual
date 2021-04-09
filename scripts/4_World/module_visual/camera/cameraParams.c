//to-do remove all these when player settings are done

class HeadLeanParams {
	static float leanAngle = 15;
}

class LensZoomParams {
	static bool enabled = true;
}

class HeadBobParams {
	static bool enabled = true;
	static float multiplier = 0.5;	
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
