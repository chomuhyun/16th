#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Monster {
public:
    string m_name;
    int m_hp; // 보기 쉽게 앞에다가 m을 붙여서 m.hp  m.atk 로 하는게 좋으련지....
    int m_atk;

    Monster(string n, int h, int a) : m_name(n), m_hp(h), m_atk(a) {}
    virtual ~Monster() {} // 다음 몬스터 소환시 오류 발생을 막기 위한 초기화

    const string& getName() const noexcept { return m_name; } // 상태비변경 (const), & - 레퍼런스 참조
    int getHP()  const noexcept { return m_hp; }  // noexcept - 예외처리 안함 (이런 소규모 작업에 메모리 오버같은 오류를 걱정할 필요가 있을지?)
    int getATK() const noexcept { return m_atk; }  // int는 값이 작아 레퍼런스 처리 하지않고 그냥 복사(필수인지는 모르겠음)

    virtual void roar() { cout << m_name << ": xxx!" << endl; }
    virtual int  attack() { return m_atk; }

    virtual void takeDamage(int dmg);
    bool isMDead() const;
    bool getIsDead() const;

    void show() {
        cout << "[ " << getName() << " ] HP:" << getHP() << " /ATK:" << getATK() << endl;
    } // 자식클래스에서 선언된것이 없으니 자동실행
};

class Goblin : public Monster {
public:
    Goblin(int lv) : Monster("Goblin", 10 + lv * 1, 1 + lv) {}
    void roar() override { cout << "Goblin: 끼익!" << endl; }
};

class Orc : public Monster {
public:
    Orc(int lv) : Monster("Orc", 20 + lv * 2, 2 + lv) {}
    void roar() override { cout << "Orc: 취익!" << endl; }
};

class Troll : public Monster {
public:
    Troll(int lv) : Monster("Troll", 30 + lv * 3, 3 + lv) {}
    void roar() override { cout << "Troll: 쿠워어!" << endl; }
};

class Slime : public Monster {
public:
    Slime(int lv) : Monster("Slime", 40 + lv * 4, 4 + lv) {}
    void roar() override { cout << "Slime: 탱글" << endl; }
};

// lv은 캐릭터의 lv, 플레이어에서 받아와야함. 근데 이 처리가 필요한건지는 모르겠음
// 구글링에서는..... 권장하던데 굳이? 몬스터의 다양성을 캐릭터의 레벨에 의존하는 방식인거 같은데,
// 몬스터의 레벨을 랜덤 부여하면 너무 강하거나 너무 약한 경우가 경우가 게임을 방해하게 되어 플레이어 레벨에 귀속시키는듯
// 플레이어의 레벨에 따라서, 알맞는 몬스터 레벨이 정해지는 규칙을 세우려면 너무 귀찮아 져서 그냥 플레이어의 레벨로 정해버리는듯
// lv. player = lv, monster 처리하는건 그냥 플레이어 레벨로 몬스터의 스텟을 정하는것과 동일하니 무의미




// 여기부터, 전투


//승리의 경우 - 

bool isMDead() const { return m_hp = 0; }      // 판정 함수 // 
bool getMIsDead() const { return isMDead(); }  // get 스타일 래퍼


// === 턴제 전투 유틸 (선언) ===
// index: 0=Goblin, 1=Orc, 2=Troll, 3=Slime
Monster* SpawnByIndex(int index, int level);

// 전투 한 판 진행(플레이어 HP는 전투에 따라 변하므로, 참조로 전달)
void TurnBattle(int& getHealth, int getAttack, int getLevel);