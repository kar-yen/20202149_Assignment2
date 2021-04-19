#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialization.h"

void convertNewLine(char str[]);
void gameRules();

void initializePlayer(player *p1, player *p2)
{
    char choice;
    printf("\t***   Welcome to Othello!   ***\n\n");

    printf("Enter 1 if you wish to read the rules before game start. Otherwise, any other keys to start game.\n");
    scanf("%c", &choice);
    fflush(stdin);

    if(choice == '1')
    {
        gameRules();
    }

    printf("\nGame starts!\n");
    printf("Please enter name of Player 1 (Black):");
    fgets(p1->name, NAME_LENGTH, stdin);
    p1->colour = BLACK;
    p1->score = 2;

    fflush(stdin);

    printf("Please enter name of Player 2 (White):");
    fgets(p2->name, NAME_LENGTH, stdin);
    p2->colour = WHITE;
    p2->score = 2;

    fflush(stdin);

    convertNewLine(p1->name);
    convertNewLine(p2->name);
}

void convertNewLine(char str[])
{
    if(str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
}

void initializeBoard(disc board[][BOARD_SIZE])
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(i == 3)
            {
                if(j == 3)
                {
                    board[i][j].colour = WHITE;
                }

                else if(j == 4)
                {
                    board[i][j].colour = BLACK;
                }

                else
                {
                    board[i][j].colour = EMPTY;
                }
            }

            else if (i == 4)
            {
                if(j == 3)
                {
                    board[i][j].colour = BLACK;
                }

                else if(j == 4)
                {
                    board[i][j].colour = WHITE;
                }

                else
                {
                    board[i][j].colour = EMPTY;
                }
            }

            else
            {
                board[i][j].colour = EMPTY;
            }

            board[i][j].row = i;
            board[i][j].col = j;
        }
    }
}

void printBoard(disc board[][BOARD_SIZE], player p1, player p2)
{
    int z;
    printf("\n\tScore: %s (Black) %d:%d %s (White)", p1.name, p1.score, p2.score, p2.name);

    // column header at the top.
    printf("\n\t   "); // 4 spaces.
    for(z = 1; z <= BOARD_SIZE; z++)
    {
        //printf("%c   ", z-1+'a');
        printf("--- ");
    }

    // rows header + data.
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        // left row header.
        printf("\n\t%d |", i+1);

        // row data.
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].colour == BLACK)
            {
                printf(" B |");
            }
            else if (board[i][j].colour == WHITE)
            {
                printf(" W |");
            }
            else
            {
                printf("   |");
            }
        }

        // right row header.
        //printf(" %d", r+1);
        printf("\n\t   "); // 4 spaces.
        for(z = 1; z <= BOARD_SIZE; z++)
        {
            printf("--- ");
        }
    }

    // column footer.
    printf("\n\t    "); // 4 spaces.
    for (z = 1; z <= BOARD_SIZE; z++)
    {
        printf("%c   ", z - 1 + 'a');
    }
    printf("\n\n");

}

void gameRules()
{
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