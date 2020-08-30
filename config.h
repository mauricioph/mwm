/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const int borderalpha	    = 0xbb;	/* border alpha for windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const int onegap		    = 0;	/* 1: diff gappx if one client 0: no gap if one client  */
static const unsigned int onegappx  = 100;	/* single window gap px */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_orange[]       = "#c37306"; /* Bar colour */
static const char col_dred[]       = "#232629"; /* Secondary Window Border colour */
static const char col_ldred[]       = "#232629"; /* All text colour */
static const char col_white[]       = "#FFFFFF"; /* Text colour of Selection */
static const char col_dcyan[]        = "#1d4664"; /* Main Background Colour Of selection */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]  = { col_white, col_dcyan,  col_dcyan  },
	[SchemeSel] = { col_ldred, col_orange, col_dred },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Blender",  NULL,       NULL,       0,            1,           -1 }, 
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
    { "[Fibonacci]",      spiral }, /* Fibonnacci layout as default */
	{ "[Tile]",      tile },    /* first entry is default */
	{ "[Floating]",      NULL },    /* no layout function means floating behavior */
	{ "[Full]",      monocle },
 	{ "[Dwindle]",      dwindle }, /* Dwindle is a corner kind of Fibonacci */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "run", "-width 20" , NULL };
static const char *termcmd[]  = { "uxterm", NULL };
static const char *audioedtcmd[] = {"audacity", NULL };
static const char *vlccmd[] = {"vlc", NULL };
static const char *firefoxcmd[] = {"firefox", NULL };
static const char *codecmd[] = {"code", NULL };
static const char *poweroffcmd[] = {"python2", "/home/mauricio/.config/dwm/poweroff.py", NULL };
static const char *lockcmd[] = {"bash","/home/mauricio/.config/dwm/lock-fusy.sh", NULL };
static const char *connectnetcmd[] = {"nmcli", "c", "up", "3ce41249-a574-4e46-815e-e49cc01dcc6f", NULL };

#include <X11/XF86keysym.h>

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static char *statuscmds[] = { "notify-send Mouse$BUTTON" };
static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

static Key keys[] = {

	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },       /* rofi menu */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },        /* st Terminal */
   	{ MODKEY,                       XK_a,      spawn,          {.v = audioedtcmd }},    /* Audio Editor */
   	{ MODKEY,                       XK_v,      spawn,          {.v = vlccmd }},         /* VLC Media Player */
   	{ MODKEY,                       XK_g,      spawn,          {.v = codecmd }},        /* VSCode */
   	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = firefoxcmd }},     /* Firefox */
   	{ MODKEY,                       XK_e,      spawn,          {.v = poweroffcmd }},    /* Power off */
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = lockcmd }},        /* Lock screen */
	{ MODKEY,			XK_n,	   spawn,	   {.v = connectnetcmd }}, /* Connect wifi to flat */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
 	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,		            	XK_c,	   spawn, 	       SHCMD("mpv --no-cache --no-osc --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
    { 0,              XF86XK_AudioRaiseVolume, spawn,          SHCMD("pactl set-sink-volume 0 +5%; kill $(ps axo pid,cmd | grep 'sleep 1m' | sed -n 1p | awk '{print $1}')") },
    { 0,              XF86XK_AudioLowerVolume, spawn,          SHCMD("pactl set-sink-volume 0 -5%; kill $(ps axo pid,cmd | grep 'sleep 1m' | sed -n 1p | awk '{print $1}')") },
    { 0,              XF86XK_AudioMute,        spawn,          SHCMD("pactl set-sink-volume 0 0; kill $(ps axo pid,cmd | grep 'sleep 1m' | sed -n 1p | awk '{print $1}')") },
    { 0,              XF86XK_MonBrightnessUp,  spawn,          SHCMD("sudo screen-backlight up") },
    { 0,            XF86XK_MonBrightnessDown,  spawn,          SHCMD("sudo screen-backlight down") },
    { 0,              XF86XK_KbdBrightnessUp,  spawn,          SHCMD("sudo keyboard-backlight total") },
    { 0,            XF86XK_KbdBrightnessDown,  spawn,          SHCMD("sudo keyboard-backlight off") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

