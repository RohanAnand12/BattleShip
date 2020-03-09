

#include "Tests.h"
#include "Board.h"
#include "Stats.h"
#include <iostream>
using namespace std;

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{

	bool answer = testInitializeGameBoard() &&
	              testRandomNumber() &&
	              testIsWinner() &&
	              testConvertStringToPosition() &&
	              testIsValidLocation();
	return answer;
}

bool Tests::testInitializeGameBoard()
{


	Board board[10][10];
	int i = 0, j = 0;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			board[i][j].symbol = '~';
			board[i][j].position.row = i;
			board[i][j].position.column = j;
		}

	Board result[10][10];

	Board* b = new Board();
	b->initializeGameBoard(result);

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if(board[i][j].symbol != result[i][j].symbol)
			{
				cout << "Test initializeGameBoard failed\n";
				return false;
			}

		}

	cout << "Test initializeGameBoard passed\n";
	return true;
}

bool Tests :: testRandomNumber()
{


	Board* board = new Board();

	int n = board->getRandomNumber(0,10);

	if(n > -1 && n < 11)
	{
		cout << "Test getRandomNumber passed\n";
		return true;
	}

	cout << "Test getRandomNumber failed\n";
	return false;
}

bool Tests:: testIsWinner()
{


	Board *board = new Board();

	Stats s1;
	s1.numHits = 17;
	s1.numMisses = 4;
	s1.totalShots = 21;
	s1.hitMissRatio = 4.25;

	Stats s2;
	s2.numHits = 12;
	s2.numMisses = 10;
	s2.totalShots = 22;
	s2.hitMissRatio = 1.2;

	Stats players[2] = {s1,s2};

	bool winner = board->isWinner(players, 0);

	if(winner == true)
	{
		cout << "Test isWinner passed\n";
		return true;
	}
	else
	{
		cout << "Test isWinner failed\n";
		return false;
	}

}

bool Tests:: testConvertStringToPosition()
{


	Coordinate position[5];
	char* stringPosition = "121212";
	int length = 3;

	Board* b = new Board();

	bool h = b->convertStringtoPosition(position, stringPosition, length);

	if(h)
	{
		cout << "Test convertStringToPosition passed\n";
		return true;
	}
	else
	{
		cout << "Test convertStringToPosition failed\n";
		return false;
	}
}

bool Tests:: testIsValidLocation()
{

	Board gameBoard[10][10];

	Coordinate position;
	position.column = 5;
	position.row = 5;

	int dir = 1;
	int len = 4;

	Board *b = new Board();
	bool test = b->isValidLocation(gameBoard, position, dir, len);

	if(test)
		{
			cout << "Test isValidLocation passed\n";
			return true;
		}
		else
		{
			cout << "Test isValidLocation failed\n";
			return false;
		}
}
