/* Orignal theme of MWM */
static const char norm_fg[]       = "#6fc3df"; /* Text Norm */
static const char norm_bg[]       = "#0c141f"; /* Background Norm */
static const char norm_border[]   = "#000000"; /* Unfocused Border */

static const char sel_fg[]       = "#000000"; /* Text Selected */
static const char sel_bg[]       = "#df740f"; /* Background Selected */
static const char sel_border[]   = "#ffe64d"; /* Focused Border */

static const char *colors[][3]      = {
	    /*               fg           bg         border */

	    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border },
	    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },
	   
	      };
