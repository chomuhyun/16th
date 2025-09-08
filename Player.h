#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Player
{
public: // 멤버함수

	Player player(string name) {} // 생성자

	//getter
	int getGold() {	return gold;} //골드
	int getHealth() { return health; } //체력
	int getExperience() { return experience; } // 경험치
	string getCharacterName() { return name; } // 캐릭터 닉네임 
	vector<Item*>& Getinv() { return inv; } // 인벤토리 접근

	//setter
	void setGold(int coin); // 골드
	void setHealth(int hp); // 체력
	void setExperience(int exp); // 경험치
	
	
	void levelUp();
	void addExperience(int amount);
	void useItem(int Index); // 아이템 사용
	void displayStatus(); // 캐릭터 스테이터스 창

private: // 멤버변수

	vector<Item*>inv;
	//레벨 공격력 초기체력 고정
	string name;
	int* P_level;
	int level;
	int HP;
	int health;
	int* P_health;
	int MaxHealth;
	int attack;
	int* P_attack;
	int gold;
	int experience;


};