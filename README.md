# UCDCOMP10050-Assignment_2
A program that allows 2 players to play othello.
The players will be able to input their names at the start of the game.
A player's turn will automatically be passed if there is no available moves to be made.
The game will continue until both the players have no available moves left.
The results of the game will be appended in the file `othello-results.txt`.

## Code structure
A struct defined as PlayBoard is the main component of the program. It holds all the basic information needed for the game to function.
```
typedef struct playBoard
{
    Player player1;
    Player player2;
    NodeState grid[GRID_SIZE][GRID_SIZE];  
} PlayBoard;
```
An enum defined as NodeState is used to indicate what each node (or cell) in the grid contains.
```
typedef enum nodeState
{
	EMPTY = 0,
	BLACK = 1,
	WHITE = 2  
} NodeState;
```


A struct defined as Player is used to hold information about the player.
```
typedef struct player
{
    char playerName[MAX_ARRAY_SIZE];
    int playerScore;
    NodeState discColour;
} Player;
```
A pointer to a Player is used in the main function to keep track of whose turn it is.
```
typedef Player* PlayerPtr;
```
```
PlayerPtr activePlayerPtr;
```

## Game Logic
The most important function that handles the game logic is:
```
int canCaptureDirection(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int centerRowIndex, int centerColIndex, int captureRowStep, int captureColStep);
```
The function returns the number of captures that can be done in the given direction determined by `captureRowStep` and `captureColStep`, both which will always be between -1 and 1.

Another function worth noting is:
```
int isMoveValid(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int rowIndex, int colIndex, int printWarnings)
```
which determines whether a move by the player is valid or not. It is also used to show player the available moves in the board.
