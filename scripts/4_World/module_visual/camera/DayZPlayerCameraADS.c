//////////////////////////////////////////
// IRONSIGHT
//////////////////////////////////////////
modded class DayZPlayerCameraIronsights {
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		m_camManager.onUpdate(pDt, pOutResult);
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){ 
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
	override bool isHeadbobEnabled(){
		return false;
	}
	
	override bool isHeadLeanEnabled(){
		return true;
	}
	
}

//////////////////////////////////////////
// OPTICS
//////////////////////////////////////////
modded class DayZPlayerCameraOptics {
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
}