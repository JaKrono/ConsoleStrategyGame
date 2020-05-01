#ifndef ENGINE_H
#define ENGINE_H

#include <fstream>
#include <iostream>
#include "Game.h"
#include "City.h"
#include "Player.h"

class Engine {
public:
	void startMenu();
	void gameMenu(int gameDifficulty);
	bool saveGame(Game theGame);
	bool loadGame(Game* tempGame);
};
#endif // Engine.h
