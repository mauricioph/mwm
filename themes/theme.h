/* Orignal theme of MWM */
static const char norm_fg[]       = "#df740f"; /* Orange */
static const char norm_bg[]       = "#6fc3df"; /* Bright Blue */
static const char norm_border[]       = "#ffe64d"; /* Bright Yellow */

static const char sel_fg[]       = "#e6ffff"; /* Whittish */
static const char sel_gb[]        = "#0c141f"; /* Dark Cyan */
static const char sel_border[]       = "#000000"; /* Black */

static const char *colors[][3]      = {
	    /*               fg           bg         border */

	    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border },
	    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },
	   
	      };
