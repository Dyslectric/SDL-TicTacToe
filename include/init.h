#ifndef __INIT_FUNCTIONS
#define __INIT_FUNCTIONS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "definitions.h"
#include "structs.h"

namespace init
{
    GameState game_state();
    Window window();
}

#endif