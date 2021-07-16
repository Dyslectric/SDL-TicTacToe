#ifndef __DEFINITIONS
#define __DEFINITIONS

// Window Title
#define NAME "Game"

// frame time (60fps by default)
#define DELTA 1.0 / 60.0

// used when compiler makes the textures array
#define TEXTURE_COUNT 3

// used to denote textures in rendering
#define TEX_GRID    0
#define TEX_CROSS   1
#define TEX_CIRCLE  2

// define asset paths
#define PNG_GRID    "assets/grid.png"
#define PNG_CROSS   "assets/cross.png"
#define PNG_CIRCLE  "assets/circle.png"

// game states
#define STATE_PLAYING       0
#define STATE_CROSS_WIN     1
#define STATE_CIRCLE_WIN    2
#define STATE_TIE           3

// player turn definitions
#define TURN_CROSS  0
#define TURN_CIRCLE 1

// used to denote tile states in board array
#define TILE_NONE   0
#define TILE_CROSS  1
#define TILE_CIRCLE 2

#endif