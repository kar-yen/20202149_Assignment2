#ifndef ASSIGNMENT2_UPDATEBOARD_H
#define ASSIGNMENT2_UPDATEBOARD_H

void mainUpdate(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateNorthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateNorth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateNorthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);


#endif //ASSIGNMENT2_UPDATEBOARD_H
