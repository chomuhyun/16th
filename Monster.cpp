#include <iostream>
#include <random>
#include "Monster.h"
#include "Player.h"

//몬스터 레벨 0.7~1.3 처리 랜덤함수
static int randInt(int lo, int hi) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(gen);
}

// 몬스터의 피해 계산 / 사망 판정
void Monster::takeDamage(int dmg) {
    if (dmg < 0) dmg = 0;
    m_hp -= dmg;
    if (m_hp < 0) m_hp = 0;
}
bool Monster::isMDead() const { return m_hp <= 0; }
bool Monster::getMIsDead() const { return isMDead(); }

// 몬스터 스폰 (랜덤함수를 사용하지않고, 특정값계산을 통해 값 산출
// 공식은 (캐릭터현재체력+캐릭터공격력)%4
Monster* SpawnByIndex(int index, int level) {
    int i = index % 4;
    if (i < 0) i += 4; // 음수가 나오지는 않겠지만, 안전한처리
    switch (i) {
    case 0: return new Goblin(level);
    case 1: return new Orc(level);
    case 2: return new Troll(level);
    default: return new Slime(level);
    }
}

// 플레이어 객체로부터 hp/atk/lv를 받아 전투 시작
bool TurnBattleFromPlayer(Player& p) {
    int hp = p.getHealth();
    int atk = p.getAttack();
    int lv = p.getLevel();
    
    bool win = TurnBattle(hp, atk, lv);  // ← 전투 결과
    p.setHealth(hp);                      // 전투 후 HP 반영
    return win;
}

// 턴제 전투 (플레이어 변수명: hp/atk/lv)
bool TurnBattle(int& hp, int atk, int lv) {
    // 플레이어 lv의 0.7~1.3배 정수 범위
    int minLv = (7 * lv) / 10;                if (minLv < 1) minLv = 1;
    int maxLv = (13 * lv + 9) / 10;           if (maxLv < minLv) maxLv = minLv;
    int monLv = randInt(minLv, maxLv);                                           // ← 1번에서 만든 randInt 사용 이부분은 더 공부 필요

    Monster* mon = SpawnByIndex((hp + atk) % 4, monLv);

    std::cout << "\n=== 야생의 " << mon->getName() << " 이(가) 나타났다! ===\n";
    mon->show();

    bool playerTurn = true; // 플레이어 선공

    while (hp > 0 && !mon->isMDead()) {
        if (playerTurn) {
            std::cout << "[플레이어 턴] 공격! 피해 " << atk << "\n";
            mon->takeDamage(atk);
        }
        else {
            int dmg = mon->attack();
            if (dmg < 0) dmg = 0;
            hp -= dmg; if (hp < 0) hp = 0;
            std::cout << "[몬스터 턴] " << mon->getName()
                << " 의 공격! 플레이어가 " << dmg << " 피해\n";
        }

        std::cout << "상태 | 플레이어 HP=" << hp
            << " | " << mon->getName() << " HP=" << mon->getHP() << "\n";

        playerTurn = !playerTurn;
    }

    bool win = (hp > 0);  // 루프가 끝났는데 내가 살아 있으면 = 몬스터 처치
    if (win) {
        std::cout << mon->getName() << " 승리\n";
    }
    else {
        std::cout << "패배\n";
    }

    delete mon; // 동적 할당 정리
    return win;
}