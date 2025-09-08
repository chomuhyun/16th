#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Player
{
public: // 멤버함수

	Player player(string name) {}

	int getGold() {

		return gold;
	}
	vector<Item*>& Getinv() { return inv; }
	void levelUp();
	void addExperience(int amount);
	void useItem(int index); // 아이템 사용

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