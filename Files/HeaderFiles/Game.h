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
};
#endif // Game.h