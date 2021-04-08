modded class DayZPlayerCameraBase{
	
	protected DayZPlayerImplement m_iPlayer; //to-do just a quick thing, change this absolutely
	
	//=========== Depth of Field ==============
	protected int m_ddofStartBoneIdx = -1;
	protected float m_currentFocusDistance = 0;
	protected float m_targetFocusDistance = 1;
	protected ref SRaycast m_sRaycast;
	protected float m_ddofVelocity[1];
	
	
	//======================================
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput){
		m_iPlayer = DayZPlayerImplement.Cast(m_pPlayer);
		m_ddofStartBoneIdx = pPlayer.GetBoneIndexByName("Head");
	}
	
	protected void updateDoF(float pDt){

		vector direction = GetGame().GetCurrentCameraDirection();
		vector from = m_pPlayer.GetBonePositionWS(m_ddofStartBoneIdx);
		vector to = from + (direction * PPEManager.getDDOFMaxDistance());
		
		m_sRaycast = new SRaycast(from, to, 0.05, ObjIntersectView, CollisionFlags.NEARESTCONTACT);
		m_sRaycast.addIgnoredObject(m_pPlayer);
		m_sRaycast.addIgnoredObject(m_pPlayer.GetDrivingVehicle());
		m_sRaycast.launch();
		
		m_targetFocusDistance = vector.Distance( from, m_sRaycast.getContactPos() ); // calculate distance between you and the point
		m_currentFocusDistance = Math.SmoothCD(m_currentFocusDistance, m_targetFocusDistance, m_ddofVelocity, 0.15, 1000, pDt); //smooth the focus distance over time
		m_currentFocusDistance = Math.Clamp(m_currentFocusDistance, PPEManager.getDDOFMinDistance(), PPEManager.getDDOFMaxDistance()); //temp-fix
		requestDoF();
	}
	
	protected void requestDoF(){
		PPEManager.requestDDOF(m_currentFocusDistance);
	}
	
	protected void updateMotionBlur(float pDt){
		PPEManager.requestMotionBlur();
	}
	
	protected void updateHeadLean(float pDt, out DayZPlayerCameraResult pOutResult){
		vector angles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		angles[2] = angles[2] + getLeanRollAngle();
		Math3D.YawPitchRollMatrix(angles, pOutResult.m_CameraTM);		
	}
	
	protected float getLeanRollAngle(){
		return m_iPlayer.m_MovementState.m_fLeaning * HeadLeanParams.leanAngle;
	}
	
}