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
	float casualtyRate; // 0 - 1
	void setValues(std::string type, int damage, int count, int foodCost, int goldCost, float casualtyRate);
};

#endif // Army.h
