modded class PPEDefaultPreset {
	override void onInit(){
		
		SGameConfigVisual cfg = SGameConfig.visual();
		
		// ========= Float params =============
		setParam(MaterialNames.GLOW,        PPEParamNames.SATURATION,                          cfg.getDefaultPPEFloat("saturation") );
		setParam(MaterialNames.GLOW,        PPEParamNames.VIGNETTE_STRENGTH,                   cfg.getDefaultPPEFloat("vignette_strength") );
		setParam(MaterialNames.GLOW,        PPEParamNames.OVERLAY_FACTOR,                      cfg.getDefaultPPEFloat("overlay_factor") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_THRESHOLD,                     cfg.getDefaultPPEFloat("bloom_threshold") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_STEEPNESS,                     cfg.getDefaultPPEFloat("bloom_steepness") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_INTENSITY,                     cfg.getDefaultPPEFloat("bloom_intensity") );
		/*                                                                                     
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_DISTORT,                        cfg.getDefaultPPEFloat("lens_distort") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CENTER_X,                       cfg.getDefaultPPEFloat("lens_center_x") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CENTER_Y,                       cfg.getDefaultPPEFloat("lens_center_y") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CHROM_ABER,                     cfg.getDefaultPPEFloat("lens_chrom_aber") );
		*/                                                                                     
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER,                   cfg.getDefaultPPEFloat("motion_blur_power") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MINDEPTH,                cfg.getDefaultPPEFloat("motion_blur_mindepth") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAXDEPTH,                cfg.getDefaultPPEFloat("motion_blur_maxdepth") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MIN_ANGLE_PER_SEC,       cfg.getDefaultPPEFloat("motion_blur_min_angle_per_sec") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAX_ANGLE_PER_SEC,       cfg.getDefaultPPEFloat("motion_blur_max_angle_per_sec") );
																						       
		setParam(MaterialNames.GAUSS_BLUR,  PPEParamNames.GAUSS_BLUR_INTENSITY,                cfg.getDefaultPPEFloat("gauss_blur_intensity") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_X,                 cfg.getDefaultPPEFloat("radial_blur_power_x") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_Y,                 cfg.getDefaultPPEFloat("radial_blur_power_y") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_X,                cfg.getDefaultPPEFloat("radial_blur_offset_x") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_Y,                cfg.getDefaultPPEFloat("radial_blur_offset_y") );
		setParam(MaterialNames.CHROM_ABER,  PPEParamNames.CHROM_ABER_POWER_X,                  cfg.getDefaultPPEFloat("chrom_aber_power_x") );
		setParam(MaterialNames.CHROM_ABER,  PPEParamNames.CHROM_ABER_POWER_Y,                  cfg.getDefaultPPEFloat("chrom_aber_power_y") );
		setParam(MaterialNames.FILM_GRAIN,  PPEParamNames.FILM_GRAIN_SHARPNESS,                cfg.getDefaultPPEFloat("film_grain_sharpness") );
		setParam(MaterialNames.FILM_GRAIN,  PPEParamNames.FILM_GRAIN_GRAIN_SIZE,               cfg.getDefaultPPEFloat("film_grain_grain_size") );
		
		/*@todo fix flickering (it happens when looking straight at the sun
		//@todo reimplement godrays params
		setParam(MaterialNames.GODRAYS_SUN,      PPEParamNames.GODRAYS_SUN_INTENSITY,          cfg.getDefaultPPEFloat("godrays_sun_intensity") );
		setParam(MaterialNames.GODRAYS_SUN,      PPEParamNames.GODRAYS_SUN_OVERBURN_INTENSITY, cfg.getDefaultPPEFloat("godrays_sun_overburn_intensity") );
		setParam(MaterialNames.GODRAYS_SUN,      PPEParamNames.GODRAYS_SUN_OVERBURN_START,     cfg.getDefaultPPEFloat("godrays_sun_overburn_start") );
		setParam(MaterialNames.GODRAYS_SUN,      PPEParamNames.GODRAYS_SUN_OVERBURN_END,       cfg.getDefaultPPEFloat("godrays_sun_overburn_end") );
		setParam(MaterialNames.GODRAYS_SUN_MASK, PPEParamNames.GODRAYS_SUN_MASK,               cfg.getDefaultPPEFloat("godrays_sun_mask") );
		setParam(MaterialNames.GODRAYS_SUN_MASK, PPEParamNames.GODRAYS_SUN_SIZE,               cfg.getDefaultPPEFloat("godrays_sun_size") );
		setParam(MaterialNames.GODRAYS_SUN_MASK, PPEParamNames.GODRAYS_SUN_V_INTENSITY,        cfg.getDefaultPPEFloat("godrays_sun_v_intensity") );
		setParam(MaterialNames.GODRAYS_SUN_MASK, PPEParamNames.GODRAYS_SUN_D_INTENSITY,        cfg.getDefaultPPEFloat("godrays_sun_d_intensity") );
		*/
		
		// ========= Color params =============
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_COLOR,                             cfg.getDefaultPPEColor("vignette_color") );
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_COLOR,                              cfg.getDefaultPPEColor("overlay_color") );
		setParam(MaterialNames.GLOW, PPEParamNames.GLOW_COLORIZATION,                          cfg.getDefaultPPEColor("colorization") );
	}
}
