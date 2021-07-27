/**
*	This class implements the pseudo-interface SAnimable
*	The "super" is a member called m_super
*/
class SCameraOverlayAnimated : SAnimable<SCameraOverlay>{
	
	override void onInit(){
		SLog.d("onInit",""+this);
	}
	
	override void onStart(){
		SLog.d("onStart",""+this);
	}
	
	override void onAnimate(float deltaTime){
		SLog.d("onAnimate",""+this);
	}	
	
	override void onStop(){
		SLog.d("onStop",""+this);
	}
	
	override void onPause(){
		SLog.d("onPause",""+this);
	}
	
	override void onResume(){
		SLog.d("onResume",""+this);
	}
		
}