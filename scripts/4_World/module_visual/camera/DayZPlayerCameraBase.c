modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //@todo just a quick thing, change this absolutely
	protected ref CameraManager m_camManager;
	
	
	//=========== Depth of Field ==============
	protected int m_ddofStartBoneIdx = -1;
	protected ref SRaycast m_sRaycast;
	
	
	//======================================
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput){
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);
		m_ddofStartBoneIdx = pPlayer.GetBoneIndexByName("Head");
		m_camManager = new CameraManager(this, PlayerBase.Cast(m_pPlayer));
		
		m_sRaycast = new SRaycast("0 0 0", "0 0 0", 0.05, ObjIntersectView, CollisionFlags.NEARESTCONTACT);

		if(isDDOFEnabled()) {
			PPEManager.enableDDOF();
		}else{
			PPEManager.disableDDOF();
			PPEManager.resetDDOF(true);
		}
	}
	
	void ~DayZPlayerCameraBase(){
		
	}
	
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		m_camManager.onUpdate(pDt, pOutResult);
	}
	
	protected bool canRequestDDOF(){
		return isDDOFEnabled() && !m_iPlayer.IsCameraBlending())
	}
	
	protected void updateDDOF(float pDt){
		PPEManager.requestDDOF(getFocusDistance());
	}
	
	protected float getFocusDistance(){
		vector direction = GetGame().GetCurrentCameraDirection();
		vector from = m_pPlayer.GetBonePositionWS(m_ddofStartBoneIdx);
		vector to = from + (direction * PPEManager.getDDOFMaxDistance());
		
		m_sRaycast.setBegPos(from);
		m_sRaycast.setEndPos(to);
		m_sRaycast.addIgnoredObject(m_pPlayer);
		m_sRaycast.addIgnoredObject(m_pPlayer.GetDrivingVehicle());
		m_sRaycast.launch();
		
		return vector.Distance( from, m_sRaycast.getContactPos() ); // calculate distance between you and the point
	}
	
	protected void updateMotionBlur(float pDt){
		//@todo smooth motion blur value here
	}
	
	bool useSimonvicCam(){
		return false;
	}
	
	bool isHeadbobEnabled(){
		return false;
	}
	
	bool isHeadLeanEnabled(){
		return false;
	}
	
	bool isDDOFEnabled(){
		return false;
	}
	
	float getLeanRollAngle(){
		return DayZPlayerImplement.Cast(m_pPlayer).m_MovementState.m_fLeaning * HeadLeanParams.leanAngle;
	}
	
	CameraManager getCameraManager(){
		return m_camManager;
	}
	
}