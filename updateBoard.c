#include "initialization.h"
#include "updateBoard.h"

// Function to update the board and score after each turn
// Integer row hold the value of the row of current player's move
// Integer column hold the value of the column of current player's move
void mainUpdate(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // Check the direction of opponent's disc that is around current player's new disc
    // i is the index for row to check if opponent's disc is around current player's new disc
    // So the range of i is from row-1 to row+1
    for(int i = row - 1; i <= row + 1; i++)
    {
        // j is the index for column to check if opponent's disc is around current player's disc
        // So the range of j is from column-1 to column+1
        for(int j = column - 1; j <= column + 1; j++)
        {
            // If opponent's disc is around current player's new disc
            // Check the specific direction of the disc and update the board by flipping opponent's disc
            if(board[i][j].colour == opponent->colour)
            {
                if(i == row - 1) // If opponent's disc is above the current player's new disc
                {
                    // There are 3 directions on above which are north-west, north, north-east
                    if(j == column - 1) // If opponent's disc is on upper left of current player's new disc
                    {
                        // Check the north-west direction
                        updateNorthWest(board, current, opponent, row, column);
                    }
                    else if(j == column) // If opponent's disc is right above of current player's new disc
                    {
                        // Check the north direction
                        updateNorth(board, current, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on upper right of current player's new disc
                    {
                        // Check the north-east direction
                        updateNorthEast(board, current, opponent, row, column);
                    }
                }
                else if(i == row) // If opponent's disc is on the same row with current player's new disc
                {
                    // There are 2 directions which are west and east
                    if(j == column - 1) // If opponent's disc is on the left of current player's new disc
                    {
                        // Check the west direction
                        updateWest(board, current, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on the right of current player's new disc
                    {
                        // Check the east direction
                        updateEast(board, current, opponent, row, column);
                    }
                }
                else if(i == row + 1) // If opponent's disc is below the current player's new disc
                {
                    // There are 3 directions on below which are south-west, south, south-east
                    if(j == column - 1) // If opponent's disc is on bottom left of current player's new disc
                    {
                        // Check the south-west direction
                        updateSouthWest(board, current, opponent, row, column);
                    }
                    else if(j == column) // If opponent's disc is right below of current player's new disc
                    {
                        // Check the south direction
                        updateSouth(board, current, opponent, row, column);
                    }
                    else if(j == column + 1) // If opponent's disc is on bottom right of current player's new disc
                    {
                        // Check the south-east direction
                        updateSouthEast(board, current, opponent, row, column);
                    }
                }
            }
        }
    }
}

// Function to update move at north-west direction
void updateNorthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column - 2; i >= 0 && j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            // Move towards upper left by decrementing both values of i and j
            i--;
            j--;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i + 1, y = j + 1; x < row && y < column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to north-west (south-east) to check if there are more opponent's disc
                    x++;
                    y++;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
                }
            }
            break; // Exit from loop
        }
        else // If the current square is empty
        {
            break;
        }
    }
}

// Function to update move at north direction
void updateNorth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column; i >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            i--;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i + 1, y = j; x < row; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to north (south) to check if there are more opponent's disc
                    x++;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at north-east direction
void updateNorthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row - 2, j = column + 2; i >= 0 && j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            i--;
            j++;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i + 1, y = j - 1; x < row && y > column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to north-east (south-west) to check if there are more opponent's disc
                    x++;
                    y--;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at west direction
void updateWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row, j = column - 2; j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            j--;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i, y = j + 1; y < column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to west (east) to check if there are more opponent's disc
                    y++;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at east direction
void updateEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row, j = column + 2; j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            j++;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i, y = j - 1; y > column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to east (west) to check if there are more opponent's disc
                    y--;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at south-west direction
void updateSouthWest(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column - 2; i < BOARD_SIZE && j >= 0; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            i++;
            j--;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i - 1, y = j + 1; x > row && y < column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to south-west (north-east) to check if there are more opponent's disc
                    x--;
                    y++;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at south direction
void updateSouth(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column; i < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            i++;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i - 1, y = j; x > row; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to south (north) to check if there are more opponent's disc
                    x--;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

// Function to update move at south-east direction
void updateSouthEast(disc board[][BOARD_SIZE], player *current, player *opponent, int row, int column)
{
    // i is the index for row and j is the index for column
    // Begin to check at the position which assumed that there is only 1 opponent's disc
    for(int i = row + 2, j = column + 2; i < BOARD_SIZE && j < BOARD_SIZE; )
    {
        // If there is more than 1 opponent's disc at current direction
        // Current square is occupied by opponent's disc
        if(board[i][j].colour == opponent->colour)
        {
            i++;
            j++;
        }
        else if(board[i][j].colour == current->colour) // If current square is occupied by current player's disc
        {
            // Flip opponent's disc
            // x is the index for row and y is the index for column
            for(int x = i - 1, y = j - 1; x > row && y > column; )
            {
                if(board[x][y].colour == opponent->colour) // If current square is occupied by opponent's disc
                {
                    board[x][y].colour = current->colour; // Flip the colour of disc to current player's colour
                    // Move in opposite direction to south-east (north-west) to check if there are more opponent's disc
                    x--;
                    y--;
                    current->score += 1; // Increment score of current player by 1
                    opponent->score -= 1; // Decrement score of opponent by 1
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

