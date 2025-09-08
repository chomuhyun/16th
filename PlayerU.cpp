#include <iostream>
#include <vector>
#include "Inventory.h"
#include "Player.h"


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
		std::cout << "레벨업! 현재 레벨:" << level << std::endl;
	}
}
void Player::addExperience(int amount) // 경험치 이월가능하게 구현했습니다!
{
	experience += amount; //현재 경험치에 새로 얻은 경험치(amount) 더해줌
	if (experience >= 100) 
		experience -= 100;
	    levelUp();
		std::cout << amount << "경험치를 획득했습니다! 현재 경험치:" << experience << std::endl;
}

