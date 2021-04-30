#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialization.h"
#include "playGame.h"

int main()
{
    // Initialize struct players 1 and 2
    player p1 = {"Player 1", EMPTY, 0};
    player p2 = {"Player 2", EMPTY, 0};

    disc board[BOARD_SIZE][BOARD_SIZE]; // Struct of 2D array for board

    time_t t1;
    time(&t1);
    printf("%s\n", ctime(&t1));

    //int(*arr)[8] = calloc(8 * 8, sizeof(int));

    /*for(int i = 0; i < NUM; i++)
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
    }*/

    initializePlayer(&p1, &p2); // Initialize player
    initializeBoard(board); // Initialize board
    printBoard(board, p1, p2); // Print the board

    takeTurn(board, &p1, &p2);

    int min, sec;
    time_t t2;
    time(&t2);
    printf("%s\n", ctime(&t2));
    printf("%.2lf\n", difftime(t2, t1));
    min = difftime(t2, t1) / 60;
    sec = difftime(t2, t1) - (min * 60);
    printf("Total duration: %d min %d sec", min, sec);

    return 0;
}
