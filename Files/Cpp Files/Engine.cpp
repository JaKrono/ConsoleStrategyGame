#include "Engine.h"

using namespace::std;

void Engine::startMenu() {

	int commandType;

	while (1) {
		cin >> commandType;
		if (commandType == 1) {

			int difficulty;
			cin >> difficulty;

			// a game with this difficulty will be 
			// made in this function
			gameMenu(difficulty);

		} else if (commandType == 2) {
			// loading a game object
		} else if (commandType == 3) {
			break;
		}
	}
	cout << "Thank you for playing!\n";
}

void Engine::gameMenu(int gameDifficulty) {

	Game game(gameDifficulty);

	int commandType;

	while (1) {
		
		cin >> commandType;

		if (commandType == 1) {

			int cityNumber;
			cin >> cityNumber;
			int attackingTroops; // number of the player's soldiers that are attacking the town
			game.player.attack(attackingTroops, &game.cities[cityNumber]);

		} else if (commandType == 2) {

			int type;
			cin >> type;
			int howMany;
			cin >> howMany;
			game.player.makeTroops(howMany, type);

		} else if (commandType == 3) {

			int cityNumber;
			cin >> cityNumber;
			game.player.sendSpy(&game.cities[cityNumber]);

		} else if (commandType == 4) {

			int cityNumber;
			cin >> cityNumber;
			game.cities[cityNumber].conspiracy();

		} else if (commandType == 5) {

			for (int i = 0;i < 10;i++) {
				game.cities[i].pirntDetailes();
			}

		} else if (commandType == 6) {

			// save the game

		} else if (commandType == 7) {

			break;

		}
	}
}