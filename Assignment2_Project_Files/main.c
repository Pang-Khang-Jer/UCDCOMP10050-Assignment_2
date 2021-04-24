#include "library.h"
#include <stdio.h>

int main()
{
    // initialize the play board. all changes in the game is made to this play board
    PlayBoard board = {{"\0", 0, BLACK}, {"\0", 0, WHITE}, {}};
    PlayerPtr activePlayerPtr;    // points to the player that is going to place a disc
    int isPlaying = 1;
    int skippedLastTurn = 0;

    // the game starts with player 1
    activePlayerPtr = &board.player1;

    initializeGrid(&board);
    printIntro();
    registerPlayers(&board);

    printBoard(board);

    while (isPlaying == 1)
    {
        int row, col;

        if (isMoveAvailable(board.grid, *activePlayerPtr))
        {
            readInput(*activePlayerPtr, &row, &col);

            if (isMoveValid(board.grid, *activePlayerPtr, row, col, 1))
            {
                // the move is valid, do all possible captures and move to the next player
                capture(&board, *activePlayerPtr, row, col);
                updateScore(&board);
                printBoard(board);
                nextTurn(&board, &activePlayerPtr);
            }
        }
        else
        {
            printf("No move available for %s (%s).\n", activePlayerPtr->playerName, activePlayerPtr->discColor == BLACK ? "Black" : "White");

            if (skippedLastTurn == 0)
            {
                nextTurn(&board, &activePlayerPtr);
                skippedLastTurn = 1;
            }
            else
            {
                isPlaying = 0;
            }
        }
    }

    endGame(board);

    return 0;
}
