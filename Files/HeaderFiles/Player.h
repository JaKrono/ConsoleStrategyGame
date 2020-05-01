#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <iomanip> // for setw()

#include "City.h"
#include "Army.h"

class Player {
private:
	int foodStock;
	int goldStock;

	Army playersArmy[4]; // Pikeman, Knight, Archer, Swordsman
	int spyCount;
	int spyFoodCost;
	int spyGoldCost;

public:
	int getFoodStock();
	int getGoldStock();
	int getSpyCount();
	void setFoodStock(int a);
	void setGoldStock(int a);
	void setSpyCount(int a);

	void setValues(int difficulty); // difficulty: 1-Easy / 2-Hard

	// returns true if the city has been captured and false if not
	bool attack(City* theCity);

	// returns true if resources are available for creating this amount of troops 
	// and false if not.
	void makeTroops();

	// returns true if a spy can be sent to the towm:
	// 1. there are no spies already in that town
	// 2. that town is an enemy
	// 3. there is at least 1 spy available
	bool sendSpy(City* theCity);

	// handles input for attacking and making troops
	int* inputArmy(std::string type); // type = "Attack" , "Make"

	// prints the player's resorces
	void printPlayer();
};
#endif // Player.h
