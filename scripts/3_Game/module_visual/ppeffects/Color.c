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
	*	@brief Build a color using another color represented in RGB format
	*	 @param rgb \p int - Color
	*	 @return Color
	*/
	static Color rgb(int rgb) {
		return Color.argb(0xff000000 | rgb);
	}
	
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
	*	@brief Build a color using another color represented in RGBA format
	*	 @param rgba \p int - Color
	*	 @return Color
	*/
	static Color rgba(int rgba) {
		return (new Color()).setRGBA(rgba);
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
	*	@brief Build a color using another color represented in ARGB format
	*	 @param argb \p int - Color
	*	 @return Color
	*/
	static Color argb(int argb) {
		return (new Color()).setARGB(argb);
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
	
	
	////////////////////////////////////////////
	// COLORS PRESETS
	// Colors from https://www.w3schools.com/cssref/css_colors.asp
	static const Color ALICE_BLUE               = Color.rgb( 0xF0F8FF );
	static const Color ANTIQUE_WHITE            = Color.rgb( 0xFAEBD7 );
	static const Color AQUA                     = Color.rgb( 0x00FFFF );
	static const Color AQUAMARINE               = Color.rgb( 0x7FFFD4 );
	static const Color AZURE                    = Color.rgb( 0xF0FFFF );
	static const Color BEIGE                    = Color.rgb( 0xF5F5DC );
	static const Color BISQUE                   = Color.rgb( 0xFFE4C4 );
	static const Color BLACK                    = Color.rgb( 0x000000 );
	static const Color BLANCHED_ALMOND          = Color.rgb( 0xFFEBCD );
	static const Color BLUE                     = Color.rgb( 0x0000FF );
	static const Color BLUE_VIOLET              = Color.rgb( 0x8A2BE2 );
	static const Color BROWN                    = Color.rgb( 0xA52A2A );
	static const Color BURLY_WOOD               = Color.rgb( 0xDEB887 );
	static const Color CADET_BLUE               = Color.rgb( 0x5F9EA0 );
	static const Color CHARTREUSE               = Color.rgb( 0x7FFF00 );
	static const Color CHOCOLATE                = Color.rgb( 0xD2691E );
	static const Color CORAL                    = Color.rgb( 0xFF7F50 );
	static const Color CORNFLOWER_BLUE          = Color.rgb( 0x6495ED );
	static const Color CORNSILK                 = Color.rgb( 0xFFF8DC );
	static const Color CRIMSON                  = Color.rgb( 0xDC143C );
	static const Color CYAN                     = Color.rgb( 0x00FFFF );
	static const Color DARK_BLUE                = Color.rgb( 0x00008B );
	static const Color DARK_CYAN                = Color.rgb( 0x008B8B );
	static const Color DARK_GOLDENROD           = Color.rgb( 0xB8860B );
	static const Color DARK_GRAY                = Color.rgb( 0xA9A9A9 );
	static const Color DARK_GREY                = Color.rgb( 0xA9A9A9 );
	static const Color DARK_GREEN               = Color.rgb( 0x006400 );
	static const Color DARK_KHAKI               = Color.rgb( 0xBDB76B );
	static const Color DARK_MAGENTA             = Color.rgb( 0x8B008B );
	static const Color DARK_OLIVEGREEN          = Color.rgb( 0x556B2F );
	static const Color DARK_ORANGE              = Color.rgb( 0xFF8C00 );
	static const Color DARK_ORCHID              = Color.rgb( 0x9932CC );
	static const Color DARK_RED                 = Color.rgb( 0x8B0000 );
	static const Color DARK_SALMON              = Color.rgb( 0xE9967A );
	static const Color DARK_SEAGREEN            = Color.rgb( 0x8FBC8F );
	static const Color DARK_SLATEBLUE           = Color.rgb( 0x483D8B );
	static const Color DARK_SLATEGRAY           = Color.rgb( 0x2F4F4F );
	static const Color DARK_SLATEGREY           = Color.rgb( 0x2F4F4F );
	static const Color DARK_TURQUOISE           = Color.rgb( 0x00CED1 );
	static const Color DARK_VIOLET              = Color.rgb( 0x9400D3 );
	static const Color DEEP_PINK                = Color.rgb( 0xFF1493 );
	static const Color DEEP_SKYBLUE             = Color.rgb( 0x00BFFF );
	static const Color DIM_GRAY                 = Color.rgb( 0x696969 );
	static const Color DIM_GREY                 = Color.rgb( 0x696969 );
	static const Color DODGER_BLUE              = Color.rgb( 0x1E90FF );
	static const Color FIRE_BRICK               = Color.rgb( 0xB22222 );
	static const Color FLORAL_WHITE             = Color.rgb( 0xFFFAF0 );
	static const Color FOREST_GREEN             = Color.rgb( 0x228B22 );
	static const Color FUCHSIA                  = Color.rgb( 0xFF00FF );
	static const Color GAINSBORO                = Color.rgb( 0xDCDCDC );
	static const Color GHOST_WHITE              = Color.rgb( 0xF8F8FF );
	static const Color GOLD                     = Color.rgb( 0xFFD700 );
	static const Color GOLDEN_ROD               = Color.rgb( 0xDAA520 );
	static const Color GRAY                     = Color.rgb( 0x808080 );
	static const Color GREY                     = Color.rgb( 0x808080 );
	static const Color GREEN                    = Color.rgb( 0x008000 );
	static const Color GREEN_YELLOW             = Color.rgb( 0xADFF2F );
	static const Color HONEY_DEW                = Color.rgb( 0xF0FFF0 );
	static const Color HOT_PINK                 = Color.rgb( 0xFF69B4 );
	static const Color INDIAN_RED               = Color.rgb( 0xCD5C5C );
	static const Color INDIGO                   = Color.rgb( 0x4B0082 );
	static const Color IVORY                    = Color.rgb( 0xFFFFF0 );
	static const Color KHAKI                    = Color.rgb( 0xF0E68C );
	static const Color LAVENDER                 = Color.rgb( 0xE6E6FA );
	static const Color LAVENDER_BLUSH           = Color.rgb( 0xFFF0F5 );
	static const Color LAWN_GREEN               = Color.rgb( 0x7CFC00 );
	static const Color LEMON_CHIFFON            = Color.rgb( 0xFFFACD );
	static const Color LIGHT_BLUE               = Color.rgb( 0xADD8E6 );
	static const Color LIGHT_CORAL              = Color.rgb( 0xF08080 );
	static const Color LIGHT_CYAN               = Color.rgb( 0xE0FFFF );
	static const Color LIGHT_GOLDENRODYELLOW    = Color.rgb( 0xFAFAD2 );
	static const Color LIGHT_GRAY               = Color.rgb( 0xD3D3D3 );
	static const Color LIGHT_GREY               = Color.rgb( 0xD3D3D3 );
	static const Color LIGHT_GREEN              = Color.rgb( 0x90EE90 );
	static const Color LIGHT_PINK               = Color.rgb( 0xFFB6C1 );
	static const Color LIGHT_SALMON             = Color.rgb( 0xFFA07A );
	static const Color LIGHT_SEAGREEN           = Color.rgb( 0x20B2AA );
	static const Color LIGHT_SKYBLUE            = Color.rgb( 0x87CEFA );
	static const Color LIGHT_SLATEGRAY          = Color.rgb( 0x778899 );
	static const Color LIGHT_SLATEGREY          = Color.rgb( 0x778899 );
	static const Color LIGHT_STEELBLUE          = Color.rgb( 0xB0C4DE );
	static const Color LIGHT_YELLOW             = Color.rgb( 0xFFFFE0 );
	static const Color LIME                     = Color.rgb( 0x00FF00 );
	static const Color LIME_GREEN               = Color.rgb( 0x32CD32 );
	static const Color LINEN                    = Color.rgb( 0xFAF0E6 );
	static const Color MAGENTA                  = Color.rgb( 0xFF00FF );
	static const Color MAROON                   = Color.rgb( 0x800000 );
	static const Color MEDIUM_AQUAMARINE        = Color.rgb( 0x66CDAA );
	static const Color MEDIUM_BLUE              = Color.rgb( 0x0000CD );
	static const Color MEDIUM_ORCHID            = Color.rgb( 0xBA55D3 );
	static const Color MEDIUM_PURPLE            = Color.rgb( 0x9370DB );
	static const Color MEDIUM_SEAGREEN          = Color.rgb( 0x3CB371 );
	static const Color MEDIUM_SLATEBLUE         = Color.rgb( 0x7B68EE );
	static const Color MEDIUM_SPRINGGREEN       = Color.rgb( 0x00FA9A );
	static const Color MEDIUM_TURQUOISE         = Color.rgb( 0x48D1CC );
	static const Color MEDIUM_VIOLETRED         = Color.rgb( 0xC71585 );
	static const Color MIDNIGHT_BLUE            = Color.rgb( 0x191970 );
	static const Color MINT_CREAM               = Color.rgb( 0xF5FFFA );
	static const Color MISTY_ROSE               = Color.rgb( 0xFFE4E1 );
	static const Color MOCCASIN                 = Color.rgb( 0xFFE4B5 );
	static const Color NAVAJO_WHITE             = Color.rgb( 0xFFDEAD );
	static const Color NAVY                     = Color.rgb( 0x000080 );
	static const Color OLD_LACE                 = Color.rgb( 0xFDF5E6 );
	static const Color OLIVE                    = Color.rgb( 0x808000 );
	static const Color OLIVE_DRAB               = Color.rgb( 0x6B8E23 );
	static const Color ORANGE                   = Color.rgb( 0xFFA500 );
	static const Color ORANGE_RED               = Color.rgb( 0xFF4500 );
	static const Color ORCHID                   = Color.rgb( 0xDA70D6 );
	static const Color PALE_GOLDENROD           = Color.rgb( 0xEEE8AA );
	static const Color PALE_GREEN               = Color.rgb( 0x98FB98 );
	static const Color PALE_TURQUOISE           = Color.rgb( 0xAFEEEE );
	static const Color PALE_VIOLETRED           = Color.rgb( 0xDB7093 );
	static const Color PAPAYA_WHIP              = Color.rgb( 0xFFEFD5 );
	static const Color PEACH_PUFF               = Color.rgb( 0xFFDAB9 );
	static const Color PERU                     = Color.rgb( 0xCD853F );
	static const Color PINK                     = Color.rgb( 0xFFC0CB );
	static const Color PLUM                     = Color.rgb( 0xDDA0DD );
	static const Color POWDER_BLUE              = Color.rgb( 0xB0E0E6 );
	static const Color PURPLE                   = Color.rgb( 0x800080 );
	static const Color REBECCA_PURPLE           = Color.rgb( 0x663399 );
	static const Color RED                      = Color.rgb( 0xFF0000 );
	static const Color ROSY_BROWN               = Color.rgb( 0xBC8F8F );
	static const Color ROYAL_BLUE               = Color.rgb( 0x4169E1 );
	static const Color SADDLE_BROWN             = Color.rgb( 0x8B4513 );
	static const Color SALMON                   = Color.rgb( 0xFA8072 );
	static const Color SANDY_BROWN              = Color.rgb( 0xF4A460 );
	static const Color SEA_GREEN                = Color.rgb( 0x2E8B57 );
	static const Color SEA_SHELL                = Color.rgb( 0xFFF5EE );
	static const Color SIENNA                   = Color.rgb( 0xA0522D );
	static const Color SILVER                   = Color.rgb( 0xC0C0C0 );
	static const Color SKY_BLUE                 = Color.rgb( 0x87CEEB );
	static const Color SLATE_BLUE               = Color.rgb( 0x6A5ACD );
	static const Color SLATE_GRAY               = Color.rgb( 0x708090 );
	static const Color SLATE_GREY               = Color.rgb( 0x708090 );
	static const Color SNOW                     = Color.rgb( 0xFFFAFA );
	static const Color SPRING_GREEN             = Color.rgb( 0x00FF7F );
	static const Color STEEL_BLUE               = Color.rgb( 0x4682B4 );
	static const Color TAN                      = Color.rgb( 0xD2B48C );
	static const Color TEAL                     = Color.rgb( 0x008080 );
	static const Color THISTLE                  = Color.rgb( 0xD8BFD8 );
	static const Color TOMATO                   = Color.rgb( 0xFF6347 );
	static const Color TURQUOISE                = Color.rgb( 0x40E0D0 );
	static const Color VIOLET                   = Color.rgb( 0xEE82EE );
	static const Color WHEAT                    = Color.rgb( 0xF5DEB3 );
	static const Color WHITE                    = Color.rgb( 0xFFFFFF );
	static const Color WHITE_SMOKE              = Color.rgb( 0xF5F5F5 );
	static const Color YELLOW                   = Color.rgb( 0xFFFF00 );
	static const Color YELLOW_GREEN             = Color.rgb( 0x9ACD32 );


}
