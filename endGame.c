#include <stdio.h>
#include <time.h>
#include "initialization.h"
#include "endGame.h"

// Function to handle ending of game
void mainEnd(disc board[][BOARD_SIZE], player p1, player p2, time_t t1, time_t t2)
{
    int min = difftime(t2, t1) / 60; // Variable to hold minutes
    int sec = difftime(t2, t1) - (min * 60); // Variable to hold seconds

    printf("\n\t\t***   Game Over!   ***\n\n"); // Print end game message to console

    if(min < 10 && sec < 10) // If both min and sec have 1 digit
    {
        printf("Total duration: 0%d min 0%d sec\n", min, sec);
    }
    else if(min < 10) // If min has 1 digit
    {
        printf("Total duration: 0%d min %d sec\n", min, sec);
    }
    else if(sec < 10) // If sec has 1 digit
    {
        printf("Total duration: %d min 0%d sec\n", min, sec);
    }
    else // If both min and sec have more than 1 digit
    {
        printf("Total duration: %d min %d sec\n", min, sec);
    }


    printf("\nFinal result:\n");
    //printf("Player 1 (Black): %s, Score: %d", p1.name, p1.score);
    //printf("Player 2 (White): %s, Score: %d", p2.name, p2.score);

    if(p1.score > p2.score) // If player 1 has higher score
    {
        // Print the name and score of winner
        printf("Player 1 wins! The winner is %s with score %d.\n", p1.name, p1.score);
    }
    else if(p2.score > p1.score) // If player 2 has higher score
    {
        // Print the name and score of winner
        printf("Player 2 wins! The winner is %s with score %d.\n", p2.name, p2.score);
    }
    else // If both players have same score
    {
        printf("Draw!\n");
    }

    printBoard(board, p1, p2); // Print the final board with score

    printf("\n\t\t***   Game Over!   ***\n\n");

    createFile(board, p1, p2, t1, t2, min, sec); // Create a text file and write the result in the file

}

// Function to create a text file with results in it
void createFile(disc board[][BOARD_SIZE], player p1, player p2, time_t t1, time_t t2, int min, int sec)
{
    FILE *fp;

    // Create a new text file in current directory with mode 'write'
    fp = fopen("othello-results.txt", "w");

    if(fp == NULL) // If file is failed to create
    {
        // Print error message to the console
        printf("Error. File unable to create.\n");
    }
    else // If file is created successfully
    {
        // Write start date and time in the file
        fprintf(fp, "Start date and time: %s\n", ctime(&t1));
        // Write end date and time in the file
        fprintf(fp, "End date and time  : %s\n", ctime(&t2));

        if(min < 10 && sec < 10) // If both min and sec have 1 digit
        {
            fprintf(fp, "Total duration     : 0%d min 0%d sec", min, sec);
        }
        else if(min < 10) // If min has 1 digit
        {
            fprintf(fp, "Total duration     : 0%d min %d sec", min, sec);
        }
        else if(sec < 10) // If sec has 1 digit
        {
            fprintf(fp, "Total duration     : %d min 0%d sec", min, sec);
        }
        else // If both min and sec have more than 1 digit
        {
            fprintf(fp, "Total duration: %d min %d sec", min, sec);
        }

        // Write the name and final score of players
        fprintf(fp, "\n\n\t\t  ***   Game Over!   ***\n\n"
                    "Final results:\n");
        fprintf(fp, "Player 1 (Black): %s, Score: %d\n", p1.name, p1.score);
        fprintf(fp, "Player 2 (White): %s, Score: %d\n\n", p2.name, p2.score);

        if(p1.score > p2.score) // If player 1 has higher score
        {
            // Write the name and score of winner in the file
            fprintf(fp, "Player 1 wins! The winner is %s with score %d.\n", p1.name, p1.score);
        }
        else if(p2.score > p1.score) // If player 2 has higher score
        {
            // Write the name and score of winner in the file
            fprintf(fp, "Player 2 wins! The winner is %s with score %d.\n", p2.name, p2.score);
        }
        else // If both players have same score
        {
            fprintf(fp, "Draw!\n");
        }

        boardFile(board, fp); // Print the final board in the file

        fprintf(fp, "\n\t\t  ***   Game Over!   ***\n\n");

        fclose(fp); // Close file
    }
}

// Function to print the final board in the file
void boardFile(disc board[][BOARD_SIZE], FILE *fp)
{
    int z;

    // Print the horizontal line for the board
    fprintf(fp, "\n\t   ");
    for(z = 1; z <= BOARD_SIZE; z++)
    {
        fprintf(fp, "--- ");
    }

    // Visualize the board by printing disc and vertical lines for board
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        // Row index from 1 to 8 on the left of board
        fprintf(fp, "\n\t%d |", i+1);

        // Print the words 'B' and 'W' to represent the disc on board
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            // If black disc is on the current square of board
            if (board[i][j].colour == BLACK)
            {
                fprintf(fp, " B |");
            }
            // If white disc is on the current square on board
            else if (board[i][j].colour == WHITE)
            {
                fprintf(fp, " W |");
            }
            // If no disc on the current square of board
            else
            {
                fprintf(fp, "   |");
            }
        }

        // Print the horizontal line for the board
        fprintf(fp, "\n\t   ");
        for(z = 1; z <= BOARD_SIZE; z++)
        {
            fprintf(fp, "--- ");
        }
    }

    // Column index from a to h on the bottom of board
    fprintf(fp, "\n\t    ");
    for (z = 1; z <= BOARD_SIZE; z++)
    {
        fprintf(fp, "%c   ", z - 1 + 'a');
    }
    fprintf(fp, "\n\n");

}
