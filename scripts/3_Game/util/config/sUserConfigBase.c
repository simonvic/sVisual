class SUserConfigBase : Managed{
	
	void load(){}	
	void save(){}	
	void createDefault(){}
	
	string getPath(){
		return "";
	}
	
	string getDefaultPath(){
		return "";
	}
	
	TStringArray getFields(){
		TStringArray fields = new TStringArray;
		for(int i = 0; i<Type().GetVariableCount(); i++){
			fields.Insert(Type().GetVariableName(i));
		}
		return fields;
	}
	
	bool isValid(){
		return SUserConfigValidator.isValid(getPath(), getFields());
	}
	
	bool isDefaultValid(){
		return SUserConfigValidator.isValid(getDefaultPath(), getFields());
	}
	
}