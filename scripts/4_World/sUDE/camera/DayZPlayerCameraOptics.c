modded class DayZPlayerCameraOptics {

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult) {
		super.AdjustCameraParameters(pDt, pOutResult);
		// HACK: needed as workaround for https://feedback.bistudio.com/T195618
		if (userCfgVisual.getHeadLeanAngle() != 0) {
			pOutResult.m_iDirectBoneMode = 3;
		}
	}

}
