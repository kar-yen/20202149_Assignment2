# Othello

Othello is a board game that is played on a board with 64 squares in an 8x8 arrangement using 64 black and white discs, black on one side, 
white on the other. Players are assigned black or white and take turns to place a disc with their assigned colour facing up. 
After each play, any discs with the opponent's colour displayed that are in a straight line bounded by the disc just placed and another
disc displaying the current player's colour are turned over to display the current player's colour. The winner of the game is the player 
who has the majority of discs turned to display their colour when the last move is made.

## 1 &nbsp;Game Start
### 1.1 &nbsp;Initialization of game
* Game rules can be shown before starting a game.
&nbsp;

![Alt text](./assignment2_img/GameRule.PNG "Game Rules")
* Both players are asked to input their name.
* The initial board is displayed with two black discs and two white discs on it.
&nbsp;

![Alt text](./assignment2_img/Initial.PNG "Starting position of a game")
&nbsp;

&nbsp;

### 1.2 &nbsp;Take turn of game
* Player with black disc will has the first move.
&nbsp;

![Alt text](./assignment2_img/Turn1.PNG "Player 1(BLACK)'s move")
* Players take alternative turn until the game ends.
&nbsp;

![Alt text](./assignment2_img/Turn2.PNG "Player 2(WHITE)'s move")
* Players have to enter their move in the specific format 'ld' where l is a letter in range **a** to **h** and d is a digit in range **1** to **8**. 
* Players are allowed to pass only when there is no valid move.
* Place the disc on board and display the updated score and board 
&nbsp;

&nbsp;

## 2 &nbsp;Game End
### 2.1 &nbsp;End of game
* The game ends when:
&nbsp;

 &nbsp; &nbsp; &nbsp; &nbsp; a) There is no space left on board (all 64 discs have been placed) 
&nbsp;

![Alt text](./assignment2_img/Final1.PNG "Full Board")
&nbsp;

 &nbsp; &nbsp; &nbsp; &nbsp; b) Neither player can legally place a disc in any of the remaining squares.
&nbsp;

![Alt text](./assignment2_img/Final2.PNG "No Move")
* The name and score of the winner will be displayed along with the final board.
* The final result will be save in a text file named 'othello-results.txt' before the program exits.
* The text file can be found in current directory.
* Example of text file:
&nbsp;

a) 
