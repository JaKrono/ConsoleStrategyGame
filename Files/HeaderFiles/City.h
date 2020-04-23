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
	
	bool hasSpy; // true if there is a spy in the city
	
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
	
	void setFoodStock(int foodStock);
	void setGoldStock(int goldStock);
	void setSoldierCount(int soldierCount);
	void setDefensivePower(int defensivePower);
	void setSatisfactionRate(int satisfactionRate);
	void setRelationState(std::string relationState);
};
#endif // City.h
