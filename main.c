#include <time.h>
#include "initialization.h"
#include "playGame.h"
#include "endGame.h"

int main()
{
    // Initialize struct players 1 and 2
    player p1 = {"Player 1", EMPTY, 0};
    player p2 = {"Player 2", EMPTY, 0};

    disc board[BOARD_SIZE][BOARD_SIZE]; // Struct of 2D array for board

    time_t startTime; // Variable to hold start time of game
    time_t endTime; // Variable to hold end time of game

    time(&startTime); // Store current time as start time

    mainInitialize(board, &p1, &p2); // Initialize player and board

    takeTurn(board, &p1, &p2); // Manage the game turn between two players

    time(&endTime); // Store current time as end time

    mainEnd(board, p1, p2, startTime, endTime); // Print out results when game is over

    return 0;
}
