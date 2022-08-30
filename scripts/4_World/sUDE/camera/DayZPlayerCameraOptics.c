modded class DayZPlayerCameraOptics {
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult) {
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
}