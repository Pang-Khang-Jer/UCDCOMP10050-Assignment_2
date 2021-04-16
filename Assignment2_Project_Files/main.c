#include <stdio.h>
#include "library.h"

int main()
{
    ActivePlayer activePlayer = PLAYER1;
    int isPlaying = 1;

    // initialize the play board. all changes in the game is made to this play board
    PlayBoard board = {"\0", "\0", 0, 0, {0}};

    initializeGrid(&board);
    printIntro();
    //registerPlayers(&board);

    printBoard(board);

    while (isPlaying)
    {
        int row, col;

        readInput(board, &row, &col);

        printf("Empty: %d\n", isNodeEmpty(board.grid, row, col));
        printf("Selectable: %d\n", isNodeSelectable(row, col));
    }

    return 0;
}
