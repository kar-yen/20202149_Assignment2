#ifndef ASSIGNMENT2_ENDGAME_H
#define ASSIGNMENT2_ENDGAME_H
#include <stdio.h>

void mainEnd(disc board[][BOARD_SIZE], player p1, player p2, time_t t1, time_t t2);
void createFile(disc board[][BOARD_SIZE], player p1, player p2, time_t t1, time_t t2, int min, int sec);
void boardFile(disc board[][BOARD_SIZE], FILE *fp);

#endif //ASSIGNMENT2_ENDGAME_H
