
/*	  __ _ ___| |____      ____ _ _ __ ___   ___  __ _| |__		*/
/*	 / _` / __| '_ \ \ /\ / / _` | '_ ` _ \ / _ \/ _` | '_ \	*/
/*	| (_| \__ \ | | \ V  V / (_| | | | | | |  __/ (_| | | | |	*/
/*	 \__,_|___/_| |_|\_/\_/ \__,_|_| |_| |_|\___|\__, |_| |_|	*/
/*	                                             |___/		*/
/*       		ashwamegh's dwm config				*/


/* See LICENSE file for copyright and license details. */

/* Constants  */
#define TERMINAL "st"
#define TERMCLASS "St"


/* appearance */
static const unsigned int borderpx      = 3;        /* border pixel of windows */
static const unsigned int snap          = 32;       /* snap pixel */
static const unsigned int gappx         = 6;        /* pixel gap between clients */
static const int showbar                = 1;        /* 0 means no bar */
static const int topbar                 = 1;        /* 0 means bottom bar */
static const int horizpadbar            = 5;        /* horizontal padding for statusbar */
static const int vertpadbar             = 7;        /* vertical padding for statusbar */
static const int iscentered             = 1;        /* all windows spawn centered if floating */
static const char *fonts[]              = {"Dejavu Sans Mono for Powerline:size=9",
                                        "JoyPixels:size=10:antialias=true:autohint=true",
                                        "FontAwesome:size=10:antialias=true:autohint=true",
                                        };
static const char dmenufont[]           = "Dejavu Sans Mono for Powerline:size=14";
static const char col_gray1[]           = "#1a1a1a";
static const char col_gray2[]           = "#1a1a1a"; /* border color unfocused windows */
static const char col_gray3[]           = "#96b5B4";
static const char col_gray4[]           = "#d7d7d7";
static const char col_blue[]            = "#1793d0"; /* border color focused windows and tags */
static const char col_red[]             = "#8f3d3d"; /* tag background color */
static const char col_white[]          = "#ffffff"; /* border color */
/* bar opacity
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0x99;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]        = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray4, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_red, col_white },
    [SchemeTitle]  = { col_gray4, col_blue, col_blue },
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
/* static const char *tags[] = { "1️⃣", "2️⃣", "3️⃣", "4️⃣", "5️⃣", "6️⃣", "7️⃣", "🎱", "9️⃣" }; */
static const char *tags[] = { "🐧", "", "📰", "📧", "🔍", "💀", "👷", "🕹", "📺" };


static const Rule rules[] = {
    /* xprop(1):
     *    WM_CLASS(STRING) = instance, class
     *    WM_NAME(STRING) = title
     */
    /* class        instance    title      tags mask    iscentered      isfloating        monitor */
    { "Thunar",     NULL,       NULL,      0,           1,              1,                -1 },
    { "Dolphin",    NULL,       NULL,      0,           1,              1,                -1 },
    { "Gimp",       NULL,       NULL,      0,           1,              1,                -1 },
    { "Firefox",    NULL,       NULL,      1 << 8,      0,              0,                -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
#include "horizgrid.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "###",      horizgrid },
    { "[C]",      centeredmaster },
    { ">C>",      centeredfloatingmaster },
    { "(@)",      spiral },
    { "[\\]",     dwindle },
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
static const char *roficmd[] = { "rofi", "-combi-modi", "window,drun,file-browser,run", "-show", "combi", "-modi", "combi", "-show-icons" , NULL};
static const char *termcmd[]     = { "st", NULL };
static const char *surftermcmd[] = { "tabbed", "surf", "-pe", NULL};
static const char *tabtermcmd[]  = { "tabbed", "-r 2", "st", "-w", "''", NULL };
static const char scratchpadname[] = "scratchpad";
/* static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL }; */
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "150x50", NULL };


/* my modkeys map (you can see the same by typing xmodmap in the terminal) */
 /* xmodmap:  up to 4 keys per modifier, (keycodes in parentheses):	*/

 /* shift       Shift_L (0x32),  Shift_R (0x3e)				*/
 /* lock        Caps_Lock (0x42)					*/
 /* control     Control_L (0x25),  Control_R (0x69)			*/
 /* mod1        Alt_L (0x40),  Alt_R (0x6c),  Meta_L (0xcd)		*/
 /* mod2        Num_Lock (0x4d)						*/
 /* mod3								*/		
 /* mod4        Super_L (0x85),  Super_R (0x86),  Super_L (0xce),  Hyper_L (0xcf) */
 /* mod5        ISO_Level3_Shift (0x5c),  Mode_switch (0xcb)		*/



#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier             key        function        argument */
    { MODKEY|ControlMask,   XK_Delete,     spawn,          SHCMD("sysact") },
    { Mod1Mask|ControlMask, XK_l,          spawn,          SHCMD("lock") },
    { MODKEY,		    XK_space,      spawn,          {.v = roficmd } },
    { MODKEY,               XK_Return,     spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,     XK_Return,     spawn,          {.v = dmenucmd } },
    { Mod1Mask,             XK_Return,     spawn,          {.v = tabtermcmd } },
    { MODKEY|ShiftMask,     XK_s,          togglescratch,  {.v = scratchpadcmd } },
    { MODKEY|ShiftMask,     XK_t,          togglebar,      {0} },
    { MODKEY|ShiftMask,     XK_j,          rotatestack,    {.i = +1 } },
    { MODKEY|ShiftMask,     XK_k,          rotatestack,    {.i = -1 } },
    { MODKEY,               XK_j,          focusstack,     {.i = +1 } },
    { MODKEY,               XK_k,          focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,     XK_i,          incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,     XK_d,          incnmaster,     {.i = -1 } },
    { MODKEY,               XK_h,          setmfact,       {.f = -0.05} },
    { MODKEY,               XK_l,          setmfact,       {.f = +0.05} },
    { Mod1Mask,               XK_space,      zoom,           {0} },
    { MODKEY,               XK_z,          view,           {0} },
    { MODKEY,     XK_q,          killclient,     {0} },

    /* Layout manipulation */
    { MODKEY,               XK_Tab,        cyclelayout,    {.i = -1 } },
    { MODKEY|ShiftMask,     XK_Tab,        cyclelayout,    {.i = +1 } },
    /* { MODKEY,               XK_space,      setlayout,      {0} }, */
    { MODKEY|ShiftMask,     XK_space,      togglefloating, {0} },

    /* Switch to specific layouts */
    { MODKEY,               XK_t,          setlayout,      {.v = &layouts[0]} },
    { MODKEY,               XK_f,          setlayout,      {.v = &layouts[1]} },
    { MODKEY,               XK_m,          setlayout,      {.v = &layouts[2]} },
    { MODKEY,               XK_g,          setlayout,      {.v = &layouts[3]} },
    { MODKEY,               XK_u,          setlayout,      {.v = &layouts[4]} },
    { MODKEY,               XK_o,          setlayout,      {.v = &layouts[5]} },
    { MODKEY,               XK_s,          setlayout,      {.v = &layouts[6]} },
    { MODKEY,               XK_d,          setlayout,      {.v = &layouts[7]} },

    { MODKEY,               XK_0,          view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,     XK_0,          tag,            {.ui = ~0 } },

    /* Media Keys */
    { 0, XF86XK_MonBrightnessUp,     spawn,        SHCMD("macbook-lighter-screen --inc 10") },
    { 0, XF86XK_MonBrightnessDown,   spawn,        SHCMD("macbook-lighter-screen --dec 10") },
    { 0, XF86XK_KbdBrightnessUp,     spawn,        SHCMD("macbook-lighter-kbd --inc 10") },
    { 0, XF86XK_KbdBrightnessDown,   spawn,        SHCMD("macbook-lighter-kbd --dec 10") },
    { 0, XF86XK_AudioMute,           spawn,        SHCMD("amixer set Master toggle") },
    { 0, XF86XK_AudioRaiseVolume,    spawn,        SHCMD("amixer set Master 5%+") },
    { 0, XF86XK_AudioLowerVolume,    spawn,        SHCMD("amixer set Master 5%-") },
    { 0, XF86XK_AudioPrev,           spawn,        SHCMD("mpc prev") },
    { 0, XF86XK_AudioNext,           spawn,        SHCMD("mpc next") },
    { 0, XF86XK_AudioPlay,           spawn,        SHCMD("mpc toggle") },
    { 0, XF86XK_Mail,		     spawn,	   SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { MODKEY,			XK_bracketleft,	    spawn,		SHCMD("mpc seek -10") },
    { MODKEY|ShiftMask,		XK_bracketleft,	    spawn,		SHCMD("mpc seek -60") },
    { MODKEY,			XK_bracketright,    spawn,		SHCMD("mpc seek +10") },
    { MODKEY|ShiftMask,		XK_bracketright,    spawn,		SHCMD("mpc seek +60") },

    /* Screencast commands */
    { Mod1Mask,                 XK_BackSpace,       spawn,        SHCMD("dmenurecord") },
    { Mod1Mask|ShiftMask,       XK_BackSpace,       spawn,        SHCMD("dmenurecord kill") },
    /* { Mod1Mask|ShiftMask,       XK_k,            spawn,        SHCMD("killall screenkey || screenkey &") }, */
    { 0,                        XK_Print,        spawn,        SHCMD("maimpick") },

    /* Switching between monitors */
    { MODKEY,               XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,               XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,     XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,     XK_period, tagmon,         {.i = +1 } },

    /* Apps Launched with Alt + KEY */
    { Mod1Mask,                 XK_grave,   spawn,      SHCMD("dmenuunicode") },
    { Mod1Mask,                 XK_l,       spawn,      SHCMD("dmenu-lpass-nu") },
    /* { Mod1Mask,                 XK_c,       spawn,      SHCMD("/usr/bin/mmenu") }, */
    { Mod1Mask|ShiftMask,       XK_w,       spawn,      CMD("networkmanager_dmenu") },
    { Mod1Mask,			XK_w,	    spawn,	SHCMD(TERMINAL " -e nmtui") },
    { Mod1Mask,			XK_e,	    spawn,	SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },
    { MODKEY|ShiftMask,	        XK_e,	    spawn,      SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },
    { Mod1Mask,                 XK_b,       spawn,      CMD("brave") },
    { Mod1Mask|ShiftMask,       XK_b,       spawn,      {.v = surftermcmd } },
    { Mod1Mask,                 XK_f,       spawn,      SHCMD(TERMINAL " -e ranger") },
    { Mod1Mask,                 XK_n,       spawn,      CMD("st -e vim ~/Dropbox/Lehigh/Notes/") },
    { Mod1Mask|ShiftMask,       XK_c,       spawn,      CMD("~/.dmenu/dmenu-edit-configs.sh") },
    { Mod1Mask,                 XK_p,       spawn,      CMD("pavucontrol") },
    { Mod1Mask|ShiftMask,       XK_p,       spawn,      CMD("cpcolor") },
    { Mod1Mask,                 XK_t,       spawn,      CMD("cawbird") },
    { Mod1Mask,                 XK_x,       spawn,      CMD("pkill mpd") },
    { Mod1Mask,                 XK_m,       spawn,      SHCMD(TERMINAL " -e ncmpcpp") },
    /* { Mod1Mask,                 XK_d,       spawn,      CMD("doppler") }, */

    /* Apps Launched with SUPER + ALT + KEY */

    TAGKEYS(                  XK_1,          0)
    TAGKEYS(                  XK_2,          1)
    TAGKEYS(                  XK_3,          2)
    TAGKEYS(                  XK_4,          3)
    TAGKEYS(                  XK_5,          4)
    TAGKEYS(                  XK_6,          5)
    TAGKEYS(                  XK_7,          6)
    TAGKEYS(                  XK_8,          7)
    TAGKEYS(                  XK_9,          8)
    { MODKEY|ShiftMask,       XK_q,          quit,      {0} },
    { MODKEY|ShiftMask,       XK_r,          quit,      {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click           event mask   button          function        argument */
    { ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
    { ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,     0,           Button2,        zoom,           {0} },
    { ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
    { ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
    { ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
    { ClkTagBar,       0,           Button1,        view,           {0} },
    { ClkTagBar,       0,           Button3,        toggleview,     {0} },
    { ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
    { ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};


