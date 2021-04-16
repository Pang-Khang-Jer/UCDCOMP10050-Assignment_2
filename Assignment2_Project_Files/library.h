#ifndef ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
#define MAX_ARRAY_SIZE 20
#define GRID_SIZE 8

typedef enum nodeState
{
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
} NodeState;

typedef enum activePlayer
{
    PLAYER1,
    PLAYER2
} ActivePlayer;

typedef struct playBoard
{
    char player1Name[MAX_ARRAY_SIZE];
    char player2Name[MAX_ARRAY_SIZE];
    int player1Score;
    int player2Score;
    NodeState grid[GRID_SIZE][GRID_SIZE];
} PlayBoard;

void printIntro();
void initializeGrid(PlayBoard *board);
void registerPlayers(PlayBoard *board);
void printBoard(PlayBoard board);
char getNodeState(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex);
int isMoveValid(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex);
int isNodeEmpty(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex);
int isNodeSelectable(int rowIndex, int colIndex);
int canCaptureDirection(NodeState grid[GRID_SIZE][GRID_SIZE], ActivePlayer activePlayer, int centerRowIndex, int centerColIndex, int captureRowStep, int captureColStep);
void readInput(PlayBoard board, int *row, int *col);

#endif //ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
