#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;



Player::Player(string name) :name(name),
level(1),
health(200),
attack(30),
experience(0) {
}


//닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리
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

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

void Player::levelUp() // 레벨업시 체력 풀 회복
{
	MaxHealth += (level * 20); // 레벨업 체력
	attack += (level * 5); // 레벨업 공격력
	health = MaxHealth;
	if (level == 10) { return; }
	else {
		level += 1;
	}
}

