// clears the renderer and renders the new screen

#include "render.h"

// this is actually pretty simple and I don't feel like commenting on it
void render(Window window, GameState state)
{
    SDL_RenderClear(window.renderer);

    SDL_RenderCopy(window.renderer, window.textures[TEX_GRID], NULL, NULL);

    int i = 0;
    SDL_Rect tileRect;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if(state.gameBoard[i] == TILE_NONE)
            {
                i++;
                continue;
            }

            tileRect = tools::get_tile_rect(row, column);

            if(state.gameBoard[i] == TILE_CROSS)
            {
                SDL_RenderCopy(window.renderer, window.textures[TEX_CROSS], NULL, &tileRect);
            }

            if(state.gameBoard[i] == TILE_CIRCLE)
            {
                SDL_RenderCopy(window.renderer, window.textures[TEX_CIRCLE], NULL, &tileRect);
            }

            i++;
        }
    }

    SDL_RenderPresent(window.renderer);
}