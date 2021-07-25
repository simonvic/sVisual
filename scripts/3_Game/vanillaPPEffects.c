modded class PPEffects{
	
	override static void ResetBlurEffects() {
		if (m_BlurValues) {
			for (int i = 0; i < m_BlurValues.Count(); ++i) {
				m_BlurValues[i] = 0;
			}
			UpdateBlur();
		}
	}
	
	override static void ResetRadialBlur(){	
		SetRadialBlur(0,0,0,0);
	}
	
	override static void SetRadialBlur(float powerX, float powerY, float offsetX, float offsetY ){
		PPEManager.vanillaSetRadialBlur(powerX, powerY, offsetX, offsetY);
		
	}

	/* VANILLA CODE
	override static void SetBlurValue(int index, float value) {
		if (m_BlurValues && index < m_BlurValues.Count()) {
			m_BlurValues[index] = value;
		} else {
			Print("Error: PPEffects: m_BlurValues with index: " + index + " is not registered.");
		}
	}
	
	override static int RegisterBlurEffect() {
		return m_BlurValues.Insert(0);
	}
	*/

	override static void SetBlur(float value) {
		PPEManager.vanillaSetGausBlur(value);
	}
	
	override static void UpdateBlur() {
		float blur_value_total = 0;
		if (m_BlurValues) {
			for (int i = 0; i < m_BlurValues.Count(); ++i) {
				blur_value_total += m_BlurValues[i];
			}
		}

		SetBlur(blur_value_total);
	}
	
	override static void SetBlurInventory(float value) {
		SetBlurValue(m_BlurInventory, value);
		UpdateBlur();
	}
	
	override static void SetBlurDrunk(float value) {
		SetBlurValue(m_BlurDrunk, value);
		UpdateBlur();
	}

	
	override static void SetBlurFever(float value) {
		SetBlurValue(m_BlurFever, value);
		UpdateBlur();
	}

	override static void SetBlurMenu(float value) {
		SetBlurValue(m_BlurMenu, value);
		UpdateBlur();
	}
	
	override static void SetBlurOptics(float value) {
		//SetBlurValue(m_BlurOptics, value);
		//UpdateBlur();
	}
	
	override static void SetBlurFlashbang(float value) {
		SetBlurValue(m_BlurFlashbang, value);
		UpdateBlur();
	}

	override static void SetBlurShock(float value) {
		SetBlurValue(m_BlurShock, value);
		UpdateBlur();
	}
	
	/* VANILLA CODE
	override static int RegisterChromAbbEffect() {
		return m_ChromAbbValues.Insert(0);
	}
	*/
	
	override static void ResetChromAbbEffects() {
		if (m_ChromAbbValues) {
			for (int i = 0; i < m_ChromAbbValues.Count(); ++i) {
				m_ChromAbbValues[i] = 0;
			}
			UpdateChromAbb();
		}
	}

	/* VANILLA CODE
	override static void SetChromAbbValue(int index, float value) {
		if (m_ChromAbbValues && index < m_ChromAbbValues.Count()) {
			m_ChromAbbValues[index] = value;
		} else {
			Print("Error: PPEffects: m_ChromAbbValues with index: " + index + " is not registered.");
		}
	}
	*/

	override static void SetChromAbb(float value) {
		// @todo why?! it uses MaxChromAber instead of powerX powerY
		PPEManager.vanillaSetLensChromAber(value);
	}
	
	override static void UpdateChromAbb() {
		float chromabb_value_total = 0;
		if (m_ChromAbbValues) {
			for (int i = 0; i < m_ChromAbbValues.Count(); ++i) {
				chromabb_value_total += m_ChromAbbValues[i]; //currently additive!
			}
		}

		SetChromAbb(chromabb_value_total);
	}

	override static void SetChromAbbOptic(float value) {
		SetChromAbbValue(m_ChromAbbOptic, value);
		UpdateChromAbb();
	}

	
	override static void ResetColorEffects() {
		if (m_ColorEffect) {
			for (int i = 0; i < m_ColorEffect.Count(); ++i) {
				//m_ColorEffect[i] = 0;
				m_ColorValues.Set(i, {0,0,0,0,0});
			}
			UpdateColor();
		}
	}
	
	/* VANILLA CODE
	override static void SetColorValue(int index, float r, float g, float b, float a, float overlay) {
		if (index < m_ColorEffect.Count()) {
			ref array < float > values = {r,g,b,a,overlay};

			m_ColorValues.Set(index, values);
		} else {
			Print("Error: PPEffects: m_ColorValues with index: " + index + " is not registered.");
		}
	}

	override static int RegisterColorEffect() {
		return m_ColorEffect.Insert(0);
	}
	*/

	override static void UpdateColor() {
		float color_value_total[4] = {0,0,0,0};
		float color_overlay;
		/*
		m_MatColors.ResetParam("OverlayColor");
		m_MatColors.ResetParam("OverlayFactor");
		*/
		if (!GetGame() || !GetGame().GetWorld()) {
			return;
		}

		for (int i = 0; i < m_ColorValues.Count(); ++i) {
			int key = m_ColorValues.GetKey(i);
			ref array < float > value = m_ColorValues.Get(key);

			color_value_total[0] = color_value_total[0] + value[0];
			color_value_total[1] = color_value_total[1] + value[1];
			color_value_total[2] = color_value_total[2] + value[2];
			color_value_total[3] = color_value_total[3] + value[3];
			color_overlay += value[4];
		}

		m_ColorValueTotal = color_value_total;
		m_ColorOverlayTotal = color_overlay;
		PPEManager.vanillaSetOverlay(color_overlay, PPEManager.getPPEColor(color_value_total[0], color_value_total[1], color_value_total[2], color_value_total[3]));
	}

	override static void SetLensEffect(float lens, float chromAbb, float centerX, float centerY) {
		PerformSetLensEffect(lens, chromAbb, centerX, centerY);
	}

	override static void PerformSetLensEffect(float lens, float chromAbb, float centerX, float centerY) {
		PPEManager.vanillaSetLens(lens, centerX, centerY, chromAbb);
	}

	override static void SetVignette(float intensity, float R, float G, float B, float A) {
		PPEManager.vanillaSetVignette(intensity, PPEManager.getPPEColor(R,G,B,A));
	}

	/* VANILLA CODE
	override static void SetVignetteEffectValue(int index, float intensity, float r, float g, float b, float a) {
		if (index < m_VignetteEffects.Count()) {
			ref array < float > values = {intensity,r,g,b,a};

			m_VignetteValues.Set(index, values);
		} else {
			Print("Error: PPEffects: m_ColorValues with index: " + index + " is not registered.");
		}
	}

	override static int RegisterVignetteEffect() {
		return m_VignetteEffects.Insert(0);
	}
	*/

	override static void SetUnconsciousnessVignette(float value) {
		SetVignetteEffectValue(m_VignetteUnconscious, value, 0, 0, 0, 0); //todo
		UpdateVignette();
	}

	override static void SetShockVignette(float value) {
		SetVignetteEffectValue(m_VignetteShock, value, 0, 0, 0, 0); //todo
		UpdateVignette();
	}

	override static void SetTunnelVignette(float value) {
		SetVignetteEffectValue(m_VignetteTunnel, value, 0, 0, 0, 0); //todo
		UpdateVignette();
	}

	override static void SetMenuVignette(float value) {
		SetVignetteEffectValue(m_VignetteMenu, value, 0, 0, 0, 0); //todo
		UpdateVignette();
	}

	override static void ResetVignettes() {
		if (m_VignetteValues) {
			for (int i = 0; i < m_VignetteValues.Count(); ++i) {
				ref array < float > values = {0,0,0,0,0};

				m_VignetteValues.Set(i, values);
			}
			UpdateVignette();
		}
	}
	
	override static void OverrideDOF(bool enable, float focusDistance, float focusLength, float focusLengthNear, float blur, float focusDepthOffset) {
		PPEManager.vanillaOverrideDOF(enable, focusDistance, focusLength, focusLengthNear, blur, focusDepthOffset);
	}

	override static void AddPPMask(float ndcX, float ndcY, float ndcRadius, float ndcBlur) {
		PPEManager.vanillaAddPPMask(ndcX, ndcY, ndcRadius, ndcBlur);
	}

	override static void ResetPPMask() {
		if (GetGame()) PPEManager.vanillaResetPPMask();
	}

	override static void ResetDOFOverride() {
		PPEManager.vanillaResetDOFOverride();
	}
	
	override static void ResetLensEffect() {
		SetLensEffect(0, 0, 0, 0);
	}

	override static void HitEffect(float value) {
		float R = Math.Lerp(Math.Clamp(m_ColorValueTotal[0], 0, 1), 1, value);
		float G = 0;
		float B = 0;
		float A = Math.Lerp(Math.Clamp(m_ColorValueTotal[0], 0, 1), 1, value);
		
		PPEManager.vanillaSetOverlay(0.05, PPEManager.getPPEColor(R,G,B,A));
	}

	override static void SetShockEffectColor(float value) {
		if (value > 0)
			SetColorValue(m_ShockEffect, COLOR_SHOCK, COLOR_SHOCK, COLOR_SHOCK, 1, value);
		else
			SetColorValue(m_ShockEffect, 0, 0, 0, 1, value);
		UpdateColor();
	}

	override static void FlashbangEffect(float value) {
		PPEManager.vanillaSetOverlay(0.75, PPEManager.getPPEColor(1,1,1, Math.Lerp(Math.Clamp(m_ColorValueTotal[0], 0, 1), 1, value)));
	}

	override static void EnableBurlapSackBlindness() {
		//SetColorValue(m_BurlapBlindness, 0, 0, 0, 1, 1.0);
		//UpdateColor();
		g_Game.SetEVValue(-5);
	}

	override static void DisableBurlapSackBlindness() {
		//SetColorValue(m_BurlapBlindness, 0, 0, 0, 0, 0.0);
		//UpdateColor();
		g_Game.SetEVValue(0);
	}

	override static void SetDeathDarkening(float value) {
		value = Math.Clamp(value, 0, 1);
		SetColorValue(m_DyingEffect, 0, 0, 0, 1, value);
		UpdateColor();
		if (value > 0.99)
			g_Game.SetEVValue(-5); //additional "darkness" to avoid lens flare
		else
			g_Game.SetEVValue(0);
	}

	override static void UpdateSaturation() {
		PPEManager.vanillaSetSaturation(m_BloodSaturation);
	}

	override static void UpdateVignette() {
		float color[4];
		float intesity;

		float intensity_value_total = 0; //use just the highest?
		if (m_VignetteEffects) {
			for (int i = 0; i < m_VignetteEffects.Count(); ++i) {
				if (m_VignetteValues.Get(i)) {
					/*color[0] = m_VignetteValues.Get(i)[1]; //red
					color[1] = m_VignetteValues.Get(i)[2]; //green
					color[2] = m_VignetteValues.Get(i)[3]; //blue
					color[3] = m_VignetteValues.Get(i)[4]; //alpha*/
					color[0] = m_VignetteValues.Get(i).Get(1); //red
					color[1] = m_VignetteValues.Get(i).Get(2); //green
					color[2] = m_VignetteValues.Get(i).Get(3); //blue
					color[3] = m_VignetteValues.Get(i).Get(4); //alpha

					intesity = m_VignetteValues.Get(i).Get(0);
					intensity_value_total += intesity;
				} else {
					//Print("no m_VignetteValues");
				}
			}
		}

		/*color[0] = m_UnconsciousVignetteColor[0];
		color[1] = m_UnconsciousVignetteColor[1];
		color[2] = m_UnconsciousVignetteColor[2];
		
		intesity = m_UnconsciousVignetteIntesity;*/

		SetVignette(intensity_value_total, color[0], color[1], color[2], color[3]);
	}

	override static void SetBloodSaturation(float value) {
		m_BloodSaturation = value;
		UpdateSaturation();
	}

	override static void SetColorizationNV(float r, float g, float b) {
		ref array < float > colorizeArray = {r,g,b};
		m_ColorizeEffects.Set(PPEffects.COLORIZE_NV, colorizeArray);
		UpdateColorize();
	}

	override static void UpdateColorize() {
		bool foundActiveEffect = false;
		int lowestKey = 1000000;
		ref array < float > chosenArray;
		// search for active effect with highest priority (lower value of key better)
		for (int i = 0; i < m_ColorizeEffects.Count(); i++) {
			int currentKey = m_ColorizeEffects.GetKey(i);
			ref array < float > colorizeValues = m_ColorizeEffects.Get(currentKey);
			// check for non-zero active effect
			for (int j = 0; j < colorizeValues.Count(); j++) {
				if (colorizeValues[j] != 0.0) {
					if (currentKey < lowestKey) {
						chosenArray = colorizeValues;
						lowestKey = currentKey;
						foundActiveEffect = true;
						break;
					}
				}
			}
		}
		if (foundActiveEffect) {
			// active effect found
			PPEManager.vanillaSetColorization(PPEManager.getPPEColor(chosenArray[0], chosenArray[1], chosenArray[2], chosenArray[3]));
		} else {
			// no active event found, reset colorize effect
			ResetColorize();
		}
	}
	
	override static void ResetColorize() {
		PPEManager.vanillaSetColorization(PPEManager.getPPEColor(1.0, 1.0, 1.0, 0));
	}

	/* VANILLA CODE
	override static void SetEVValuePP(float value) {
		g_Game.SetEVValue(value);
	}
	*/

	// light multiplier and noise intensity (using filmgrainNV.emat!) for nvg
	// added other parameters for filmgrainNV.emat, sharpness and grain size
	override static void SetNVParams(float light_mult, float noise_intensity, float sharpness, float grain_size) {
		Material matHDR = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/filmgrainNV");
		/*#ifdef PLATFORM_CONSOLE
		//worst-case scenario console fix!
				noise_intensity = 0.0;
		#endif*/
		g_Game.NightVissionLightParams(light_mult, noise_intensity);
		PPEManager.vanillaSetFilmGrain(sharpness, grain_size);
	}

	// bloom PP, experimental stuff
	override static void SetBloom(float thres, float steep, float inten) {
		PPEManager.vanillaSetBloom(steep, inten, thres);
	}

	override static void ResetAll() {
		ResetBlurEffects();
		ResetColorEffects();
		ResetVignettes();
		ResetPPMask();
		ResetDOFOverride();
		ResetLensEffect();
		SetBloodSaturation(1);
		//RemoveUnconsciousnessVignette();
		ResetColorize();
	}
	
}