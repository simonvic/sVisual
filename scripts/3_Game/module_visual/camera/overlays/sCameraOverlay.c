typedef array<ref SCameraOverlay> TSCameraOverlaysList;
typedef set<ref SCameraOverlay> TSCameraOverlaySet;

class SCameraOverlay {
	protected string m_image;
	protected float m_alpha = 1.0;
	
	protected string m_mask;
	protected float m_maskProgress = 1.0;
	protected float m_maskTransitionWidth = 0.1;
	
	protected ref ImageWidget m_widget= null;
	
	void SCameraOverlay(string image, float alpha = 1.0, string mask = "", float maskProgress = 1.0, float maskTransitionWidth = 0.1){
		m_image = image;
		m_alpha = alpha;
		m_mask = mask;
		m_maskProgress = maskProgress;
		m_maskTransitionWidth = maskTransitionWidth;
	}
	
	string getImageName(){
		return m_image;
	}
	
	void setImage(string image){
		m_image = image;
	}
	
	float getAlpha(){
		return m_alpha;
	}
	
	void setAlpha(float alpha){
		m_alpha = alpha;
	}
	
	string getMask(){
		return m_mask;
	}
	
	void setMask(string mask){
		m_mask = mask;
	}
	
	float getMaskProgress(){
		return m_maskProgress;
	}
	
	void setMaskProgress(float maskProgress){
		m_maskProgress = maskProgress;
	}
	
	float getMaskTransitionWidth(){
		return m_maskTransitionWidth;
	}
	
	void setMaskTransitionWidth(float maskTransitionWidth){
		m_maskTransitionWidth = maskTransitionWidth;
	}
	
	ImageWidget getWidget(){
		return m_widget;
	}
	
	ImageWidget buildWidget(Widget parent = null){
		m_widget = ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets(getLayout(), parent));
		m_widget.LoadImageFile(0, getImageName());
		m_widget.SetAlpha(getAlpha());
		m_widget.LoadMaskTexture(getMask());
		m_widget.SetMaskProgress(getMaskProgress());
		m_widget.SetMaskTransitionWidth(getMaskTransitionWidth());
		m_widget.Show(true);
		return m_widget;
	}
	
	protected string getLayout(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/ingameHUD/image_overlay.layout";
	}
	
	string toString(){
		return string.Format("image= %1 \n alpha= %2 \n mask= %3 \n maskProgress= %4 \n maskTransitionWidth= %5",
			getImageName(),
			getAlpha(),
			getMask(),
			getMaskProgress(),
			getMaskTransitionWidth());
	}
	
	void debugPrint(int depth = 0){
		SLog.d(this,"",depth);
		depth++;
		SLog.d(getImageName(),"imageName",depth);
		SLog.d(getAlpha(),"alpha",depth);
		SLog.d(getMask(),"mask",depth);
		SLog.d(getMaskProgress(),"maskProgress",depth);
		SLog.d(getMaskTransitionWidth(),"maskTranstitionWidth",depth);
	}
}



