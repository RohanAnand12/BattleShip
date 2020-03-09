

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Board.h"
#include "Stats.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

template<typename Base, typename T>
inline bool instanceof(const T) {
	return is_base_of<Base, T>::value;
}

Board::Board() {
	symbol = '~';
	position.row = 0;
	position.column = 0;
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

/**
 * Function name : initializeGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : initializeGameBoard ();
 * Definition    : This function displays initializes values of the multi-
 *                 dimensional array called gameBoard.
 * Pre-condition : ROWS & COLS are defined as constant macros
 * Post-condition: Array initialize to (~) tilde representing water
 */
void Board::initializeGameBoard (Board gameBoard[][10])
{
	int i = 0, j = 0;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			gameBoard[i][j].symbol          = '~';
			gameBoard[i][j].position.row    = i;
			gameBoard[i][j].position.column = j;
		}
}

/**
 * Function name : printGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : printGameBoard (Cell [][], Boolean);
 * Definition    : This function prints the game board on the console
 *                 screen with an option of showing or not showing the pegs
 * Pre-condition : Game board is of Cell struct type and showPegs
                   if Boolean enum type
 * Post-condition: Game board printed on console screen
 */
void Board::printGameBoard (Board gameBoard [][10], bool showPegs)
{
	int i = 0, j = 0;

	printf("  0 1 2 3 4 5 6 7 8 9\n");

	for (i = 0; i < 10; i++) {
		printf ("%d ", i);

		for (j = 0; j < 10; j++) {
			if (showPegs == true)
				printf ("%c ", gameBoard [i][j].symbol);
			else {
				switch (gameBoard [i][j].symbol) {
				case '*':   printf ("%c ", '*');   break;
				case 'm':   printf ("%c ", 'm');   break;
				case '~':
				default:    printf ("%c ", '~');  break;
				}
			}
		}
		putchar ('\n');
	}
}

/**
 * Function name : putShipOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : putShipOnGameBoard (Cell [][], WaterCraft, Coordinate, int)
 * Definition    : This function allows you to put the 5 types of ship in the
 *                 the game board specified in the formal argument
 * Pre-condition : n/a
 * Post-condition: Specific type of ship place on specificied target cell
 */
void Board::putShipOnGameBoard (Board gameBoard[][10], Ship* ship,
		Coordinate position, int direction, int i)
{
	int temp = 0;
	char sym = 'x';
	if(i == 0)
	{
		temp = 4;
		sym = 'b';

	}
	else if(i == 1)
	{
		temp = 5;
		sym = 'c';

	}
	else if(i == 2)
	{
		temp = 3;
		sym = 'r';
	}
	else if(i == 3)
	{
		temp = 2;
		sym = 'd';

	}
	else if(i == 4)
	{
		temp = 3;
		sym = 's';

	}

	int x = temp - 1;

	for (x = 0; x < temp; x++)
	{
		if (direction == 0)
			gameBoard [position.row][position.column + x].symbol = sym;
		else /* VERTICAL */
			gameBoard [position.row + x][position.column].symbol = sym;
	}
}

/**
 * Function name : manuallyPlaceShipsOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : manuallyPlaceShipsOnGameBoard (Cell [][], WaterCraft []);
 * Definition    : This function allows user to manually place ship on the specified
 *                 gameboard with specific ship
 * Pre-condition : Assuming user inputs correct coordinates as it does not check
 *                 if input is correctly inputted
 * Post-condition: Ships placed on game board
 */
void Board::manuallyPlaceShipsOnGameBoard (Board gameBoard[][10], Ship* ship[])
{
	char stringPosition[11] = "";
	int i = 0, j = 0;

	Coordinate position[5];
	bool isValid = true;

	fflush (stdin);

	int temp = 0;
	string nm = " ";
	char sym = 'x';

	for (i = 0; i < 5; i++)
	{


		if(i == 0)
		{
			temp = 4;
			nm = "Battleship";
			sym = 'b';

		}
		else if(i == 1)
		{
			temp = 5;
			nm = "Carrier";
			sym = 'c';

		}
		else if(i == 2)
		{
			temp = 3;
			nm = "Cruiser";
			sym = 'r';
		}
		else if(i == 3)
		{
			temp = 2;
			nm = "Destroyer";
			sym = 'd';

		}
		else if(i == 4)
		{
			temp = 3;
			nm = "Submarine";
			sym = 's';

		}

		do {
			printGameBoard (gameBoard, true);
			printf ("> Please enter the %d cells to place the ", temp);
			cout << nm;
			cout << " across (no spaces):\n";
			printf ("> ");
			scanf ("%s", stringPosition);

			/* convertStringtoPosition returns false if unsuccessful */
			if (convertStringtoPosition (position, stringPosition, temp))
			{

				isValid = true;

				for (j = 0; j < temp; j++)
				{

					if (gameBoard[position[j].row][position[j].column].symbol == '~')
					{
						gameBoard[position[j].row][position[j].column].symbol = sym;
					}
					else
					{
						isValid = false;
						printf ("> Invalid input!\n");

						if (j != 0)
							while (j >= 0)
							{
								gameBoard[position[j].row][position[j].column].symbol = '~';
								j--;
							}

						break;
					}
				}
			} else
			{
				isValid = false;
				printf ("> Invalid input!\n");
			}
		} while(isValid == false);

	}
}
/**
 * Function name : randomlyPlaceShipsOnGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : randomlyPlaceShipsOnGameBoard (Cell [][], WaterCraft []);
 * Definition    : This function lets the computer randomly place ship on the
 *                 game board
 * Pre-condition : n/a
 * Post-condition: Ships placed on game board
 */
void Board:: randomlyPlaceShipsOnGameBoard (Board gameBoard[][10], Ship* ship[])
{
	Coordinate position;
	int direction = -1;
	int temp = 0;

	for (int i = 0; i < 5; i++)
	{
		if(i == 0)
		{
			temp = 4;
		}
		else if(i == 1)
		{
			temp = 5;
		}
		else if(i == 2)
		{
			temp = 3;
		}
		else if(i == 3)
		{
			temp = 2;
		}
		else if(i == 4)
		{
			temp = 3;

		}
		while (true)
		{
			direction = getRandomNumber (0, 1); /* 0 -> horizontal, 1 -> vertical */
			position = generatePosition (direction, temp);

			if (isValidLocation (gameBoard, position, direction, temp)) break;

		}

		putShipOnGameBoard (gameBoard, ship[i], position, direction, i);

	}

}

/**
 * Function name : getRandomNumber ()
 * Date Created  : 17 October 2012
 * Usage         : getRandomNumber (int, int);
 * Definition    : This function returns a random number between and
 *                 including the lowest to the highest number
 * Pre-condition : n/a
 * Post-condition: n/a
 */
int Board::getRandomNumber (int lowest, int highest)
{
	if (lowest == 0)
		return rand () % ++highest;

	if (lowest > 0)
		return rand () % ++highest + lowest;
	return 0;
}

/**
 * Function name : convertStringtoPosition ()
 * Date Created  : 17 October 2012
 * Usage         : convertStringtoPosition (Cell [], char *, int);
 * Definition    : This function converts string coordinates into individual
 *                 integer coordinates
 * Pre-condition : Assuming that user inputs correct coordinates since program
 *                 does not check for inccorrect coordinates
 * Post-condition: n/a
 */
bool Board::convertStringtoPosition (Coordinate position[], char *stringPosition, int length)
{
	bool flag = true;
	int i = 0;
	int j = 0;
	int k = 1;

		/* checks if length of input is good */
		if(strlen(stringPosition)/2 == (length)) {
			/* loops through the length of the ship */
			for (i = 0; i < length && flag; i++) {
				/* checks if each cell is a digit */
				if (isdigit (stringPosition[j]) && isdigit (stringPosition[k])) {
					position[i].row    = stringPosition[j] - '0';
					position[i].column = stringPosition[k] - '0';

					j += 2;
					k += 2;
				} else {
					flag = false;
				}
			}
		} else {
			flag = false;
		}

	return flag;
}

/**
 * Function name : generatePosition ()
 * Date Created  : 17 October 2012
 * Usage         : generatePosition (int, int);
 * Definition    : This function generates position based on the
 *                 direction and length specified and it can't be
 *                 more than the game board size
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Coordinate Board::generatePosition (int direction, int length)
{
	Coordinate position;

	if (direction == 0) {
		position.row    = getRandomNumber (0, 10);
		position.column = getRandomNumber (0, 10 - length);
	} else { /* VERTICAL */
		position.row    = getRandomNumber (0, 10 - length);
		position.column = getRandomNumber (0, 10);
	}

	return position;
}

/**
 * Function name : isValidLocation ()
 * Date Created  : 17 October 2012
 * Usage         : isValidLocation (Cell [][], Coordinate, int, int);
 * Definition    : This function checks if specified position, direction and
 *                 length is valid on location specified on the game board
 * Pre-condition : n/a
 * Post-condition: n/a
 */
bool Board::isValidLocation (Board gameBoard[][10], Coordinate position,
		int direction, int length)
{
	int i = length - 1;
	bool isValid = true;

	for (i = 0; isValid && i < length; i++) {
		if (direction == 0) {
			if (gameBoard [position.row][position.column + i].symbol != '~' &&
					(position.column + i) < 10)
				isValid = false;
		} else { /* VERTICAL */
			if (gameBoard [position.row + i][position.column].symbol != '~' &&
					(position.row + i) < 10)
				isValid = false;
		}
	}

	return isValid;
}

/**
 * Function name : checkShot ()
 * Date Created  : 17 October 2012
 * Usage         : checkShot (Cell [][], Coordinate);
 * Definition    : This function checks if the coordinates on the
 *                 game board is a miss, hit, water or water craft
 * Pre-condition : n/a
 * Post-condition: n/a
 */
short Board::checkShot (Board gameBoard[][10], Coordinate target)
{
	int hit = -2;

	switch (gameBoard[target.row][target.column].symbol) {
	/* miss */
	case '~':
		hit = 0;
		break;

		/* hit */
	case 'c':
	case 'b':
	case 'r':
	case 's':
	case 'd':
		hit = 1;
		break;

	case '*':
	case 'm':
	default:
		hit = -1;
		break;
	}

	return hit;
}

/**
 * Function name : checkBoundsOfCardinal ()
 * Date Created  : 17 October 2012
 * Usage         : checkBoundsOfCardinal (Boolean [], int, int);
 * Definition    : This function checks if the specified direction is
 *                 not over the bounds and sets the cardinals with TRUE
 *                 if its within bounds, otherwise FALSE
 * Pre-condition : n/a
 * Post-condition: Updates the cardinals array
 */
void Board::checkBoundsOfCardinal (bool cardinals[], int bound, int direction)
{
	switch (direction) {
	case 0:
		if (bound < 0)
			cardinals[0] = false;
		else
			cardinals[0] = true;
		break;

	case 1:
		if (bound > 9)
			cardinals[1] = false;
		else
			cardinals[1] = true;
		break;

	case 2:
		if (bound < 0)
			cardinals[2] = false;
		else
			cardinals[2] = true;
		break;

	case 3:
		if (bound > 9)
			cardinals[3] = false;
		else
			cardinals[3] = true;
		break;
	}
}

/**
 * Function name : getTarget ()
 * Date Created  : 17 October 2012
 * Usage         : getTarget ();
 * Definition    : This function reads a row and column values from
 *                 the user
 * Pre-condition : n/a
 * Post-condition: n/a
 */
Coordinate Board:: getTarget ()
{
	Coordinate target;

	fflush (stdin);

	printf ("> Enter Target (ex. > 3 4):\n");
	printf ("> ");
	scanf ("%d %d", &target.row, &target.column);

	return target;
}


/**
 * Function name : checkSunkShip ()
 * Date Created  : 17 October 2012
 * Usage         : checkSunkShip (shor [][], short, char, FILE *);
 * Definition    : This function check if a ship has sunk based on the
 *                 how of the length of ship is left. If a ship was sunk
 *                 it is logged on an output file
 * Pre-condition : stream to output file was created
 * Post-condition: n/a
 */
bool Board:: checkSunkShip (short sunkShip[][5], short player, char shipSymbol, FILE *stream)
{
	bool sunked = false;

	switch (shipSymbol) {
	case 'c':
		if (--sunkShip[player][0] == 0) {
			printf ("> Player %d's Carrier sunked!\n", player + 1);

			/* Write to battleship.log */
			fprintf (stream, "Player %d's Carrier sunked!\n", player + 1);

			sunked = true;
		}
		break;

	case 'b':
		if (--sunkShip[player][1] == 0) {
			printf ("> Player %d's Battleship sunked!\n", player + 1);

			/* Write to battleship.log */
			fprintf (stream, "Player %d's Battleship sunked!\n", player + 1);

			sunked = true;
		}
		break;

	case 'r':
		if (--sunkShip[player][2] == 0) {
			printf ("> Player %d's Cruiser sunked!\n", player + 1);

			/* Write to battleship.log */
			fprintf (stream, "Player %d's Cruiser sunked!\n", player + 1);

			sunked = true;
		}
		break;

	case 's':
		if (--sunkShip[player][3] == 0) {
			printf ("> Player %d's Submarine sunked!\n", player + 1);

			/* Write to battleship.log */
			fprintf (stream, "Player %d's Submarine sunked!\n", player + 1);

			sunked = true;
		}
		break;

	case 'd':
		if (--sunkShip[player][4] == 0) {
			printf ("> Player %d's Destroyer sunked!\n", player + 1);

			/* Write to battleship.log */
			fprintf (stream, "Player %d's Destroyer sunked!\n", player + 1);

			sunked = true;
		}
		break;
	}

	return sunked;
}

/**
 * Function name : updateGameBoard ()
 * Date Created  : 17 October 2012
 * Usage         : updateGameBoard (Cell [][], Coordinate);
 * Definition    : This function updates the game board whether
 *                 its a hit or miss
 * Pre-condition : n/a
 * Post-condition: Game board updated with proper symbol
 */
void Board::updateGameBoard (Board gameBoard[][10], Coordinate target)
{
	switch (gameBoard[target.row][target.column].symbol) {
	/* miss */
	case '~':
		gameBoard[target.row][target.column].symbol = 'm';
		break;

		/* hit */
	case 'c':
	case 'b':
	case 'r':
	case 's':
	case 'd':
		gameBoard[target.row][target.column].symbol = '*';
		break;

	case '*':
	case 'm':
	default:
		break;
	}
}

/**
 * Function name : isWinner ()
 * Date Created  : 17 October 2012
 * Usage         : isWinner (Stats [], int);
 * Definition    : This function determines if there is a winner based
 *                 on the 17 total pegs for each player
 * Pre-condition : n/a
 * Post-condition: n/a
 */
bool Board::isWinner (Stats players[], int player)
{
	bool isWin = false;

	if (players[player].numHits == 17)
		isWin = true;

	return isWin;
}


