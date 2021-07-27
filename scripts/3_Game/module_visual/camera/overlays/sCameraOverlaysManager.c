enum eSCameraOverlayState {
	REQUESTED,
	ACTIVE,
	ANIMATING,
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
	protected ref map<ref SCameraOverlayAnimated, eSCameraOverlayState> m_overlaysAnimated = new map<ref SCameraOverlayAnimated, eSCameraOverlayState>();

	
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
	void activate(SCameraOverlay overlay){
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
	void deactivate(TSCameraOverlaysList overlays){
		foreach(SCameraOverlay overlay : overlays){
			deactivate(overlay);
		}
	}
	
	/**
	*	@brief Remove an overlay, decrease counter if it has been requested multiple time
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*/
	void deactivate(SCameraOverlay overlay){
		if(!overlay) return;
		m_overlays.Set(overlay, eSCameraOverlayState.PENDING_DELETION);
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove all overlays
	*/	
	void deactivateAll(){
		foreach(auto overlay, auto state : m_overlays){
			m_overlays.Set(overlay, eSCameraOverlayState.PENDING_DELETION);
		}
		m_overlaysHaveChanged = true;
	}
	
	
	
	
	/**
	*	@brief Request to show an animated overlay
	*	 @param animatedOverlay \p SCameraOverlayAnimated - overlay
	*/
	void activateAnimation(SCameraOverlayAnimated animatedOverlay){
		if(!animatedOverlay) return;
		m_overlaysAnimated.Set(animatedOverlay, eSCameraOverlayState.REQUESTED);
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove an animated overlay, decrease counter if it has been requested multiple time
	*	 @param animatedOverlay \p SCameraOverlay - overlay to remove
	*/
	void deactivateAnimation(SCameraOverlayAnimated animatedOverlay){
		if(!animatedOverlay) return;
		m_overlaysAnimated.Set(animatedOverlay, eSCameraOverlayState.PENDING_DELETION);
		m_overlaysHaveChanged = true;
	}
	
	
	
	
	
	/**
	*	@brief Update requested overlays
	*	 @param root \p Widget - root widget of overlays
	*/
	void onUpdate(float deltaTime, Widget root){
		
		animateOverlays(deltaTime, root);
		
		if(!m_overlaysHaveChanged) return;
		
		updateAnimatedOverlays(deltaTime, root);
		updateStaticOverlays(deltaTime, root);
		
		m_overlaysHaveChanged = false;
	}
	
	protected void animateOverlays(float deltaTime, Widget root){
		foreach(SCameraOverlayAnimated animatedOverlay, eSCameraOverlayState state : m_overlaysAnimated){
			if(animatedOverlay.isPlaying()){
				animatedOverlay.animate(deltaTime);
			}else if(animatedOverlay.hasStopped()){
				SLog.d("Found stopped animation",""+this);
			}
		}
	}
	
	protected void updateStaticOverlays(float deltaTime, Widget root){
		foreach(SCameraOverlay overlay, eSCameraOverlayState state : m_overlays){
			if(!overlay) SLog.w("Found null overlay!","SCameraOverlaysManager");
			switch(m_overlays.Get(overlay)){
				case eSCameraOverlayState.REQUESTED:
					performActivate(overlay, root);
					break;
				case eSCameraOverlayState.PENDING_DELETION:
					performDeactivate(overlay, root);
					break;
			}
		}
	}
	
	protected void updateAnimatedOverlays(float deltaTime, Widget root){
		foreach(SCameraOverlayAnimated animatedOverlay, eSCameraOverlayState state : m_overlaysAnimated){
			if(!animatedOverlay) SLog.w("Found null animated overlay!","SCameraOverlaysManager");
			switch(m_overlaysAnimated.Get(animatedOverlay)){
				case eSCameraOverlayState.REQUESTED:
					performActivate(animatedOverlay, root);
					break;
				case eSCameraOverlayState.PENDING_DELETION:
					performDeactivate(animatedOverlay.getSuper(), root);
					break;
			}
		}
	}
	
	/**
	*	@brief Actual removal of widget
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*	 @param root \p Widget - parent of widget to remove
	*/
	protected void performDeactivate(SCameraOverlay overlay, Widget parent){ //@todo unnecesary to pass parent
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
	protected void performActivate(SCameraOverlay overlay, Widget parent){
		overlay.buildWidget(parent);
		m_overlays.Set(overlay, eSCameraOverlayState.ACTIVE);
	}
	
	/**
	*	@brief Actual creation of widget
	*	 @param animatedOverlay \p SCameraOverlayAnimated - overlay to show
	*	 @param parent \p Widget - parent of widget to add
	*/
	protected void performActivate(SCameraOverlayAnimated animatedOverlay, Widget parent){
		m_overlaysAnimated.Set(animatedOverlay, eSCameraOverlayState.ANIMATING);
		animatedOverlay.start();
		if(animatedOverlay.getSuper().getWidget()) return;		
		animatedOverlay.getSuper().buildWidget(parent);
	}
	
	/**
	*	@brief Actual removal of widget
	*	 @param animatedOverlay \p animatedOverlay - overlay to remove
	*	 @param root \p Widget - parent of widget to remove
	*/
	protected void performDeactivate(SCameraOverlayAnimated animatedOverlay, Widget parent){ //@todo unnecesary to pass parent
		if(animatedOverlay.getSuper().getWidget()){
			parent.RemoveChild(animatedOverlay.getSuper().getWidget());
		}
		m_overlaysAnimated.Remove(animatedOverlay);
	}
	
	bool overlaysHaveChanged(){
		return m_overlaysHaveChanged;
	}
	
	bool isActive(SCameraOverlay overlay){
		return m_overlays.Contains(overlay));
	}
	
	bool isActive(SCameraOverlayAnimated animatedOverlay){
		return m_overlaysAnimated.Contains(animatedOverlay));
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
		
		foreach(auto ao, auto state : m_overlaysAnimated){
			SLog.d(ao,"",1);
			SLog.d(typename.EnumToString(eSCameraOverlayState, state),"",2);
			SLog.d(typename.EnumToString(eSAnimableState, ao.getAnimationState()),"",2);
		}
		
	}
	

}