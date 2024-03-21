/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 18;        /* gaps between windows */
static const unsigned int snap      = 0;        /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "ComicCode Nerd Font:size=8" };
static const char dmenufont[]       = "ComicCode Nerd Font:size=8";
static const char *colors[][4]      = {
	/*               fg         bg         border     float bd. */
	[SchemeNorm] = { "#c8d3f5", "#222436", "#222436", "#ffc777" },
	[SchemeSel]  = { "#82aaff", "#222436", "#82aaff", "#ffc777" },
};
static const unsigned int baralpha = 10;
static const unsigned int borderalpha = 208;
static const unsigned int alphas[][3] = {
    /*               fg      bg        border*/
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title       tags mask  iscentered  isfloating   monitor */
	{ "Gimp",          NULL,       NULL,       0,         0,          1,           -1 },
	{ "Firefox",       NULL,       NULL,       1 << 8,    0,          0,           -1 },
	{ "Pavucontrol",   NULL,       NULL,       0,         1,          1,           -1 },
	{ "stpulsemixer",  NULL,       NULL,       0,         1,          1,           -1 },
	{ "stdashboard",   NULL,       NULL,       0,         1,          1,           -1 },
	{ "stcentered",    NULL,       NULL,       0,         1,          1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[|]",      tile },    /* first entry is default */
	{ "~~~",      NULL },    /* no layout function means floating behavior */
	{ "O_O",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask /* Mod4 = Super */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_m,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	/* { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_r,      rotatestack,    {.i = +1 } },
    /* { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } }, */
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	/* { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	/* { MODKEY,                       XK_space,  setlayout,      {0} }, */
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	/* { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, */
	{ MODKEY,                       XK_b,      focusmon,       {.i = +1 } },
	/* { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, */
	{ MODKEY|ShiftMask,             XK_b,      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Right,  viewnext,       {.i = +1 } },
	{ MODKEY,                       XK_Left,   viewprev,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	/* TAGKEYS(                        XK_9,                      8) */
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	/* { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } }, */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

