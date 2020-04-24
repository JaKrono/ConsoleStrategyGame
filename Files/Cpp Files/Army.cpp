#include "Army.h"

void Army::setValues(std::string type, int damage, int count, int foodCost, int goldCost, float casualtyRate) {
	this->type = type;
	this->damage = damage;
	this->count = count;
	this->foodCost = foodCost;
	this->goldCost = goldCost;
	this->casualtyRate = casualtyRate;
}
