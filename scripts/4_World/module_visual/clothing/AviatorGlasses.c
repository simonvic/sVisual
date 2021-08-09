modded class AviatorGlasses{
	override TSCameraOverlaysList loadCameraOverlaysList(){
		return SGameConfig.visual().getCameraOverlays(SportGlasses_ColorBase);
	}
}