#ifndef __EVENT_HANDLER
#define __EVENT_HANDLER

#include <iostream>
#include <SDL2/SDL.h>

#include "init.h"
#include "definitions.h"
#include "structs.h"
#include "tools.h"

void    eventHandler(SDL_Event event, GameState &state);
void    gameInput(const int tile, GameState &state);
void    calculateState(GameState &state);

#endif