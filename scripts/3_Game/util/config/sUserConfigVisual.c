class SUserConfigVisual : SUserConfigBase{
		
	override string getPath(){
		return "$saves:\\sUDE\\config\\sVisual.json";
	}
	
	override string getDefaultPath(){
		return "$profile:\\sUDE\\config\\sVisual_default.json";
	}
	
	protected static ref SUserConfigConstraints_Visual m_constraints;
	SUserConfigConstraints_Visual getConstraints() {
		return m_constraints;
	}
	
	override void onRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.onRPC(sender, target, rpc_type, ctx);
		switch (rpc_type) {	
			
			case sVisual_RPC.SYNC_USER_CONFIG_CONSTRAINTS_VISUAL:
			
			SLog.d("sVisual_RPC.SYNC_S_USER_CONFIG_VISUAL",""+this);
			int index;
			if (ctx.Read(m_constraints)) {
				SLog.d("ACK: " + index,"",1);
			} else {
				SLog.d("failed","",1);
			}
			
			break;
		}
	}
	
	override string getNonSerializedFields() {
		return super.getNonSerializedFields()+";m_constraints";
	}
	
	override void deserialize(string data, out string error){
		auto cfg = this;
		getSerializer().ReadFromString(cfg, data, error);
	}
	
	override string serialize(){
		string result;
		auto cfg = this;
		getSerializer().WriteToString(cfg, true, result);
		return result;
	}
	
	override string serializeDefault(){
		string result;
		auto cfg = new SUserConfigGunplay();
		getSerializer().WriteToString(cfg, true, result);
		return result;
	}
		
	///////////////////////////////////////
	// these go in json
	protected float ddofIntensity = 0.0;
	protected bool ddofEnabledIn3PP = false;
	protected bool ddofEnabledInVehicle = true;
	protected float headbobIntensity = 0.0;
	protected bool headbobEnabledIn3PP = false;
	protected float motionBlurIntensity = 0.0;
	protected float bloomIntensity = 0.0;
	protected float headLeanAngle = 0.0;
	///////////////////////////////////////

	float getDDOFIntensity(){
		return ddofIntensity;
	}
	
	void setDDOFIntensity(float intensity){
		ddofIntensity = getConstraints().getDDOFIntensity().constrain(intensity);
	}
	
	bool isDDOFEnabledIn3PP(){
		return ddofEnabledIn3PP;
	}
	
	void setDDOFEnabledIn3PP(bool enabled){
		ddofEnabledIn3PP = getConstraints().getDDOFEnabledIn3PP().constrain(enabled);
	}
	
	bool isDDOFEnabledInVehicle(){
		return ddofEnabledInVehicle;
	}
	
	void setDDOFEnabledInVehicle(bool enabled){
		ddofEnabledInVehicle = getConstraints().getDDOFEnabledInVehicle().constrain(enabled);
	}
	
	float getHeadbobIntensity(){
		return headbobIntensity;
	}
	
	void setHeadbobIntensity(float intensity){
		headbobIntensity = getConstraints().getHeadbobIntensity().constrain(intensity);
	}
	
	bool isHeadbobEnabledIn3pp(){
		return headbobEnabledIn3PP;
	}
	
	void setHeadbobEnabledIn3pp(bool enabled){
		headbobEnabledIn3PP = getConstraints().getHeadbobEnabledIn3PP().constrain(enabled);
	}
	
	float getMotionBlurIntensity(){
		return motionBlurIntensity;
	}
	
	void setMotionBlurIntensity(float intensity){
		motionBlurIntensity = getConstraints().getMotionBlurIntensity().constrain(intensity);
	}
	
	float getBloomIntensity(){
		return bloomIntensity;
	}
	
	void setBloomIntensity(float intensity){
		bloomIntensity = getConstraints().getBloomIntensity().constrain(intensity);
	}
	
	float getHeadLeanAngle(){
		return headLeanAngle;
	}
	
	void setHeadLeanAngle(float angle){
		headLeanAngle = getConstraints().getHeadLeanAngle().constrain(angle);
	}
	
	
}