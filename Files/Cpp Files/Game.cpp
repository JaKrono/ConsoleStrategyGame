#include "Game.h"
#include <fstream>

using namespace::std;

Game::Game(int difficulty){
	//Player 
	
	if( difficulty== 1 ){//Easy game level
	
		this->setEasyLevelCitiesSoldiers();
		this->setEasyLevelCitiesSatisfactionRates();
		this->setEasyLevelCitiesDefensivePowers();
		
	} else {//Hard game level
		
		this->setHardLevelCitiesSoldiers();
		this->setHardLevelCitiesSatisfactionRates();
		this->setHardLevelCitiesDefensivePowers();
		
	} 
	this->setCitiesResources();
	
}

bool Game::saveGame(){
	fstream fs("SavedGames.txt",ios::in | ios::out | ios::binary);
	if(!fs){
		return false;
	}
	
	Game tempGame = *this ;
	tempGame.setSaveStatus(true);
	fs.write(reinterpret_cast<char*> (&tempGame),sizeof(tempGame));	
	fs.close();
	return true;
}


bool Game::loadGame(){
	Game tempGame;
	fstream fs("SavedGames.txt",ios::in | ios::out | ios::binary);
	if(!fs){
		return false;
	}
	fs.read( reinterpret_cast<char*>(&tempGame),sizeof(tempGame));
	if(tempGame.getSaveStatus()){
		this->cities = tempGame.cities ;
		this->player = tempGame.player ;
		return true;
	}else {
		return flase;
	}
	fs.close();
	
}

//Set Soldiers Amount in the Cities According to Easy Level
void Game::setEasyLevelCitiesSoldiers(){
	
	this->cities[0].setSoldierCount(40);
	this->cities[1].setSoldierCount(50);
	this->cities[2].setSoldierCount(60);
	this->cities[3].setSoldierCount(20);
	this->cities[4].setSoldierCount(30);
	this->cities[5].setSoldierCount(35);
	this->cities[6].setSoldierCount(18);
	this->cities[7].setSoldierCount(80);
	this->cities[8].setSoldierCount(50);
	this->cities[9].setSoldierCount(60);
	
}

//Set Soldiers Amount in the Cities According to Hard Level
void Game::setHardLevelCitiesSoldiers(){
	
	this->cities[0].setSoldierCount(55);
	this->cities[1].setSoldierCount(62);
	this->cities[2].setSoldierCount(75);
	this->cities[3].setSoldierCount(30);
	this->cities[4].setSoldierCount(42);
	this->cities[5].setSoldierCount(48);
	this->cities[6].setSoldierCount(28);
	this->cities[7].setSoldierCount(105);
	this->cities[8].setSoldierCount(62);
	this->cities[9].setSoldierCount(76);
	
}

//Set Satisfaction Rates Amount in the Cities According to Easy Level
void Game::setEasyLevelCitiesSatisfactionRates(){
	
	this->cities[0].setSatisfactionRate(38);
	this->cities[1].setSatisfactionRate(46);
	this->cities[2].setSatisfactionRate(76);
	this->cities[3].setSatisfactionRate(23);
	this->cities[4].setSatisfactionRate(50);
	this->cities[5].setSatisfactionRate(40);
	this->cities[6].setSatisfactionRate(15);
	this->cities[7].setSatisfactionRate(90);
	this->cities[8].setSatisfactionRate(65);
	this->cities[9].setSatisfactionRate(60);
	
}

//Set Satisfaction Rates Amount in the Cities According to Hard Level
void Game::setHardLevelCitiesSatisfactionRates(){
	
	this->cities[0].setSatisfactionRate(43);
	this->cities[1].setSatisfactionRate(50);
	this->cities[2].setSatisfactionRate(80);
	this->cities[3].setSatisfactionRate(32);
	this->cities[4].setSatisfactionRate(60);
	this->cities[5].setSatisfactionRate(52);
	this->cities[6].setSatisfactionRate(25);
	this->cities[7].setSatisfactionRate(100);
	this->cities[8].setSatisfactionRate(76);
	this->cities[9].setSatisfactionRate(72);
	
}

//Set Defensive Powers Amount in the Cities According to Easy Level
void Game::setEasyLevelCitiesDefensivePowers(){
	
	this->cities[0].setDefensivePower(70);
	this->cities[1].setDefensivePower(65);
	this->cities[2].setDefensivePower(13);
	this->cities[3].setDefensivePower(46);
	this->cities[4].setDefensivePower(32);
	this->cities[5].setDefensivePower(65);
	this->cities[6].setDefensivePower(90);
	this->cities[7].setDefensivePower(34);
	this->cities[8].setDefensivePower(65);
	this->cities[9].setDefensivePower(43);
	
}

//Set Defensive Powers Amount in the Cities According to Hard Level
void Game::setHardLevelCitiesDefensivePowers(){
	
	this->cities[0].setDefensivePower(82);
	this->cities[1].setDefensivePower(76);
	this->cities[2].setDefensivePower(35);
	this->cities[3].setDefensivePower(65);
	this->cities[4].setDefensivePower(43);
	this->cities[5].setDefensivePower(78);
	this->cities[6].setDefensivePower(100);
	this->cities[7].setDefensivePower(43);
	this->cities[8].setDefensivePower(78);
	this->cities[9].setDefensivePower(55);
	
}
