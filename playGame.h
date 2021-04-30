#ifndef ASSIGNMENT2_PLAYGAME_H
#define ASSIGNMENT2_PLAYGAME_H

void takeTurn(disc board[][BOARD_SIZE], player *p1, player *p2);
void getMove(disc board[][BOARD_SIZE], player *current, player *opponent, int num, int *pass);

#endif //ASSIGNMENT2_PLAYGAME_H
