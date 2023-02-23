/* Mauricio's theme of MWM */
static const char norm_fg[]       = "#ffffff"; /* Text bar */
static const char norm_bg[]       = "#090909"; /* bar */
static const char norm_border[]       = "#858c91"; /* Border Bar*/

static const char sel_fg[]       = "#000000"; /* Text Sel */
static const char sel_bg[]        = "#990000"; /* Select BG  */
static const char sel_border[]       = "#993300"; /* Select Border */


static const char *colors[][3]      = {
    /*               fg           bg         border        */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused 
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // focused 
};
