#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "City.h"
#include "Army.h"

class Player {
private:
	int foodStock;
	int goldStock;

	Army playersArmy;
	int spyCount;
public:
	int getFoodStock();
	int getGoldStock();
	int getSoldierCount();
	int getSpyCount();

	// returns true if the city has been captured and false if not
	bool attack(int attackingTroops, City* theCity);

	// returns true if resources are available for creating this amount of troops 
	// and false if not. Type for soldier is 1 and for spy is 2
	bool makeTroops(int number, int type);

	// returns true if a spy can be sent to the towm:
	// 1. there are no spies already in that town
	// 2. that town is an enemy
	// 3. there is at least 1 spy available
	bool sendSpy(City* theCity);
};
#endif // Player.h