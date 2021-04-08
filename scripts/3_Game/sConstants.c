class PPEConstants{
	static const float RESET_SPEED = 0.95; //how slow post process effects will return to normal. (0.0 = immediate | 0.5 = almost immediate | 0.95 = normal | 0.999 very slow)
	static const float EPSILON = 1e-3; //used when comparing two float values (PPEffects.equals())
	
	static const float FOCUS_VIGNETTE_MULTIPLIER = 1; // multiplier for vignette effect when focusing
	
}


class PPEDefaultValues { //to-do lol... move default ppe constants to config.cpp
	static const float SATURATION = 1.0;
	static const float VIGNETTE_STRENGTH = 0.0;
	static const float OVERLAY_FACTOR = 0.0;
	static const float BLOOM_THRESHOLD = 0.01;
	static const float BLOOM_STEEPNESS = 0.0;
	static const float BLOOM_INTENSITY = 0.5;
	static const float LENS_DISTORT = 0.0;
	static const float LENS_CENTER_X = 0.0;
	static const float LENS_CENTER_Y = 0.0;
	static const float LENS_CHROM_ABER = 0.0;
	static const float MOTION_BLUR_POWER = 0.01;
	static const float MOTION_BLUR_INTENSITY = 0.1;
	static const float MOTION_BLUR_MINDEPTH = 0.8;
	static const float MOTION_BLUR_MAXDEPTH = 0.9;
	static const float GAUSS_BLUR_INTENSITY = 0.0;
	static const float RADIAL_BLUR_POWER_X = 0.0;
	static const float RADIAL_BLUR_POWER_Y = 0.0;
	static const float RADIAL_BLUR_OFFSET_X = 0.0;
	static const float RADIAL_BLUR_OFFSET_Y = 0.0;
	static const float CHROM_ABER_POWER_X = 0.0;
	static const float CHROM_ABER_POWER_Y = 0.0;
	static const float FILM_GRAIN_SHARPNESS = 0.0;
	static const float FILM_GRAIN_GRAIN_SIZE = 0.0;
	static const float GODRAYS_SUN_INTENSITY = 0.8;
	static const float GODRAYS_SUN_OVERBURN_INTENSITY = 0.25;
	static const float GODRAYS_SUN_OVERBURN_START = 0.025;
	static const float GODRAYS_SUN_OVERBURN_END = 0.175;
	static const float GODRAYS_SUN_MASK = 0.8;
	static const float GODRAYS_SUN_SIZE = 0.15;
	static const float GODRAYS_SUN_V_INTENSITY = 0.75;
	static const float GODRAYS_SUN_D_INTENSITY = 0.60;
	
	static const float VIGNETTE_COLOR[4] = {0.0, 0.0, 0.0, 0.0};
	static const float OVERLAY_COLOR[4] = {0.0, 0.0, 0.0, 0.0};
	static const float COLORIZATION[4] = {1.0, 1.0, 1.0, 1.0};
}