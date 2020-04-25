#include "Player.h"

using namespace::std;

int Player::getFoodStock() {
	return foodStock;
}

int Player::getGoldStock() {
	return goldStock;
}

int Player::getSpyCount() {
	return spyCount;
}

void Player::setFoodStock(int a) {
	foodStock = a;
}

void Player::setGoldStock(int a) {
	goldStock = a;
}

void Player::setSpyCount(int a) {
	spyCount = a;
}

void Player::setValues(int difficulty) {

	if (difficulty == 1) { // Easy
		foodStock = 800;
		goldStock = 600;
		spyCount = 8;
		spyFoodCost = 35;
		spyGoldCost = 40;
		playersArmy[0].setValues("Archer", 23, 60, 12, 10, 0.2f);
		playersArmy[1].setValues("Pikeman", 28, 45, 20, 20, 0.34f);
		playersArmy[2].setValues("Swordsman", 32, 35, 25, 30, 0.4f);
		playersArmy[3].setValues("Knight", 45, 30, 30, 35, 0.28f);
	} else if (difficulty = 2) { // Hard
		spyCount = 4;
		spyFoodCost = 45;
		spyGoldCost = 50;
		playersArmy[0].setValues("Archer", 15, 30, 18, 16, 0.2f);
		playersArmy[1].setValues("Pikeman", 18, 25, 25, 28, 0.34f);
		playersArmy[2].setValues("Swordsman", 20, 20, 35, 38, 0.4f);
		playersArmy[3].setValues("Knight", 30, 15, 40, 48, 0.28f);
		foodStock = 600;
		goldStock = 400;
	}
}

bool Player::attack(City* theCity) {
	if (theCity->getRelationState() == "Enemy") {
		int* input = inputArmy("Attack");
		int inputArr[4] = { *(input + 0), *(input + 1), *(input + 2),*(input + 3) };
		bool correctNumber = true; // true if player is sending a negative number of units for an attack 
		bool sendingZeroUnits = true; // true if player is assigning 0 units for an attack
		for (int i = 0;i < 4;i++) {
			if (inputArr[i] < 0) {
				correctNumber = false;
			} else if (inputArr[i] > 0) {
				sendingZeroUnits = false;
			}
		}
		if (correctNumber && !sendingZeroUnits) {
			int ourDamage, theirDamage = theCity->getSoldierCount() * theCity->getDefensivePower() / 4;
			for (int i = 0;i < 4;i++) {
				ourDamage += playersArmy[i].damage * inputArr[i];
			}
			if (ourDamage > theirDamage) { // Win
				
				if ((float)ourDamage / (float)theirDamage >= 3.0f) {
					cout << "After seeing the power of our army, enemy forces dropped their weapons and surrendered!\nWe now have control over the city.\n";
					return true;
				} else if (float(ourDamage) / (float)theirDamage >= 2.0f){
					cout << "Not so hard, but not so easy as well. The city is ours.\n";
				} else {
					cout << "It was a rough battle, but won bravely by our men.\n";
				}

				for (int i = 0;i < 4;i++) {
					if (inputArr[i] > 0) {
						playersArmy[i].count -= ((float)log(ourDamage) / (float)log(theirDamage) - 1.0f) * playersArmy[i].casualtyRate * inputArr[i];
						cout << "We lost " << playersArmy[i].count - inputArr[i] << " " << playersArmy[i].type << "(s).\n";
					}
				}
				
				return true;

			} else { // Lose

				cout << "That had nothing but lost lives for us. Such a stupid decision...\n";
				for (int i = 0;i < 4;i++) {
					if (inputArr[i] > 0) {
						playersArmy[i].count -= ((float)log(ourDamage) / (float)log(theirDamage) - 1.0f) * (1.0f - playersArmy[i].casualtyRate + 0.2f) * inputArr[i];
						cout << "We lost " << playersArmy[i].count - inputArr[i] << " " << playersArmy[i].type << "(s).\n";
					}
				}
				theCity->setSoldierCount( (float)theCity->getSoldierCount() * (float)ourDamage / (float)theirDamage );
				return false;

			}
		} else {
			cout << "We can't assign these units for an attack.\n";
			return false;
		}
	} else {
		cout << "That city is not controlled by our enemies.\n";
		return false;
	}
}

void Player::makeTroops() {
	int* input = inputArmy("Make");
	int inputArr[5] = { *(input + 0), *(input + 1), *(input + 2),*(input + 3) , *(input + 4)};
	bool makingZeroUnits = true, correctNumber = true;
	for (int i = 0;i < 5;i++) {
		if (inputArr[i] < 0) {
			correctNumber = false;
		} else if (inputArr[i] > 0) {
			makingZeroUnits = false;
		}
	}
	if (!makingZeroUnits && correctNumber) {
		int totalFoodCost = 0, totalGoldCost = 0;
		for (int i = 0;i < 4;i++) {
			totalFoodCost += inputArr[i] * playersArmy[i].foodCost;
			totalGoldCost += inputArr[i] * playersArmy[i].goldCost;
		}
		totalFoodCost += inputArr[4] * spyFoodCost;
		totalGoldCost += inputArr[4] * spyGoldCost;

		if (totalFoodCost > foodStock || totalGoldCost > goldStock) {
			cout << "Recruitment failed.\n";
			//return false;
		} else {
			cout << "Recruitment successful.\n";
			for (int i = 0; i < 4;i++) {
				playersArmy[i].count += inputArr[i];		
				if (playersArmy[i].count > 0) {
					cout << "We now have " << playersArmy[i].count << " unit(s) of " << playersArmy[i].type << ".\n";
				}
			}
			spyCount += inputArr[4];
			if (spyCount > 0) {
				cout << "We now have " << spyCount << " unit(s) of Spy.\n";
			}

			//return true;
		}
	} else {
		cout << "Recruitment failed.\n";
		//return false;
	}
}

bool Player::sendSpy(City* theCity) {
	if (!theCity->getSpyState() // there are no spies in that city
		&& this->spyCount > 0 // player has enough spies
		&& theCity->getRelationState() == "Enemy") // the town is an enemy's
		{
		// spy sent
		theCity->setSpyState(true);
		return true;
	} else {
		return false;
	}
}

int* Player::inputArmy(string type) {
	int result[5] = { 0,0,0,0,0 }; // the first 4 are for Army, the last one is for spies
	if (type == "Attack") {
		for (int i = 0;i < 4;i++) {
			if (playersArmy[i].count > 0) {
				cout << "We have " << playersArmy[i].count << ' ' << playersArmy[i].type << "(s). How many units do you want to send? ";
				cin >> result[i];
			}
		}
	} else if (type == "Make") {
		cout << "We currently have " << foodStock << " unit(s) of food and " << goldStock << "unit(s) of gold.\n";
		for (int i = 0;i < 4;i++) {
			cout << "We have " << playersArmy[i].count << ' ' << playersArmy[i].type << "(s)." << endl;
			cout << "Each " << playersArmy[i].count << " needs " << playersArmy[i].foodCost << " units of food & " << playersArmy[i].goldCost << " units of gold. How many units do you want to recruit? ";
			cin >> result[i];
		}
		// take input for spy and store it in result[5]
		cout << "We have " << this->spyCount << " Spy(s).\n";
		cout << "Each Spy needs " << spyFoodCost << " unit(s) of food and " << spyGoldCost << " unit(s) of gold. How many units do you want to recruit? ";
		cin >> result[5];
	}
	return result;
}
