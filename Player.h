#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Player
{
public: // 멤버함수

	void levelUp();

	void useItem(int index); // 아이템 사용

	void displayStatus(); // 캐릭터 스테이터스 창

private: // 멤버변수

	//레벨 공격력 초기체력 고정
	string name;
	int level;
	int health;
	int MaxHealth;
	int attack;
	int experience;
	int gold;

	vector<Item*>inventory;


};