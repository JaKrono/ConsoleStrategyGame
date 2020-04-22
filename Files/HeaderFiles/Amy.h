#ifndef ARMY_H
#define ARMY_H

#include <string>
class Army {
public:
	std::string type;
	int damage;
	int count;
	int foodCost;
	int goldCost;

	Army(std::string t, int d, int c, int f, int g);
};

#endif // Army.h
