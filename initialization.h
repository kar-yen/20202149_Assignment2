#ifndef ASSIGNMENT2_INITIALIZATION_H
#define ASSIGNMENT2_INITIALIZATION_H

#define BOARD_SIZE 8
#define NAME_LENGTH 20

enum discColour
{
    BLACK,
    WHITE,
    EMPTY
};

typedef struct player
{
    char name[NAME_LENGTH];
    enum discColour colour;
    int score;
}player;

typedef struct disc
{
    enum discColour colour;
    int row;
    int col;
}disc;

void initializePlayer(player *p1, player *p2);
void initializeBoard(disc board[][BOARD_SIZE]);
void printBoard(disc board[][BOARD_SIZE], player p1, player p2);

#endif //ASSIGNMENT2_INITIALIZATION_H
