enum SLoggerLevels{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
}

class SLog{
		
	static bool overrideEnabled = true;
	static bool filePrintEnabled = true;
	
	/**
	*	$profile
	*	$saves
	*/
	static const string LOG_PATH = "$profile:sVisual\\logs";
	
	/**
	*	%1 : level
	*	%2 : indentation
	*	%3 : caller
	*	%4 : text
	*/
	static const string PRINT_FORMAT = "[ %1 ] %2 ::%3 : %4"; 
	
	/**
	*	%1 : typename
	*	%2 : variable value
	*/
	static const string VARIABLE_PRINT_FORMAT = "< %1 > %2";
	
	/**
	* @brief Print a debug message to script log
	* 	@param text \p string Text to print
	* 	@param caller \p string Caller
	* 	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void d(string text, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(text,SLoggerLevels.DEBUG,caller,indentation, enabled);
	}
	
	static void d(Class variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	static void d(typename variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	static void d(float variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	static void d(int variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	static void d(bool variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	static void d(vector variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.d(toString(variable), caller, indentation, enabled);
	}
	
	/**
	* @brief Print an informative message to script log
	* 	@param text \p string Text to print
	* 	@param caller \p string Caller
	* 	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void i(string text,string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(text,SLoggerLevels.INFO,caller,indentation, enabled);
	}
	
	static void i(Class variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
	static void i(typename variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
	static void i(float variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
	static void i(int variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
	static void i(bool variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
	static void i(vector variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.i(toString(variable), caller, indentation, enabled);
	}
	
		
	/**
	* @brief Print a warning message to script log
	* 	@param text \p string Text to print
	* 	@param caller \p string Caller
	* 	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void w(string text,string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(text,SLoggerLevels.WARNING,caller,indentation, enabled);
	}
	
	static void w(Class variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	static void w(typename variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	static void w(float variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	static void w(int variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	static void w(bool variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	static void w(vector variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.w(toString(variable), caller, indentation, enabled);
	}
	
	/**
	* @brief Print an eerror message to script log
	* 	@param text \p string Text to print
	* 	@param caller \p string Caller
	*	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void e(string text,string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(text,SLoggerLevels.ERROR,caller,indentation, enabled);
	}
	
	static void e(Class variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	static void e(typename variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	static void e(float variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	static void e(int variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	static void e(bool variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	static void e(vector variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.e(toString(variable), caller, indentation, enabled);
	}
	
	/**
	* @brief Print a critical e message to script log
	* 	@param text \p string Text to print
	* 	@param caller \p string Caller
	* 	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void c(string text, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(text,SLoggerLevels.CRITICAL,caller,indentation, enabled);
	}
	
	static void c(Class variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	static void c(typename variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	static void c(float variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	static void c(int variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	static void c(bool variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	static void c(vector variable, string caller = "", int indentation = 0, bool enabled = true){
		SLog.c(toString(variable), caller, indentation, enabled);
	}
	
	
	/**
	* @brief Print a message to script log
	* 	@param text \p string Text to print
	* 	@param level \p int Level type of the message
	* 	@param caller \p string Caller
	* 	@param indentation \p int Indentation of the print
	* 	@param enabled \p bool Enable this print
	*/
	static void log(string text, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		if(overrideEnabled && enabled){
			string output = string.Format(PRINT_FORMAT, getLevel(level), getIndentation(indentation), caller, text);
			PrintFormat(output);
			if(filePrintEnabled){
				SLog.logToFile(output);			
			}
		}
	}
	
	static void log(Class variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level, caller, indentation, enabled);
	}
	
	static void log(typename variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level,  caller, indentation, enabled);
	}
	
	static void log(float variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level,  caller, indentation, enabled);
	}
	
	static void log(int variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level,  caller, indentation, enabled);
	}
	
	static void log(bool variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level,  caller, indentation, enabled);
	}
	
	static void log(vector variable, SLoggerLevels level = SLoggerLevels.INFO, string caller = "", int indentation = 0, bool enabled = true){
		SLog.log(toString(variable), level,  caller, indentation, enabled);
	}
	
	private static void logToFile(string text){
		int year;
		int month;
		int day;
		GetYearMonthDayUTC(year,month,day);
		string today = ""+year+"-"+month+"-"+day;
		string filePath = LOG_PATH+"\\"+today+".slog";
		
		SFileHelper.touch(filePath);
		FileHandle file = OpenFile(filePath, FileMode.APPEND);
		if (file != 0){
			FPrintln(file, text);
			CloseFile(file);
		}
		
	}
		
	static string toString(Class variable){
		return string.Format(VARIABLE_PRINT_FORMAT, variable.Type().ToString(), variable.ToString());
	}
	
	static string toString(typename variable){
		return string.Format(VARIABLE_PRINT_FORMAT, "typename", variable.ToString());
	}
	
	static string toString(float variable){
		return string.Format(VARIABLE_PRINT_FORMAT, "float", variable.ToString());
	}
	
	static string toString(int variable){
		return string.Format(VARIABLE_PRINT_FORMAT, "int", variable.ToString());
	}
	
	static string toString(bool variable){
		return string.Format(VARIABLE_PRINT_FORMAT, "bool", variable.ToString());
	}
	
	static string toString(vector variable){
		return string.Format(VARIABLE_PRINT_FORMAT, "vector", variable.ToString());
	}	
	
	private static string getIndentation(int indentation){
		string temp = "";
		for(int i=0; i<indentation; i++){
			temp += "│\t";
		}
		return temp;
	}
	
	private static string getLevel(SLoggerLevels level){
		switch(level){
			case SLoggerLevels.DEBUG: return "dd";
			case SLoggerLevels.INFO: return "ii";
			case SLoggerLevels.WARNING: return "ww";
			case SLoggerLevels.ERROR: return "ee";
			case SLoggerLevels.CRITICAL: return "cc";
		}
		return "xx";
	}
	
}

//can we have an amen for OOP ?