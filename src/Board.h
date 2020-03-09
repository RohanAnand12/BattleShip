

#ifndef BOARD_H_
#define BOARD_H_

#include "Ship.h"
#include "Stats.h"
#include "Coordinate.h"

class Board {
public:
	Board();
	virtual ~Board();
	void initializeGameBoard (Board gameBoard[][10]);
	void printGameBoard (Board gameBoard [][10], bool showPegs);
	void manuallyPlaceShipsOnGameBoard (Board gameBoard[][10], Ship* ship[]);
	void randomlyPlaceShipsOnGameBoard (Board gameBoard[][10], Ship* ship[]);
	int getRandomNumber (int lowest, int highest);
	bool convertStringtoPosition (Coordinate position[], char *stringPosition, int length);
	Coordinate generatePosition (int direction, int length);
	bool isValidLocation (Board gameBoard[][10], Coordinate position,
					         int direction, int length);
	short checkShot (Board gameBoard[][10], Coordinate target);
	void checkBoundsOfCardinal (bool cardinals[], int bound, int direction);
	Coordinate getTarget ();
	bool checkSunkShip (short sunkShip[][5], short player, char shipSymbol, FILE *stream);
	void updateGameBoard (Board gameBoard[][10], Coordinate target);
	bool isWinner (Stats players[], int player);
	void putShipOnGameBoard (Board gameBoard[][10], Ship* ship,
			Coordinate position, int direction, int i);

	char symbol;
	Coordinate position;

};

#endif /* BOARD_H_ */
