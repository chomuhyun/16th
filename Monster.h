#pragma once 
#include <iostream> 
#include <string> 
#include <vector> 
#include "Player.h" 
using namespace std; 

class Monster { 
public: 
	// 몬스터 상태 (이름 통일) 
	string m_name; 
	int m_hp; 
	int m_atk; 
	int m_lv; 
	
	Monster(string n, int h, int a) 
		: m_name(n), m_hp(h), m_atk(a), m_lv(1) { } 
	virtual ~Monster() {} 
	
	// getter (이름 유지 + 레벨 추가) 
	const string& getName() const noexcept { return m_name; } 
	int getHP() const noexcept { return m_hp; } 
	int getATK() const noexcept { return m_atk; } 
	int getLV() const noexcept { return m_lv; } 
	
	// 공통 동작 
	virtual void roar() { cout << m_name << ": xxx!" << endl; } 
	virtual int attack() { return m_atk; } 
	
	// 전투 관련 
	virtual void takeDamage(int dmg); 
	bool isMDead() const; 
	bool getMIsDead() const; 
	
	void show() { 
		cout << "[ " << getName() << " ] " << "LV:" << getLV() << " HP:" << getHP() << " /ATK:" << getATK() << endl;
	} 
}; 

// 파생 몬스터들 (m_lv 설정 추가) 
class Goblin : public Monster { 
public: 
	Goblin(int lv) : Monster("Goblin", 10 + lv * 1, 1 + lv) { m_lv = lv; } 
	void roar() override { cout << "Goblin: 끼익!" << endl;} 
}; 
class Orc : public Monster { 
public: 
	Orc(int lv) : Monster("Orc", 20 + lv * 2, 2 + lv) { m_lv = lv; } 
	void roar() override { cout << "Orc: 취익!" << endl; } 
}; 
class Troll : public Monster { 
public: 
	Troll(int lv) : Monster("Troll", 30 + lv * 3, 3 + lv) { m_lv = lv; } 
	void roar() override { cout << "Troll: 쿠워어!" << endl; }
}; 
class Slime : public Monster { 
public: 
	Slime(int lv) : Monster("Slime", 40 + lv * 4, 4 + lv) { m_lv = lv; } 
	void roar() override { cout << "Slime: 탱글" << endl; } 
};

// === 턴제 전투 유틸 (전역 선언) ===
//index: 0=Goblin, 1=Orc, 2=Troll, 3=Slime 
Monster* SpawnByIndex(int index, int level); 

// 플레이어 쪽 변수명 통일: hp/atk/lv 
bool TurnBattle(int& getHealth, int getAttack, int getLevel);
bool TurnBattleFromPlayer(Player& p);