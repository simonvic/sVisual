class SClothingOverlaysManager {
	
	private static ref SClothingOverlaysManager INSTANCE = new SClothingOverlaysManager();
	private void SClothingOverlaysManager(){}
	static SClothingOverlaysManager getInstance(){
		return INSTANCE;
	}
	
	protected bool m_overlaysHaveChanged;
	protected ref TClothingOverlaysList m_requestedOverlays = {};
	protected ref array<ref ImageWidget> m_activeOverlayWidgets = new array<ref ImageWidget>();
	
	
	void request(TClothingOverlaysList overlaysImages){
		foreach(string img : overlaysImages){
			request(img);
		}
	}
	
	void request(string overlayImage){
		if(!isImageValid(overlayImage)) return;
		m_requestedOverlays.Insert(overlayImage);
		m_overlaysHaveChanged = true;
	}
	
	void clear(){
		m_requestedOverlays.Clear();
		foreach(ImageWidget img : m_activeOverlayWidgets){
			img.Show(false);
		}
		m_activeOverlayWidgets.Clear();
		m_overlaysHaveChanged = true;
	}
	
	void displayOn(Widget root){
		m_activeOverlayWidgets.Clear();
		float x = 0;
		foreach(string imageName : m_requestedOverlays){
			ImageWidget img = ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets(getLayoutName(), root));
			img.LoadImageFile(0, imageName);
			/*
			img.SetPos(x, 0.0);
			img.SetSize(0.1, 0.1);
			x += 0.1;
			*/
			img.Show(true);
			m_activeOverlayWidgets.Insert(img);
		}
		m_overlaysHaveChanged = false;
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
		
	array<ref ImageWidget> getActiveOverlayWidgets(){
		return m_activeOverlayWidgets;
	}
	
	TClothingOverlaysList getRequestedOverlays(){
		return m_requestedOverlays;
	}
}