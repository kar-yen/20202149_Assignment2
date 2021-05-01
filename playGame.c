#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "playGame.h"
#include "getPossibleMove.h"
#include "updateBoard.h"

// Function to handle the game between two players
void takeTurn(disc board[][BOARD_SIZE], player *p1, player *p2)
{
    int turn = 1; // Variable to hold the number of game turn
    int pass = 0; // Variable to calculate number of pass of players

    // Calculate space left on board
    int spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);

    // Game continue while there is space left on the board
    // Exit from loop if both players pass the game consecutively
    while(spaceLeft && pass != 2)
    {
        if(turn % 2 != 0) // Player 1's turn if odd number
        {
            // Print turn to remind player 1.
            printf("Round %d.\nPlayer 1's turn.\n", turn);
            getMove(board, p1, p2, 1, &pass); // Obtain move from player 1
            printBoard(board, *p1, *p2); // Update and print board after a valid move

            turn++; // Increment of turn
        }
        else if(turn % 2 == 0) // Player 2's turn if even number
        {
            // Print turn to remind player 2
            printf("Round %d.\nPlayer 2's turn.\n", turn);
            getMove(board, p2, p1, 2, &pass); // Obtain move from player 2
            printBoard(board, *p1, *p2); // Update and print board after a valid move

            turn++; // Increment of turn
        }

        // Update space left on board after each turn
        spaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->score + p2->score);
    }
}

// Function to obtain and check the move enter by user
void getMove(disc board[][BOARD_SIZE], player *current, player *opponent, int num, int *pass)
{
    char move[3]; // Char array to store the coordinates enter by user
    possibleMovePtr startPtr = NULL; // Initially there is no node in the list

    // Prompt user to enter move in specific format
    printf("A move should be enter in the form of 'ld' where l is letter and d is digit. (E.g. a1)\n"
           "Enter your move:");
    scanf("%s", move); // Get user input
    fflush(stdin);

    // Convert move into integer
    int r = move[1] - '1'; // Variable r represents row
    int c = move[0] - 'a'; // Variable c represents column

    // Check all the possible move of current player and store in the linked list
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

    //printList(startPtr);

    // Check if the move enter by user is valid
    if(isEmpty(startPtr)) // If there is no possible move for current player
    {
        if(move[0] != 'p') // User does not pass the game
        {
            // Ask user to re-enter the move
            do {
                printf("Invalid move.\n");
                printf("Enter your move again:");
                scanf("%s", move);
                fflush(stdin);

                r = move[1] - '1';
                c = move[0] - 'a';
            } while (move[0] != 'p'); // Repeat prompting if user does not pass the game
        }
    }
    else // If there are possible moves for current player
    {
        // If user want to pass the game or entered an invalid move
        if(!(findInList(&startPtr, r, c)) || move[0] == 'p')
        {
            // Ask user to re-enter the move
            do {
                printf("Invalid move.\n");
                printf("Enter your move again:");
                scanf("%s", move);
                fflush(stdin);

                r = move[1] - '1';
                c = move[0] - 'a';
            } while (!(findInList(&startPtr, r, c)) || !(isEmpty(startPtr)) && move[0] == 'p');
            // Repeat prompting if user does not enter a valid move
        }
    }

    // Place the move of player if a valid move is entered
    placeMove(board, current, opponent, move, r, c, pass, num, &startPtr);
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

// Function to check if the linked list is empty
int isEmpty(possibleMovePtr sPtr)
{
    // Return 1 if the list is empty, 0 otherwise
    return sPtr == NULL;
}

// Function to dequeue the node in the linked list
void delete(possibleMovePtr *cPtr)
{
    possibleMovePtr tempPtr = *cPtr;
    *cPtr = (*cPtr)->nextPtr;
    free(tempPtr); // Free current node in the list
}

// Function to find if the coordinates (r, c) enter by user is in the linked list of possible moves
// Return 1 if coordinate is found in the list, 0 otherwise
// sPtr = start pointer
int findInList(possibleMovePtr *sPtr, int r, int c)
{
    // If the coordinate is found on the first node
    if(r == (*sPtr)->row && c == (*sPtr)->col)
    {
        return 1;
    }
    else // If the coordinate is not found on the first node
    {
        // prePtr = previous pointer, cPtr = current pointer
        possibleMovePtr prePtr = *sPtr; // Pointer to previous node in the list
        possibleMovePtr cPtr = (*sPtr)->nextPtr; // Pointer to current node in the list

        // Traverse the list to find the coordinate before reaching the end of list
        while (cPtr != NULL && (cPtr->row != r || cPtr->col != c))
        {
            // Go to next node if current node is different with the coordinate
            prePtr = cPtr;
            cPtr = cPtr->nextPtr;
        }

        if(cPtr != NULL) // If the coordinate is found in the list
        {
            return 1;
        }
    }

    return 0;
}

// Function to handle place the move of player
void placeMove(disc board[][BOARD_SIZE], player *current, player *opponent, const char move[], int r, int c, int *pass, int num, possibleMovePtr *sPtr)
{
    // If player does not pass the turn and the square has no disc on board
    if(move[0] != 'p' && board[r][c].colour == EMPTY)
    {
        board[r][c].colour = current->colour; // Place the disc of current player on the square of board
        current->score += 1; // Increment the score of player by 1

        mainUpdate(board, current, opponent, r, c); // Update the score and board of current player after flipping opponent's disc
        *pass = 0; // Reset the number of pass
        while(!(isEmpty(*sPtr))) // If the linked list is not empty
        {
            // Free all the nodes in the list
            delete(sPtr);
        }
    }
    else if(move[0] == 'p') // If player pass the turn
    {
        // Print the message to the console
        printf("There is no valid move. Player %d pass.\n", num);
        *pass += 1; // Increment pass by 1
    }
    else // Simple error handling
    {
        printf("Error. Invalid move.\n");
    }
}