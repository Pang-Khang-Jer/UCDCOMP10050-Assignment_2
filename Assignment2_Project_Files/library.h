#ifndef ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define MAX_ARRAY_SIZE 20
typedef enum gridState
{
    EMPTY,
    BLACK,
    WHITE
} GridState;

typedef struct playBoard
{
    char player1[MAX_ARRAY_SIZE];
    char player2[MAX_ARRAY_SIZE];
    GridState grid[64][64];
} PlayBoard;

void printIntro();
void registerPlayers(PlayBoard *board);

#endif //ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
