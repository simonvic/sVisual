modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //@todo just a quick thing, change this absolutely
	protected ref CameraManager m_camManager;
	
	
	//=========== Depth of Field ==============
	protected int m_ddofStartBoneIdx = -1;
	protected float m_currentFocusDistance = 0;
	protected float m_targetFocusDistance = 1;
	protected ref SRaycast m_sRaycast;
	protected float m_ddofVelocity[1];
	
	
	//======================================
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput){
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);
		m_ddofStartBoneIdx = pPlayer.GetBoneIndexByName("Head");
		m_camManager = new CameraManager(this, PlayerBase.Cast(m_pPlayer));
		
		m_sRaycast = new SRaycast("0 0 0", "0 0 0", 0.05, ObjIntersectView, CollisionFlags.NEARESTCONTACT);
	}
	
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult){
		super.OnUpdate(pDt, pOutResult);
		m_camManager.onUpdate(pDt, pOutResult);
	}
	
	protected void updateDoF(float pDt){
		
		vector direction = GetGame().GetCurrentCameraDirection();
		vector from = m_pPlayer.GetBonePositionWS(m_ddofStartBoneIdx);
		vector to = from + (direction * PPEManager.getDDOFMaxDistance());
		
		m_sRaycast.setBegPos(from);
		m_sRaycast.setEndPos(to);
		m_sRaycast.addIgnoredObject(m_pPlayer);
		m_sRaycast.addIgnoredObject(m_pPlayer.GetDrivingVehicle());
		m_sRaycast.launch();
		
		m_targetFocusDistance = vector.Distance( from, m_sRaycast.getContactPos() ); // calculate distance between you and the point
		m_currentFocusDistance = Math.SmoothCD(m_currentFocusDistance, m_targetFocusDistance, m_ddofVelocity, 0.15, 1000, pDt); //smooth the focus distance over time
		m_currentFocusDistance = Math.Clamp(m_currentFocusDistance, PPEManager.getDDOFMinDistance(), PPEManager.getDDOFMaxDistance()); //temp-fix
		PPEManager.requestDDOF(m_currentFocusDistance);
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
	
	float getLeanRollAngle(){
		return DayZPlayerImplement.Cast(m_pPlayer).m_MovementState.m_fLeaning * HeadLeanParams.leanAngle;
	}
	
	CameraManager getCameraManager(){
		return m_camManager;
	}
	
}