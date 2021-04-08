class SFileHelper {
		
	
	/**
	*	@brief Touch a file. If it doesn't exist, create it, and if necessary create its parent directories
	*	 @param path - File path to touch
	*/
	static void touch(string path){
		if(FileExist(path)) return;

		//Trim file name		
		TStringArray dirs = new TStringArray;
		path.Split("\\",dirs);
		dirs.Remove(dirs.Count() - 1);
		string parentDir = "";
		for(int i = 0; i< dirs.Count(); i++){
			parentDir += dirs[i] + "\\\";
		}
		
		// Make parent folder
		mkdir(parentDir);
		
		FileHandle file = OpenFile(path, FileMode.WRITE);
		if (file != 0){
			FPrint(file, "");
			CloseFile(file);
		}
	}
	
	/**
	*	@brief Make directory, and its parents if necessary
	*	 @param path - Directory path to create
	*/
	static void mkdir(string path){
		TStringArray dirs = new TStringArray;
		path.Split("\\",dirs);
		string temp = dirs[0];
		MakeDirectory(temp);
		for(int i = 0; i<dirs.Count() - 1; i++){
			temp += "\\\" + dirs[i+1];
			MakeDirectory(temp);
		}
	}
	
	
	
	static void sandbox(){
				
		SUserConfig userCfg = SUserConfig.load();
		SLog.d("========================================");
		SLog.d(userCfg.module_visual.ddofIntensity,"",1);
		SLog.d(userCfg.module_visual.headbobIntensity,"",1);
		SLog.d(userCfg.module_visual.motionBlurIntensity,"",1);
		SLog.d(userCfg.module_visual.bloomIntensity,"",1);
		SLog.d(userCfg.module_visual.headLeanAngle,"",1);
		SLog.d("========================================");
	}
}