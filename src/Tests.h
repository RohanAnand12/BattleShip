

#ifndef TESTS_H_
#define TESTS_H_

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();


	bool testInitializeGameBoard();
	bool testRandomNumber();
	bool testIsWinner();
	bool testConvertStringToPosition();
	bool testIsValidLocation();






};


#endif /* TESTS_H_ */
