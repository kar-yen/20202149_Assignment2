#ifndef ASSIGNMENT2_GETPOSSIBLEMOVE_H
#define ASSIGNMENT2_GETPOSSIBLEMOVE_H

void findMove(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findNorthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findNorth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findNorthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouthWest(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouth(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);
void findSouthEast(disc board[][BOARD_SIZE], possibleMovePtr *sPtr, player opponent, int row, int column);

#endif //ASSIGNMENT2_GETPOSSIBLEMOVE_H
