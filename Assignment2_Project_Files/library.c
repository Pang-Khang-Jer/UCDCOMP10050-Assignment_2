#include "library.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#define OUTPUT_FILE_PATH "othello-results.txt"

void printIntro()
{
    puts("*** Welcome to Othello! ***");
}

void initializeGrid(PlayBoard *board)
{
    int center = GRID_SIZE / 2;
    board->grid[center - 1][center - 1] = WHITE;
    board->grid[center][center - 1] = BLACK;
    board->grid[center - 1][center] = BLACK;
    board->grid[center][center] = WHITE;

    board->player1.playerScore = 2;
    board->player2.playerScore = 2;
}

// assign the players of a game
void registerPlayers(PlayBoard *board)
{
    printf("Enter Enter name of Player 1 (Black): ");
    gets(board->player1.playerName);
    printf("Enter name of Player 2 (White): ");
    gets(board->player2.playerName);
}

// returns the char representing the disc located in rowIndex, colIndex
char getNodeState(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex)
{
    NodeState disc = grid[rowIndex][colIndex];
    char output;

    switch (disc)
    {
        case BLACK:
            output = 'B';
            break;
        case WHITE:
            output = 'W';
            break;
        default:
            output = ' ';
    }

    return output;
}

// returns the string that represents the player's colour
char* getNodeColourString(NodeState nodeState)
{
    char *colourStr;

    if (nodeState == BLACK)
    {
        colourStr = "Black";
    }
    else if (nodeState == WHITE)
    {
        colourStr = "White";
    }
    else
    {
        colourStr = "Null";
    }

    return colourStr;
}

// print the board based on input board's grid
void printBoard(PlayBoard board, Player activePlayer)
{
    // print scoreboard
    printf(" Score: %s (Black) %d:%d %s (White)\n\n", board.player1.playerName, board.player1.playerScore, board.player2.playerScore, board.player2.playerName);

    // print the column labels at the top of the board
    char xLabel = 'a';
    printf("     ");
    for (int x = 0; x < GRID_SIZE; ++x)
    {
        printf("%-4c", xLabel);
        xLabel++;
    }
    printf("\n");

    // print the grid
    // loop until GRID_SIZE * 2 + 1 because each row needs to be looped twice and one extra loop is needed to close the grid
    for (int y = 0; y < GRID_SIZE * 2 + 1; ++y)
    {
        // prints the row labels at the left end of the board according to parity of printed row
        if (y % 2 == 0)
        {
            printf("    ");
        }
        else
        {
            // print the row label
            printf(" %d |", y / 2 + 1);
        }

        for (int x = 0; x < GRID_SIZE; ++x)
        {
            // prints the continuation of the rows according to parity of printed row
            if (y % 2 == 0)
            {
                printf("--- ");
            }
            else
            {
                // location of current printed grid in grid index
                int localGridX = x;
                int localGridY = y / 2;
                char gridChar;

                if (isMoveValid(board.grid, activePlayer, localGridY, localGridX, 0))
                {
                    gridChar = '.';
                }
                else
                {
                    gridChar = getNodeState(board.grid, localGridY, localGridX);
                }

                printf(" %c |", gridChar);
            }
        }

        // prints the row labels at the right end of the board according to parity of printed row
        if (y % 2 == 0)
        {
            printf("    ");
        }
        else
        {
            printf(" %d", y / 2 + 1);
        }

        printf("\n");
    }

    // print the column labels at the bottom of the board
    xLabel = 'a';
    printf("     ");
    for (int x = 0; x < GRID_SIZE; ++x)
    {
        printf("%-4c", xLabel);
        xLabel++;
    }

    printf("\n\n");
}

// read input in format "%d%c" and convert it to index
void readInput(Player activePlayer, int *row, int *col)
{
    int inputRow = -1;
    char inputCol = -1;
    char discColorStr[MAX_ARRAY_SIZE];
    int read;

    strcpy(discColorStr, getNodeColourString(activePlayer.discColour));

    printf("It's %s (%s)'s  turn.\n", activePlayer.playerName, discColorStr);
    printf("Enter move (a number followed by a character, e.g. b1, g5): ");

    //read player's input with error checking
    read = scanf(" %c %d", &inputCol, &inputRow);

    while (read != 2)
    {
        puts("Error reading input.");
        printf("Enter move (a number followed by a character, e.g. b1, g5): ");

        read = scanf(" %c %d", &inputCol, &inputRow);
    }

    *row = inputRow - 1;
    *col = inputCol - 'a';
}

// return 1 if the move is valid, 0 otherwise
int isMoveValid(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int rowIndex, int colIndex, int printWarnings)
{
    if (!isNodeSelectable(rowIndex, colIndex))
    {
        if (printWarnings)
        {
            puts("Invalid move: Selected node is outside the grid.");
        }

        return 0;
    }
    else if (!isNodeEmpty(grid, rowIndex, colIndex))
    {
        if (printWarnings)
        {
            puts("Invalid move: Selected node is occupied.");
        }

        return 0;
    }
    else
    {
        // this might be a valid move. check the surrounding nodes
        for (int y = -1; y <= 1; ++y)
        {
            for (int x = -1; x <= 1; ++x)
            {
                // skip checking the node that is just placed
                if (y == 0 && x == 0)
                {
                    continue;
                }

                // check if a capture is possible in all directions
                if (canCaptureDirection(grid, activePlayer, rowIndex, colIndex, y, x) > 0)
                {
                    return 1;
                }
            }
        }

        if (printWarnings)
        {
            puts("Invalid move: No discs to capture.");
        }
    }

    return 0;
}

// return 1 if the NodeState of the given index is empty, 0 otherwise
int isNodeEmpty(const NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex)
{
    return grid[rowIndex][colIndex] == EMPTY;
}

// return 1 if the input index is inside the grid, 0 otherwise
int isNodeSelectable(int rowIndex, int colIndex)
{
    int maxIndex = GRID_SIZE - 1;

    if (rowIndex > maxIndex || rowIndex < 0 || colIndex > maxIndex || colIndex < 0)
    {
        return 0;
    }

    return 1;
}

// return the number of captures that can be made in the direction specified by captureRowStep and captureColStep
int canCaptureDirection(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer, int centerRowIndex, int centerColIndex, int captureRowStep, int captureColStep)
{
    int stepsMoved = 0;         //number of steps moved
    NodeState activeColor;      //stores the colour of the active player
    NodeState opponentColor;    //stores the colour to be captured
    int curRowIndex;            //stores the row index of the node being checked
    int curColIndex;            //stores the column index of the node being checked
    NodeState curNode;          //stores the colour of the current node being checked

    activeColor = activePlayer.discColour;
    opponentColor = activeColor == BLACK ? WHITE : BLACK;

    // move one step and get the node
    curRowIndex = centerRowIndex + captureRowStep;
    curColIndex = centerColIndex + captureColStep;
    curNode = grid[curRowIndex][curColIndex];

    // move in the given step until it reaches the border or the current node is not the opponent's colour
    while (isNodeSelectable(curRowIndex, curColIndex) && curNode == opponentColor)
    {
        stepsMoved += 1;
        curRowIndex += captureRowStep;
        curColIndex += captureColStep;
        curNode = grid[curRowIndex][curColIndex];
    }

    // check the current node to see if it can be captured
    if (curNode == activeColor)
    {
        return stepsMoved;
    }

    // the last disc checked is not the active colour. cannot capture
    return 0;
}

// place the active player's disc in the input position and do all possible captures
void capture(PlayBoard *board, Player activePlayer, int centerRowIndex, int centerColIndex)
{
    // the number of discs to be captured
    int numCapture;
    NodeState activeColor = activePlayer.discColour;

    // place the center disc
    board->grid[centerRowIndex][centerColIndex] = activeColor;

    // capture discs in all direction
    for (int y = -1; y <= 1; ++y)
    {
        for (int x = -1; x <= 1; ++x)
        {
            // assign the center position (resets every iteration)
            int curRowIndex = centerRowIndex;
            int curColIndex = centerColIndex;

            // skip checking the node that is just placed
            if (y == 0 && x == 0)
            {
                continue;
            }

            numCapture = canCaptureDirection(board->grid, activePlayer, centerRowIndex, centerColIndex, y, x);

            for (int captured = 0; captured < numCapture; ++captured)
            {
                curRowIndex += y;
                curColIndex += x;
                board->grid[curRowIndex][curColIndex] = activeColor;
            }
        }
    }
}

// Make activePlayerPtr point to the next player. Pointer to board needs to be used so that activePlayerPtr points to the board with file scope
void nextTurn(PlayBoard *board, PlayerPtr *curActivePlayerPtr)
{
    if ((*curActivePlayerPtr)->discColour == BLACK)
    {
        // current active player is player 1, change it to player 2
        *curActivePlayerPtr = &board->player2;
    }
    else if ((*curActivePlayerPtr)->discColour == WHITE)
    {
        // current active player is player 2, change it to player 1
        *curActivePlayerPtr = &board->player1;
    }
    else
    {
        // precaution
        puts("Error: Player with invalid disc colour entered. Failed to proceed to next turn");
    }
}

// Returns 0 if there is no available moves in the board for the active player, 1 otherwise
int isMoveAvailable(const NodeState grid[GRID_SIZE][GRID_SIZE], Player activePlayer)
{
    for (int y = 0; y < GRID_SIZE; ++y)
    {
        for (int x = 0; x < GRID_SIZE; ++x)
        {
            if (isMoveValid(grid, activePlayer, y, x, 0))
            {
                // The active player can take this move, hence at least one move is available to the active player
                return 1;
            }
        }
    }

    return 0;
}

// updates the scores of the playboard
void updateScore(PlayBoard *board)
{
    int score1 = 0; //black score
    int score2 = 0; //white score

    for (int y = 0; y < GRID_SIZE; ++y)
    {
        for (int x = 0; x < GRID_SIZE; ++x)
        {
            NodeState curNode = board->grid[y][x];
            if (curNode == board->player1.discColour)
            {
                score1++;
            }
            else if (curNode == board->player2.discColour)
            {
                score2++;
            }
        }
    }

    board->player1.playerScore = score1;
    board->player2.playerScore = score2;
}

void endGame(PlayBoard board)
{
    Player winner;

    puts("Game Ended");
    puts("--------------");
    puts("Final score:");
    puts("--------------");
    printf("%s (Black): %d\n", board.player1.playerName, board.player1.playerScore);
    printf("%s (White): %d\n", board.player2.playerName, board.player2.playerScore);

    if (board.player1.playerScore != board.player2.playerScore)
    {
        if (board.player1.playerScore > board.player2.playerScore)
        {
            winner = board.player1;
        }
        else if (board.player1.playerScore < board.player2.playerScore)
        {
            winner = board.player2;
        }

        printf("The winner is %s (%s)\n", winner.playerName, getNodeColourString(winner.discColour));
    }
    else
    {
        puts("The game ended as a draw.");
    }
}

// create or append the date, time, winner and score of the game to the output file
void saveGameResult(PlayBoard board)
{
    FILE *fp = NULL;
    time_t curTime;

    curTime = time(NULL);

    fp = fopen(OUTPUT_FILE_PATH, "a");

    if (fp != NULL)
    {
        char *timeString;

        timeString = ctime(&curTime);
        fprintf(fp, "%s", timeString);
        fprintf(fp, "Score: %s (Black) %d:%d %s (White)\n", board.player1.playerName, board.player1.playerScore, board.player2.playerScore, board.player2.playerName);
        fprintf(fp, "Winner: ");

        if (board.player1.playerScore != board.player2.playerScore)
        {
            if (board.player1.playerScore > board.player2.playerScore)
            {
                fprintf(fp, "%s (Black)\n", board.player1.playerName);
            }
            else if (board.player1.playerScore < board.player2.playerScore)
            {
                fprintf(fp, "%s (White)\n", board.player2.playerName);
            }
        }
        else
        {
            fprintf(fp, "Null (Draw)\n");
        }

        fprintf(fp, "\n");

        printf("Successfully saved game result to %s\n", OUTPUT_FILE_PATH);
    }
    else
    {
        puts("Error creating file to save result.");
    }

    fclose(fp);
}