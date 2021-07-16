#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"
#include "structs.h"
#include "tools.h"
#include "init.h"

#include "event_handler.h"
#include "render.h"

int main()
{
    Window window = init::window();
    GameState state = init::game_state();

    SDL_Event event;

    double lastRefresh = tools::uptime();

    while(!state.quit)
    {
        while((tools::uptime() - lastRefresh) < DELTA)
        {
            eventHandler(event, state);
        }
        lastRefresh = tools::uptime();

        render(window, state);
    }

    SDL_DestroyWindow(window.window);
    SDL_Quit();

    return 0;
}