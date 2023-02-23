/* Dracula theme of MWM */
static const char norm_fg[]       = "#282A36"; /* Orange */
static const char norm_bg[]       = "#4D4D4D"; /* Bright Blue */
static const char norm_border[]       = "#50FA7B"; /* Bright Yellow */

static const char sel_fg[]       = "#8BE9FD"; /* Whittish */
static const char sel_bg[]        = "#BD93F9"; /* Dark Cyan */
static const char sel_border[]       = "#BFBFBF"; /* Black */

static const char *colors[][3]      = {
	    /*               fg           bg         border                         */
	    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused 
	    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // focused 
};
