////////////////////////////////////////////
// VALUE based presets
////////////////////////////////////////////
class PPEPresetBase{
	void PPEPresetBase(){
		init();
	}
	
	void init(){};
}

class DoFPreset : PPEPresetBase{
	float blurStrenght;
	float focusDistance;
	float focusLenght;
	float focusLenghtNear;
	float focusDepthOffset;
	float focusMinDistance;
	float focusMaxDistance;
	
	void initPreset(float blur, float fDistance, float fLength, float fLengthNear, float fDepthOffset, float fMinDistance, float fMaxDistance){
		blurStrenght = blur;
		focusDistance = fDistance;
		focusLenght = fLength;
		focusLenghtNear = fLengthNear;
		focusDepthOffset = fDepthOffset;
		focusMinDistance = fMinDistance;
		focusMaxDistance = fMaxDistance;
	}
}

class PPEMaskPreset : PPEPresetBase{
	float posX;
	float posY;
	float radius;
	float blur;
	
	void initPreset(float positionX, float positionY, float maskRadius, float blurStrength){
		posX = positionX;
		posY = positionY;
		radius = maskRadius;
		blur = blurStrength;
	}
	
}






////////////////////////////////////////////
// Material based presets
////////////////////////////////////////////
class PPEMaterialPresetBase : PPEParams{
	void PPEMaterialPresetBase(){
		init();
	}
	
	void init(){};
}

//to-do replace set param with setter helpers
class PPEDefaultPreset : PPEMaterialPresetBase{
	override void init(){
		
		SConfigVisual cfg = SConfig.visual();
		
		// ========= Float params =============
		setParam(MaterialNames.GLOW,        PPEParamNames.SATURATION,            cfg.getDefaultPPEFloat("saturation") );
		setParam(MaterialNames.GLOW,        PPEParamNames.VIGNETTE_STRENGTH,     cfg.getDefaultPPEFloat("vignette_strength") );
		setParam(MaterialNames.GLOW,        PPEParamNames.OVERLAY_FACTOR,        cfg.getDefaultPPEFloat("overlay_factor") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_THRESHOLD,       cfg.getDefaultPPEFloat("bloom_threshold") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_STEEPNESS,       cfg.getDefaultPPEFloat("bloom_steepness") );
		setParam(MaterialNames.GLOW,        PPEParamNames.BLOOM_INTENSITY,       cfg.getDefaultPPEFloat("bloom_intensity") );
		/*
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_DISTORT,          cfg.getDefaultPPEFloat("lens_distort") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CENTER_X,         cfg.getDefaultPPEFloat("lens_center_x") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CENTER_Y,         cfg.getDefaultPPEFloat("lens_center_y") );
		setParam(MaterialNames.GLOW,        PPEParamNames.LENS_CHROM_ABER,       cfg.getDefaultPPEFloat("lens_chrom_aber") );
		*/
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER,     cfg.getDefaultPPEFloat("motion_blur_power") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_INTENSITY, cfg.getDefaultPPEFloat("motion_blur_intensity") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MINDEPTH,  cfg.getDefaultPPEFloat("motion_blur_mindepth") );
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAXDEPTH,  cfg.getDefaultPPEFloat("motion_blur_maxdepth") );
		setParam(MaterialNames.GAUSS_BLUR,  PPEParamNames.GAUSS_BLUR_INTENSITY,  cfg.getDefaultPPEFloat("gauss_blur_intensity") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_X,   cfg.getDefaultPPEFloat("radial_blur_power_x") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_Y,   cfg.getDefaultPPEFloat("radial_blur_power_y") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_X,  cfg.getDefaultPPEFloat("radial_blur_offset_x") );
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_Y,  cfg.getDefaultPPEFloat("radial_blur_offset_y") );
		setParam(MaterialNames.CHROM_ABER,  PPEParamNames.CHROM_ABER_POWER_X,    cfg.getDefaultPPEFloat("chrom_aber_power_x") );
		setParam(MaterialNames.CHROM_ABER,  PPEParamNames.CHROM_ABER_POWER_Y,    cfg.getDefaultPPEFloat("chrom_aber_power_y") );
		setParam(MaterialNames.FILM_GRAIN,  PPEParamNames.FILM_GRAIN_SHARPNESS,  cfg.getDefaultPPEFloat("film_grain_sharpness") );
		setParam(MaterialNames.FILM_GRAIN,  PPEParamNames.FILM_GRAIN_GRAIN_SIZE, cfg.getDefaultPPEFloat("film_grain_grain_size") );
			
		/*to-do fix flickering (it happens when looking straight at the sun
		//to-do reimplement godrays params
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
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_COLOR,    cfg.getDefaultPPEColor("vignette_color") );
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_COLOR,     cfg.getDefaultPPEColor("overlay_color") );
		setParam(MaterialNames.GLOW, PPEParamNames.GLOW_COLORIZATION, cfg.getDefaultPPEColor("colorization") );
	}
}

class PPEMotionBlurPreset : PPEMaterialPresetBase{
	void initPreset(float blurPower, float blurIntensity, float minimumDepth, float maximumDepth){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER, blurPower);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_INTENSITY, blurIntensity);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MINDEPTH, minimumDepth);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAXDEPTH, maximumDepth);
	}
}

class PPEVignettePreset : PPEMaterialPresetBase{
	void initPreset(float strength, TPPEColor color ){
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_STRENGTH, strength);
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_COLOR, color);
	}
}

class PPERadialBlurPreset : PPEMaterialPresetBase{
	void initPreset(float powerX, float powerY, float offsetX, float offsetY){
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_X, powerX);
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_Y, powerY);
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_X, offsetX);
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_Y, offsetY);
	}
}

class PPEChromAberPreset : PPEMaterialPresetBase{
	void initPreset(float powerX, float powerY){
		setParam(MaterialNames.CHROM_ABER, PPEParamNames.CHROM_ABER_POWER_X, powerX);
		setParam(MaterialNames.CHROM_ABER, PPEParamNames.CHROM_ABER_POWER_Y, powerY);
	}
}

class PPEBloomPreset : PPEMaterialPresetBase{
	void initPreset(float treshold, float steepness, float intensity){
		setParam(MaterialNames.GLOW, PPEParamNames.CHROM_ABER_POWER_X, treshold);
		setParam(MaterialNames.GLOW, PPEParamNames.CHROM_ABER_POWER_Y, steepness);
		setParam(MaterialNames.GLOW, PPEParamNames.CHROM_ABER_POWER_Y, intensity);
	}
}

class PPEOverlayPreset : PPEMaterialPresetBase{
	void initPreset(float factor, TPPEColor color){
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_FACTOR, factor);
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_COLOR, color);
	}
}

class PPEFilmGrainPreset : PPEMaterialPresetBase{
	void initPreset(float sharpness, float grainSize){
		setParam(MaterialNames.FILM_GRAIN, PPEParamNames.FILM_GRAIN_SHARPNESS, sharpness);
		setParam(MaterialNames.FILM_GRAIN, PPEParamNames.FILM_GRAIN_GRAIN_SIZE, grainSize);
	}
}

class PPELensPreset : PPEMaterialPresetBase{
	void initPreset(float distortStrength, float centerX, float centerY, float chromAber){
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_DISTORT, distortStrength);
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CENTER_X, centerX);
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CENTER_Y, centerY);
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CHROM_ABER, chromAber);
	}
}

class PPECameraEffectPreset : PPEMaterialPresetBase{
	 void initPreset(float saturation, TPPEColor colorization){
		setParam(MaterialNames.GLOW, PPEParamNames.SATURATION, saturation);
		setParam(MaterialNames.GLOW, PPEParamNames.GLOW_COLORIZATION, colorization);		
	}
}

class PPEBlurPreset : PPEMaterialPresetBase{
	void initPreset(float intensity){
		setParam(MaterialNames.GLOW, PPEParamNames.GAUSS_BLUR_INTENSITY, intensity);
	}
}