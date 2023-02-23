// Created by pywall
static const char norm_fg[] = "#dfded3";
static const char norm_bg[] = "#0a0a0a";
static const char norm_border[] = "#9c9b93";

static const char sel_fg[] = "#dfded3";
static const char sel_bg[] = "#7B7EA1";
static const char sel_border[] = "#dfded3";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};
