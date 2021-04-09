#include <stdio.h>
#include "library.h"

int main()
{
    PlayBoard board;

    printIntro();
    registerPlayers(&board);

    printf("%s %s", board.player1, board.player2);

    return 0;
}
