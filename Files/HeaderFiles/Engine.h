#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "Game.h"
#include "City.h"
#include "Player.h"

class Engine {
public:
	void startMenu();
	void gameMenu(int gameDifficulty);
};
#endif // Engine.h