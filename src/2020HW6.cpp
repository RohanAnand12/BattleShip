//============================================================================
// Name        : BattleShip - Homework 6
// Author      : Rohan Anand
//Partners     : Ishan Rathi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Tests.h"
#include "Production.h"

#include <string>



int main(int argc, char* argv[])
{
    cout<< "BattleShip Time! - Homework 6" << endl;
	Tests* tsP = new Tests();
	if(tsP->tests())
	{
		Production* pP = new Production();
		if(pP->prod(argc, argv))
		{
			cout <<"Production passed." << endl;
		}
		delete(pP);
	}
	else
    {
		cout <<"Not all tests passed." << endl;
	}
	delete(tsP);


		return 0;
	}


