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

typedef struct player
{
    char playerName[MAX_ARRAY_SIZE];
    int playerScore;
    NodeState discColor;
} Player;

typedef struct playBoard
{
    Player player1;
    Player player2;
    NodeState grid[GRID_SIZE][GRID_SIZE];
} PlayBoard;

typedef Player* PlayerPtr;

void printIntro();
void initializeGrid(PlayBoard *board);
void registerPlayers(PlayBoard *board);
void printBoard(PlayBoard board);
void readInput(Player activePlayer, int *row, int *col);
char getNodeState(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex);
int isMoveValid(NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int rowIndex, int colIndex);
int isNodeEmpty(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex);
int isNodeSelectable(int rowIndex, int colIndex);
int canCaptureDirection(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int centerRowIndex, int centerColIndex, int captureRowStep, int captureColStep);
void capture(PlayBoard *board, Player activePlayer, int centerRowIndex, int centerColIndex);
void nextTurn(const PlayBoard *board, PlayerPtr *curActivePlayerPtr);

#endif //ASSIGNMENT2_PROJECT_FILES_LIBRARY_H
