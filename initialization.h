#ifndef ASSIGNMENT2_INITIALIZATION_H
#define ASSIGNMENT2_INITIALIZATION_H

#define BOARD_SIZE 8
#define NAME_LENGTH 20

// Enum to hold the colour of disc
enum discColour
{
    BLACK,
    WHITE,
    EMPTY
};

// Structure to hold the name, disc colour and score of player
typedef struct player
{
    char name[NAME_LENGTH];
    enum discColour colour;
    int score;
}player;

// Structure to hold the colour of disc on board
typedef struct disc
{
    enum discColour colour;
}disc;

// Linked list to store the possible move of player on each turn
struct PossibleMove
{
    int row;
    int col;
    struct PossibleMove *nextPtr;
};

typedef struct PossibleMove possibleMove;
typedef possibleMove *possibleMovePtr;

void mainInitialize(disc board[][BOARD_SIZE], player *p1, player *p2);
void initializePlayer(player *p1, player *p2);
void initializeBoard(disc board[][BOARD_SIZE]);
void printBoard(disc board[][BOARD_SIZE], player p1, player p2);
void convertNewLine(char str[]);
void gameRules();

#endif //ASSIGNMENT2_INITIALIZATION_H
