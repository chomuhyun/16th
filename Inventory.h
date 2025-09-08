#pragma once
#include <string>


class Player; // 전방 선언

class Item //추상클래스
{
public:
	virtual ~Item() {} // 가상 소멸자
	virtual std::string getName() = 0; // 순수 가상함수,아이템 이름 꺼내는 함수 (자식클래스에서 구현)
	virtual void use(Player& player) = 0; //순수 가상함수, 포션 사용 함수 (자식클래스에서 구현)
	virtual int gainItem() = 0; // 아이템 갯수 +1 (상점 구입, 전투중 드랍)
	virtual int lossItem() = 0; // 아이템 갯수 -1(상점 판매, 아이템 사용)
};

class HealthPotion : public Item {
private:
	std::string name; // 아이템 이름 (ex: 빨간 포션)
	int healthRestore; // 회복량 (ex: 체력+50)
	int numberofHealthPotion = 0; // 회복포션 개수 
public:
	HealthPotion(std::string n, int Restore); //생성자: 이름(n), 회복량(Restore)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

class AttackBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 파워 부스트)
	int attackIncrease; // 증가량 (ex: 공격력+10)
	int numberofAttackBoost =0; // 공격 부스트 개수
public:
	AttackBoost(std::string n, int Increase); //생성자: 이름(n), 증가량(Increase)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

class ExperienceBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 경험치 부스트)
	int experienceIncrease; // 증가량 (ex: 경험치+20)
	int numberofExperienceBoost =0; // 경험치 부스트 개수
public:
	ExperienceBoost(std::string n, int Increase); //생성자: 이름(n), 증가량(Increase)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

// 인벤토리 클래스 추가하기
class Inventory
{
	Inventory();
	~Inventory() {};
};
void PrintCurrentItemAndGold(); // 현재 아이템 개수 및 골드 출력 선언

//게임 자체의 시뮬레이션이 돌아가야함
//* 전투에서 승리했다면 골드를 얻고 확률적으로 아이템을 습득함 - 수정,효정,다훈,병관
//* 몬스터는 죽었다로 판정이 되면 확률에 따라 상점에서 판매하는 아이템을 드랍할 수 있어야 함 - 다훈, 병관
//* 상점에 아이템은 언제든지 늘어날수 있고, 아이템에 객체를 언제든지 생성시킬수있어야한다 - 병관, 승원
//* 케릭터가 아이템을 사용했을때 아이템이 부여하는 속성에 따라 스텟이 변해야함 - 병관,효정,수정 --> (0)