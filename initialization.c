#include <stdio.h>
#include <string.h>
#include "initialization.h"

// Main function to initialize the game
void mainInitialize(disc board[][BOARD_SIZE], player *p1, player *p2)
{
    initializePlayer(p1, p2); // Initialize player
    initializeBoard(board); // Initialize board
    printBoard(board, *p1, *p2); // Print the board

}

// Function to initialize player
void initializePlayer(player *p1, player *p2)
{
    char choice; // Variable to hold user's choice

    printf("\n\t\t***   Welcome to Othello!   ***\n\n");

    // Prompt user to see if they want to know game rules
    printf("Enter 1 if you wish to read the rules before game start. Otherwise, press any other keys to start game.\n");
    scanf("%c", &choice);
    fflush(stdin);

    // If user want to see the rules
    if(choice == '1')
    {
        gameRules();
    }

    printf("\nGame starts!\n");

    // Ask and get player 1's name
    printf("Please enter name of Player 1 (Black):");
    fgets(p1->name, NAME_LENGTH, stdin);
    convertNewLine(p1->name); // Convert new line to \0

    p1->colour = BLACK; // Assign black to first player
    p1->score = 2; // Place two black discs on the board

    fflush(stdin);

    // Ask and get player 2's name
    printf("Please enter name of Player 2 (White):");
    fgets(p2->name, NAME_LENGTH, stdin);
    convertNewLine(p2->name); // Convert new line to \0

    p2->colour = WHITE; // Assign white to second player
    p2->score = 2; // Place two white discs on board

    fflush(stdin);
}

// Function to convert new line to \0 in string
void convertNewLine(char str[])
{
    if(str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
}

// Function to initialize board
void initializeBoard(disc board[][BOARD_SIZE])
{
    // Place two black and white discs on the board
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(i == 3)
            {
                if(j == 3)
                {
                    // Place white disc on board at coordinates d4
                    board[i][j].colour = WHITE;
                }

                else if(j == 4)
                {
                    // Place black disc on board at coordinates e4
                    board[i][j].colour = BLACK;
                }

                else
                {
                    // Empty for the remaining position
                    board[i][j].colour = EMPTY;
                }
            }

            else if (i == 4)
            {
                if(j == 3)
                {
                    // Place black disc on board at coordinates d5
                    board[i][j].colour = BLACK;
                }

                else if(j == 4)
                {
                    // Place white disc on board at coordinates e5
                    board[i][j].colour = WHITE;
                }

                else
                {
                    // Empty for the remaining position
                    board[i][j].colour = EMPTY;
                }
            }

            else
            {
                // Empty for the remaining position
                board[i][j].colour = EMPTY;
            }
        }
    }
}

// Function to print the board and discs
void printBoard(disc board[][BOARD_SIZE], player p1, player p2)
{
    int z;

    // Print the score of each player
    printf("\n\tScore: %s (Black) %d:%d %s (White)", p1.name, p1.score, p2.score, p2.name);

    // Print the horizontal line for the board
    printf("\n\t   ");
    for(z = 1; z <= BOARD_SIZE; z++)
    {
        printf("--- ");
    }

    // Visualize the board by printing disc and vertical lines for board
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        // Row index from 1 to 8 on the left of board
        printf("\n\t%d |", i+1);

        // Print the words 'B' and 'W' to represent the disc on board
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            // If black disc is on the current square of board
            if (board[i][j].colour == BLACK)
            {
                printf(" B |");
            }
            // If white disc is on the current square on board
            else if (board[i][j].colour == WHITE)
            {
                printf(" W |");
            }
            // If no disc on the current square of board
            else
            {
                printf("   |");
            }
        }

        // Print the horizontal line for the board
        printf("\n\t   ");
        for(z = 1; z <= BOARD_SIZE; z++)
        {
            printf("--- ");
        }
    }

    // Column index from a to h on the bottom of board
    printf("\n\t    ");
    for (z = 1; z <= BOARD_SIZE; z++)
    {
        printf("%c   ", z - 1 + 'a');
    }
    printf("\n\n");

}

void gameRules()
{
    // Game rules for othello
    printf("Game Rules:\n"
           "1) Enter name for players 1 and 2.\n"
           "2) Black will always be the first player to move.\n"
           "3) Players take turn to enter their moves.\n"
           "4) A move can either be p (for \"Pass\") or in the format ld, where l is a letter (a to h), and d is a digit (1 to 8).\n"
           "5) Pass is only allowed when there is no valid move.\n"
           "6) Game ends when neither player can move.\n"
           "7) This occurs when there has no blank space left on the board or "
           "when neither player can legally place a disc in any of the remaining squares.\n"
           "8) The winner of the game is the player who has more discs on the board when the game ends.\n");
}