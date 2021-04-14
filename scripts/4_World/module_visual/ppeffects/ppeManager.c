typedef set<ref PPEParams> TPPEParamsList;
typedef set<ref PPEAnimatedParams> TPPEAnimatedParamsList;

class PPEManager extends PluginBase {
	
	protected static float m_time;
	static bool m_debugMode = false;
	
	//=========== Depth of Field ==============
	protected static bool m_WeaponDOF_Enabled = true; // Weapon Depth of Field (used when aiming down sight)
	protected static ref DoFPreset m_weaponDOF = new WeaponDOFPreset(); //default Depth of Field while aiming down sight
	
	protected static bool m_DDOF_Enabled = true; // Dynamic Depth of Field (used in 1st person view)	
	protected static bool m_peakMitigationEnabled = true; // Dynamic Depth of Field (used in 3rd person view as shoulder peak mitigation)	
	protected static ref DoFPreset m_DDOF = new DDOFPreset(); //default Dynamic Depth of Field values
	
	protected static float m_DOF_BlurStrength = 0; // final computed DoF blur strength
	protected static float m_DOF_FocusDistance = 0; // final computed focus distance
	
	//=========== Vignette ==============
	protected static ref PPEFocusingVignettePreset m_focusVignette = new PPEFocusingVignettePreset(); //vignette effect used when focusing
	 
	//=========== Misc ==============
	protected static ref PPEOpticZoomChangeAnimation m_opticZoomChange = new PPEOpticZoomChangeAnimation(0.5); //vignette effect used when focusing
	
	//=========== Motion Blur ==============
	protected static bool m_MotionBlur_Enabled = true;
	
	//=========== Bloom ==============
	protected static bool m_Bloom_Enabled = false;
	
	//=========== Materials ============== (unused)
	protected static Material glow;
	protected static Material radialBlur;
	protected static Material motionBlur;
	protected static Material gaussBlur;
	protected static Material chromAber;	
	protected static Material filmgrain;
	
	//=========== PostProcess Effects Parameters ==============
	protected static ref PPEParams m_defaultPPE = new PPEParams(); //default params with no modifiers
	
	protected static ref TPPEParamsList m_persistentPPE = new TPPEParamsList; //all "non-animated" params
	protected static ref TPPEAnimatedParamsList m_animatedPPE = new TPPEAnimatedParamsList; //all animated params
	
	protected static ref PPEParams m_resultPPE = new PPEParams(); // final ppe params after the merge
	
	//=========================================================
	
	
	//----------------------------------------------------------
	//				INIT
	//----------------------------------------------------------
	
	void PPEManager(){	
	}
	
	void ~PPEManager(){
	}
	
	override void OnInit(){
		loadMaterials();	
		loadDefaultParams();	
		activateInitialPPE();
	}
	
	protected void activateInitialPPE(){
		activate(m_focusVignette);
	}
	
	override void OnDestroy(){
		
	}
	
	//to-do find a way of caching material instead of getting it every time
	protected void loadMaterials(){
		glow = GetGame().GetWorld().GetMaterial(MaterialNames.GLOW);
		radialBlur = GetGame().GetWorld().GetMaterial(MaterialNames.RADIAL_BLUR);
		motionBlur = GetGame().GetWorld().GetMaterial(MaterialNames.MOTION_BLUR);
		gaussBlur = GetGame().GetWorld().GetMaterial(MaterialNames.GAUSS_BLUR);
		chromAber = GetGame().GetWorld().GetMaterial(MaterialNames.CHROM_ABER);
		filmgrain = GetGame().GetWorld().GetMaterial(MaterialNames.FILM_GRAIN);
	}
	
	protected void loadDefaultParams(){
		m_defaultPPE.init(new PPEDefaultPreset);
		//m_resultPPE.init(new PPEDefaultPreset);
	}
	
	
	
	
	
	
	

	//----------------------------------------------------------
	//				MODIFIERS
	//----------------------------------------------------------
	
	/**
	* @brief Add a post process effect modifier 
	* 	@params params \p PPEParams - Modifier Parameters to be added
	*/
	static void activate(PPEParams params){
		if(params.IsInherited(PPEAnimatedParams)){
			PPEAnimatedParams ppeAp = PPEAnimatedParams.Cast(params);
			m_animatedPPE.Insert(ppeAp); // https://www.youtube.com/watch?v=Ct6BUPvE2sM
			ppeAp.start();
		}else{
			m_persistentPPE.Insert(params);
		}
		params.onActivate();
	}
	
	/**
	* @brief Remove a post process effect modifier 
	* 	@params params \p PPEParams - Modifier Parameters to be removed
	*/
	static void deactivate(PPEParams params){
		if(params.IsInherited(PPEAnimatedParams)){
			PPEAnimatedParams ppeAp = PPEAnimatedParams.Cast(params);
			ppeAp.stop();
			m_animatedPPE.Remove(m_animatedPPE.Find(ppeAp));
		}else{
			m_persistentPPE.Remove(m_persistentPPE.Find(params));			
		}
		params.onDeactivate();
	}
	
	/**
	* @brief Remove all modifiers
	*/
	static void deactivateAll(){
		deactivateAllPersitentPPE();
		deactivateAllAnimations();		
	}
	
	static void deactivateAllPersitentPPE(){
		foreach(PPEParams params : m_persistentPPE){
			params.onDeactivate();
		}
		m_persistentPPE.Clear();
	}
	
	static void deactivateAllAnimations(){
		foreach(auto ppeAp : m_animatedPPE){
			ppeAp.stop();
			ppeAp.onDeactivate();
		}
		m_animatedPPE.Clear();
	}
	
	
	
	
	
	
	
	
	
	
	
	//----------------------------------------------------------
	//				UPDATING PROCESS
	//----------------------------------------------------------

	override void OnUpdate(float delta_time){
		m_time += delta_time;
		
		animateParams(delta_time);
		mergeResult();		
		if(m_resultPPE.hasChanged()){
			applyParams(m_resultPPE);
		}
	}	
		
	/**
	* @brief Iterate over all animated parameters and animate
	*/
	protected static void animateParams(float deltaTime){
		foreach(PPEAnimatedParams ap : m_animatedPPE){
			if(!ap.hasStopped() && !ap.isPaused()){
				ap.animate(deltaTime);
			}
		}
	}
	
	protected static void mergeResult(){
		
		//if the final result of PPEffects are altered, return to default values at RESET_SPEED
		if(!m_resultPPE.equals(m_defaultPPE)){
			m_resultPPE.merge(m_defaultPPE, PPEConstants.RESET_SPEED);			
		}
		
		//Apply persistent PPEffects
		foreach(PPEParams p : m_persistentPPE){
			//if(p.hasChanged()){
				m_resultPPE.merge(p);
				p.onMerge();
			//}
		}
		
		//Apply animated PPEffects
		foreach(PPEAnimatedParams ap : m_animatedPPE){
			if(ap.hasChanged()){
				m_resultPPE.merge(ap);
				ap.onMerge();
			}
		}
		
	}
	
	/**
	* @brief Iterate and apply the parameters
	* 	@params params \p PPEParams - Parameters to be applied
	*/
	protected static void applyParams(PPEParams params){
		if(m_debugMode){
			SLog.d("params have changed, updating...","",0);
			SLog.d("==========================","",0);
			SLog.d("staticPPE     has " + m_persistentPPE.Count() + " total active PPEParams","",1);
			SLog.d("m_animatedPPE has " + m_animatedPPE.Count() + " total active PPEParams","",1);				
			params.debugPrint();
		}
		applyFloatParams(params);
		applyColorParams(params);
		params.onApply();
	}

	
	/**
	* @brief Iterate over all (float) parameters for each material and apply them	
	*/
	protected static void applyFloatParams(PPEParams params){
		TPPEFloatParamsMap ppeParams = params.getFloatParams();
		foreach(auto ppeMaterial, auto ppeParam : ppeParams){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				applyPPEParamTo(ppeParamName, ppeParamValue, ppeMaterial);
			}
		}

	}
	
	/**
	* @brief Iterate over all (TPPEColor) parameters for each material and apply them
	*/
	protected static void applyColorParams(PPEParams params){
		TPPEColorParamsMap ppeParams = params.getColorParams();
		foreach(auto ppeMaterial, auto ppeParam : ppeParams){
			foreach(auto ppeParamName, auto ppeParamValue : ppeParam){
				applyPPEParamTo(ppeParamName, ppeParamValue, ppeMaterial);
			}
		}	
	}
	
	/**
	* @brief Apply a float parameter to a material
	* 	@param paramName \p TPPEParamName - Name of the parameter
	* 	@param paramValue \p float - Value of the parameter
	* 	@param mat \p TPPEMaterial - Material to apply parameter to
	* 	@return \p bool - return true if parameter has been applied succesfully, false otherwise
	*/
	protected static bool applyPPEParamTo(TPPEParamName paramName, float paramValue, TPPEMaterial mat){
		SLog.d("Mat: " + mat + "\t\t : " + paramName + " : " + paramValue, "",1, m_debugMode);
		return GetGame().GetWorld().GetMaterial(mat).SetParam(paramName,paramValue);
	}
	
	
	/**
	* @brief Apply a TPPEColor parameter to a material
	* 	@param paramName \p TPPEParamName - Name of the parameter
	* 	@param paramValue \p TPPEColor - Color to be applied, which will be converted in a static array and then applied
	* 	@param mat \p TPPEMaterial - Material to apply parameter to
	* 	@return \p bool - return true if parameter has been applied succesfully, false otherwise
	*/
	protected static bool applyPPEParamTo(TPPEParamName paramName, TPPEColor paramValue, TPPEMaterial mat){
		SLog.d("Mat: " + mat + "\t\t : " + paramName + " : " + paramValue, "",1, m_debugMode);
		float color[4];
		color[0] = paramValue[0];
		color[1] = paramValue[1];
		color[2] = paramValue[2];
		color[3] = paramValue[3];
		return GetGame().GetWorld().GetMaterial(mat).SetParam(paramName,color);
	}	
	
	
	/**
	* @brief Get the (float) default value of a parameter
	* 	@param ppeMaterial \p TPPEMaterial - Material of parameter
	* 	@param ppeParamName \p TPPEParamName - Name of parameter
	* 	@return \p float - default parameter value
	*/
	static float getFloatDefaultValue(TPPEMaterial ppeMaterial, TPPEParamName ppeParamName){
		return m_defaultPPE.getFloatParam(ppeMaterial, ppeParamName);
	}
	
	/**
	* @brief Get the (TPPEColor) default value of a parameter
	* 	@param ppeMaterial \p TPPEMaterial - Material of parameter
	* 	@param ppeParamName \p TPPEParamName - Name of parameter
	* 	@return \p TPPEColor - default parameter value
	*/
	static TPPEColor getColorDefaultValue(TPPEMaterial ppeMaterial, TPPEParamName ppeParamName){
		return m_defaultPPE.getColorParam(ppeMaterial, ppeParamName);
	}
	
	

	
	//----------------------------------------------------------
	//				UTILS
	//----------------------------------------------------------
	
	/**
	* @brief Convert four float values to a TPPEColor
	* 	@param R \p float - Red
	* 	@param G \p float - Green
	* 	@param B \p float - Blue
	* 	@param A \p float - Alpha
	* 	@return \p TPPEColor - return converted TPPEColor
	*/
	static TPPEColor getPPEColor(float R, float G, float B, float A){
		TPPEColor color = new TPPEColor;
		color.InsertAt(R, 0); //Red
		color.InsertAt(G, 1); //Green
		color.InsertAt(B, 2); //Blue
		color.InsertAt(A, 3); //Alpha
		return color;
	}
	
	/**
	* @brief Mix the values of two TPPEColor
	* 	@param color1 \p TPPEColor - First color
	* 	@param color2 \p TPPEColor - Second color
	* 	@return \p TPPEColor - return mixed TPPEColor
	*/
	static TPPEColor mixColors(TPPEColor color1, TPPEColor color2, float coeff = 0.5){
		if(!color1 || !color2) return null;
		
		TPPEColor result = new TPPEColor;
		result.InsertAt(Math.Lerp(color1[0], color2[0], coeff), 0); //Red
		result.InsertAt(Math.Lerp(color1[1], color2[1], coeff), 1); //Green
		result.InsertAt(Math.Lerp(color1[2], color2[2], coeff), 2); //Blue
		result.InsertAt(Math.Lerp(color1[3], color2[3], coeff), 3); //Alpha
		if(m_debugMode){
			SLog.d("","mixColors()",0);
			SLog.d(string.Format("Color1 : %1 %2 %3 %4", color1[0],color1[1],color1[2],color1[3]) ,"",1);
			SLog.d(string.Format("Color2 : %1 %2 %3 %4", color2[0],color2[1],color2[2],color2[3]) ,"",1);
			SLog.d(string.Format("Result : %1 %2 %3 %4", result[0],result[1],result[2],result[3]) ,"",1);
		}
		return result;
	}
	
	
	
	//----------------------------------------------------------
	//				DEBUG
	//----------------------------------------------------------
	static TPPEAnimatedParamsList getAnimations(){
		return m_animatedPPE;
	}
	
	static void debugPrintAll(){
		SLog.d("debugPrintAll","PluginPPEffect",0);
		
		SLog.d("==================== m_defaultPPE ====================", "",1);
		m_defaultPPE.debugPrint();

		SLog.d("==================== m_persistentPPE ====================", "",1);
		foreach(PPEParams p : m_persistentPPE){
			p.debugPrint();
		}
		
		SLog.d("==================== m_animatedPPE ====================", "",1);
		foreach(PPEParams ap : m_animatedPPE){
			ap.debugPrint();
		}
		
		SLog.d("==================== m_resultPPE ====================", "",1);
		m_resultPPE.debugPrint();
	}
	
	
	
	
	
	
	//----------------------------------------------------------
	//				VIGNETTE
	//----------------------------------------------------------
	
	static void requestFocusVignette(float intensity){
		m_focusVignette.setVignetteIntensity(intensity);
	}
	
	static void disableFocusVignette(){
		m_focusVignette.resetAllToDefault();
	}
	
	
	
	//----------------------------------------------------------
	//				DEPTH of FIELD
	//----------------------------------------------------------
	
	static float getDDOFStrength(){
		return m_DDOF.blurStrenght;
	}
	
	static float getDDOFMaxDistance(){
		return m_DDOF.focusMaxDistance;
	}
	
	static float getDDOFMinDistance(){
		return m_DDOF.focusMinDistance;
	}
		
	static bool isDDOFEnabled(){
		return m_DDOF_Enabled;
	}
	
	static bool isPeakMitigationEnabled(){
		return m_peakMitigationEnabled;
	}
	
	static void setDDOFBlurStrength(float blurStrength){
		if(blurStrength <= 0){
			m_DDOF_Enabled = false;
			m_DDOF.blurStrenght = 0;
		}else{
			m_DDOF_Enabled = true;
			m_DDOF.blurStrenght = blurStrength;
		}
	}
	
	static void requestIronsightDOF(){ //to-do add ironsight dof preset or use "per-weapon" dof like vanilla
		PPEffects.OverrideDOF(m_WeaponDOF_Enabled, m_weaponDOF.focusDistance, m_weaponDOF.focusLenght, m_weaponDOF.focusLenghtNear, m_weaponDOF.blurStrenght * 0.9, m_weaponDOF.focusDepthOffset);
	}
	
	static void disableIronsightDOF(){
		PPEffects.ResetDOFOverride();
	}
	
	static void requestOpticDOF(){
		PPEffects.OverrideDOF(m_WeaponDOF_Enabled, m_weaponDOF.focusDistance, m_weaponDOF.focusLenght, m_weaponDOF.focusLenghtNear, m_weaponDOF.blurStrenght, m_weaponDOF.focusDepthOffset);
	}
	
	static void disableOpticDOF(){
		PPEffects.ResetDOFOverride();
	}
	
	static void requestDDOF(float focusDistance){
		m_DDOF_Enabled = true;
		m_DDOF.focusDistance = focusDistance;
		applyDOF();		
	}
	
	static void disableDDOF(){
		m_DDOF_Enabled = false;
		resetDOF();
	}
	
	static void enablePeakMitigation(){
		m_peakMitigationEnabled = true;
	}
	
	static void disablePeakMitigation(){
		m_peakMitigationEnabled = false;
		resetDOF();
	}
	
	/**
	* @brief Update DoF applying all registered modifiers
	*/
	protected static void applyDOF(){
		//do all the cool computation stuff here and then apply final result
		//if is in weapon, if needs glasses, if burlap sacks etc.
		//for now just use DDOF
		//PPEffects.ResetDOFOverride();
		PPEffects.OverrideDOF(true, m_DDOF.focusDistance, m_DDOF.focusLenght, m_DDOF.focusLenghtNear, m_DDOF.blurStrenght, m_DDOF.focusDepthOffset);
	}
	
	/**
	* @brief Reset Depth of Field
	*/
	protected static void resetDOF(){
		PPEffects.ResetDOFOverride();		
	}
	
	//----------------------------------------------------------
	//				MOTION BLUR
	//----------------------------------------------------------
	
	static bool isMotionBlurEnabled(){
		return m_MotionBlur_Enabled;
	}
	
	static float getMotionBlurStrength(){
		return m_defaultPPE.getFloatParam(MaterialNames.MOTION_BLUR, PPEParamNames.MOTION_BLUR_POWER);
	}
	
	static void setMotionBlurStrength(float strength){
		if(strength <= 0){
			m_MotionBlur_Enabled = false;
			m_defaultPPE.setMotionBlurPower(0.0);
		}else{
			m_MotionBlur_Enabled = true;
			m_defaultPPE.setMotionBlurPower(strength);
		}
		
	}
	
	static void requestMotionBlur(){
		PPEffects.UpdateBlur();
	}
	
	
	//----------------------------------------------------------
	//				BLOOM
	//----------------------------------------------------------
	
	static bool isBloomEnabled(){
		return m_Bloom_Enabled;
	}
	
	static float getBloomStrength(){
		return m_defaultPPE.getFloatParam(MaterialNames.GLOW, PPEParamNames.BLOOM_STEEPNESS);
	}
	
	static void setBloomStrength(float strength){
		if(strength <= 0){
			m_Bloom_Enabled = false;
			m_defaultPPE.setBloomSteepness(0.0);
		}else{
			m_Bloom_Enabled = true;
			m_defaultPPE.setBloomSteepness(strength);
		}
		
	}
	
	//----------------------------------------------------------
	//				OPTICS (LENSES AND MASKS)
	//----------------------------------------------------------

	static void requestOpticMask(float positionX, float positionY, float radius, float blur){
		PPEffects.AddPPMask(positionX, positionY, radius, blur);
	}
		
	static void resetMask(){
		PPEffects.ResetPPMask();
	}
	
	static void requestOpticLens(float distortStrength, float centerX, float centerY, float chromAberStrength){
		PPEffects.SetLensEffect(distortStrength, chromAberStrength, centerX, centerY);
	}
		
	static void disableOpticLens(){
		PPEffects.ResetLensEffect();
	}
	
	static void requestOpticZoomChange(){
		activate(m_opticZoomChange);
	}
}