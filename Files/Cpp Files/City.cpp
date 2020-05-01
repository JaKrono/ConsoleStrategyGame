#include "City.h"

using namespace::std;

int City::getFoodStock() {
	return foodStock;
}

int City::getGoldStock() {
	return goldStock;
}

int City::getSoldierCount() {
	return soldierCount;
}

int City::getDefensivePower() {
	return defensivePower;
}

int City::getSatisfactionRate() {
	return satisfactionRate;
}

bool City::getSpyState() {
	return hasSpy;
}

string City::getRelationState() {
	return relationState;
}

void City::setCityName(std::string n) {
	name = n;
}

void City::setFoodStock(int foodStock) {
	this->foodStock = foodStock;
}

void City::setGoldStock(int goldStock) {
	this->goldStock = goldStock;
}

void City::setSoldierCount(int soldierCount) {
	this->soldierCount = soldierCount;
}

void City::setDefensivePower(int defensivePower) {
	this->defensivePower = defensivePower;
}

void City::setSatisfactionRate(int satisfactionRate) {
	this->satisfactionRate = satisfactionRate;
}

void City::setSpyState(bool spyState) {
	this->hasSpy = spyState;
}

void City::setRelationState(std::string relationState) {
	this->relationState = relationState;
}

void City::printDetailes() {
	cout << name << ". ";
	if (relationState == "Captured") {
		cout << "This city is one of ours.\n";
	} else if (hasSpy) {
		cout << "    This city is controlled by our enemies. Based on our spy in the city:\n";
		cout << "    They have " << foodStock << " units of food & " << goldStock << " units of gold.\n";
		cout << "    There are currently " << soldierCount << " soldier(s) in this city.\n";
		cout << "    " << satisfactionRate << " percent of the population are satisfied with their governer.\n";
		cout << "    The city's architecture and location increases their chance of winning in a battle by " << defensivePower << " percents.\n";
	} else {
		cout << "Enemy's city. No more detailes.\n";
	}
}

bool City::conspiracy() {

	if (satisfactionRate < 50) {

		soldierCount = 0;
		relationState = "Captured";
		cout << "Coup de'tat was successful. We now have control over the city.\n";
		return true;

	} else if (satisfactionRate >= 50 && satisfactionRate < 80) {
		soldierCount /= 2;
		hasSpy = false;
		satisfactionRate -= 30;
		cout << "Things took a turn for worse in the final moments. Our spy is dead.\n";
		return false;

	} else if (satisfactionRate >= 80) {
		hasSpy = false;
		soldierCount = (soldierCount * 3) / 4;
		satisfactionRate -= 40;
		cout << "They sent us a gift. Our spy's head. May it be a lesson...\n";
		return false;
	}
}
