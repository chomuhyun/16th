#include <iostream>
#include <vector>
#include "Playerl.h"

using namespace std;

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

void Player::levelUp() // 레벨업시 체력 풀 회복
{
	health += (level * 20); // 레벨업 체력
	attack += (level * 5); // 레벨업 공격력

}