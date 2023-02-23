/* Dracula theme of MWM */
static const char norm_fg[]    = "#282A36"; /* Text Norm */
static const char norm_bg[]    = "#4D4D4D"; /* Background Norm */
static const char norm_border[]= "#50FA7B"; /* Unfocused Border */

static const char sel_fg[]     = "#8BE9FD"; /* Text Selected */
static const char sel_bg[]     = "#BD93F9"; /* Background Selected */
static const char sel_border[] = "#BFBFBF"; /* Focused Border */

static const char *colors[][3] = {
	    /*               fg           bg         border                         */
	    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused 
	    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // focused 
};

