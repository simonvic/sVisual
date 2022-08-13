modded class DayZPlayerCameraIronsights {

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){ 
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
	override bool isHeadLeanEnabled(){
		return true;
	}
}