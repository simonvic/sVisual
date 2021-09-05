modded class PPEDefaultPreset {
	override void onInit(){
		
		SGameConfigVisual cfg = SGameConfig.visual();
		
		//////////////////////////////////////////
		// Float params
		setSaturation(cfg.getDefaultPPEFloat("saturation"));
		setVignetteIntensity(cfg.getDefaultPPEFloat("vignette_strength"));
		setOverlayFactor(cfg.getDefaultPPEFloat("overlay_factor"));
		
		setBloomTreshold(cfg.getDefaultPPEFloat("bloom_threshold"));
		setBloomSteepness(cfg.getDefaultPPEFloat("bloom_steepness"));
		setBloomIntensity(cfg.getDefaultPPEFloat("bloom_intensity"));
		
		setMotionBlurPower(cfg.getDefaultPPEFloat("motion_blur_power"));
		setMotionBlurMinDepth(cfg.getDefaultPPEFloat("motion_blur_mindepth"));
		setMotionBlurMaxDepth(cfg.getDefaultPPEFloat("motion_blur_maxdepth"));
		setMotionBlurMinAnglePerSec(cfg.getDefaultPPEFloat("motion_blur_min_angle_per_sec"));
		setMotionBlurMaxAnglePerSec(cfg.getDefaultPPEFloat("motion_blur_max_angle_per_sec"));
		
		setGausBlur(cfg.getDefaultPPEFloat("gauss_blur_intensity"));
																						       
		setRadialBlurPowerX(cfg.getDefaultPPEFloat("radial_blur_power_x"));
		setRadialBlurPowerY(cfg.getDefaultPPEFloat("radial_blur_power_y"));
		setRadialBlurOffsetX(cfg.getDefaultPPEFloat("radial_blur_offset_x"));
		setRadialBlurOffsetY(cfg.getDefaultPPEFloat("radial_blur_offset_y"));
		
		setChromAberPowerX(cfg.getDefaultPPEFloat("chrom_aber_power_x"));
		setChromAberPowerY(cfg.getDefaultPPEFloat("chrom_aber_power_y"));
		
		setFilmGrainSharpness(cfg.getDefaultPPEFloat("film_grain_sharpness"));
		setFilmGrainSize(cfg.getDefaultPPEFloat("film_grain_grain_size"));
		
		
		setGodraysIntensity(cfg.getDefaultPPEFloat("godrays_sun_intensity"));
		setGodraysOverburn(cfg.getDefaultPPEFloat("godrays_sun_overburn_intensity"));
		setGodraysOverburnStart(cfg.getDefaultPPEFloat("godrays_sun_overburn_start"));
		setGodraysOverburnEnd(cfg.getDefaultPPEFloat("godrays_sun_overburn_end"));
		setGodraysMask(cfg.getDefaultPPEFloat("godrays_sun_mask"));
		setGodraysSize(cfg.getDefaultPPEFloat("godrays_sun_size"));
		setGodraysVerticalIntensity(cfg.getDefaultPPEFloat("godrays_sun_v_intensity"));
		setGodraysDiagonalIntensity(cfg.getDefaultPPEFloat("godrays_sun_d_intensity"));
		
		//////////////////////////////////////////
		// Color params
		setVignetteColor(cfg.getDefaultPPEColor("vignette_color"));
		setOverlayColor(cfg.getDefaultPPEColor("overlay_color"));
		setColorization(cfg.getDefaultPPEColor("colorization"));		
	}
}
