#ifndef __TOOLS
#define __TOOLS

#include <SDL2/SDL.h>

namespace tools
{
    double uptime();
    int get_tile(const int x, const int y);
    SDL_Rect get_tile_rect(const int row, const int column);
}

#endif