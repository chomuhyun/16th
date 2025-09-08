
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

void Player::addExperience(int amount)
{
	experience += amount;
	if (experience >= 100)
		experience -= 100;
	levelUp();
	cout << amount << "경험치를 획득했습니다! 현재 경험치:" << experience << endl;
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



//아이템 사용 번호 선택 1.HP 2.공격력강화 3. 경험치 강화
void Player::useItem()
{
	int index;
	std::cin >> index;

	if (index < 0 || index >= inv.size())  // 인덱스 값이 0보다 작거나 인덱스 크기보다 큰경우 함수 종료
	{
		std::cout << "잘못된 인덱스 입니다." << std::endl;
		return;
	}

	Item* item = inv[index];
	// vector<Item*>inv  안에있는 객체를 가리키는 포인터 선언
	//dynamic_cast로 item이 내가 원하는 자식 클래스가 맞는지 확인,아니라면 nullptr

	if (HealthPotion* hpPotion = dynamic_cast<HealthPotion*>(item))
	{
		hpPotion->use(*this);
		hpPotion->lossItem();
		std::cout << hpPotion->getName() << "사용!" << std::endl;
	}
	else if (AttackBoost* atkboost = dynamic_cast<AttackBoost*>(item))
	{
		atkboost->use(*this);
		atkboost->lossItem();
		std::cout << atkboost->getName() << "사용!" << std::endl;
	}
	else if (ExperienceBoost* expboost = dynamic_cast<ExperienceBoost*>(item))
	{
		expboost->use(*this);
		expboost->lossItem();
		std::cout << expboost->getName() << "사용!" << std::endl;
	}
	else
	{
		std::cout << "사용할수 있는 아이템이 없습니다." << std::endl;
		return;
	}

	//메모리 처리 (공통) 벡터 제거 + 메모리 해제
	delete inv[index];
	inv.erase(inv.begin() + (index - 1)); //인덱스는 0 번부터 시작

}


