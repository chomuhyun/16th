#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

void Player::levelUp() // 레벨업시 체력 풀 회복
{
	MaxHealth += (level * 20);  // 레벨에 20곱한 값만큼 최대체력증가
	attack += (level * 5);     // 레벨에 5곱한 값만큼 공격력증가
	health = MaxHealth;
	if (level == 10) { return; } //만약 레벨이 10이면 돌아간다
	else {
		level += 1;
		
	}
}
void Player::useItem(int index) {

}