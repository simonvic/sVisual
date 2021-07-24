class SCameraOverlaysManager {
	
	private static ref SCameraOverlaysManager INSTANCE = new SCameraOverlaysManager();
	private void SCameraOverlaysManager(){}
	static SCameraOverlaysManager getInstance(){
		return INSTANCE;
	}
	
	protected bool m_overlaysHaveChanged;
	protected ref TSCameraOverlaySet m_requested = new TSCameraOverlaySet();
	protected ref TSCameraOverlaySet m_pendingDeletion = new TSCameraOverlaySet();
	protected ref TSCameraOverlaySet m_active = new TSCameraOverlaySet();
	
	
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
		m_requested.Insert(overlay);
		m_pendingDeletion.Remove(m_pendingDeletion.Find(overlay));
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove multiple overlays, decrease counter if they have been requested multiple time
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*/
	void remove(TSCameraOverlaySet overlays){
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
		m_pendingDeletion.Insert(overlay);
		m_requested.Remove(m_requested.Find(overlay));
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove all overlays
	*/	
	void removeAll(){
		foreach(SCameraOverlay overlay : m_requested){
			m_pendingDeletion.Insert(overlay);
		}
		m_requested.Clear();
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Update requested overlays
	*	 @param root \p Widget - root widget of overlays
	*/
	void updateOn(Widget root){
		foreach(SCameraOverlay requested : m_requested){
			performAdd(requested, root);
		}
		
		foreach(SCameraOverlay pendingDel : m_pendingDeletion){			
			performRemove(pendingDel, root);
		}
		m_overlaysHaveChanged = false;
	}
	
	/**
	*	@brief Actual removal of widget
	*	 @param overlay \p SCameraOverlay - overlay to remove
	*	 @param root \p Widget - parent of widget to remove
	*/
	protected void performRemove(SCameraOverlay overlay, Widget parent){ //@todo unnecesary to pass parent
		parent.RemoveChild(overlay.getWidget());
		m_active.Remove(m_active.Find(overlay));
		m_requested.Remove(m_requested.Find(overlay));
		m_pendingDeletion.Remove(m_pendingDeletion.Find(overlay));
	}
	
	/**
	*	@brief Actual creation of widget
	*	 @param overlay \p SCameraOverlay - overlay to show
	*	 @param parent \p Widget - parent of widget to add
	*/
	protected void performAdd(SCameraOverlay overlay, Widget parent){
		overlay.buildWidget(parent);
		m_active.Insert(overlay);
	}
	
	bool overlaysHaveChanged(){
		return m_overlaysHaveChanged;
	}
		
	TSCameraOverlaySet getActive(){
		return m_active;
	}
	
	TSCameraOverlaySet getRequested(){
		return m_requested;
	}
	
	TSCameraOverlaySet getPendingDeletion(){
		return m_pendingDeletion;
	}
	

}