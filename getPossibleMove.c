#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "getPossibleMove.h"

// Function to find all the possible moves of current player
// Integer variable row holds the value of the row of current player's disc
// Integer variable column holds the value of the column of current player's disc
void findMove(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // Check if opponent's disc is beside current player's disc
    // i is the index for row to check if opponent's disc is around current player's disc
    // So the range of i is from row-1 to row+1
    for(int i = row - 1; i <= row + 1; i++)
    {
        // Ignore if the value of i is outside the board
        if(!(i >= 0 && i < BOARD_SIZE))
        {
            continue;
        }

        // j is the index for column to check if opponent's disc is around current player's disc
        // So the range of j is from column-1 to column+1
        for(int j = column - 1; j <= column + 1; j++)
        {
            // Ignore if the value of j is outside the board
            if(!(j >= 0 && j < BOARD_SIZE))
            {
                continue;
            }

            // Ignore the relative disc of current player
            if(i == row && j == column)
            {
                continue;
            }

            // If opponent's disc is around current player's disc
            // Check the specific direction and store in linked list
            if(board[i][j].colour == opponent.colour)
            {
                if(i == row - 1) // If opponent's disc is above the current player's disc
                {
                    // There are 3 directions on above which are north-west, north, north-east
                    if(j == column - 1) // If opponent's disc is on upper left of current player's disc
                    {
                        // Check direction of north-west
                        findNorthWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column) // If opponent's disc is right above current player's disc
                    {
                        // Check direction of north
                        findNorth(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on upper right of current player's disc
                    {
                        // Check direction of north-east
                        findNorthEast(board, sPtr, opponent, row, column);
                    }
                }
                else if(i == row) // If opponent's disc is on the same row with current player's disc
                {
                    // There are 2 directions which are west and east
                    if(j == column - 1) // If opponent's disc is on the left of current player's disc
                    {
                        // Check direction of west
                        findWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on the right of current player's disc
                    {
                        // Check direction of east
                        findEast(board, sPtr, opponent, row, column);
                    }
                }
                else if(i == row + 1) // If opponent's disc is below the current player's disc
                {
                    // There are 3 directions on below which are south-west, south, south-east
                    if(j == column - 1) // If opponent's disc is on bottom left of current player's disc
                    {
                        // Check direction of south-west
                        findSouthWest(board, sPtr, opponent, row, column);
                    }
                    else if(j == column) // If opponent's disc is right below of current player's disc
                    {
                        // Check direction of south
                        findSouth(board, sPtr, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on bottom right of current player's disc
                    {
                        // Check direction of south-east
                        findSouthEast(board, sPtr, opponent, row, column);
                    }
                }
            }
        }
    }
}

// Function to check if the coordinates already exist in the linked list
int checkList(possibleMovePtr cPtr, int row, int column)
{
    while(cPtr != NULL) // Before reaching the end of the list
    {
        // Return 1 if the coordinate is found in the list
        if(cPtr->row == row && cPtr->col == column)
        {
            return 1;
        }

        cPtr = cPtr->nextPtr; // Move to next node to check through the whole list
    }

    return 0;
}

// Function to insert a coordinate in the linked list in ascending order according to value of row
void insert(possibleMovePtr *sPtr, int row, int column)
{
    if(!(checkList(*sPtr, row, column))) // If the coordinate is not found in list
    {
        possibleMovePtr newPtr = malloc(sizeof(possibleMove)); // Create a new node

        if(newPtr != NULL) // If there is available space
        {
            newPtr->row = row; // Store the value of row in the node
            newPtr->col = column; // Store the value of column in the node
            newPtr->nextPtr = NULL; // Point to NULL because it is not linked with other node

            possibleMovePtr previousPtr = NULL; // Pointer to previous node in the list
            possibleMovePtr currentPtr = *sPtr; // Pointer to current node in the list

            // Find the correct position of new node in the list before the list comes to end
            // First, check if the value of row in new node is greater than the value of row of the existing node
            // If so, move to next node until a bigger value is found in the list
            // If they have same value of row, check the value of column
            while(currentPtr != NULL && ((row > currentPtr->row) || (row == currentPtr->row && column > currentPtr->col)))
            {
                // Move to next node in the list
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            }

            // Insert a new node at the beginning of the list
            if(previousPtr == NULL)
            {
                newPtr->nextPtr = *sPtr;
                *sPtr = newPtr;
            }
            else // Insert the new node between previousPtr and currentPtr
            {
                previousPtr->nextPtr = newPtr;
                newPtr->nextPtr = currentPtr;
            }
        }
        else // If memory is insufficient
        {
            printf("Error. No memory available.");
        }
    }
}

// Function to find possible move at north-west direction
void findNorthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column - 2; i >= 0 && j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards upper left by decrementing both values of i and j
            i--;
            j--;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at north direction
void findNorth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column; i >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move upwards by decrementing value of i
            i--;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at north-east direction
void findNorthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column + 2; i >= 0 && j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards upper right by decrementing value of i and incrementing value of j
            i--;
            j++;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at west direction
void findWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row, j = column - 2; j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards left side by decrementing the value of j
            j--;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at east direction
void findEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row, j = column + 2; j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards right side by incrementing the value of j
            j++;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at south-west direction
void findSouthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column - 2; i < BOARD_SIZE && j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards bottom left by incrementing value of i and decrementing value of j
            i++;
            j--;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at south direction
void findSouth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column; i < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move downwards by incrementing value of i
            i++;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}

// Function to find possible move at south-east direction
void findSouthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column + 2; i < BOARD_SIZE && j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent.colour)
        {
            // Move towards bottom right by incrementing both values of i and j
            i++;
            j++;
        }
        else if(board[i][j].colour == EMPTY) // If current square is empty
        {
            insert(sPtr, i, j); // Insert current coordinate into linked list
            break; // Exit from loop
        }
        else // If no available move in this direction
        {
            break;
        }
    }
}
