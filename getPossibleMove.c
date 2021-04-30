#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "getPossibleMove.h"

void findNorthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findNorth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findNorthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);

void findMove(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // Check if opponent's disc is right beside current player's disc
    for(int i = row - 1; i <= row + 1; i++)
    {
        // Ignore if outside the board
        if(!(i >= 0 && i < BOARD_SIZE))
        {
            continue;
        }

        for(int j = column - 1; j <= column + 1; j++)
        {
            // Ignore if outside the board
            if(!(j >= 0 && j < BOARD_SIZE))
            {
                continue;
            }

            // Ignore own particular disc
            if(i == row && j == column)
            {
                continue;
            }

            // If opponent's disc is beside current player's disc
            if(board[i][j].colour == opponent.colour)
            {
                // Check directions and store in linked list
                if(i == row - 1)
                {
                    if(j == column - 1)
                    {
                        findNorthWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column)
                    {
                        findNorth(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        findNorthEast(board, sPtr, opponent, row, column);
                    }
                }
                else if(i == row)
                {
                    if(j == column - 1)
                    {
                        findWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        findEast(board, sPtr, opponent, row, column);
                    }
                }
                else if(i == row + 1)
                {
                    if(j == column - 1)
                    {
                        findSouthWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column)
                    {
                        findSouth(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        findSouthEast(board, sPtr, opponent, row, column);
                    }
                }
            }
        }
    }
}

int checkList(possibleMovePtr cPtr, int row, int column)
{
    while(cPtr != NULL)
    {
        if(cPtr->row == row && cPtr->col == column)
        {
            return 1;
        }

        cPtr = cPtr->nextPtr;
    }

    return 0;
}

void insert(possibleMovePtr *sPtr, int row, int column)
{
    if(!(checkList(*sPtr, row, column)))
    {
        possibleMovePtr newPtr = malloc(sizeof(possibleMove));

        if(newPtr != NULL)
        {
            newPtr->row = row;
            newPtr->col = column;
            newPtr->nextPtr = NULL;

            possibleMovePtr previousPtr = NULL;
            possibleMovePtr currentPtr = *sPtr;

            while(currentPtr != NULL && ((row > currentPtr->row) || (row == currentPtr->row && column > currentPtr->col)))
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            }

            if(previousPtr == NULL)
            {
                newPtr->nextPtr = *sPtr;
                *sPtr = newPtr;
            }
            else
            {
                previousPtr->nextPtr = newPtr;
                newPtr->nextPtr = currentPtr;
            }
        }
        else
        {
            printf("Error, no memory available.");
        }
    }
}

void findNorthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row - 2, j = column - 2; i >= 0 && j >= 0; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i--;
            j--;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("nw %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findNorth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row - 2, j = column; i >= 0; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i--;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("n %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findNorthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row - 2, j = column + 2; i >= 0 && j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i--;
            j++;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("ne %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row, j = column - 2; j >= 0; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            j--;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("w %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row, j = column + 2; j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            j++;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("e %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findSouthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row + 2, j = column - 2; i < BOARD_SIZE && j >= 0; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i++;
            j--;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("sw %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findSouth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row + 2, j = column; i < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i++;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("s %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}

void findSouthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    for(int i = row + 2, j = column + 2; i < BOARD_SIZE && j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent.colour)
        {
            i++;
            j++;
        }
        else if(board[i][j].colour == EMPTY)
        {
            //printf("se %d %d\n", i, j);
            insert(sPtr, i, j);
            break;
        }
        else
        {
            break;
        }
    }
}
