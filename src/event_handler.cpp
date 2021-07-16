// handles input events, processes game logic on tile basis

#include "event_handler.h"

// handles sdl events and sends them into gameInput as a tile index
// tools::get_tile translates the mouse's x and y position into a tile index
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

// handles input on a tile basis so that game logic is more simply programmed
void gameInput(const int tile, GameState &state)
{
    // if a suitable tile is not clicked, get_tile will return -1
    // this will cause gameInput to access unallocated memory, use this return to fix
    if(tile == -1)
        return;

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

        calculateState(state);

        //
        //  yeah, is there a better way to do this? post an issue if you know.
        //
        if(state.winningColumn != -1)
        {
            if(state.winningColumn == 0)
            {
                for(int tile = 1; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                for(int tile = 2; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
            if(state.winningColumn == 1)
            {
                for(int tile = 0; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                for(int tile = 2; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
            if(state.winningColumn == 2)
            {
                for(int tile = 0; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                for(int tile = 1; tile < 9; tile += 3)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
        }
        if(state.winningRow != -1)
        {
            if(state.winningRow == 0)
            {
                for(int tile = 3; tile < 9; tile += 1)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
            if(state.winningRow == 1)
            {
                for(int tile = 0; tile < 3; tile += 1)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                for(int tile = 6; tile < 9; tile += 1)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
            if(state.winningRow == 2)
            {
                for(int tile = 0; tile < 6; tile += 1)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
        }
        if(state.winningDiag != -1)
        {
            if(state.winningDiag == 0)
            {
                for(int tile = 1; tile < 4; tile++)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                for(int tile = 5; tile < 8; tile++)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
            if(state.winningDiag == 1)
            {
                for(int tile = 0; tile < 2; tile++)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
                state.gameBoard[3] = TILE_NONE;
                state.gameBoard[5] = TILE_NONE;
                for(int tile = 7; tile < 9; tile++)
                {
                    state.gameBoard[tile] = TILE_NONE;
                }
            }
        }
    }

    else
    {
        // if the game state is not playing, the game is over.
        // clicking in this state will reset the board, and restart the game.
        state = init::game_state();
    }
}

// goes through the game board and runs a win checking and
// tie checking algorithm and returns the state as such
void calculateState(GameState &state)
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
                state.winningColumn = column;
                break;
            }
        }

        if(column == 0)
        {
            if( state.gameBoard[tile + 1] == player &&
                state.gameBoard[tile + 2] == player)
            {
                win = true;
                state.winningRow = row;
                break;
            }
        }

        if(row == 1 && column == 1)
        {
            if
            (
                state.gameBoard[tile - 4] == player &&
                state.gameBoard[tile + 4] == player
            ) 
            {
                win = true;
                state.winningDiag = 0;
                break;
            }
            if
                (   
                    state.gameBoard[tile - 2] == player &&
                    state.gameBoard[tile + 2] == player
                )
            {
                win = true;
                state.winningDiag = 1;
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
            state.state = STATE_CROSS_WIN;
        }
        if(player == TILE_CIRCLE)
        {
            state.state = STATE_CIRCLE_WIN;
        }
    }

    else if(tie == true)
    {
        state.state = STATE_TIE;
    }

}