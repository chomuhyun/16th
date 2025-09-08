#pragma once
#include <string>

/*
*아이템 및 골드 관리 * *
-전투에서 이기면 골드를 얻고, 가끔(30 % 확률) 아이템이 떨어집니다. ------> 수정, 효정, 다훈
- 아이템은 * *체력 + 50 * *또는 * *공격력 + 10 * *을 해주는 멋진 효과! ------> 수정, 효정
- 전투 중에는 "이럴 때 아이템!" 하고 랜덤하게 사용됩니다. (디테일은 자유롭게!) ------> 다훈
- 아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영됩니다. ------> 수정, 효정
*/
class Player; // 전방 선언

class Item //추상클래스
{
public:
	virtual ~Item() {} // 가상 소멸자
	virtual std::string getName() = 0; // 순수 가상함수,아이템 이름 꺼내는 함수 (자식클래스에서 구현)
	virtual void use(Player& player) = 0; //순수 가상함수, 포션 사용 함수 (자식클래스에서 구현)
	virtual void gainItem() = 0; // 아이템 갯수 +1 (상점 구입, 전투중 드랍)
	virtual void lossItem() = 0; // 아이템 갯수 -1(상점 판매, 아이템 사용)
};

class HealthPotion : public Item {
private:
	std::string name; // 아이템 이름 (ex: 빨간 포션)
	int healthRestore; // 회복량 (ex: 체력+50)
	int numberofHealthPotion; // 회복포션 개수 
public:
	HealthPotion(std::string n, int Restore); //생성자: 이름(n), 회복량(Restore)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	void gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	void lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

class AttackBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 파워 부스트)
	int attackIncrease; // 증가량 (ex: 공격력+10)
	int numberofAttackBoost; // 공격 부스트 개수
public:
	AttackBoost(std::string n, int Increase); //생성자: 이름(n), 증가량(Increase)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	void gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	void lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

class ExperienceBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 경험치 부스트)
	int experienceIncrease; // 증가량 (ex: 경험치+20)
	int numberofExperienceBoost; // 경험치 부스트 개수
public:
	ExperienceBoost(std::string n, int Increase); //생성자: 이름(n), 증가량(Increase)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	void gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	void lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
};

// 인벤토리 클래스 추가하기
class Inventory
{
	Inventory();
	~Inventory() {};
};

// 전투 승리시 30% 확률로 아이템 랜덤 획득 함수 만들기
// 몬스터 처치시 확률적으로 아이템 랜덤 드랍 함수 만들기

//게임 자체의 시뮬레이션이 돌아가야함
// 케릭터 생성 및 아이디 설정 - 효정
// 케릭터가 상점을 갈지 전투를 할지 선택할수있어야함 - 무현
// 만약 전투를 선택했다면 몬스터를 생성하고 랜덤한 몬스터와 전투를함 - 다훈
//* 전투에서 승리했다면 골드를 얻고 확률적으로 아이템을 습득함 - 수정,효정,다훈,병관
// 전투에서 패배했다면 체력이 최대체력에 절반인 상대로 리젠되어야함 - 다훈, 무현
// 전투에서 승리한 골드로 상점에서 아이템을 구매 할 수 있어야 하고 구매한 아이템은 인벤토리에 보관되어야함 - 승원,효정,수정
// 인벤토리 창을 열면 보관되어있는 아이템이 전부 나열되어야함 - 무현, 수정,효정
// 인벤토리 내의 아이템을 사용하면 그에 따른 스탯이 증가해야함 - 효정,수정
// 상점에서 아이템은 단일, 다수의 갯수를 구매 할 수 있어야함 - 승원
// 케릭터가 가지고 있는 아이템을 상점에 판매를 할 수 있어야하고 판매 할땐 일정 퍼센테이지를 떼어 판매되어야함 -승원,효정,수정
// 상점에 판매되고 있는 아이템에 목록을 띄우는 창을 만들어야함 - 승원
// 케릭터 레벨에따라 몬스터의 레벨도 변동되어야함 - 다훈
// 몬스터는 케릭터로부터 받는 데미지를 계산하는 수식이 필요함 - 다훈
//* 몬스터는 죽었다로 판정이 되면 확률에 따라 상점에서 판매하는 아이템을 드랍할 수 있어야 함 - 다훈, 병관
// 전투가 진행되는동안 다수의 몬스터가 아닌 단일 몬스터만 생성되어야함 - 다훈
// 전투는 턴제 형식으로 몬스터가 공격을 받았다면 다음은 몬스터가 공격할수있어야함 - 다훈,무현
//* 상점에 아이템은 언제든지 늘어날수 있고, 아이템에 객체를 언제든지 생성시킬수있어야한다 - 병관, 승원
//* 케릭터가 아이템을 사용했을때 아이템이 부여하는 속성에 따라 스텟이 변해야함 - 병관,효정,수정 --> (0)
// 
// 위 내용 번외 - 선공을 할 수 있는 수치가 케릭터와 몬스터에게 둘다 있을수가 있음
// 보스몬스터는 아직 제외 - 일반 몬스
