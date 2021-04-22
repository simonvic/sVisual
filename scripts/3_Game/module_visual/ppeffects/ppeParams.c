
typedef string TPPEMaterial; //I have to use material name instead of Material because it crashes (maybe the problem is passing the material which is int[] ? )
typedef string TPPEParamName; //name of the post process effect parameter
typedef array<float> TPPEColor; // dynamic array of float representing RGBA color

typedef float Float;
typedef map<TPPEParamName, float> TPPEFloatParams; //float post process effect parameter
typedef map<TPPEParamName, ref TPPEColor> TPPEColorParams; //RGBA post process effect parameter

typedef map<TPPEMaterial, ref TPPEFloatParams> TPPEFloatParamsMap; //map of Material and its float parameters
typedef map<TPPEMaterial, ref TPPEColorParams> TPPEColorParamsMap; //map of Material and its color parameters (because fuck generics lol)

typedef array<ref PPEMaterialPresetBase> TPPEMaterialPresets;


class MaterialNames {
	static const TPPEMaterial GLOW = "Graphics/Materials/postprocess/glow";
	static const TPPEMaterial RADIAL_BLUR = "graphics/materials/postprocess/radialblur";
	static const TPPEMaterial MOTION_BLUR = "graphics/materials/postprocess/rotblur";
	static const TPPEMaterial GAUSS_BLUR = "graphics/materials/postprocess/gauss";
	static const TPPEMaterial CHROM_ABER = "graphics/materials/postprocess/chromaber";
	static const TPPEMaterial FILM_GRAIN = "Graphics/Materials/postprocess/filmgrainNV";
	static const TPPEMaterial GODRAYS_SUN = "graphics/materials/postprocess/godrayssun";
	static const TPPEMaterial GODRAYS_SUN_MASK = "graphics/materials/postprocess/godrayssunmask";
	static const TPPEMaterial HBAO = "graphics/materials/postprocess/hbao";
	static const TPPEMaterial RAIN = "graphics/materials/postprocess/rain";
}

class PPEParamNames { //just a precaution for future updates... because who knows :shrug:
	static const TPPEParamName VIGNETTE_STRENGTH = "Vignette";
	static const TPPEParamName VIGNETTE_COLOR = "VignetteColor";
	
	static const TPPEParamName MOTION_BLUR_INTENSITY = "Intensity";
	static const TPPEParamName MOTION_BLUR_POWER = "Power";
	static const TPPEParamName MOTION_BLUR_MINDEPTH = "MinDepth";
	static const TPPEParamName MOTION_BLUR_MAXDEPTH = "MaxDepth";
	
	static const TPPEParamName RADIAL_BLUR_POWER_X = "PowerX";
	static const TPPEParamName RADIAL_BLUR_POWER_Y = "PowerY";
	static const TPPEParamName RADIAL_BLUR_OFFSET_X = "OffsetX";
	static const TPPEParamName RADIAL_BLUR_OFFSET_Y = "OffsetY";
	
	static const TPPEParamName LENS_DISTORT = "LensDistort";
	static const TPPEParamName LENS_CENTER_X = "LensCenterX";
	static const TPPEParamName LENS_CENTER_Y = "LensCenterY";
	static const TPPEParamName LENS_CHROM_ABER = "MaxChromAbberation";
	
	static const TPPEParamName GLOW_COLORIZATION = "ColorizationColor";
	static const TPPEParamName SATURATION = "Saturation";
	
	static const TPPEParamName OVERLAY_FACTOR = "OverlayFactor";
	static const TPPEParamName OVERLAY_COLOR = "OverlayColor";
	
	static const TPPEParamName BLOOM_THRESHOLD = "BloomThreshold";
	static const TPPEParamName BLOOM_STEEPNESS = "BloomSteepness";
	static const TPPEParamName BLOOM_INTENSITY = "BloomIntensity";
	
	static const TPPEParamName CHROM_ABER_POWER_X = "PowerX";
	static const TPPEParamName CHROM_ABER_POWER_Y = "PowerY";
	
	static const TPPEParamName FILM_GRAIN_SHARPNESS = "Sharpness";
	static const TPPEParamName FILM_GRAIN_GRAIN_SIZE = "GrainSize";
	
	static const TPPEParamName GAUSS_BLUR_INTENSITY = "Intensity";
	
	static const TPPEParamName GODRAYS_SUN_INTENSITY = "Intensity";
	static const TPPEParamName GODRAYS_SUN_OVERBURN_INTENSITY = "OverBurnIntensity";
	static const TPPEParamName GODRAYS_SUN_OVERBURN_START = "OverBurnStart";
	static const TPPEParamName GODRAYS_SUN_OVERBURN_END = "OverBurnEnd";
	
	static const TPPEParamName GODRAYS_SUN_MASK = "Intensity";
	static const TPPEParamName GODRAYS_SUN_SIZE = "SunSize";
	static const TPPEParamName GODRAYS_SUN_V_INTENSITY = "VerticalStreakIntensity";
	static const TPPEParamName GODRAYS_SUN_D_INTENSITY = "DiagonalStreakIntensity";
	
	static const TPPEParamName HBAO_RADIUS = "RadiusMeters";
	static const TPPEParamName HBAO_INTENSITY = "Intensity";
	static const TPPEParamName HBAO_SAMPLES = "NumSamples"; //power of 2
	
	static const TPPEParamName RAIN_SPEED = "Speed";
	static const TPPEParamName RAIN_DISTANTSPEED = "DistantSpeed";
	
}

//@todo make this managed?
class PPEParams {
	
	protected ref TPPEFloatParamsMap m_params = new TPPEFloatParamsMap();
	protected ref TPPEColorParamsMap m_colorParams = new TPPEColorParamsMap();
	protected bool m_hasChanged = true;
	protected bool m_isActive = false;
	
	void ~PPEParams(){
		//PPEManager.deactivate(this);
	}
	
	/**
	* @brief Init the parameters with multiple PPEPresets
	* 	@param presets \p TPPEMaterialPresets - Presets parameters to be added
	*/
	void init(TPPEMaterialPresets presets){
		clear();
		add(presets);
	}
	
	/**
	* @brief Init the parameters with a PPEPreset
	* 	@param preset \p PPEMaterialPresetBase - Preset parameters to be added
	*/
	void init(PPEMaterialPresetBase preset){
		clear();
		add(preset);	
	}
	
	/**
	* @brief Init the parameters with another PPEParams
	* 	@param ppeParams \p PPEParams - Parameters to be added
	*/
	void init(PPEParams ppeParams){
		clear();
		add(ppeParams);
	}
	
	/**
	* @brief Add parameters of multiple presets
	* 	@param presets \p TPPEMaterialPresets - Presets parameters to be added
	*/
	void add(TPPEMaterialPresets presets){
		foreach(PPEMaterialPresetBase preset : presets){
			add(preset);
		}
	}
	
	/**
	* @brief Add parameters from another PPEParams
	* 	@param ppeParams \p PPEParams - Parameters to be added
	*/
	void add(PPEParams ppeParams){
		add(ppeParams.getFloatParams());
		add(ppeParams.getColorParams());
	}
	
	/**
	* @brief Add float parameters
	* 	@param params \p TPPEFloatParamsMap - Parameters to be added
	*/
	void add(TPPEFloatParamsMap params){		
		foreach(auto ppeMaterial, auto ppeParam : params){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				setParam(ppeMaterial, ppeParamName, ppeParamValue);
			}
		}
	}
	
	/**
	* @brief Add color parameters
	* 	@param params \p TPPEColorParamsMap - Parameters to be added
	*/
	void add(TPPEColorParamsMap params){
		foreach(auto ppeMaterial, auto ppeParam : params){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				setParam(ppeMaterial, ppeParamName, ppeParamValue);
			}
		}
	}
	
	/**
	* @brief Merge with another PPEParams by interpolating the values
	* 	@param params \p PPEParams - Parameters to be merged with
	* 	@param coeff \p float - Interpolation coefficient
	*/
	void merge(PPEParams params, float coeff = 0.5){
		mergeFloatParams(params, coeff);
		mergeColorParams(params, coeff);
	} 
	
	void mergeFloatParams(PPEParams params, float coeff = 0.5){
		TPPEFloatParamsMap tempFloat = params.getFloatParams();
		foreach(auto ppeMaterial, auto ppeParam : tempFloat){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				setParam(ppeMaterial, ppeParamName, Math.Lerp(ppeParamValue, getFloatParam(ppeMaterial, ppeParamName), coeff ));				
			}
		}
	}
	
	void mergeColorParams(PPEParams params, float coeff = 0.5){
		TPPEColorParamsMap tempColor = params.getColorParams();
		foreach(auto ppeMaterial, auto ppeParam : tempColor){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				TPPEColor prevColor = getColorParam(ppeMaterial, ppeParamName);
				if(!prevColor){ 
					prevColor = PPEManager.getColorDefaultValue(ppeMaterial, ppeParamName);
				}
				setParam(ppeMaterial, ppeParamName, PPEManager.mixColors(ppeParamValue, prevColor, coeff ));
			}
		}
	}
	
	/**
	* @brief Delete all parameters
	*/
	void clear(){
		m_params.Clear();
		m_colorParams.Clear();
	}
	
	/**
	* @brief Reset all parameters to their default values
	*/
	void resetAllToDefault(){
		resetFloatToDefault();
		resetColorsToDefault();
	}
	
	void resetFloatToDefault(){
		foreach(auto ppeMaterial, auto ppeParam : m_params){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				resetToDefault(ppeMaterial, ppeParamName);
			}
		}
	}
	
	void resetColorsToDefault(){
		foreach(auto ppeMaterial, auto ppeParam : m_colorParams){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				resetToDefault(ppeMaterial, ppeParamName);
			}
		}
	}
	
	/**
	* @brief Reset the parameter to its default value
	* 	@param ppeMaterial \p TPPEMaterial - Material of parameter
	* 	@param ppeParamName \p PPEParamNames - Name of parameter
	*/
	void resetToDefault(TPPEMaterial ppeMaterial, TPPEParamName ppeParamName){
		
		TPPEColor colorDefault = PPEManager.getColorDefaultValue(ppeMaterial,ppeParamName);		
		if(colorDefault) {
			setParam(ppeMaterial, ppeParamName, colorDefault);
			return;
		}
		
		float floatDefault = PPEManager.getFloatDefaultValue(ppeMaterial,ppeParamName);	
		setParam(ppeMaterial, ppeParamName, floatDefault);
	}
	
	TPPEFloatParamsMap getFloatParams(){
		return m_params;
	}
	
	TPPEColorParamsMap getColorParams(){
		return m_colorParams;
	}
	
	float getFloatParam(TPPEMaterial ppeMaterial, TPPEParamName ppeParamName){
		if(m_params && m_params[ppeMaterial]) {
			return m_params[ppeMaterial][ppeParamName];
		}
		return 0;
	}
	
	TPPEColor getColorParam(TPPEMaterial ppeMaterial, TPPEParamName ppeParamName){
		if(m_colorParams && m_colorParams[ppeMaterial] ) {
			return m_colorParams[ppeMaterial][ppeParamName];
		}
		return null;
	}
	
	int count(){
		return countFloat() + countColor(); //@todo improve this
	}
	
	int countFloat(){
		int total;
		foreach(auto ppeMaterial, auto ppeParam : m_params){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				total++;
			}
		}
		return total;
	}
	
	int countColor(){
		int total;
		foreach(auto ppeMaterial, auto ppeParam : m_colorParams){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				total++;
			}
		}
		return total;
	}
	
	/**
	* @brief Check if two PPEParams are equals
	* 	@param params \p PPEParams - params to compare with
	* 	@return \p bool - if are equals (not really equals, for now it only checks if their shared parameters values are equals; it doesn't compare additional parameters in "params")
	*/
	bool equals(PPEParams params){
		if(this == params) return true;
		if(params == null) return false;
		//if(this.Type() != params.Type()) return false;
		return equalsFloat(params) && equalsColor(params);
	}
	
	bool equalsFloat(PPEParams params){
		TPPEFloatParamsMap floatParams = params.getFloatParams();
		foreach(auto ppeMaterial, auto ppeParam : m_params){
			//if it doesn't contain the same parameter
			if(!floatParams[ppeMaterial]){
				return false;
			}
			
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				//if the parameter value is different				
				if( !SMath.equal(floatParams[ppeMaterial][ppeParamName], m_params[ppeMaterial][ppeParamName], PPEConstants.EPSILON) ){
					return false;
				}
			}
		}
		return true;
	}
	
	bool equalsColor(PPEParams params){
		TPPEColorParamsMap colorParams = params.getColorParams();
		foreach(auto ppeMaterial, auto ppeParam : m_colorParams){
			//if it doesn't contain the same parameter
			if(!colorParams[ppeMaterial]){ 
				return false;
			}
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				//if the parameter value is different
				if( !SMath.equal(colorParams[ppeMaterial][ppeParamName], m_colorParams[ppeMaterial][ppeParamName], PPEConstants.EPSILON) ){ 
					return false;
				}
			}
		}
		return true;
	}
	
	bool isActive(){
		return m_isActive;
	}
	
	bool hasChanged(){
		return m_hasChanged;
	}
	
	void onActivate(){
		m_isActive = true;
	}
	
	void onApply(){
		m_hasChanged = false;
	}
	
	void onMerge(){
		m_hasChanged = false;
	}
	
	protected void onChange(){
		m_hasChanged = true;
	}
	
	void onDeactivate(){
		m_isActive = false;
	}
	
	
	
	
	//----------------------------------------------------------
	//				SETTER HELPER
	//----------------------------------------------------------
	
	
	////////////// VIGNETTE
	
	/**
	* @brief Quickly set vignette parameters
	* 	@param intensity \p float - Intensity of vignette
	* 	@param color \p TPPEColor - Color of vignette
	*/
	void setVignette(float intensity, TPPEColor color){
		setVignetteIntensity(intensity);
		setVignetteColor(color);
	}
	
	/**
	* @brief Quickly set vignette intensity
	* 	@param intensity \p float - Intensity of vignette
	*/
	void setVignetteIntensity(float intensity){
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_STRENGTH, intensity);
	}
	
	/**
	* @brief Quickly set vignette color
	* 	@param color \p TPPEColor - Color of vignette
	*/
	void setVignetteColor(TPPEColor color){
		setParam(MaterialNames.GLOW, PPEParamNames.VIGNETTE_COLOR, color);
	}
	
	
	
	
	////////////// OVERLAY
	
	/**
	* @brief Quickly set overlay parameters
	* 	@param factor \p float - Factor(strength?) of overlay
	* 	@param color \p TPPEColor - Color of overlay
	*/
	void setOverlay(float factor, TPPEColor color){
		setOverlayFactor(factor);
		setOverlayColor(color);
	}
	
	/**
	* @brief Quickly set overlay factor
	* 	@param factor \p float - Factor(strength?) of overlay
	*/
	void setOverlayFactor(float factor){
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_FACTOR, factor);
	}
	
	/**
	* @brief Quickly set overlay color
	* 	@param color \p TPPEColor - Color of overlay
	*/
	void setOverlayColor(TPPEColor color){
		setParam(MaterialNames.GLOW, PPEParamNames.OVERLAY_COLOR, color);
	}
	
	
	
	////////////// RADIAL BLUR
	
	/**
	* @brief Quickly set radial blur parameters
	* 	@param powerX \p float - Horizontal strength
	* 	@param powerY \p float - Vertical strength
	* 	@param offsetX \p float - Horizontal offset
	* 	@param offsetY \p float - Vertical offset
	*/
	void setRadialBlur(float powerX, float powerY, float offsetX = 0.0, float offsetY = 0.0){
		setRadialBlurPowerX(powerX);	
		setRadialBlurPowerY(powerY);	
		setRadialBlurOffsetX(offsetX);	
		setRadialBlurOffsetY(offsetY);	
	}
	
	/**
	* @brief Quickly set radial blur horizontal power
	* 	@param powerX \p float - Horizontal strength
	*/
	void setRadialBlurPowerX(float powerX){
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_X, powerX);			
	}
	
	/**
	* @brief Quickly set radial blur vertical power
	* 	@param powerY \p float - Vertical strength
	*/
	void setRadialBlurPowerY(float powerY){
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_POWER_Y, powerY);			
	}
	
	/**
	* @brief Quickly set radial blur horizontal offset
	* 	@param offsetX \p float - Horizontal offset
	*/
	void setRadialBlurOffsetX(float offsetX){
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_X, offsetX);
	}
	
	/**
	* @brief Quickly set radial blur vertical offset
	* 	@param offsetY \p float - Vertical offset
	*/
	void setRadialBlurOffsetY(float offsetY){
		setParam(MaterialNames.RADIAL_BLUR, PPEParamNames.RADIAL_BLUR_OFFSET_Y, offsetY);
	}
	
	
	
	
	////////////// FILM GRAIN
	
	/**
	* @brief Quickly set film grain parameters
	* 	@param sharpness \p float - Sharpness
	* 	@param grainSize \p float - Grain size
	*/
	void setFilmGrain(float sharpness, float grainSize){
		setFilmGrainSharpness(sharpness);
		setFilmGrainSize(grainSize);
	}
	
	/**
	* @brief Quickly set film grain sharpness
	* 	@param sharpness \p float - Sharpness
	*/
	void setFilmGrainSharpness(float sharpness){
		setParam(MaterialNames.FILM_GRAIN, PPEParamNames.FILM_GRAIN_SHARPNESS, sharpness);		
	}
	
	/**
	* @brief Quickly set film grain size
	* 	@param grainSize \p float - Grain size
	*/
	void setFilmGrainSize(float grainSize){
		setParam(MaterialNames.FILM_GRAIN, PPEParamNames.FILM_GRAIN_GRAIN_SIZE, grainSize);
	}
	
	
	
	
	
	////////////// GAUSSIAN BLUR
	
	/**
	* @brief Quickly set gaussian blur parameters
	* 	@param intensity \p float - Intensity
	*/
	void setGausBlur(float intensity){
		setParam(MaterialNames.GAUSS_BLUR, PPEParamNames.GAUSS_BLUR_INTENSITY, intensity);
	}
	
	
	
	////////////// CHROMATIC ABERATION
	
	/**
	* @brief Quickly set chromatic aberration parameters
	* 	@param powerX \p float - Horizontal intensity
	* 	@param powerY \p float - Vertical intensity
	*/
	void setChromAber(float powerX, float powerY){
		setChromAberPowerX(powerX);
		setChromAberPowerY(powerY);
	}
	
	/**
	* @brief Quickly set chromatic horizontal intensity
	* 	@param powerX \p float - Horizontal intensity
	*/
	void setChromAberPowerX(float powerX){
		setParam(MaterialNames.CHROM_ABER, PPEParamNames.CHROM_ABER_POWER_X, powerX);
	}
	
	/**
	* @brief Quickly set chromatic vertical intensity
	* 	@param powerY \p float - Vertical intensity
	*/
	void setChromAberPowerY(float powerY){
		setParam(MaterialNames.CHROM_ABER, PPEParamNames.CHROM_ABER_POWER_Y, powerY);
	}
	
	
	
	
	////////////// MAGNIFICATION LENS
	
	/**
	* @brief Quickly set magnification lens parameters
	* 	@param intensity \p float - Magnification power
	* 	@param centerX \p float - Horizontal screen position
	* 	@param centerY \p float - Vertical screen position
	* 	@param chromAber \p float - Lens chromatic aberration
	*/
	void setLens(float intensity, float centerX = 0.0, float centerY = 0.0, float chromAber = 0.0){
		setLensIntensity(intensity);
		setLensCenterX(centerX);
		setLensCenterY(centerY);
		setLensChromAber(chromAber);
	}
	
	/**
	* @brief Quickly set magnification lens intensity
	* 	@param intensity \p float - Magnification power
	*/
	void setLensIntensity(float intensity){
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_DISTORT, intensity);
	}
	
	/**
	* @brief Quickly set magnification horizontal position
	* 	@param centerX \p float - Horizontal screen position
	*/
	void setLensCenterX(float centerX){
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CENTER_X, centerX);
	}
	
	/**
	* @brief Quickly set magnification vertical position
	* 	@param centerY \p float - Vertical screen position
	*/
	void setLensCenterY(float centerY){
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CENTER_Y, centerY);
	}
	
	/**
	* @brief Quickly set magnification lens chromatic aberration
	* 	@param chromAber \p float - Lens chromatic aberration
	*/
	void setLensChromAber(float chromAber = 0.0){
		setParam(MaterialNames.GLOW, PPEParamNames.LENS_CHROM_ABER, chromAber);
	}
	
	
	
	
	////////////// MOTION BLUR
	
	/**
	* @brief Quickly set motion blur parameters
	* 	@param intensity \p float - Intensity
	* 	@param power \p float - Power
	* 	@param minDepth \p float - Minimum depth from the camera position
	* 	@param maxDepth \p float - Maximum depth from the camera position
	*/
	void setMotionBlur(float intensity, float power, float minDepth, float maxDepth){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_INTENSITY, intensity);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER, power);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MINDEPTH, minDepth);
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAXDEPTH, maxDepth);
	}
	
	/**
	* @brief Quickly set motion blur intensity
	* 	@param intensity \p float - Intensity
	*/
	void setMotionBlurIntensity(float intensity){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_INTENSITY, intensity);
	}
	
	/**
	* @brief Quickly set motion blur power
	* 	@param power \p float - Power
	*/
	void setMotionBlurPower(float power){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER, power);
	}
	
	/**
	* @brief Quickly set motion blur minimum depth
	* 	@param minDepth \p float - Minimum depth from the camera position
	*/
	void setMotionBlurMinDepth(float minDepth){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MINDEPTH, minDepth);
	}
	
	/**
	* @brief Quickly set motion blur maximum depth
	* 	@param maxDepth \p float - Maximum depth from the camera position
	*/
	void setMotionBlurMaxDepth(float maxDepth){
		setParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_MAXDEPTH, maxDepth);
	}
	
	
	
	
	
	
	////////////// BLOOM
	
	/**
	* @brief Quickly set bloom parameters
	* 	@param steepness \p float - The "smoothness" of the bloom (also used as strength setting instead of `Intensity`)	
	* 	@param intensity \p float - Intensity	
	* 	@param treshold \p float - Treshold of bloom, lower treshold means bloom on less reflective materials
	*/
	void setBloom(float steepness, float intensity, float treshold){
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_STEEPNESS, steepness);		
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_INTENSITY, intensity);		
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_THRESHOLD, treshold);		
	}
	
	/**
	* @brief Quickly set bloom steepness
	* 	@param steepness \p float - The "smoothness" of the bloom (also used as strength setting instead of `Intensity`)	
	*/
	void setBloomSteepness(float steepness){
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_STEEPNESS, steepness);		
	}
	
	/**
	* @brief Quickly set bloom intensity
	* 	@param intensity \p float - Intensity	
	*/
	void setBloomIntensity(float intensity){
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_INTENSITY, intensity);		
	}
	
	/**
	* @brief Quickly set bloom treshold
	* 	@param treshold \p float - Treshold of bloom, lower treshold means bloom on less reflective materials
	*/
	void setBloomTreshold(float treshold){
		setParam(MaterialNames.GLOW, PPEParamNames.BLOOM_THRESHOLD, treshold);		
	}
	
	
	
	
	////////////// CAMERA EFFECTS
	
	/**
	* @brief Quickly set camera effects parameters
	* 	@param saturation \p float - Saturation of the camera
	* 	@param colorization \p TPPEColor - Some kind of instagram color effect lol (pretty cool)
	*/
	void setCameraEffects(float saturation, TPPEColor colorization){
		setParam(MaterialNames.GLOW, PPEParamNames.SATURATION, saturation);
		setParam(MaterialNames.GLOW, PPEParamNames.GLOW_COLORIZATION, colorization);
	}
	
	/**
	* @brief Quickly set saturation
	* 	@param saturation \p float - Saturation of the camera
	*/
	void setSaturation(float saturation){
		setParam(MaterialNames.GLOW, PPEParamNames.SATURATION, saturation);
	}
	
	/**
	* @brief Quickly set colorization
	* 	@param colorization \p TPPEColor - Some kind of instagram color effect lol (pretty cool)
	*/
	void setColorization(TPPEColor colorization){
		setParam(MaterialNames.GLOW, PPEParamNames.GLOW_COLORIZATION, colorization);
	}
	
	
	
	
	
	//----------------------------------------------------------
	//				LOW LEVEL SETTER
	//----------------------------------------------------------
	
	
	/**
	* @brief Set a float parameter, (instantiate the maps if not instantiated)
	* 	@param paramName \p TPPEParamName - Name of the parameter
	* 	@param paramValue \p float - Value of the parameter
	* 	@param mat \p TPPEMaterial - Material of the parameter to
	*/
	protected void setParam(TPPEMaterial mat, TPPEParamName paramName, float paramValue){
		if(!m_params) 		m_params = new TPPEFloatParamsMap();
		if(!m_params[mat]) 	m_params[mat] = new TPPEFloatParams();
		
		m_params[mat][paramName] = paramValue;
		onChange();
	}
	
	
	/**
	* @brief Set a color parameter, (instantiate the maps if not instantiated)
	* 	@param paramName \p TPPEParamName - Name of the parameter
	* 	@param paramValue \p TPPEColor - Value of the parameter
	* 	@param mat \p TPPEMaterial - Material of the parameter to
	*/
	protected void setParam(TPPEMaterial mat, TPPEParamName paramName, TPPEColor paramValue){
		if(!paramValue) 			return;
		if(!m_colorParams) 			m_colorParams = new TPPEColorParamsMap();
		if(!m_colorParams[mat]) 	m_colorParams[mat] = new TPPEColorParams();
		
		m_colorParams[mat][paramName] = paramValue;
		onChange();
	}
	
	void debugPrint(bool logsEnabled = true){
		if(logsEnabled == false) return;
		SLog.d("ppeParams debug printing","",0);
		SLog.d(this);
		SLog.d("float parameters","",1);
		foreach(auto ppeMaterial, auto ppeParam : m_params){
			SLog.d("" + ppeMaterial,"",2);
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				SLog.d("" + ppeParamName + " : " + ppeParamValue,"",3);
			}
		}
		
		SLog.d("color parameters","",1);
		foreach(auto ppeColorMaterial, auto ppeColorParam : m_colorParams){
			SLog.d("" + ppeColorMaterial,"",2);
			foreach(auto ppeColorParamName, auto ppeColorParamValue : ppeColorParam){
				SLog.d("" + ppeColorParamName + " : " + ppeColorParamValue,"",3);
			}
		}
	}
	
}