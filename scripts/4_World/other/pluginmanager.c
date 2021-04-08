modded class PluginManager{
	
	override void Init(){
		super.Init();
		
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin( "PPEManager",						    true,   false ); //server false?
		RegisterPlugin( "CameraManager",                        true,   false ); //server false?
	}
}