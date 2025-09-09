
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "GameManager.h"


using namespace std;


Player::Player(std::string name)
	: name(name), level(1), health(200), attack(30), experience(0), inv()
{

}

//Setter 함수

void Player::setAttack(int atk)
{
    attack = atk;
}

void Player::setGold(int coin)
{
    gold = coin;
}


void Player::setHealth(int hp)
{
    health = hp;
}


void Player::displayStatus()
{
	cout << " * Character status * " << endl;
	cout << "======================" << endl;
	cout << "닉네임 : " << name << endl;
	cout << "Level : " << level << endl;
	cout << "HP : " << health << endl;
	cout << "공격력 : " << attack << endl;
	cout << "경험치 : " << experience << endl;
	cout << "골드 : " << gold << endl;
	cout << "======================" << endl;

}


void Player::levelUp() // 레벨업시 체력 풀 회복
{
	MaxHealth += (level * 20);  // 레벨에 20곱한 값만큼 최대체력증가
	attack += (level * 5);     // 레벨에 5곱한 값만큼 공격력증가
	health = MaxHealth;
	if (level == 10) { return; } //만약 레벨이 10이면 돌아간다
	else {
		level += 1;
		cout << "레벨업! 현재 레벨:" << level << endl;
	}
}

void Player::addExperience(int amount) // 경험치
{
    experience += amount;
    if (experience >= 100)
        experience -= 100;
    levelUp();
    cout << amount << "경험치를 획득했습니다! 현재 경험치:" << experience << endl;
}

void Player::useItem() 
{

    int input;
    std::cin >> input;

    Item* selectedItem = nullptr;
    int index = 1;

    auto& inventory = Getinv();

    for (int i = 0; i < inventory.size(); i++)
    {
        if (input == 1 && dynamic_cast<HealthPotion*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 2 && dynamic_cast<AttackBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 3 && dynamic_cast<ExperienceBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }

        if (inventory.empty()) {
            std::cout << "해당 아이템이 없습니다." << std::endl;
            return;
        }
    }


    selectedItem->use(*this);
    selectedItem->lossItem();

    delete selectedItem;
    inventory.erase(inventory.begin() + index);
}