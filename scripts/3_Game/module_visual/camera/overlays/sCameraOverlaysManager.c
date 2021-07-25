enum eSCameraOverlayState {
	REQUESTED,
	ACTIVE,
	PENDING_DELETION
}

class SCameraOverlaysManager {
	
	private static ref SCameraOverlaysManager INSTANCE = new SCameraOverlaysManager();
	private void SCameraOverlaysManager(){}
	static SCameraOverlaysManager getInstance(){
		return INSTANCE;
	}
	
	protected bool m_overlaysHaveChanged;
	protected ref map<ref SCameraOverlay, eSCameraOverlayState> m_overlays = new map<ref SCameraOverlay, eSCameraOverlayState>();
	
	
	/**
	*	@brief Request to show multiple overlays
	*	 @param overlays \p TSCameraOverlaySet - list of overlays
	*/
	void add(TSCameraOverlaySet overlays){
		foreach(SCameraOverlay overlay : overlays){
			add(overlay);
		}
	}
	
	/**
	*	@brief Request to show an overlay
	*	 @param overlay \p SCameraOverlay - overlay
	*/
	void add(SCameraOverlay overlay){
		if(!overlay) return;
		m_overlays.Set(overlay, eSCameraOverlayState.REQUESTED);
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove multiple overlays, decrease counter if they have been requested multiple time
	*	 @param overlays \p TSCameraOverlaySet - overlays to remove
	*/
	void remove(TSCameraOverlaySet overlays){
		foreach(SCameraOverlay overlay : overlays){
			remove(overlay);
		}
	}
	
	/**
	*	@brief Remove multiple overlays, decrease counter if they have been requested multiple time
	*	 @param overlays \p TSCameraOverlaysList - overlays to remove
	*/
	void remove(TSCameraOverlaysList overlays){
		foreach(SCameraOverlay overlay : overlays){
			remove(overlay);
		}
	}
	
	/**
	*	@brief Remove an overlay, decrease counter if it has been requested multiple time
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*/
	void remove(SCameraOverlay overlay){
		if(!overlay) return;
		m_overlays.Set(overlay, eSCameraOverlayState.PENDING_DELETION);
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove all overlays
	*/	
	void removeAll(){
		foreach(auto overlay, auto state : m_overlays){
			m_overlays.Set(overlay, eSCameraOverlayState.PENDING_DELETION);
		}
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Update requested overlays
	*	 @param root \p Widget - root widget of overlays
	*/
	void onUpdate(float deltaTime, Widget root){
		if(!m_overlaysHaveChanged) return;
		
		foreach(auto overlay, auto state: m_overlays){
			if(!overlay) SLog.d("found null overlay","OverlayManager");
			switch(m_overlays.Get(overlay)){
				case eSCameraOverlayState.REQUESTED:
					performAdd(overlay, root);
					break;
				case eSCameraOverlayState.PENDING_DELETION:
					performRemove(overlay, root);
					break;
			}
		}
		
		m_overlaysHaveChanged = false;
	}
	
	/**
	*	@brief Actual removal of widget
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*	 @param root \p Widget - parent of widget to remove
	*/
	protected void performRemove(SCameraOverlay overlay, Widget parent){ //@todo unnecesary to pass parent
		if(overlay.getWidget()){
			parent.RemoveChild(overlay.getWidget());
		}
		m_overlays.Remove(overlay);
	}
	
	/**
	*	@brief Actual creation of widget
	*	 @param overlay \p SCameraOverlay - overlay to show
	*	 @param parent \p Widget - parent of widget to add
	*/
	protected void performAdd(SCameraOverlay overlay, Widget parent){
		overlay.buildWidget(parent);
		m_overlays.Set(overlay, eSCameraOverlayState.ACTIVE);
	}
	
	bool overlaysHaveChanged(){
		return m_overlaysHaveChanged;
	}
		
	TSCameraOverlaySet getActive(){
		TSCameraOverlaySet overlays = new TSCameraOverlaySet();
		foreach(auto overlay, auto state: m_overlays){
			if(state == eSCameraOverlayState.ACTIVE){
				overlays.Insert(overlay);
			}
		}
		return overlays;
	}
	
	TSCameraOverlaySet getRequested(){
		TSCameraOverlaySet overlays = new TSCameraOverlaySet();
		foreach(auto overlay, auto state: m_overlays){
			if(state == eSCameraOverlayState.REQUESTED){
				overlays.Insert(overlay);
			}
		}
		return overlays;
	}
	
	TSCameraOverlaySet getPendingDeletion(){
		TSCameraOverlaySet overlays = new TSCameraOverlaySet();
		foreach(auto overlay, auto state: m_overlays){
			if(state == eSCameraOverlayState.PENDING_DELETION){
				overlays.Insert(overlay);
			}
		}
		return overlays;
	}
	
	void debugPrint(){
		TSCameraOverlaySet requested = SCameraOverlaysManager.getInstance().getActive();
		SLog.d(requested,"requested");
		foreach(SCameraOverlay r : requested){
			SLog.d(r,"",1);
		}
				
		TSCameraOverlaySet active = SCameraOverlaysManager.getInstance().getActive();
		SLog.d(active,"active");
		foreach(SCameraOverlay a : active){
			SLog.d(a,"",1);
		}
		
		TSCameraOverlaySet pending = SCameraOverlaysManager.getInstance().getPendingDeletion();
		SLog.d(pending,"pending deletion");
		foreach(SCameraOverlay p : pending){
			SLog.d(p,"",1);
		}
	}
	

}