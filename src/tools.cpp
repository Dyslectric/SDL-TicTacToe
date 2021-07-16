#include "tools.h"

double tools::uptime()
{
    double t = SDL_GetTicks();
    t *= 0.001;
    return t;
}

int tools::get_tile(const int x, const int y)
{
    //
    //  converts x and y inputs to tile indicies
    //
    //  game screen is 1024x768
    //  grid is a 720x720 square, divided into 3 tiles
    //  each tile is, therefore, 240x240px
    //
    //  x begins at 128 ((1024 - 768) / 2) and ends at 848 ((1024 - 768) - 2 + (240 x 3))
    //  y begins at 24 and ends at 744 (768 - 24)
    //  oh yeah fun fact this grid isn't centered... oops
    //

    if(x < 128 || x > 848)
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
    // the tile textures are 2/3 the width and height of their tiles
    // therefore, textures' x will start at 168 (128 + [(240 - 160) / 2])
    // and textures' y will start at 64 (24 + [(240 - 160) / 2])
    SDL_Rect tileRect;
    tileRect.x = (168 + column * 240);
    tileRect.y = (64 + row * 240);
    tileRect.w = 160;
    tileRect.h = 160;

    return tileRect; 
}