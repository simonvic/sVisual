//////////////////////////////////////////
// IRONSIGHT
//////////////////////////////////////////
modded class DayZPlayerCameraIronsights{
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		if( HeadLeanParams.enabled ){
			updateHeadLean(pDt, pOutResult);
		}
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){ 
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
}

//////////////////////////////////////////
// OPTICS
//////////////////////////////////////////
modded class DayZPlayerCameraOptics {
	
	protected int m_currentStepFOV;

	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
}