typedef array<ref SCameraOverlay> TSCameraOverlaysList;
typedef set<ref SCameraOverlay> TSCameraOverlaySet;

class SCameraOverlay : Managed {
	
	protected string m_image;
	protected float m_alpha;
	
	protected string m_mask;
	protected float m_maskProgress;
	protected float m_maskTransitionWidth;
	
	protected vector m_position;
	protected vector m_size;
	protected vector m_rotation;
	
	protected int m_priority;
	
	protected ref ImageWidget m_widget = null;
	
	//maybe use a builder? lol
	void SCameraOverlay(
		string image = "",
		float alpha = 1.0,
		string mask = "",
		float maskProgress = 1.0,
		float maskTransitionWidth = 0.1,
		vector position = "0.0 0.0 0.0",
		vector size = "1.0 1.0 1.0",
		vector rotation = "0.0 0.0 0.0",
		int priority = 0){
		
		m_image = image;
		m_alpha = alpha;
		m_mask = mask;
		m_maskProgress = maskProgress;
		m_maskTransitionWidth = maskTransitionWidth;
		m_position = position;
		m_size = size;
		m_rotation = rotation;
		m_priority = priority;
		onInit();
	}
	
	void onInit();
	
	string getImageName(){
		return m_image;
	}
	
	void setImage(string image){
		m_image = image;
		if(m_widget) m_widget.LoadImageFile(0, image);
	}
	
	float getAlpha(){
		return m_alpha;
	}
	
	void setAlpha(float alpha){
		m_alpha = alpha;
		if(m_widget) m_widget.SetAlpha(alpha);
	}
	
	
	
	string getMask(){
		return m_mask;
	}
	
	void setMask(string mask){
		m_mask = mask;
		if(m_widget) m_widget.LoadMaskTexture(mask);
	}
	
	float getMaskProgress(){
		return m_maskProgress;
	}
	
	void setMaskProgress(float maskProgress){
		m_maskProgress = maskProgress;
		if(m_widget) m_widget.SetMaskProgress(maskProgress);
	}
	
	float getMaskTransitionWidth(){
		return m_maskTransitionWidth;
	}
	
	void setMaskTransitionWidth(float maskTransitionWidth){
		m_maskTransitionWidth = maskTransitionWidth;
		if(m_widget) m_widget.SetMaskTransitionWidth(maskTransitionWidth);
	}
	
	
	
	vector getPosition(){
		return m_position;
	}
	
	void setPosition(float x, float y){
		setPosition(Vector(x, y, 0));
	}
	
	void setPosition(vector position){
		m_position = position;
		if(m_widget) m_widget.SetPos(position[0], position[1]);
	}
	
	
	
	
	vector getSize(){
		return m_size;
	}
	
	void setSize(float x, float y){
		setSize(Vector(x, y, 0));
	}
	
	void setSize(vector size){
		m_size = size;
		if(m_widget) m_widget.SetSize(size[0], size[1]);
	}
	
	
	
	vector getRotation(){
		return m_rotation;
	}
	
	void setRotation(vector rotation){
		m_rotation = rotation;
		if(m_widget) m_widget.SetRotation(rotation[0], rotation[1], rotation[2]);
	}
	
	
	
	int getPriority(){
		return m_priority;
	}
	
	void setPriority(int priority){
		m_priority = priority;
		if(m_widget) m_widget.SetSort(priority);
	}
	
	
	ImageWidget getWidget(){
		return m_widget;
	}
	
	ImageWidget buildWidget(Widget parent){
		if(!m_widget){
			m_widget = ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets(getLayout(), parent));
		}else{
			parent.AddChild(m_widget);
		}
		m_widget.LoadImageFile(0, getImageName());
		m_widget.SetAlpha(getAlpha());
		m_widget.LoadMaskTexture(getMask());
		m_widget.SetMaskProgress(getMaskProgress());
		m_widget.SetMaskTransitionWidth(getMaskTransitionWidth());
		m_widget.SetPos(m_position[0], m_position[1]);
		m_widget.SetSize(m_size[0], m_size[1]);
		m_widget.SetRotation(m_rotation[0], m_rotation[1], m_rotation[2]);
		m_widget.SetSort(getPriority());
		//m_widget.SetName(getImageName());
		m_widget.Show(true);
		return m_widget;
	}
	
	protected string getLayout(){
		return "MyMODS/sVisual/scripts/5_Mission/gui/ingameHUD/camera_overlay.layout";
	}
	
	string toString(){
		return string.Format(
			"image= %1 \n alpha= %2 \n mask= %3 \n maskProgress= %4 \n maskTransitionWidth= %5 \n position= %6 \n size= %7 \n rotation= %8 \n priority= %9",
			getImageName(),
			getAlpha(),
			getMask(),
			getMaskProgress(),
			getMaskTransitionWidth(),
			getPosition(),
			getSize(),
			getRotation(),
			getPriority());
	}
	
	void debugPrint(int depth = 0){
		SLog.d(this,"",depth);
		depth++;
		SLog.d(getImageName(),"imageName",depth);
		SLog.d(getAlpha(),"alpha",depth);
		SLog.d(getMask(),"mask",depth);
		SLog.d(getMaskProgress(),"maskProgress",depth);
		SLog.d(getMaskTransitionWidth(),"maskTranstitionWidth",depth);
		SLog.d(getPosition(),"position",depth);
		SLog.d(getSize(),"size",depth);
		SLog.d(getRotation(),"rotation",depth);
		SLog.d(getPriority(),"priority",depth);
	}
}



