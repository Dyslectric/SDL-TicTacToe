#ifndef __STRUCTS
#define __STRUCTS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"

struct GameState
{
    int state;          // playing, won, or tie
    int playerTurn;     // which player's turn is it?
    int quit;           // will the game exit at the end of the loop?
    int gameBoard[9];   // 3x3 game board array

    int winningColumn;
    int winningRow;
    int winningDiag;
};

struct Window
{
    int posX;
    int posY;
    int width;
    int height;

    SDL_Window*     window;
    SDL_Renderer*   renderer;

    // an array is used for textures
    // this way i can just call a texture definition when rendering
    SDL_Texture*    textures[TEXTURE_COUNT];
};

#endif