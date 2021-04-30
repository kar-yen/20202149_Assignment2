#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "playGame.h"
#include "getPossibleMove.h"
#include "updateBoard.h"

int isEmpty(possibleMovePtr sPtr);
void delete(possibleMovePtr *cPtr);
void printList(possibleMovePtr cPtr);
int findInList(possibleMovePtr *sPtr, int r, int c);

void takeTurn(disc board[][BOARD_SIZE], player *p1, player *p2)
{
    int turn = 1;
    int pass = 0;
    // Calculate space left on board
    int spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);

    // Game continue while there is space left on the board
    // Exit from loop if both players pass the game consecutively
    while(spaceLeft && pass != 2)
    {
        if(turn % 2 != 0) // Player 1's turn if odd number
        {
            printf("Round %d.\nPlayer 1's turn.\n", turn);
            getMove(board, p1, p2, 1, &pass);
            printBoard(board, *p1, *p2);

            turn++; // Increment turn
        }
        else if(turn % 2 == 0) // Player 2's turn if even number
        {
            printf("Round %d.\nPlayer 2's turn.\n", turn);
            getMove(board, p2, p1, 2, &pass);
            printBoard(board, *p1, *p2);

            turn++;
        }

        // Update space left on board after each turn
        spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);
        printf("\n\n%d %d\n\n", spaceLeft, pass);
    }
}

void getMove(disc board[][BOARD_SIZE], player *current, player *opponent, int num, int *pass)
{
    char move[3];
    possibleMovePtr startPtr = NULL;

    printf("A move should be enter in the form of 'ld' where l is letter and d is digit. (E.g. a3)\n"
           "Enter your move: ");
    scanf("%s", move);
    fflush(stdin);
    //printf("%s\n", move);
    int r = move[1] - '1';
    int c = move[0] - 'a';

    printf("%c %c\n", move[0], move[1]);
    printf("%d %d\n", r, c);

    /*if((move[0] != 'p') && ((move[0] < 'a' || move[0] > 'h') || (move[1] < '1' || move[1] > '8')))
    {
        printf("Invalid move.\n");
        do {
            printf("aEnter your move again:");
            scanf("%s", move);
            fflush(stdin);
        } while ((move[0] != 'p') && ((move[0] < 'a' || move[0] > 'h') || (move[1] < '1' || move[1] > '8')));
        r = move[1] - '1';
        c = move[0] - 'a';
    }

    if(board[r][c].colour != EMPTY && move[0] != 'p')
    {
        printf("Invalid move.\n");
        do {
            printf("bEnter your move again:");
            scanf("%s", move);
            fflush(stdin);
            r = move[1] - '1';
            c = move[0] - 'a';
        } while (board[r][c].colour != EMPTY && move[0] != 'p');

        //getMove(board, current, opponent, num);
    }*/

    // Check all the possible move of current player and store in a 2d array
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].colour == current->colour)
            {
                findMove(board, &startPtr, *opponent, i, j);
            }
        }
    }

    printList(startPtr);

    if(isEmpty(startPtr))
    {
        if(move[0] != 'p')
        {
            printf("Invalid move.\n");
            do {
                printf("cEnter your move again:");
                scanf("%s", move);
                fflush(stdin);
                //r = move[1] - '1';
                //c = move[0] - 'a';
            } while (move[0] != 'p');
        }
    }
    else
    {
        if(!(findInList(&startPtr, r, c)) || move[0] == 'p')
        {
            printf("Invalid move.\n");
            do {
                printf("dEnter your move again:");
                scanf("%s", move);
                fflush(stdin);
                r = move[1] - '1';
                c = move[0] - 'a';
            } while (!(findInList(&startPtr, r, c)) || !(isEmpty(startPtr)) && move[0] == 'p');
            //getMove(board, current, opponent, num);
        }
    }

    /*if(!(isEmpty(startPtr)) && move[0] == 'p')
    {
        printf("Invalid move.\n");
        do {
            printf("dEnter your move again:");
            scanf("%s", move);
            fflush(stdin);
            r = move[1] - '1';
            c = move[0] - 'a';
        } while (!(isEmpty(startPtr)) && move[0] == 'p');
        //getMove(board, current, opponent, num);
    }*/

    if(move[0] != 'p' && board[r][c].colour == EMPTY)
    {
        board[r][c].colour = current->colour;
        current->score += 1;

        mainUpdate(board, current, opponent, r, c);
        *pass = 0;
        while(!(isEmpty(startPtr)))
        {
            delete(&startPtr);
        }
    }
    else if(move[0] == 'p')
    {
        printf("There is no valid move. Player %d pass.", num);
        *pass += 1;
    }
    else
    {
        printf("Error, invalid move.\n");
    }

    // Check if user input is a valid move by comparing with the array that store all possible moves.
    // Prompt user to enter another move if it is not valid
    // If loop when there is no possible move
}

void printList(possibleMovePtr cPtr)
{
    if(cPtr == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Possible move:\n");
        while(cPtr != NULL)
        {
            printf("%d %d\n", cPtr->row, cPtr->col);
            cPtr = cPtr->nextPtr;
        }
    }
}

int isEmpty(possibleMovePtr sPtr)
{
    // Return 1 if the list is empty, 0 otherwise
    return sPtr == NULL;
}

void delete(possibleMovePtr *cPtr)
{
    possibleMovePtr tempPtr = *cPtr;
    *cPtr = (*cPtr)->nextPtr;
    free(tempPtr);
}

int findInList(possibleMovePtr *sPtr, int r, int c)
{
    if(r == (*sPtr)->row && c == (*sPtr)->col)
    {
        //printf("m %d %d %d %d\n", r, c, (*sPtr)->row, (*sPtr)->col);
        return 1;
    }
    else
    {
        possibleMovePtr prePtr = *sPtr;
        possibleMovePtr cPtr = (*sPtr)->nextPtr;

        while (cPtr != NULL && (cPtr->row != r || cPtr->col != c))
        {
            prePtr = cPtr;
            cPtr = cPtr->nextPtr;
        }

        if(cPtr != NULL)
        {
            //printf("pre %d %d\n", prePtr->row, prePtr->col);
            //printf("n %d %d %d %d\n", r, c, cPtr->row, cPtr->col);
            return 1;
        }
    }

    return 0;
}
