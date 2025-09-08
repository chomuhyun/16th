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

void AttackBoost::gainItem() // 공격력 부스트 개수 +1
{
	numberofAttackBoost++;
}

void AttackBoost::lossItem() // 공격력 부스트 개수 -1
{
	if (numberofAttackBoost > 0) {
		numberofAttackBoost--;
	}
	else {
		cout << "공격력 부스트가 없습니다!" << endl;
	}
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

void HealthPotion::gainItem() // 체력 포션 개수 +1
{
	numberofHealthPotion++;
}

void HealthPotion::lossItem() // 체력 포션 개수 -1
{
	if (numberofHealthPotion > 0) {
		numberofHealthPotion--;
	}
	else {
		cout << "체력 포션이 없습니다!" << endl;
	}
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
void ExperienceBoost::gainItem()//경험치 부스트 개수 +1
{
	numberofExperienceBoost++; 
}
void ExperienceBoost::lossItem()//경험치 부스트 개수 -1
{
	if (numberofExperienceBoost > 0) {
		numberofExperienceBoost--;
	}
	else {
		cout << "경험치 부스트가 없습니다!" << endl;
	}
}
//***** 아이템 현재 갯수 및 골드 출력
void PrintCurrentItemAndGold() {
	cout << "[이름: " <<  " 메인함수(getter) 가져오기" <<
		", 총 Gold: " << " 플레이어 (getter) 가져오기" << "G]" << endl;
}
