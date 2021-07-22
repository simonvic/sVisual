class SClothingOverlaysManager {
	
	private static ref SClothingOverlaysManager INSTANCE = new SClothingOverlaysManager();
	private void SClothingOverlaysManager(){}
	static SClothingOverlaysManager getInstance(){
		return INSTANCE;
	}
	
	protected bool m_overlaysHaveChanged;
	protected ref map<string, int> m_requested = new map<string, int>(); //image, count
	protected ref map<string, ref ImageWidget> m_activeOverlayWidgets = new map<string, ref ImageWidget>();
	
	
	/**
	*	@brief Request to show multiple image overlays
	*	 @param images \p array<string> - list of images
	*/
	void add(TStringArray images){
		foreach(string img : images){
			add(img);
		}
	}
	
	/**
	*	@brief Request to show an image overlay
	*	 @param image \p string - image
	*/
	void add(string image){
		if(!isImageValid(image)) return;
		if(m_requested.Contains(image)){
			m_requested.Set(image, m_requested.Get(image) + 1);
		}else{
			m_requested.Set(image, 1);
		}
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove multiple image overlays, decrease counter if they have been requested multiple time
	*	 @param image \p string - image to remove
	*/
	void remove(TStringArray images){
		foreach(string image : images){
			remove(image);
		}
	}
	
	/**
	*	@brief Remove an image overlay, decrease counter if it has been requested multiple time
	*	 @param image \p string - image to remove
	*/
	void remove(string image){
		if(m_requested.Contains(image)){
			m_requested.Set(image, m_requested.Get(image) - 1);
		}
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Remove all image overlays
	*/	
	void removeAll(){
		foreach(string image, int count : m_requested){
			m_requested.Set(image, 0);
		}
		m_overlaysHaveChanged = true;
	}
	
	/**
	*	@brief Update requested overlays
	*	 @param root \p Widget - root widget of overlays
	*/
	void updateOn(Widget root){
		foreach(string image, int count : m_requested){
			if(count <= 0){
				performRemove(image, root);
			}else if(!m_activeOverlayWidgets.Contains(image)){
				performAdd(image, root);
			}
		}
		m_overlaysHaveChanged = false;
	}
	
	/**
	*	@brief Actual removal of widget
	*	 @param image \p string - image to remove
	*	 @param root \p Widget - parent of widget to remove
	*/
	protected void performRemove(string image, Widget parent){
		parent.RemoveChild(m_activeOverlayWidgets.Get(image));
		m_activeOverlayWidgets.Remove(image);
		m_requested.Remove(image);
	}
	
	/**
	*	@brief Actual creation of widget
	*	 @param image \p string - image to show
	*	 @param parent \p Widget - parent of widget to remove
	*/
	protected void performAdd(string image, Widget parent){
		ImageWidget imageWidget = ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets(getLayoutName(), parent));
		imageWidget.LoadImageFile(0, image);
		imageWidget.SetAlpha(0.9);
		imageWidget.Show(true);
		m_activeOverlayWidgets.Set(image, imageWidget);
	}
	
	static bool isImageValid(string overlayImage){
		return overlayImage != string.Empty;
	}
	
	protected string getLayoutName(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/ingameHUD/image_overlay.layout";
	}
	
	bool overlaysHaveChanged(){
		return m_overlaysHaveChanged;
	}
		
	map<string, ref ImageWidget> getActiveOverlayWidgets(){
		return m_activeOverlayWidgets;
	}
	
	map<string, int> getRequestedOverlays(){
		return m_requested;
	}
}