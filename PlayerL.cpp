//효정
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

using namespace std;

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

Player::Player(string name):Name(name),
	level(1),
	health(200), 
	attack(30), 
	experience(0){}


//void useItem()
//{
//
//}

//레벨 체력 공격력 경험치 포인터


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