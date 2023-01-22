modded class DayZPlayerCameraBase {
	
	protected DayZPlayerImplement m_iPlayer;
	protected static SUserConfigVisual userCfgVisual;
	
	protected static int m_ddofStartBoneIdx = -1;
	protected static ref SRaycast m_ddofRaycast = new SRaycast("0 0 0", "0 0 0", 0.05, ObjIntersectView, CollisionFlags.NEARESTCONTACT);
	
	protected float m_timeHeadbob;
	protected float m_headbobYawVel[1];
	protected float m_headbobPitchVel[1];
	
	
	void DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput) {
		userCfgVisual = SUserConfig.visual();
		m_iPlayer = DayZPlayerImplement.Cast(pPlayer);

		if (isDDOFEnabled() && userCfgVisual.getDDOFIntensity() != 0) {
			SPPEManager.enableDDOF();
		} else {
			SPPEManager.disableDDOF();
			SPPEManager.resetDDOF(true);
		}
		
		SCameraOverlaysManager.getInstance().setActiveCameraType(this.Type());
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult) {
		super.OnUpdate(pDt, pOutResult);
		updateDDOF(pDt, pOutResult);
		updateCamAngles(pDt, pOutResult);
	}
	
	protected void updateCamAngles(float pDt, DayZPlayerCameraResult pOutResult) {
		vector camAngles = Math3D.MatrixToAngles(pOutResult.m_CameraTM);
		
		if (isHeadbobEnabled()) {
			applyHeadBob(pDt, camAngles);
		}
		
		if (canApplyHeadLean()) {
			applyHeadLean(pDt, camAngles);
		}
		
		Math3D.YawPitchRollMatrix(camAngles, pOutResult.m_CameraTM);
	}
	
	protected bool canApplyHeadLean() {
		return isHeadLeanEnabled() && !m_pPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE | DayZPlayerConstants.STANCEMASK_PRONE);
	}
	
	protected void applyHeadBob(float pDt, out vector angles) {
		HumanCommandMove hcm = m_iPlayer.GetCommand_Move();
		if (!hcm) return;
		float movSpeed = hcm.GetCurrentMovementSpeed();
		
		array<float> headbobParams = getHeadbobParameters();
		float yawStrenght = headbobParams[0];
		float yawFrequency = headbobParams[1];
		float pitchStrenght = headbobParams[2];
		float pitchFrequency = headbobParams[3];
		
		float intensity = getHeadbobIntensity();
		yawStrenght *= intensity;
		pitchStrenght *= intensity;
		
		if (movSpeed == 0) {
			m_timeHeadbob = 0;
		} else {
			m_timeHeadbob += pDt * movSpeed;
		}

		angles[0] = Math.SmoothCD(angles[0], angles[0] + yawStrenght * Math.Sin(m_timeHeadbob * yawFrequency), m_headbobYawVel, 0.2, 1000, pDt);
		angles[1] = Math.SmoothCD(angles[1], angles[1] + pitchStrenght * Math.Cos(m_timeHeadbob * pitchFrequency), m_headbobPitchVel, 0.2, 1000, pDt); 	
	}
	
	protected array<float> getHeadbobParameters() {
		switch (m_iPlayer.m_MovementState.m_iMovement) { 			
			
			case 0: //idling
			return HeadBobConstants.IDLE;			
			
			case 1: // walking
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT))       return HeadBobConstants.WALKING_ERECT;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)) return HeadBobConstants.WALKING_ERECT_RAISED;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH))      return HeadBobConstants.WALKING_CROUCH;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))       return HeadBobConstants.WALKING_PRONE;
			break;
			
			case 2: // jogging
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT))       return HeadBobConstants.JOGGING_ERECT;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDERECT)) return HeadBobConstants.JOGGING_ERECT_RAISED;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH))      return HeadBobConstants.JOGGING_CROUCH;
			break;

			case 3: // running
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT))       return HeadBobConstants.RUNNING_ERECT;
			if (m_iPlayer.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH))      return HeadBobConstants.RUNNING_CROUCH;
			break;
		}
		
		return HeadBobConstants.IDLE;
	}
	
	protected void applyHeadLean(float pDt, out vector angles) {
		angles[2] = angles[2] + getLeanRollAngle();
	}
	
	
	protected bool canRequestDDOF() {
		return isDDOFEnabled() && !m_pPlayer.IsCameraBlending());
	}
	
	protected void updateDDOF(float pDt, DayZPlayerCameraResult pOutResult) {
		if (canRequestDDOF()) {
			SPPEManager.requestDDOF(getFocusDistance());
		}
	}
	
	protected float getFocusDistance() {
		if (m_ddofStartBoneIdx == -1) {
			m_ddofStartBoneIdx = m_pPlayer.GetBoneIndexByName("Head");
			return 0;
		}
		
		vector from = m_pPlayer.GetBonePositionWS(m_ddofStartBoneIdx);
		
		m_ddofRaycast.init(
			from,
			from + (GetGame().GetCurrentCameraDirection() * SPPEManager.getDDOFMaxDistance()));
		
		m_ddofRaycast.ignore(m_pPlayer, m_pPlayer.GetDrivingVehicle());
		
		return vector.Distance(from, m_ddofRaycast.launch().getContactPosition());
	}
	
	protected bool isHeadbobEnabled() {
		return false;
	}
	
	protected bool isHeadLeanEnabled() {
		return false;
	}
	
	protected bool isDDOFEnabled() {
		return false;
	}
	
	protected float getLeanRollAngle() { //@todo report this. m_fLeaning doesn't reset when going prone while peeking (Q/E)
		return m_iPlayer.m_MovementState.m_fLeaning * getHeadLeanAngle();
	}
	
	protected static float getHeadbobIntensity() {
		return userCfgVisual.getHeadbobIntensity();
	}
	
	protected static float getHeadLeanAngle() {
		return userCfgVisual.getHeadLeanAngle();
	}
	
	protected static bool isDDOFEnabledInVehicle() {
		return userCfgVisual.isDDOFEnabledInVehicle();
	}
	
	protected static bool isHeadbobEnabledIn3pp() {
		return userCfgVisual.isHeadbobEnabledIn3pp();
	}
	
	protected static bool isDDOFEnabledIn3PP() {
		return userCfgVisual.isDDOFEnabledIn3PP();
	}
	
	
}