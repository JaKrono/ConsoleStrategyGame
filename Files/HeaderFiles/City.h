#ifndef CITY_H
#define CITY_H

#include <string>

class City {
private:
	int foodStock;
	int goldStock;
	
	int soldierCount;
	int defensivePower; // 0 - 100

	int satisfactionRate; // 0 - 100
	
	std::string relationState; // "Enemy" - "Captured"
public:
	// returns true if coup de'tat has been successful and false if not
	bool conspiracy();

	void pirntDetailes();

	int getFoodStock();
	int getGoldStock();
	int getSoldierCount();
	int getDefensivePower();
	int getSatisfactionRate();
	std::string getRelationState();
};
#endif // City.h