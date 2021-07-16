#include "init.h"

GameState init::game_state()
{
    GameState state;

    state.state = STATE_PLAYING;
    state.playerTurn = TURN_CROSS;
    state.quit = false;

    for(int i = 0; i < 9; i++)
    {
        state.gameBoard[i] = TILE_NONE;
    }

    state.winningColumn = -1;
    state.winningRow    = -1;
    state.winningDiag   = -1;

    return state;
}


Window init::window()
{
    Window window;

    window.posX = SDL_WINDOWPOS_UNDEFINED;
    window.posY = SDL_WINDOWPOS_UNDEFINED;
    window.width = 1024;
    window.height = 768;

    window.window = SDL_CreateWindow(   NAME,
                                        window.posX, window.posY,
                                        window.width, window.height,
                                        SDL_WINDOW_SHOWN);
        
    if(window.window == NULL)
        std::cout <<    "SDL_CreateWindow failed.\n"
                        "Error code: " << SDL_GetError() << std::endl;

    window.renderer = SDL_CreateRenderer(   window.window, -1,
                                            SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);

    if(window.renderer == NULL)
        std::cout <<    "SDL_CreateRenderer failed.\n"
                        "Error code: " << SDL_GetError() << std::endl;
        
    window.textures[TEX_GRID] =     IMG_LoadTexture(window.renderer, PNG_GRID);
    window.textures[TEX_CROSS] =    IMG_LoadTexture(window.renderer, PNG_CROSS);
    window.textures[TEX_CIRCLE] =   IMG_LoadTexture(window.renderer, PNG_CIRCLE);

    if(window.textures[0] == NULL)
        std::cout <<    "Texture loading failed.\n"
                        "Error code: " << SDL_GetError() << std::endl;

    return window;
}