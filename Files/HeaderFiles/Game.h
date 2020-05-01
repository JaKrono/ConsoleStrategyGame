#ifndef GAME_H
#define GAME_H

#include "City.h"
#include "Player.h"
#include <fstream>

class Game {
public:
	Player player;
	City cities[10];
	
	// set default values of player, cities, ...
	void setValues(int difficulty);

	// constructor
	Game();

private:
	//bool saveStatus = false;
	
	void setCityNames();

	void setEasyLevelCitiesSoldiers();
	void setHardLevelCitiesSoldiers();

	void setEasyLevelCitiesSatisfactionRates();
	void setHardLevelCitiesSatisfactionRates();

	void setEasyLevelCitiesDefensivePowers();
	void setHardLevelCitiesDefensivePowers();

	void setCitiesResources();
};
#endif // Game.h
