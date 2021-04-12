#include <stdio.h>
#include "library.h"

int main()
{
    // initialize the play board. all changes in the game is made to this play board
    PlayBoard board = {"\0", "\0", 0, 0, {0}};

    initializeGrid(&board);
    printIntro();
    registerPlayers(&board);

    printBoard(board);

    return 0;
}
