#include "Inventory.h"
#include "Player.h"
#include <iostream>

AttackBoost::AttackBoost(std::string n, int increase)
	:name(n), attackIncrease(increase) {
}

std::string AttackBoost::getName() {
	return name;
}

void AttackBoost::use(Player& player) {
	player.attack += attackIncrease; //player 정의되어야함
	std::cout << name << " 사용! 공격력이 " << attackIncrease << "만큼 증가하였습니다. \n";

}

HealthPotion::HealthPotion(std::string n, int restore)
	:name(n), healthRestore(restore) {
}

std::string HealthPotion::getName() {
	return name;
}

void HealthPotion::use(Player& player) {
	player.health += healthRestore;
	std::cout << name << " 사용! 체력이 " << healthRestore << "만큼 회복되었습니다. \n";
}

ExperienceBoost::ExperienceBoost(std::string n, int Increase)
	:name(n), experienceIncrease(Increase) {
}

std::string ExperienceBoost::getName() {
	return name;
}

void ExperienceBoost::use(Player& player) {
	player.experience += experienceIncrease;
	std::cout << name << " 사용! 경험치 " << experienceIncrease << "만큼 획득하었습니다." << "\n";

}
