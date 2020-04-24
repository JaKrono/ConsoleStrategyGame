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

			// Attacking
			int cityNumber;
			cin >> cityNumber;
			if (game.player.attack(&game.cities[cityNumber])) {
				game.player.setFoodStock(game.player.getFoodStock() + game.cities[cityNumber].getFoodStock());
				game.player.setGoldStock(game.player.getGoldStock() + game.cities[cityNumber].getGoldStock());
			}

		} else if (commandType == 2) {

			// Making troops
			game.player.makeTroops();

		} else if (commandType == 3) {

			// Sending Spy
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
