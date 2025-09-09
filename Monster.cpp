#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"
#include "Inventory.h"

void Monster::takeDamage(int dmg) { if (dmg < 0) dmg = 0; m_hp -= dmg; if (m_hp < 0) m_hp = 0; }
bool Monster::isMDead() const { return m_hp <= 0; }
bool Monster::getIsDead() const { return isMDead(); }

Monster* SpawnByIndex(int index, int level) {
    int i = index % 4;
    if (i < 0) i += 4;
    switch (i) {
    case 0: return new Goblin(level);
    case 1: return new Orc(level);
    case 2: return new Troll(level);
    default: return new Slime(level);
    }
}
 
void TurnBattle(int& getHealth, int getAttack, int getLevel) {
    Monster* mon = SpawnByIndex((getHealth + getAttack) % 4, getLevel);

    std::cout << "\n=== 야생의 " << mon->getName() << " 이(가) 나타났다! ===" << std::endl;
    mon->show();

    bool playerTurn = true; // 플레이어 선공

    while (getHealth > 0 && !mon->isMDead()) {
        if (playerTurn) {
            std::cout << "[플레이어 턴] 공격! 피해 " << getAttack << std::endl;
            mon->takeDamage(getAttack);
        }
        else {
            int dmg = mon->attack();
            if (dmg < 0) dmg = 0;
            getHealth -= dmg; if (getHealth < 0) getHealth = 0;
            std::cout << "[몬스터 턴] " << mon->getName()
                << " 의 공격! 플레이어가 " << dmg << " 피해" << std::endl;
        }

        std::cout << "상태 | 플레이어 HP=" << getHealth
            << " | " << mon->getName() << " HP=" << mon->getHP() << std::endl;

        playerTurn = !playerTurn; // 턴 교대
    }

    if (getHealth <= 0) {
        std::cout << "패배" << std::endl;
    }
    else {
        std::cout << mon->getName() << "승리" << std::endl;
    }

    delete mon; // 동적 생성 정리
}