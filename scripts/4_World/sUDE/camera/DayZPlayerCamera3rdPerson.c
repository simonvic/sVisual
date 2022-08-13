modded class DayZPlayerCamera3rdPerson {
	
	override bool isHeadbobEnabled(){
		return isHeadbobEnabledIn3pp();
	}
	
	override bool isHeadLeanEnabled(){
		return false;
	}
	
	override bool isDDOFEnabled(){
		return isDDOFEnabledIn3PP();
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		super.OnUpdate(pDt, pOutResult);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
	
}

modded class DayZPlayerCamera3rdPersonProneBase {
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		super.OnUpdate(pDt, pOutResult);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
}