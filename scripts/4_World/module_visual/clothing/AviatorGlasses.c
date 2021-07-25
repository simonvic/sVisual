modded class AviatorGlasses{
	override TSCameraOverlaysList loadCameraOverlaysList(){
		return SGameConfig.visual().getCameraOverlays(MotoHelmet_ColorBase);
	}
}