#pragma once
#include <string>

/*
*아이템 및 골드 관리 * *
-전투에서 이기면 골드를 얻고, 가끔(30 % 확률) 아이템이 떨어집니다. ------> 수정, 효정
- 아이템은 * *체력 + 50 * *또는 * *공격력 + 10 * *을 해주는 멋진 효과!
- 전투 중에는 "이럴 때 아이템!" 하고 랜덤하게 사용됩니다. (디테일은 자유롭게!) ------> 다훈
- 아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영됩니다. ------> 수정, 효정
*/

class Item //추상클래스
{
public:
	virtual ~Item() {} // 가상 소멸자
	virtual std::string getName() = 0; // 순수 가상함수,아이템 이름 꺼내는 함수 (자식클래스에서 구현)
	virtual void use(player: Player*) = 0; //순수 가상함수, 포션 사용 함수 (자식클래스에서 구현)
};

class HealthPotion : public Item {
private:
	std::string name; // 아이템 이름 (ex: 빨간 포션)
	int healthRestore; // 회복량 (ex: 체력+50)
public:
	HealthPotion(std::string n, int Restore); //생성자: 이름(n), 회복량(Restore)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(player: Player*) override; //부모클래스(포션 사용) 받아와 구현
};

class AttackBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 파워 포션)
	int attackIncrease; // 증가량 (ex: 공격력+10)
public:
	AttackBoost(std::string n, int Increase); //생성자: 이름(n), 증가량(Increase)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(player: Player*) override; //부모클래스(포션 사용) 받아와 구현
};

// 인벤토리 클래스 추가하기
class Inventory
{
	Inventory();
	~Inventory() {};
};
