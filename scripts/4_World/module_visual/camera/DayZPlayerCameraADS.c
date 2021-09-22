//////////////////////////////////////////
// IRONSIGHT
//////////////////////////////////////////
modded class DayZPlayerCameraIronsights {

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);

		//need to also update here because vanilla doesn't call super
		if (m_camManager.canUpdateFrom(this)) {
			m_camManager.onUpdate(pDt, pOutResult);
		}
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){ 
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
	override bool isHeadLeanEnabled(){
		return true;
	}
	
}

//////////////////////////////////////////
// OPTICS
//////////////////////////////////////////
modded class DayZPlayerCameraOptics { //extends Ironsight
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult){
		super.AdjustCameraParameters(pDt, pOutResult);
		pOutResult.m_iDirectBoneMode = 3;
	}
	
}