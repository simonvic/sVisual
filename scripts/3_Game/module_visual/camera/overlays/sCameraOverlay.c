typedef array<ref SCameraOverlay> TSCameraOverlaysList;
typedef set<ref SCameraOverlay> TSCameraOverlaySet;

class SCameraOverlay : Managed {
	
	/**
	*	@brief Path of the image to be loaded. It can be whatever an ImageWidget accepts
	*	 @code
	*	 	"set:dayz_crosshairs image:imperfect"                // image sets
	*	 	"MyMODS/sVisual/GUI/textures/overlays/blood.edds"    // image paths
	*	 	"MyMODS/sVisual/GUI/icons/logo/sVisual.paa"          // image paths
	*/
	protected string m_image;
	
	/**
	*	@brief Alpha of the widget, [0.0 - 1.0]
	*/
	protected float m_alpha;
	
	/**
	*	@brief Path of the image to be loaded used as an alpha mask
	*	        Usually a white and black image, where 
	*	        WHITE : alpha=1.0
	*	        GREY  : alpha=0.5
	*	        BLACK : alpha=0.0
	*/
	protected string m_mask;
	
	/**
	*	@brief Progress determines which alpha values are opaque using the mask. For progress x, 
	*	        pixels with alpha in mask < x will be opaque and alpha in mask > x will be transparent.
	*	        For smooth transition @see m_maskTransitionWidth.
	*/
	protected float m_maskProgress;
	
	/**
	*	@brief Alpha values will be fully opaque at m_maskProgress. Values between m_maskProgress and
	*	        m_maskProgress + m_maskTransitionWidth will be smooth
	*/
	protected float m_maskTransitionWidth;
	
	/**
	*	@brief Position of the widget (ORIGIN) defined in screen space [0.0 - 1.0]
	*	        Only position[0] and position[1] is used to determine X and Y position where
	*	        0.0 : top left of the screen
	*	        0.5 : center of the screen
	*	        1.0 : bottom right of the screen
	*	 @note Values lower than 0.0 and higher than 1.0 are accepted
	*/
	protected vector m_position;
	
	/**
	*	@brief Size of the widget defined in screen space [0.0 - 1.0]
	*	        Only size[0] and size[1] is used to determine X and Y size where
	*	        0.5 : half size
	*	        1.0 : full screen
	*	 @note Values lower than 0.0 and higher than 1.0 are accepted
	*/
	protected vector m_size;
	
	/**
	*	@brief Rotation of the widget defined with Yaw, Pitch and Roll angles
	*/
	protected vector m_rotation;
	
	/**
	*	@brief Priority of the ImageWidget. It determines how close to the camera will be (also known
	*	        as z-depth).
	*	        Higher priority will bring the image widget closer to the camera
	*	        @note Vanilla UI priority is ~200. Setting values higher than this may cover the UI 
	*/
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
	
	void setRotation(float yaw, float pitch, float roll){
		setRotation(Vector(yaw, pitch, roll));
	}
	
	void setRotation(vector rotation){
		m_rotation = rotation;
		if(m_widget) m_widget.SetRotation(rotation[1], rotation[0], rotation[2]);
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
	
	
	static void debugProjection(SCameraOverlay overlay, float size, vector origin = "69.2194 15.71244 1594.24"){
		overlay.setImage("MyMODS/sVisual/GUI/textures/masks/misc.edds");
		overlay.setMask("MyMODS/sVisual/GUI/textures/masks/misc.edds");
		///setMaskProgress(Math.AbsFloat(Math.Sin(getTime() * 2) * 0.7) + 0.05);
		
		vector upRight = origin + vector.Forward * size;
		vector downRight = upRight - vector.Up * size;
		vector downLeft = origin - vector.Up * size;
			
		vector screen_origin = GetGame().GetScreenPosRelative(origin);
		vector screen_upRight = GetGame().GetScreenPosRelative(upRight);
		vector screen_downRight = GetGame().GetScreenPosRelative(downRight);
		vector screen_downLeft = GetGame().GetScreenPosRelative(downLeft);
		
		float c0[2] = {screen_origin[0], screen_origin[1]};
		float c1[2] = {screen_upRight[0], screen_upRight[1]};
		float c2[2] = {screen_downRight[0], screen_downRight[1]};
		float c3[2] = {screen_downLeft[0], screen_downLeft[1]};
		float uvs[4][2] = {c0,c1,c2,c3};
		overlay.getWidget().SetUV(uvs);
		
		//setPosition(screen_origin);
		/*
		SDebug.spawnDebugDot(playerPos);
		SDebug.spawnDebugDot(origin);
		SDebug.spawnDebugDot(upRight);
		SDebug.spawnDebugDot(downRight);
		SDebug.spawnDebugDot(downLeft);
		*/
	}
}



