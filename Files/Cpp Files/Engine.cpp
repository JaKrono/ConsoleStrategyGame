#include "Engine.h"

using namespace::std;

bool Engine::saveGame(Game theGame) {
	fstream fs;
	fs.open("SavedGames.txt", ios::out);
	if (!fs) {
		cout << "Error in opening/creatinr the file.\n";
		return false;
	}
	fs.write((char*)&theGame, sizeof(Game));
	fs.close();
	cout << "Game Saved.\n";
	return true;
}

bool Engine::loadGame(Game* tempGame) {
	fstream fs;
	fs.open("SavedGames.txt", ios::in);
	if (!fs) {
		cout << "Couldn't load the game.\n";
		return false;
	}
	if (fs.read((char*)(tempGame), sizeof(Game))) {
		cout << "Game loaded successfully.\n";
		fs.close();
		return true;
	} else {
		cout << "Couldn't load the game.\n";
		fs.close();
		return false;
	}
}

void Engine::startMenu() {

	int commandType;

	while (1) {
		cout << "   ::StartMenu::\n1. Start a new game\n2. Load a game\n3. Exit\n   Enter your choice: ";
		cin >> commandType;
		if (commandType == 1) {

			int difficulty;
			cout << "Enter 1 for an easy game and 2 for a hard game: ";
			cin >> difficulty;

			// a game with this difficulty will be 
			// made in this function
			gameMenu(difficulty);

		} else if (commandType == 2) {

			// loading a game object
			gameMenu(-1);

		} else if (commandType == 3) {
			break;
		}
	}
	cout << "Thank you for playing!\n";
}

void Engine::gameMenu(int gameDifficulty) {

	Game game;
	if (gameDifficulty == -1) {
		if (!loadGame(&game)) {
			return;
		}
	} else {
		game.setValues(gameDifficulty);
	}

	int commandType;

	while (1) {
		
		cout << "\n   ::GameMenu::\n1. Attack a city\n2. Recruit troops\n";
		cout << "3. Send a spy to a city\n4. Coup de'tat\n5. View your resources\n6. Print cities' detailes\n7. Save the game\n8. Exit\n";
		cout << "   Enter your choice: ";
		cin >> commandType;

		if (commandType == 1) {

			// Attacking
			cout << "Which city do you want to attack? ";
			int cityNumber;
			cin >> cityNumber;
			cityNumber--;
			if (game.player.attack(&game.cities[cityNumber])) {
				game.player.setFoodStock(game.player.getFoodStock() + game.cities[cityNumber].getFoodStock());
				game.player.setGoldStock(game.player.getGoldStock() + game.cities[cityNumber].getGoldStock());
			}

		} else if (commandType == 2) {

			// Making troops
			game.player.makeTroops();

		} else if (commandType == 3) {

			// Sending Spy
			cout << "Which city do you want our spy to go to? ";
			int cityNumber;
			cin >> cityNumber;
			cityNumber--;
			if (game.player.sendSpy(&game.cities[cityNumber])) {
				game.player.setSpyCount(game.player.getSpyCount() - 1);
			}

		} else if (commandType == 4) {

			// Coup de'tat
			int cityNumber;
			cout << "Which city do you want this operation to be performed in?\n";
			cin >> cityNumber;
			cityNumber--;
			if (game.cities[cityNumber].getRelationState() == "Enemy") {
				if (game.cities[cityNumber].getSpyState()) {
					if (game.cities[cityNumber].conspiracy()) {
						game.player.setSpyCount(game.player.getSpyCount() + 1);
						game.player.setFoodStock(game.player.getFoodStock() + game.cities[cityNumber].getFoodStock());
						game.player.setGoldStock(game.player.getGoldStock() + game.cities[cityNumber].getGoldStock());
					} else {
						game.player.setSpyCount(game.player.getSpyCount() - 1);
					}
				} else {
					cout << "We dont have any spies in this city to perform this operations.\n";
				}
			} else {
				cout << "Are you out of your mind? That city is one of ours!\n";
			}


		} else if (commandType == 5) {

			// Print player's detailes
			game.player.printPlayer();

		} else if (commandType == 6) {

			// Print cities' detailes
			for (int i = 0;i < 10;i++) {
				cout << setw(2) << i+1 << ". ";
				game.cities[i].printDetailes();
			}

		} else if (commandType == 7) {

			// Save the game
			saveGame(game);

		} else if (commandType == 8) {

			// Exit game menu and open start menu
			break;
		}
	}
}
