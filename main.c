#include <stdio.h>
#include "initialization.h"
#include "playGame.h"

int main()
{
    player p1 = {"Player 1", EMPTY, 0};
    player p2 = {"Player 2", EMPTY, 0};

    disc board[BOARD_SIZE][BOARD_SIZE];

    initializePlayer(&p1, &p2);
    initializeBoard(board);
    printBoard(board, p1, p2);

    takeTurn(board, &p1, &p2);

    return 0;
}
