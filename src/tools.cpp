#include "tools.h"

double tools::uptime()
{
    double t = SDL_GetTicks();
    t *= 0.001;
    return t;
}

int tools::get_tile(const int x, const int y)
{
    if(x < 128 || x > 896)
        return -1;
    
    if(y < 24 || y > 744)
        return -1;
    
    int posX = x;
    int posY = y;

    posX = (posX - 128) / 240;
    posY = (posY - 24) / 240;

    return posY * 3 + posX;
}

SDL_Rect tools::get_tile_rect(const int row, const int column)
{
    SDL_Rect tileRect;
    tileRect.x = (168 + column * 240);
    tileRect.y = (64 + row * 240);
    tileRect.w = 160;
    tileRect.h = 160;

    return tileRect; 
}