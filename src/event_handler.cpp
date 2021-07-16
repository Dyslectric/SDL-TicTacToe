// handles the events of the game during blanks

#include "event_handler.h"

void eventHandler(SDL_Event event, GameState &state)
{
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            state.quit = true;
            break;
        }
        
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            gameInput(tools::get_tile(event.button.x, event.button.y), state);
        }
    }
}

void gameInput(const int tile, GameState &state)
{
    if(state.state == STATE_PLAYING)
    {
        if(state.gameBoard[tile] == TILE_NONE)
        {
            switch(state.playerTurn)
            {
                case TURN_CROSS:
                    state.gameBoard[tile] = TILE_CROSS;
                    state.playerTurn = TURN_CIRCLE;
                    break;

                case TURN_CIRCLE:
                    state.gameBoard[tile] = TILE_CIRCLE;
                    state.playerTurn = TURN_CROSS;
                    break;
            }
        }

        state.state = calculateState(state);

        if(state.state == STATE_CROSS_WIN)
        {
            for(int tile = 0; tile < 9; tile++)
            {
                if(state.gameBoard[tile] == TILE_CIRCLE)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
        }

        if(state.state == STATE_CIRCLE_WIN)
        {
            for(int tile = 0; tile < 9; tile++)
            {
                if(state.gameBoard[tile] == TILE_CROSS)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
        }
    }

    else
    {
        std::cout << "test" << std::endl;
        state = init::game_state();
    }
}

int calculateState(const GameState state)
{
    int win = false;
    int tie = false;
    int player = TILE_NONE;

    // win checking for loop algorithm
    for(int tile = 0; tile < 9; tile++)
    {
        player = TILE_NONE;
        if(state.gameBoard[tile] == TILE_NONE)
        {
            continue;
        }

        else if(state.gameBoard[tile] == TILE_CROSS)
        {
            player = TILE_CROSS;
        }

        else if(state.gameBoard[tile] == TILE_CIRCLE)
        {
            player = TILE_CIRCLE;
        }

        int row = tile / 3;
        int column = tile % 3;

        if(row == 0)
        {
            if( state.gameBoard[tile + 3] == player &&
                state.gameBoard[tile + 6] == player)
            {
                win = true;
                break;
            }
        }

        if(column == 0)
        {
            if( state.gameBoard[tile + 1] == player &&
                state.gameBoard[tile + 2] == player)
            {
                win = true;
                break;
            }
        }

        if(row == 1 && column == 1)
        {
            if
            (
                (   
                    state.gameBoard[tile - 4] == player &&
                    state.gameBoard[tile + 4] == player
                ) ||
                (   
                    state.gameBoard[tile - 2] == player &&
                    state.gameBoard[tile + 2] == player
                )
            )
            {
                win = true;
                break;
            }
        }
    }

    // tie checking for loop algorithm
    for(int tile = 0; tile < 9; tile++)
    {
        if(state.gameBoard[tile] == TILE_NONE)
            break;
        
        if(tile == 8)
            tie = true;
    }

    if(win == true)
    {
        if(player == TILE_CROSS)
        {
            return STATE_CROSS_WIN;
        }
        if(player == TILE_CIRCLE)
        {
            return STATE_CIRCLE_WIN;
        }
    }

    else if(tie == true)
    {
        return STATE_TIE;
    }

    else return STATE_PLAYING;
}