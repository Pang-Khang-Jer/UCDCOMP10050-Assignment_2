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

    printBoard(board, *activePlayerPtr);

    while (isPlaying == 1)
    {
        int row, col;

        if (isMoveAvailable(board.grid, *activePlayerPtr))
        {
            skippedLastTurn = 0;

            readInput(*activePlayerPtr, &row, &col);

            if (isMoveValid(board.grid, *activePlayerPtr, row, col, 1))
            {
                // the move is valid, do all possible captures and move to the next player
                capture(&board, *activePlayerPtr, row, col);
                nextTurn(&board, &activePlayerPtr);
                updateScore(&board);
                printBoard(board, *activePlayerPtr);
            }
        }
        else
        {
            printf("No move available for %s (%s).\n", activePlayerPtr->playerName, getNodeColourString(activePlayerPtr->discColour));

            if (skippedLastTurn == 0)
            {
                // pass the current player and reprint the board to show possible moves by the next player
                nextTurn(&board, &activePlayerPtr);
                printBoard(board, *activePlayerPtr);
                skippedLastTurn = 1;
            }
            else
            {
                isPlaying = 0;
            }
        }
    }

    endGame(board);
    saveGameResult(board);

    puts("Program ended");

    return 0;
}
