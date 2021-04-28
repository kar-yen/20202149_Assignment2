#include <stdio.h>
#include "initialization.h"

void findMove(disc board[][BOARD_SIZE], player opponent, int row, int column);

void takeTurn(disc board[][BOARD_SIZE], player *p1, player *p2)
{
    int turn = 1;
    int pass = 0;
    // Calculate space left on board
    int spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);

    // Game continue while there is space left on the board
    // Exit from loop if both players pass the game consecutively
    while(spaceLeft)
    {
        if(turn % 2 != 0) // Player 1's turn if odd number
        {
            printf("Round %d.\nPlayer 1's turn.\n", turn);

            turn++; // Increment turn
        }

        if(turn % 2 == 0) // Player 2's turn if even number
        {
            printf("Round %d.\nPlayer 2's turn.\n", turn);

            turn++;
        }

        // Update space left on board after each turn
        spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);
    }
}

void getMove(disc board[][BOARD_SIZE], player *current, player *opponent)
{
    char move[3];
    char coordinates[BOARD_SIZE][3];

    printf("A move should be enter in the form of 'ld' where l is letter and d is digit. (E.g. a3)\n"
           "Enter your move: ");
    scanf("%s", move);
    fflush(stdin);

    // Check all the possible move of current player and store in a 2d array
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].colour == current->colour)
            {
                findMove(board, *opponent, i, j);
            }
        }
    }

    // Check if user input is a valid move by comparing with the array that store all possible moves.
    // Reprompt user to enter another move if it is not valid
    // If loop when there is no possible move
}

void findMove(disc board[][BOARD_SIZE], player opponent, int row, int column)
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
                // Check directions and store in a array
            }
        }
    }
}