#include "Inventory.h"
#include "Character.h"
#include <iostream>

AttackBoost::AttackBoost(std::string n, int increase)
	:name(n), attackIncrease(increase) {
}

std::string AttackBoost::getName() {
	return name;
}

void AttackBoost::use(character: Character*) {
	character->attack += attackIncrease;
	std::cout << name << " 사용! 캐릭터 공격력이 " << attackIncrease << "만큼 증가하였습니다. 현재 공격력 "
		<< character->attack << "\n";
}

HealthPotion::HealthPotion(std::string n, int restore)
	:name(n), healthRestore(restore) {
}

std::string HealthPotion::getName() {
	return name;
}

void HealthPotion::use(character: Character*) {
	character->health += healthRestore;
	std::cout << name << " 사용! 캐릭터 체력이 " << healthRestore << "만큼 회복되었습니다. 현재 체력 "
		<< character->health << "\n";
}