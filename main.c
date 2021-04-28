#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "playGame.h"

int main()
{
    // Initialize struct players 1 and 2
    player p1 = {"Player 1", EMPTY, 0};
    player p2 = {"Player 2", EMPTY, 0};

    disc board[BOARD_SIZE][BOARD_SIZE]; // Struct of 2D array for board

    int(*arr)[NUM] = calloc(NUM * 2, sizeof(int));

    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            arr[i][j] = j;
        }
    }

    for(int i = 0; i < NUM; i++)
    {
        for(int j = 0; j < NUM; j++)
        {
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }

    initializePlayer(&p1, &p2); // Initialize player
    initializeBoard(board); // Initialize board
    printBoard(board, p1, p2); // Print the board

    //takeTurn(board, &p1, &p2);

    return 0;
}
