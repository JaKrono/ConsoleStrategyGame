#include "Game.h"

using namespace::std;

void Game::setValues(int difficulty){
	
	if( difficulty== 1 ){//Easy game level
	
		this->setEasyLevelCitiesSoldiers();
		this->setEasyLevelCitiesSatisfactionRates();
		this->setEasyLevelCitiesDefensivePowers();
		this->player.setValues(difficulty);
		
	} else {//Hard game level
		
		this->setHardLevelCitiesSoldiers();
		this->setHardLevelCitiesSatisfactionRates();
		this->setHardLevelCitiesDefensivePowers();
		this->player.setValues(difficulty);
		
	} 

	this->setCitiesResources();
	this->setCityNames();
	
}

Game::Game() {
	//cout << "Game obj created.\n";
}

void Game::setCityNames() {
	this->cities[0].setCityName("Aalborg");
	this->cities[1].setCityName("Jomsborg");
	this->cities[2].setCityName("Reric");
	this->cities[3].setCityName("Rouen");
	this->cities[4].setCityName("Cork");
	this->cities[5].setCityName("Fyrkat");
	this->cities[6].setCityName("Vinland");
	this->cities[7].setCityName("Wolin");
	this->cities[8].setCityName("Hedeby");
	this->cities[9].setCityName("Gevninge");
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
	
	this->cities[0].setSatisfactionRate(48);
	this->cities[1].setSatisfactionRate(56);
	this->cities[2].setSatisfactionRate(86);
	this->cities[3].setSatisfactionRate(43);
	this->cities[4].setSatisfactionRate(60);
	this->cities[5].setSatisfactionRate(50);
	this->cities[6].setSatisfactionRate(45);
	this->cities[7].setSatisfactionRate(90);
	this->cities[8].setSatisfactionRate(75);
	this->cities[9].setSatisfactionRate(80);
	
}

//Set Satisfaction Rates Amount in the Cities According to Hard Level
void Game::setHardLevelCitiesSatisfactionRates(){
	
	this->cities[0].setSatisfactionRate(63);
	this->cities[1].setSatisfactionRate(80);
	this->cities[2].setSatisfactionRate(100);
	this->cities[3].setSatisfactionRate(62);
	this->cities[4].setSatisfactionRate(80);
	this->cities[5].setSatisfactionRate(82);
	this->cities[6].setSatisfactionRate(65);
	this->cities[7].setSatisfactionRate(100);
	this->cities[8].setSatisfactionRate(86);
	this->cities[9].setSatisfactionRate(92);
	
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

void Game::setCitiesResources() {

	this->cities[0].setFoodStock(200);
	this->cities[1].setFoodStock(300);
	this->cities[2].setFoodStock(500);
	this->cities[3].setFoodStock(150);
	this->cities[4].setFoodStock(350);
	this->cities[5].setFoodStock(250);
	this->cities[6].setFoodStock(150);
	this->cities[7].setFoodStock(650);
	this->cities[8].setFoodStock(400);
	this->cities[9].setFoodStock(380);

	this->cities[0].setGoldStock(100);
	this->cities[1].setGoldStock(200);
	this->cities[2].setGoldStock(350);
	this->cities[3].setGoldStock(80);
	this->cities[4].setGoldStock(100);
	this->cities[5].setGoldStock(95);
	this->cities[6].setGoldStock(75);
	this->cities[7].setGoldStock(450);
	this->cities[8].setGoldStock(320);
	this->cities[9].setGoldStock(165);

}
