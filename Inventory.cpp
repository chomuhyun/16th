#include "Inventory.h"
#include "Player.h"
#include <iostream>

AttackBoost::AttackBoost(std::string n, int increase, int Numberof, int price) // 공격력 부스트(이름, 증가량, 수량, 가격)
	:name(n), attackIncrease(increase), numberofAttackBoost(Numberof), priceAttackBoost(price){
}

std::string AttackBoost::getName() { // 공격력 부스트 이름 반환 함수
	return name;
}

void AttackBoost::use(Player& player) { // 공격력 부스트 사용 후 공격력 증가 함수
	int currentAttack = player.getAttack();          // getter로 읽고
	player.setAttack(currentAttack + attackIncrease); // setter로 공격력 증가
	std::cout << name << " 사용! 공격력이 " << attackIncrease << "만큼 증가하였습니다. \n";

}

int AttackBoost::gainItem() // 공격력 부스트 개수 +1
{
	return ++numberofAttackBoost;
}

int AttackBoost::lossItem() // 공격력 부스트 개수 -1
{
	if (numberofAttackBoost > 0) {
		return --numberofAttackBoost;
	}
	else {
		std::cout << "공격력 부스트가 없습니다!" << std::endl;
		return 0;
	}
}

HealthPotion::HealthPotion(std::string n, int restore, int Numberof, int price) // 회복 포션(이름, 회복량, 수량)
	:name(n), healthRestore(restore), numberofHealthPotion(Numberof), priceHealthPotion(price){
}

std::string HealthPotion::getName() {// 회복 포션 이름 반환 함수
	return name;
}

void HealthPotion::use(Player& player) { // 회복 포션 사용 후 체력 증가 함수
	int currentHealth = player.getHealth();  // getter로 현재체력 읽음
	int maxHealth = player.getMaxHealth(); // getter로 최대체력 읽음

	if (currentHealth == maxHealth) 
	{
		std::cout << "체력이 가득 찼습니다! 포션을 사용할 수 없습니다.\n";
		return;
	}

	else if (currentHealth + healthRestore < maxHealth) // (조건)현재체력 + 회복량 < 최대체력
	{
		player.setHealth(currentHealth + healthRestore); // setter로 회복량 만큼 체력 증가
		std::cout << name << " 사용! 체력이 " << healthRestore << "만큼 회복되었습니다. \n";
	}

	else 
	{
		player.setHealth(maxHealth); // 현재체력 + 회복량이 최대체력은 넘기지 않음
		std::cout << name << " 사용! 체력이 완전히 회복되었습니다. \n";
	}
	
}

int HealthPotion::gainItem() // 체력 포션 개수 +1
{
	return ++numberofHealthPotion;
}

int HealthPotion::lossItem() // 체력 포션 개수 -1
{
	if (numberofHealthPotion > 0) {
		return --numberofHealthPotion;
	}
	else {
		std::cout << "체력 포션이 없습니다!" << std::endl;
		return 0;
	}
}

ExperienceBoost::ExperienceBoost(std::string n, int Increase, int Numberof, int price) // 경험치 부스트(이름, 증가량, 수량, 가격)
	:name(n), experienceIncrease(Increase), numberofExperienceBoost(Numberof), priceExperienceBoost(price){
}

std::string ExperienceBoost::getName() { // 경험치 부스트 이름 반환 함수
	return name;
}

void ExperienceBoost::use(Player& player) { // 경험치 부스트 사용 후 경험치 증가 함수
	int currentExperience = player.getExperience();           // getter로 읽고
	player.addExperience(currentExperience + experienceIncrease); // setter로 경험치 증가
	std::cout << "\n" << name << " 사용! 경험치 " << experienceIncrease << "만큼 획득하었습니다." << "\n";

}
int ExperienceBoost::gainItem()//경험치 부스트 개수 +1
{
	return ++numberofExperienceBoost; 
}
int ExperienceBoost::lossItem()//경험치 부스트 개수 -1
{
	if (numberofExperienceBoost > 0) {
		return --numberofExperienceBoost;
	}
	else {
		std::cout << "경험치 부스트가 없습니다!" << std::endl;
		return 0;
	}
}
//***** 아이템 현재 갯수 및 골드 출력
void Inventory::PrintCurrentItemAndGold(Player& player, HealthPotion& hp, AttackBoost& ab, ExperienceBoost& exp) {
	std::cout << "[체력 포션: " << hp.getCount() << "개, 공격력 증가 포션: " << ab.getCount() <<"개, 경험치 증가 포션: "<< exp.getCount() <<
		"개, 현재 Gold: " << player.getGold() << "G]" << std::endl;
}

