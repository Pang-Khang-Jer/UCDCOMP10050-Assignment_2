#include "library.h"
#include <stdio.h>

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

    board->player1Score = 2;
    board->player2Score = 2;
}

// assign the players of a game
void registerPlayers(PlayBoard *board)
{
    printf("Enter Enter name of Player 1 (Black): ");
    gets(board->player1Name);
    printf("Enter name of Player 2 (White): ");
    gets(board->player2Name);
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

// print the board based on input board's grid
void printBoard(PlayBoard board)
{
    // print scoreboard
    printf(" Score: %s (Black) %d:%d %s (White)\n", board.player1Name, board.player1Score, board.player2Score, board.player2Name);

    // loop until GRID_SIZE * 2 + 1 because each row needs to be looped twice and one extra loop is needed to close the grid
    for (int y = 0; y < GRID_SIZE * 2 + 1; ++y)
    {
        // prints the start of the rows according to parity of printed row
        if (y % 2 == 0)
        {
            printf("    ");
        }
        else
        {
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
                char gridChar = getNodeState(board.grid, localGridX, localGridY);

                printf(" %c |", gridChar);
            }
        }
        printf("\n");
    }

    char xLabel = 'a';
    printf("     ");
    for (int x = 0; x < GRID_SIZE; ++x)
    {
        printf("%-4c", xLabel);
        xLabel++;
    }

    printf("\n\n");
}

// return 1 if the move is valid, 0 otherwise
int isMoveValid(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex)
{
    if (!isNodeEmpty(grid, rowIndex, colIndex))
    {
        puts("Not a valid move. The selected node is occupied.");
        return 0;
    }
    else if (!isNodeSelectable(rowIndex, colIndex))
    {
        puts("Not a valid move. The selected node is outside the grid.");
        return 0;
    }
    else
    {
        /*
        // this might be a valid move. check the surrounding nodes

        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                // skip the node that is just placed
                if (i == 0 && j == 0)
                {
                    continue;
                }

                //int checkRow = rowIndex + i;
                //int checkCol = colIndex + j;


            }
        }
         */
    }
}

// return 1 if the NodeState of the given index is empty, 0 otherwise
int isNodeEmpty(NodeState grid[GRID_SIZE][GRID_SIZE], int rowIndex, int colIndex)
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
int canCaptureDirection(NodeState grid[GRID_SIZE][GRID_SIZE], ActivePlayer activePlayer, int centerRowIndex, int centerColIndex, int captureRowStep, int captureColStep)
{
    int stepsMoved = 0;         //number of steps moved
    NodeState activeColor;      //stores the color of the active player
    NodeState opponentColor;    //stores the color to be captured
    int curRowIndex;            //stores the row index of the node being checked
    int curColIndex;            //stores the column index of the node being checked
    NodeState curNode;          //stores the color of the current node being checked

    activeColor = activePlayer == PLAYER1 ? BLACK : WHITE;
    // player 1 captures white discs, player 2 captures black discs
    opponentColor = activePlayer == PLAYER1 ? WHITE : BLACK;

    printf("Player's active color is: %d\n", activeColor);
    printf("Opponent's color is: %d\n", opponentColor);

    curRowIndex = centerRowIndex + captureRowStep;
    curColIndex = centerColIndex + captureColStep;
    curNode = grid[curRowIndex][curColIndex];
    printf("Comparing %d, %d\n", curRowIndex, curColIndex);

    // move in the given step until it reaches the border or the current node is not the opponent's color
    while (isNodeSelectable(curRowIndex, curColIndex) && curNode == opponentColor)
    {
        stepsMoved += 1;
        curRowIndex += captureRowStep;
        curColIndex += captureColStep;
        curNode = grid[curRowIndex][curColIndex];
        printf("Comparing %d, %d\n", curRowIndex, curColIndex);
    }

    // check the current node to see if it can be captured
    if (curNode == activeColor)
    {
        return stepsMoved;
    }

    // the last disc checked is not the active color. cannot capture
    puts("cannot capture");
    return 0;
}

// read input in format "int char" and convert it to index
void readInput(PlayBoard board, int *row, int *col)
{
    int inputRow;
    char inputCol;

    printf("? ");
    scanf("%d %c", &inputRow, &inputCol);

    *row = inputRow - 1;
    *col = inputCol - 'a';
}
