--------------------------------------------
   Program 2 Knight Escape
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
    
 ---------------------------------------------

#include iostream		 for input and output
#include cctype		    for toupper()
using namespace std;

 Global variables for the pieces are allowed for this program,
 but will generally not be allowed in the future.
 You will likely want to declare global variables at least for the 25 board positions.
 ...

 Characters of the pieces to be used on the board
 Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = u2658;		 White knight character
const string BlackKnight = u265E;		 Black knight character
const string BlankPosition =  ;			 Blank position character

--------------------------------------------------------------------------------
 Display welcome message, introducing the user to the program and
 describing the instructions for the game
void displayWelcomeMessage()
{
    cout  Program 2 Knight Escape n
          CS 141, Spring 2022, UIC n
           n
          The objective of this puzzle is to get the white knight 
		  up to the empty square in the top right corner of the board. 
		  Use standard knight moves from a traditional chess game, 
		  where a knight moves in an L-shape. n
		  This means that a knight can only move either 
		  1) two squares in a horizontal direction, then one in a vertical direction, OR 
		  2) two squares in a vertical direction, then one in a horizontal direction.
		   n
		  Your score decreases by 5 with each valid move, and by 10 with each invalid move. n
		  Try to complete the puzzle with the smallest number of valid moves!
    	  endl;
}end displayWelcomeMessage()

    
 ----------------------------------------------------------------------
 Display the current board, along with the corresponding positions
 This function makes use of global variables p1..p25, which represent
 each of the positions on the board

declare variables
string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25;
int score, startingPos, destinationPos, numOfMoves; 

displaying the knights on 5 by 5 board, as well as their associated numbers on the right
void displayBoard()
{	
    cout n
                                       Board                                         Position n
              p1      p2      p3      p4      p5       1  2  3  4  5 n
              p6      p7      p8      p9     p10       6  7  8  9 10 n
             p11     p12     p13     p14     p15      11 12 13 14 15 n
             p16     p17     p18     p19     p20      16 17 18 19 20 n
             p21     p22     p23     p24     p25      21 22 23 24 25 n
          endl;
} end displayBoard()

function resets values and positions of the game
void resetGame(){

	score = 500;
	startingPos = 0, destinationPos = 0;
	numOfMoves = 1; 
	
	p1 = BlackKnight, p2 = BlackKnight, p3 = BlackKnight, p4 = BlackKnight, 
		p6 = BlackKnight, p7 = BlackKnight, p8 = BlackKnight, p9 = BlackKnight, 
		p10 = BlackKnight, p11 = BlackKnight, p12 = BlackKnight, p13 = BlackKnight, p14 = BlackKnight, 
		p15 = BlackKnight, p16 = BlackKnight, p17 = BlackKnight, p18 = BlackKnight, p19 = BlackKnight, 
		p20 = BlackKnight, p22 = BlackKnight, p23 = BlackKnight, p24 = BlackKnight, p25 = BlackKnight;
	p5 = BlankPosition;
	p21 = WhiteKnight;
} end resetGame()

function take any position and returns knights or blank position at that spot
string getPos(int pos) {
  switch (pos) {
    case 1 return p1;
    case 2 return p2;
    case 3 return p3;
    case 4 return p4;
    case 5 return p5;
    case 6 return p6;
    case 7 return p7;
    case 8 return p8;
    case 9 return p9;
    case 10 return p10;
    case 11 return p11;
    case 12 return p12;
    case 13 return p13;
    case 14 return p14;
    case 15 return p15;
    case 16 return p16;
    case 17 return p17;
    case 18 return p18;
    case 19 return p19;
    case 20 return p20;
    case 21 return p21;
    case 22 return p22;
    case 23 return p23;
    case 24 return p24;
    case 25 return p25;
	default return 0;
  }
} end getPos()

function sets input position equal to the input value
void setPosVal(int pos, string value) {
  switch (pos) {
    case 1 p1 = value; break;
	case 2 p2 = value; break;
	case 3 p3 = value; break;
	case 4 p4 = value; break;
	case 5 p5 = value; break;
	case 6 p6 = value; break;
	case 7 p7 = value; break;
	case 8 p8 = value; break;
	case 9 p9 = value; break;
	case 10 p10 = value; break;
	case 11 p11 = value; break;
	case 12 p12 = value; break;
	case 13 p13 = value; break;
	case 14 p14 = value; break;
	case 15 p15 = value; break;
	case 16 p16 = value; break;
	case 17 p17 = value; break;
	case 18 p18 = value; break;
	case 19 p19 = value; break;
	case 20 p20 = value; break;
	case 21 p21 = value; break;
	case 22 p22 = value; break;
	case 23 p23 = value; break;
	case 24 p24 = value; break;
	case 25 p25 = value; break;
    
  }
} end setPosVal()

function take inputs of starting position and destination position, returning true if they forms and L-shape
bool checkShapeL(int startingPos, int destinationPos){
	switch (startingPos) {
    case 1 return (destinationPos == 8  destinationPos == 12);
    case 2 return (destinationPos == 11  destinationPos == 13  destinationPos == 9);
    case 3 return (destinationPos == 12  destinationPos == 14  destinationPos == 10  destinationPos == 6);
    case 4 return (destinationPos == 7  destinationPos == 13  destinationPos == 15);
    case 5 return (destinationPos == 8  destinationPos == 14);
    case 6 return (destinationPos == 17  destinationPos == 13  destinationPos == 3);
    case 7 return (destinationPos == 16  destinationPos == 18  destinationPos == 4  destinationPos == 14);
    case 8 return (destinationPos == 1  destinationPos == 5  destinationPos == 11  destinationPos == 15  destinationPos == 17  destinationPos == 19);
    case 9 return (destinationPos == 18  destinationPos == 20  destinationPos == 12  destinationPos == 2);
    case 10 return (destinationPos == 3  destinationPos == 13  destinationPos == 19);
    case 11 return (destinationPos == 2  destinationPos == 22  destinationPos== 8  destinationPos == 18);
    case 12 return (destinationPos == 1  destinationPos == 3  destinationPos == 21  destinationPos == 23  destinationPos == 9  destinationPos == 19);
    case 13 return (destinationPos == 2  destinationPos == 4  destinationPos == 6  destinationPos == 16  destinationPos == 22  destinationPos == 24  destinationPos == 10  destinationPos == 20);
    case 14 return (destinationPos == 3  destinationPos == 5  destinationPos == 23  destinationPos == 25  destinationPos == 7  destinationPos == 17);
    case 15 return (destinationPos == 4  destinationPos == 24  destinationPos == 8  destinationPos == 18);
    case 16 return (destinationPos == 7  destinationPos == 13  destinationPos == 23);
    case 17 return (destinationPos == 8  destinationPos == 6  destinationPos == 24  destinationPos == 14);
    case 18 return (destinationPos == 9  destinationPos == 7  destinationPos == 15  destinationPos == 25  destinationPos == 11  destinationPos == 21);
    case 19 return (destinationPos == 8  destinationPos == 10  destinationPos == 12  destinationPos == 22);
    case 20 return (destinationPos == 9  destinationPos == 13  destinationPos == 23);
    case 21 return (destinationPos == 12  destinationPos == 18);
    case 22 return (destinationPos == 19  destinationPos == 11  destinationPos == 13);
    case 23 return (destinationPos == 20  destinationPos == 16  destinationPos == 12  destinationPos == 14);
    case 24 return (destinationPos == 15  destinationPos == 17  destinationPos == 13);
    case 25 return (destinationPos == 18  destinationPos == 14);
	default return 0;
  }
} end checkShapeL()


 ----------------------------------------------------------------------
 Main() function of the program, containing the loop that controls
 game play
int main() {

   	displayWelcomeMessage();
	
	 Set board values to the default starting position
   	 ...
	resetGame();

	display the board
   	displayBoard();

	display the score
	cout  Current score   score  endl;
   	
   	 Loop that controls game play and loops until player's score reaches 0
   	while(score  0) {
		
		output menu options and associated number of moves
      	cout  numOfMoves  . 
              Enter one of the following n
			    - M to move a knight from one position to another, n
			    - R to reset the board back to the beginning, or n
			    - X to exit the game. n
			  Your choice - ;

		innitializing and taking the input
		char menuOption;
		cin  menuOption;
		menuOption = toupper(menuOption);  convert user input to uppercase
		
		 If the user entered 'X' to exit,
		 break out of this loop that controls game play
		 ...
		if (menuOption == 'X'){
			cout  Exiting...  endl;
			break;
		} end if-statement
		
		 If the user entered 'R' to reset,
		 reset the board back to the beginning
		 ...
		else if (menuOption == 'R'){
			cout      Restarting  endl;
			resetGame();
			displayBoard();
			cout  Current score   score  endl;
			continue;
		} end else if-statement

		 If the user entered 'M' to move a knight,
		 ask for the position of the knight to be moved
		 ...
		else if (menuOption == 'M'){
			cout  Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5) ;
			cin  startingPos  destinationPos;
			cout  You have chosen to move a knight from position   startingPos   to position   destinationPos  .  endl;
		} end else if-statement
		
		 Check that FROM position is valid, i.e. within 1-25. Subtract 10 from score and outprint the erros, as well as score
		if (startingPos  25  startingPos  1){
			score -= 10;
			cout  The source position should be a valid position on the board (1-25). Try again.  endl;
			cout  Current score   score  endl;
			continue;
		} end if-statement
		
		 Check that TO position is valid, i.e. within 1-25. Subtract 10 from score and outprint the erros, as well as score
		
		if (destinationPos  25  destinationPos  1){
			score -= 10;
			cout  The destination position should be a valid position on the board (1-25). Try again.   endl;
			cout  Current score   score  endl;
			continue;
		} end if-statement

		 Check that the source position has a knight. Subtract 10 from score and outprint the erros, as well as score
		if(!(getPos(startingPos) == BlackKnight  getPos(startingPos) == WhiteKnight) ) {
			score -= 10;
			cout  The source position should have a knight. Try again.   endl;
			cout  Current score   score  endl;
			continue;
		} end if-statement
		
		 Check that the destination position is empty. Subtract 10 from score and outprint the erros, as well as score
		if(!(getPos(destinationPos) ==  BlankPosition)) {
			score -= 10;
			cout  The destination position should be empty. Try again.   endl;
			cout  Current score   score  endl;
			continue;
		} end if-statement

		 Check that the move is valid - knights can only move in an L-shape. Subtract 10 from score and outprint the erros, as well as score
		if (!checkShapeL(startingPos,destinationPos)){
			score -= 10;
			cout  Invalid move. Knights can only move in an L-shape. Try again.  endl;
			cout  Current score   score  endl;
			continue;
		} end if-statement

		 Make the move and update the board
		check if at at the starting position is black knight and move it. Subtract 5 points and increment number of moves
		if(getPos(startingPos) == BlackKnight) {
			setPosVal(destinationPos, BlackKnight);
			setPosVal(startingPos, BlankPosition);
			score -= 5;
			numOfMoves++;
		}end if-statement

		check if at at the starting position is white knight and move it. Subtract 5 points and increment number of moves
		else if(getPos(startingPos) == WhiteKnight){
			setPosVal(destinationPos, WhiteKnight);
			setPosVal(startingPos, BlankPosition);
			score -= 5;
			numOfMoves++;

			check if player won and break out of loop
			if (p5 == WhiteKnight) {
				displayBoard();
	   			cout  endl   Congratulations, you did it!  endl;
				break;			
  			} end inner if-statement
		} end outter else if-statement

		show the board and score
		displayBoard();
		cout  Current score   score  endl;
		cout  endl;

   }  end loop for game play
   
    check the score is 0, output loosing message
	if (score = 0){
	   cout  endl  You have run out of moves. Try to do better next time!  endl;
   	} end if-statement

	thank user after the game ends
	cout  Thank you for playing!  endl;

	return 0;
}
