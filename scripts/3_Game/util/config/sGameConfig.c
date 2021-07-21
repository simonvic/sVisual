class SGameConfig {

	static const string CFG_BASENAME = "Cfg_sUDE";
	
	static string getCfgName(){
		return CFG_BASENAME;
	}
	
	static int getInt(string path){
		int value;
		get(path, value);
		return value;
	}
	
	static float getFloat(string path){
		float value;
		get(path, value);
		return value;
	}
	
	static bool getBool(string path){
		bool value;
		get(path, value);
		return value;
	}
	
	static string getString(string path){
		string value;
		get(path, value);
		return value;
	}
	
	static vector getVector(string path){
		vector value;
		get(path, value);
		return value;
	}
	
	static TIntArray getIntArray(string path){
		TIntArray value = new TIntArray();
		get(path, value);
		return value;
	}
	
	static TFloatArray getfloatArray(string path){
		TFloatArray value = new TFloatArray();
		get(path, value);
		return value;
	}
	
	static TStringArray getStringArray(string path){
		TStringArray value = new TStringArray();
		get(path, value);
		return value;
	}	
	
	static void get(string path, out int value){
		value = GetGame().ConfigGetInt(path);
	}
	
	static void get(string path, out float value){
		value = GetGame().ConfigGetFloat(path);
	}
	
	static void get(string path, out bool value){
		value = GetGame().ConfigGetInt(path);
	}
	
	static void get(string path, out string value){
		GetGame().ConfigGetText(path, value);
	}
	
	static void get(string path, out vector value){
		value = GetGame().ConfigGetVector(path);
	}
	
	static void get(string path, inout TIntArray values){
		GetGame().ConfigGetIntArray(path, values);
	}
	
	static void get(string path, inout TFloatArray values){
		GetGame().ConfigGetFloatArray(path, values);
	}
	
	static void get(string path, inout TStringArray values){
		GetGame().ConfigGetTextArray(path, values);
	}
	
	
	private static ref SGameConfigVisual m_visual = new SGameConfigVisual();
	static SGameConfigVisual visual(){
		return m_visual;
	}
	
}
