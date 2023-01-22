class HeadBobConstants{
	//                                                   yawStrenght, yawFrequency, pitchStrenght, pitchFrequency
	static const ref array<float> IDLE                   = { 0.00,        0.00,          1.10,         0.50  };

	static const ref array<float> WALKING_ERECT          = { 1.38,        6.00,          2.00,        12.00  };
	static const ref array<float> WALKING_ERECT_RAISED   = { 0.75,        4.00,          1.50,         6.50  };
	static const ref array<float> WALKING_CROUCH         = { 1.38,        5.00,          2.50,        10.00  };
	static const ref array<float> WALKING_PRONE          = { 0.38,        5.00,          0.75,        10.00  };

	static const ref array<float> JOGGING_ERECT          = { 1.75,        9.0/2,         2.25,        16.0/2  };
	static const ref array<float> JOGGING_ERECT_RAISED   = { 1.75,        8.0/2,         2.25,        15.0/2  };
	static const ref array<float> JOGGING_CROUCH         = { 1.75,        8.0/2,         2.50,        12.0/2  };

	static const ref array<float> RUNNING_ERECT          = { 1.75,       13.5/3,         2.25,        24.0/3  };
	static const ref array<float> RUNNING_CROUCH         = { 1.75,       12.0/3,         2.50,        18.0/3  };
}