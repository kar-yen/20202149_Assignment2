#include <stdio.h>
#include "initialization.h"
#include "updateBoard.h"

void updateNorthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateNorth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateNorthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);
void updateSouthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column);


void mainUpdate(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row - 1; i <= row + 1; i++)
    {
        for(int j = column - 1; j <= column + 1; j++)
        {
            if(board[i][j].colour == opponent->colour)
            {
                if(i == row - 1)
                {
                    if(j == column - 1)
                    {
                        updateNorthWest(board, current, opponent, row, column);
                    }
                    else if(j == column)
                    {
                        updateNorth(board, current, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        updateNorthEast(board, current, opponent, row, column);
                    }
                }
                else if(i == row)
                {
                    if(j == column - 1)
                    {
                        updateWest(board, current, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        updateEast(board, current, opponent, row, column);
                    }
                }
                else if(i == row + 1)
                {
                    if(j == column - 1)
                    {
                        updateSouthWest(board, current, opponent, row, column);
                    }
                    else if(j == column)
                    {
                        updateSouth(board, current, opponent, row, column);
                    }
                    else if(j == column + 1)
                    {
                        updateSouthEast(board, current, opponent, row, column);
                    }
                }
            }
        }
    }
}

void updateNorthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row - 2, j = column - 2; i >= 0 && j >= 0; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i--;
            j--;
        }
        else if(board[i][j].colour == current->colour)
        {
            //printf("nw %d %d\n", i, j);
            for(int x = i + 1, y = j + 1; x < row && y < column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x++;
                    y++;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateNorth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row - 2, j = column; i >= 0; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i--;
        }
        else if(board[i][j].colour == current->colour)
        {
            //printf("nw %d %d\n", i, j);
            for(int x = i + 1, y = j; x < row; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x++;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateNorthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row - 2, j = column + 2; i >= 0 && j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i--;
            j++;
        }
        else if(board[i][j].colour == current->colour)
        {
            //printf("nw %d %d\n", i, j);
            for(int x = i + 1, y = j - 1; x < row && y > column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x++;
                    y--;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row, j = column - 2; j >= 0; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            j--;
        }
        else if(board[i][j].colour == current->colour)
        {
            for(int x = i, y = j + 1; y < column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    y++;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row, j = column + 2; j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            j++;
        }
        else if(board[i][j].colour == current->colour)
        {
            for(int x = i, y = j - 1; y > column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    y--;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateSouthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row + 2, j = column - 2; i < BOARD_SIZE && j >= 0; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i++;
            j--;
        }
        else if(board[i][j].colour == current->colour)
        {
            for(int x = i - 1, y = j + 1; x > row && y < column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x--;
                    y++;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateSouth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row + 2, j = column; i < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i++;
        }
        else if(board[i][j].colour == current->colour)
        {
            for(int x = i - 1, y = j; x > row; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x--;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

void updateSouthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    for(int i = row + 2, j = column + 2; i < BOARD_SIZE && j < BOARD_SIZE; )
    {
        if(board[i][j].colour == opponent->colour)
        {
            i++;
            j++;
        }
        else if(board[i][j].colour == current->colour)
        {
            for(int x = i - 1, y = j - 1; x > row && y > column; )
            {
                if(board[x][y].colour == opponent->colour)
                {
                    board[x][y].colour = current->colour;
                    x--;
                    y--;
                    current->score += 1;
                    opponent->score -= 1;
                }
            }
            break;
        }
        else
        {
            break;
        }
    }
}

