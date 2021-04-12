#ifndef ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define MAX_ARRAY_SIZE 20
#define GRID_SIZE 8

typedef enum gridState
{
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
} GridState;

typedef struct playBoard
{
    char player1Name[MAX_ARRAY_SIZE];
    char player2Name[MAX_ARRAY_SIZE];
    int player1Score;
    int player2Score;
    GridState grid[GRID_SIZE][GRID_SIZE];
} PlayBoard;

void printIntro();
void initializeGrid(PlayBoard *board);
void registerPlayers(PlayBoard *board);
void printBoard(PlayBoard board);
char getGridDisc(PlayBoard board, int rowIndex, int colIndex);

#endif //ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
