//효정
#include <iostream>
#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

using namespace std;

vector<inventory>inv; //인벤토리 클래스를 사용하는 벡터배열

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

Player::Player(string name):name(name),
	level(1),
	health(200), 
	attack(30), 
	experience(0),
	Inventory(Inventory){} //클래스 추가 해야함


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

//전투 보상 : 전투에서 이기면 골드를 얻고,가끔(30 % 확률) 
// 아이템이 떨어집니다" 




//일반 몬스터전투 승리시

gold += 12

inventory.push_back()
