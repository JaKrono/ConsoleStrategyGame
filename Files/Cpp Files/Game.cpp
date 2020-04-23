#include "Game.h"
#include <fstream>

using namespace::std;

Game::Game(int difficulty){
	
}

bool Game::saveGame(){
	fstream fs("SavedGames.txt",ios::in | ios::out | ios::binary);
	if(!fs){
		return false;
	}
	this->saveStatus = true;
	Game tempGame = *this ;
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
