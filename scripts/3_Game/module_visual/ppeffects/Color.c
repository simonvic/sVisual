class Color {

	protected int argbValue; //current color represented in ARGB format
	
	void Color(int r = 0, int g = 0, int b = 0, int a = 255) {
		setRGBA(r, g, b, a);
	}

	/**
	*	@brief Set current color using r g b a values
	*	 @param r \p int - Red
	*	 @param g \p int - Green
	*	 @param b \p int - Blue
	*	 @param a \p int - Alpha
	*/
	Color setRGBA(int r, int g, int b, int a) {
		argbValue = ((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8)  | ((b & 0xFF) << 0);
		return this;
	}
	
	/**
	*	@brief Set current color using RGB value (e.g. 0xF0544C)
	*	 @param rgb \p int - Color represented in RGB format
	*/
	Color setRGB(int rgb){
		setARGB((getAlpha() << 24 ) | rgb);
		return this;
	}
	
	/**
	*	@brief Set current color using RGBA value (e.g. 0xF0544Caa)
	*	 @param rgba \p int - Color represented in RGBA format
	*/
	Color setRGBA(int rgba){
		argbValue = toARGB(rgba);
		return this;
	}
	
	/**
	*	@brief Set current color using ARGB value (e.g. 0xaaF0544C)
	*	 @param argb \p int - Color represented in ARGB format
	*/
	Color setARGB(int argb){
		argbValue = argb;
		return this;
	}
	
	/**
	*	@brief Set current color using hue, saturation, brightness values [0 - 1] (e.g. 0.03, 0.683, 0.941)
	*	 @param hue \p float - Hue of color [0 - 1]
	*	 @param saturation \p float - Saturation of color [0 - 1]
	*	 @param brightness \p float - Brightness of color [0 - 1]
	*/
	Color setHSB(float hue, float saturation, float brightness){
		setARGB((getAlpha() << 24) | Color.HSBtoRGB(hue, saturation, brightness));
		return this;
	}
	
	/**
	*	@brief Brighten the current color
	*	 @param factor \p float - Factor of brightening [0 - 1]
	*/
	Color brighten(float factor = 0.7) {
		int r = getRed();
		int g = getGreen();
		int b = getBlue();
		int alpha = getAlpha();
		
		int i = (int)(1.0/(1.0-factor));
		if ( r == 0 && g == 0 && b == 0) {
			setRGBA(i, i, i, alpha);
			return this;
		}
		if ( r > 0 && r < i ) r = i;
		if ( g > 0 && g < i ) g = i;
		if ( b > 0 && b < i ) b = i;

		setRGBA(Math.Min((int)(r/factor), 255),
		        Math.Min((int)(g/factor), 255),
		        Math.Min((int)(b/factor), 255),
		        alpha);
		return this;
		
	}

	/**
	*	@brief Darken the current color
	*	 @param factor \p float - Factor of darkening [0 - 1]
	*/
	Color darken(float factor = 0.7) {
		setRGBA(Math.Max((int)(getRed() * factor), 0),
		        Math.Max((int)(getGreen() * factor), 0),
		        Math.Max((int)(getBlue() * factor), 0),
		        getAlpha());
		return this;
	}

	/**
	*	@brief Get the current color values in RGBA format
	*	 @param rgba \p float[4] - Float array containing RGBA values
	*/
	Color collectRGBA(out float rgba[4]) {
		rgba[0] = getRed();
		rgba[1] = getGreen();
		rgba[2] = getBlue();
		rgba[3] = getAlpha();
		return this;
	}

	/**
	*	@brief Get the current color values in RGB format
	*	 @param rgb \p float[3] - Float array containing RGB values
	*/
	Color collectRGB(out float rgb[3]) {
		rgb[0] = getRed();
		rgb[1] = getGreen();
		rgb[2] = getBlue();
		return this;
	}
	
	/**
	*	@brief Get the current color represented in RGBA format
	*	 @return int - RGBA color
	*/
	int getRGBA(){
		return Color.toRGBA(getARGB());
	}
	
	/**
	*	@brief Get the current color represented in ARGB format
	*	 @return int - ARGB color
	*/
	int getARGB() {
		return argbValue;
	}
	
	/**
	*	@brief Get the current alpha value (opacity)
	*	 @return int - Alpha
	*/
	int getAlpha() {
		return Color.getAlpha(getARGB());
	}

	/**
	*	@brief Get the current red value
	*	 @return int - Red
	*/
	int getRed() {
		return Color.getRed(getARGB());
	}

	/**
	*	@brief Get the current green value
	*	 @return int - Green
	*/
	int getGreen() {
		return Color.getGreen(getARGB());
	}

	/**
	*	@brief Get the current blue value
	*	 @return int - Blue
	*/
	int getBlue() {
		return Color.getBlue(getARGB());
	}
	
	
	
	
	
	
	////////////////////////////////////////////
	// STATIC METHODS
	
	/**
	*	@brief Build a color using R G B values
	*	 @param r \p int - Red
	*	 @param g \p int - Green
	*	 @param b \p int - Blue
	*	 @return Color
	*/
	static Color rgb2(int r, int g, int b) {
		return (new Color(r, g, b));
	}
	
	/**
	*	@brief Build a color using R G B A values
	*	 @param r \p int - Red
	*	 @param g \p int - Green
	*	 @param b \p int - Blue
	*	 @param a \p int - Alpha
	*	 @return Color
	*/
	static Color rgba(int r, int g, int b, int a) {
		return (new Color(r, g, b, a));
	}
	
	/**
	*	@brief Build a color using A R G B values
	*	 @param a \p int - Alpha
	*	 @param r \p int - Red
	*	 @param g \p int - Green
	*	 @param b \p int - Blue
	*	 @return Color
	*/
	static Color argb(int a, int r, int g, int b){
		return (new Color(r, g, b, a));
	}
	
	/**
	*	@brief Build a color using another color represented in RGB format
	*	 @param rgb \p int - Color
	*	 @return Color
	*/
	static Color rgb(int rgb) {
		return Color.rgba(0xff000000 | rgb);
	}
	
	/**
	*	@brief Build a color using another color represented in RGBA format
	*	 @param rgba \p int - Color
	*	 @return Color
	*/
	static Color rgba(int rgba) {
		return (new Color()).setRGBA(rgba);
	}
	
	/**
	*	@brief Build a color using another color represented in ARGB format
	*	 @param argb \p int - Color
	*	 @return Color
	*/
	static Color argb(int argb) {
		return (new Color()).setARGB(argb);
	}
	
	/**
	*	@brief Build a color using hue, saturation and brightness values
	*	 @param hue \p float - Hue of color [0 - 1]
	*	 @param saturation \p float - Saturation of color [0 - 1]
	*	 @param brightness \p float - Brightness of color [0 - 1]
	*	 @return Color
	*/
	static Color hsb(float hue, float saturation, float brightness){
		return (new Color()).setHSB(hue, saturation, brightness);
	}
	
	/**
	*	@brief Get the alpha value of the color represented in ARGB
	*	 @param argb \p int - Color
	*	 @return int - Alpha
	*/
	static int getAlpha(int argb) {
		return (argb >> 24) & 0xff;
	}

	/**
	*	@brief Get the red value of the color represented in ARGB
	*	 @param argb \p int - Color
	*	 @return int - Red
	*/
	static int getRed(int argb) {
		return (argb >> 16) & 0xFF;
	}

	/**
	*	@brief Get the green value of the color represented in ARGB
	*	 @param argb \p int - Color
	*	 @return int - Green
	*/
	static int getGreen(int argb) {
		return (argb >> 8) & 0xFF;
	}

	/**
	*	@brief Get the blue value of the color represented in ARGB
	*	 @param argb \p int - Color
	*	 @return int - Blue
	*/
	static int getBlue(int argb) {
		return (argb >> 0) & 0xFF;
	}
	
	/**
	*	@brief Convert a color represented in ARGB to RGBA
	*	 @param argb \p int - Color
	*	 @return int - Color in RGBA
	*/
	static int toRGBA(int argb){
		//remove alpha by shifting left, add alpha at the end
		return ((argb << 8) | ((argb >> 24) & 0xff));
	}
	
	/**
	*	@brief Convert a color represented in RGBA to ARGB
	*	 @param rgba \p int - Color
	*	 @return int - Color in ARGB
	*/
	static int toARGB(int rgba){
		//get the alpha bits, move them to the left, move rgba to the right, insert alpha bits
		return (((rgba >> 8) & 0x00ffffff) | ((rgba & 0x000000ff) << 24)));
	}
 
	/**
	*	@brief Convert hue, saturation and brightness values to a RGB color
	*	 @param hue \p float - Hue of color [0 - 1]
	*	 @param saturation \p float - Saturation of color [0 - 1]
	*	 @param brightness \p float - Brightness of color [0 - 1]
	*	 @return int - Color in RGB
	*/
	static int HSBtoRGB(float hue, float saturation, float brightness) {
		int r = 0, g = 0, b = 0;
		if (saturation == 0) {
			r = (int) (brightness * 255.0 + 0.5);
			g = (int) (brightness * 255.0 + 0.5);
			b = (int) (brightness * 255.0 + 0.5);
		} else {
			float h = (hue - (float)Math.Floor(hue)) * 6.0;
			float f = h - (float)Math.Floor(h);
			float p = brightness * (1.0 - saturation);
			float q = brightness * (1.0 - saturation * f);
			float t = brightness * (1.0 - (saturation * (1.0 - f)));
			switch ((int) h) {
			case 0:
				r = (int) (brightness * 255.0 + 0.5);
				g = (int) (t * 255.0 + 0.5);
				b = (int) (p * 255.0 + 0.5);
				break;
			case 1:
				r = (int) (q * 255.0 + 0.5);
				g = (int) (brightness * 255.0 + 0.5);
				b = (int) (p * 255.0 + 0.5);
				break;
			case 2:
				r = (int) (p * 255.0 + 0.5);
				g = (int) (brightness * 255.0 + 0.5);
				b = (int) (t * 255.0 + 0.5);
				break;
			case 3:
				r = (int) (p * 255.0 + 0.5);
				g = (int) (q * 255.0 + 0.5);
				b = (int) (brightness * 255.0 + 0.5);
				break;
			case 4:
				r = (int) (t * 255.0 + 0.5);
				g = (int) (p * 255.0 + 0.5);
				b = (int) (brightness * 255.0 + 0.5);
				break;
			case 5:
				r = (int) (brightness * 255.0 + 0.5);
				g = (int) (p * 255.0 + 0.5);
				b = (int) (q * 255.0 + 0.5);
				break;
			}
		}
		return (r << 16) | (g << 8) | (b << 0);
	}
	
	/**
	*	@brief Convert an RGB color to hue, saturation and brightness values
	*	 @param r \p int - Red
	*	 @param g \p int - Green
	*	 @param b \p int - Blue
	*	 @param hue \p float - Hue of color [0 - 1]
	*	 @param saturation \p float - Saturation of color [0 - 1]
	*	 @param brightness \p float - Brightness of color [0 - 1]
	*/
	static void RGBtoHSB(int r, int g, int b, out float hue, out float saturation, out float brightness) {
		int cmax;
		if (r > g) cmax = r; else cmax = g;
		if (b > cmax) cmax = b;
		int cmin;
		if (r < g) cmin = r; else cmin = g;
		if (b < cmin) cmin = b;

		brightness = ((float) cmax) / 255.0;
		if (cmax != 0)
			saturation = ((float) (cmax - cmin)) / ((float) cmax);
		else
			saturation = 0;
		if (saturation == 0)
			hue = 0;
		else {
			float redc = ((float) (cmax - r)) / ((float) (cmax - cmin));
			float greenc = ((float) (cmax - g)) / ((float) (cmax - cmin));
			float bluec = ((float) (cmax - b)) / ((float) (cmax - cmin));
			if (r == cmax)
				hue = bluec - greenc;
			else if (g == cmax)
				hue = 2.0 + redc - bluec;
			else
				hue = 4.0 + greenc - redc;
			hue = hue / 6.0;
			if (hue < 0)
				hue = hue + 1.0;
		}
	}

}
