#include "library.h"
#include <stdio.h>

void printIntro()
{
    puts("*** Welcome to Othello! ***");
}

void registerPlayers(PlayBoard *board)
{
    printf("Enter Enter name of Player 1 (Black): ");
    scanf("%s", board->player1);
    printf("Enter name of Player 2 (White): ");
    scanf("%s", board->player2);
}