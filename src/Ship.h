

#ifndef SHIP_H_
#define SHIP_H_
#include <string>
using namespace std;


class Ship {
public:
	Ship();
	virtual ~Ship();

	int length;
	char symbol;
	string name;
};

#endif /* SHIP_H_ */
