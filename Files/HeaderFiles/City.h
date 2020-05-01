#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

class City {
private:
	int foodStock;
	int goldStock;
	
	int soldierCount;
	int defensivePower; // 0 - 100

	int satisfactionRate; // 0 - 100

	bool hasSpy = false; // true if there is a spy in the city
	
	std::string relationState = "Enemy"; // "Enemy" - "Captured"

	std::string name;

public:

	// returns true if coup de'tat has been successful and false if not
	bool conspiracy();

	// prints the detailes that player knows about the city
	void printDetailes();

	int getFoodStock();
	int getGoldStock();
	int getSoldierCount();
	int getDefensivePower();
	int getSatisfactionRate();
	bool getSpyState(); // returns hasSpy
	std::string getRelationState();
	
	void setCityName(std::string n);
	void setFoodStock(int foodStock);
	void setGoldStock(int goldStock);
	void setSoldierCount(int soldierCount);
	void setDefensivePower(int defensivePower);
	void setSatisfactionRate(int satisfactionRate);
	void setSpyState(bool spyState);
	void setRelationState(std::string relationState);
};
#endif // City.h
