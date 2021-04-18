#include "library.h"
#include <stdio.h>

int main()
{
    // initialize the play board. all changes in the game is made to this play board
    PlayBoard board = {{"\0", 0, BLACK}, {"\0", 0, WHITE}, {}};
    PlayerPtr activePlayerPtr;    // points to the player that is going to place a disc
    int isPlaying = 1;

    // the game starts with player 1
    activePlayerPtr = &board.player1;

    initializeGrid(&board);
    printIntro();
    registerPlayers(&board);

    printBoard(board);

    while (isPlaying)
    {
        int row, col;

        readInput(*activePlayerPtr, &row, &col);

        /*
        printf("Input: %d%d\n", row, col);
        printf("Empty: %d\n", isNodeEmpty(board.grid, row, col));
        printf("Selectable: %d\n", isNodeSelectable(row, col));
        printf("Move valid: %d\n", isMoveValid(board.grid, activePlayer, row, col));
        */

        if (isMoveValid(board.grid, *activePlayerPtr, row, col))
        {
            capture(&board, *activePlayerPtr, row, col);
            printBoard(board);
            nextTurn(&board, &activePlayerPtr);
        }
    }

    return 0;
}
