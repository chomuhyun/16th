#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Monster {
    string name;
    int hp; // 보기 쉽게 앞에다가 m을 붙여서 m.hp  m.atk 로 하는게 좋으련지....
    int atk;

    Monster(string n, int h, int a) : name(n), hp(h), atk(a) {}
    virtual ~Monster() {} // 다음 몬스터 소환시 오류 발생을 막기 위한 초기화

    const string& getName() const noexcept { return name; } // 상태비변경 (const), & - 레퍼런스 참조
    int getHP()  const noexcept { return hp; }  // noexcept - 예외처리 안함 (이런 소규모 작업에 메모리 오버같은 오류를 걱정할 필요가 있을지?)
    int getATK() const noexcept { return atk; }  // int는 값이 작아 레퍼런스 처리 하지않고 그냥 복사(필수인지는 모르겠음)

    virtual void roar() { cout << name << ": xxx!" << endl; }
    virtual int  attack() { return atk; }

    virtual void takeDamage(int dmg) {
        if (dmg < 0) dmg = 0; // 오류 방지
        hp -= dmg;
        if (hp < 0) hp = 0; // dmg는 플레이어의 공격력으로, 외부에서 받아와야함, 아마도 main에서 처리?
    }

    bool isDead() { return hp <= 0; }

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