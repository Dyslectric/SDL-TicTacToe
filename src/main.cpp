#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"
#include "structs.h"
#include "tools.h"
#include "init.h"

#include "event_handler.h"
#include "render.h"

int main(int argc, char *argv[])
{
    // initiallize the window and the game parameters
    Window window = init::window();
    GameState state = init::game_state();

    // create an event variable for user input
    SDL_Event event;

    // initiallizes last screen refresh variable at current time
    double lastRefresh = tools::uptime();

    while(!state.quit)
    {
        // keeps the game from advancing until the next frame
        while((tools::uptime() - lastRefresh) < DELTA)
        {
        }
        lastRefresh = tools::uptime();

        eventHandler(event, state); // polls user input and processes game logic
        render(window, state);      // renders the screen after user input is processed
    }

    SDL_DestroyWindow(window.window);   // destroys the window after while loop is escaped
    SDL_Quit();                         // cleans up subsystem intialization on exit

    return 0;
}

// Windows support yay :/

int WinMain(int argc, char* argv[])
{
    return main(argc, argv);
}