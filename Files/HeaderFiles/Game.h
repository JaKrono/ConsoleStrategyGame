#ifndef GAME_H
#define GAME_H

#include "City.h"
#include "Player.h"
class Game {
public:
	Player player;
	City cities[10];
	
	// constructor
	Game(int difficulty);
	
	
	bool getSaveStatus(){
		return this->saveStatus;
	}
	void setSaveStatus(bool saveStatus){
		this->saveStatus = saveStatus ;
	}
private:
	bool saveStatus = false;
	
	void setEasyLevelCitiesSoldiers();
	void setHardLevelCitiesSoldiers();

	void setEasyLevelCitiesSatisfactionRates();
	void setHardLevelCitiesSatisfactionRates();

	void setEasyLevelCitiesDefensivePowers();
	void setHardLevelCitiesDefensivePowers();

	void setCitiesResources();
};
#endif // Game.h
