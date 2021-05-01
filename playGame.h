#ifndef ASSIGNMENT2_PLAYGAME_H
#define ASSIGNMENT2_PLAYGAME_H

void takeTurn(disc board[][BOARD_SIZE], player *p1, player *p2);
void getMove(disc board[][BOARD_SIZE], player *current, player *opponent, int num, int *pass);
void printList(possibleMovePtr cPtr);
int isEmpty(possibleMovePtr sPtr);
void delete(possibleMovePtr *cPtr);
int findInList(possibleMovePtr *sPtr, int r, int c);
void placeMove(disc board[][BOARD_SIZE], player *current, player *opponent, const char move[], int r, int c, int *pass, int num, possibleMovePtr *sPtr);

#endif //ASSIGNMENT2_PLAYGAME_H
