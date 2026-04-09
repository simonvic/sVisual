modded class DayZPlayerCameraIronsights {

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		super.OnUpdate(pDt, pOutResult);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult) { 
		super.AdjustCameraParameters(pDt, pOutResult);
		// HACK: needed as workaround for https://feedback.bistudio.com/T195618
		if (userCfgVisual.getHeadLeanAngle() != 0) {
			pOutResult.m_iDirectBoneMode = 3;
		}
	}

	override bool isHeadLeanEnabled() {
		return true;
	}

}
