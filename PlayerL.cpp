//효정
#include <iostream>
#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

#include <cstdlib> //rand 사용
#include <ctime> // time 사용


using namespace std;


vector<Item*>inv; //추상클래스는 포인터 사용해야함 (player.h에 변경 요청)


//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

Player::player(string name):name(name),
	level(1),
	health(200), 
	attack(30), 
	experience(0),
	inv()
{} // 이따 복습 


//레벨 체력 공격력 경험치 포인터

//닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리
void Player::displayStatus()
{
	cout << " * Character status * " << endl;
	cout << "======================" << endl;
	cout << "닉네임 : " << name << endl;
	cout << "Level : " << level << endl;
	cout << "HP : " << health << endl;
	cout << "공격력 : " << attack << endl;
	cout << "경험치 : " << experience << endl;
	cout << "골드 : " << gold << endl;
	cout << "======================" << endl;

}

// 전투
// bool battle = false - 기본 전투 승리여부 (상의 해야함)
// 전투에서 승리했다면 골드를 얻고 확률적으로 아이템을 습득함 - 효정,다훈,병관

int Player::battle(bool battle) //일반 몬스터전투 승리시 경험치 + 50 / 골드 10~20 전투..
{
	cout << "전투에서 승리했습니다 ! " << endl;
	cout << " * 획득 보상 * " << endl;
	cout << name << "가" << experience + 50 << "EXP와" << gold + 12 << "골드를 획득 했습니다.";
	cout << "현재 EXP : " << experience << "/100, 골드 : " << gold << endl;
	
	
}


bool random = false; // player.h 추가 변수 랜덤 함수 사용시 필요

//srand(static_cast<unsigned int>(time(0)));  -> 메인 cpp에 추가 해야함
void Player::Random(int random) // 입력 받을 값 (확률)
{
	int randomValue = rand() % 100 + 1;
	if (randomValue <= random)
	{
		r = true;
	}
	else
	{
		r = false;
	}
}


//아이템 사용 번호 선택 1.HP
void Player::useItem() //입력받은값에 클래스를 가지고온확률이 큼
{
	int index;
	cin >> index;

	if (index < 0 || index > inv.size()) return; // 인덱스 값이 0보다 작거나 인덱스 크기보다 큰경우 함수 종료
	{
		inv[index]->use(*this); // inv[인덱스]를 가리키는 포인터, 해당객체의 use() 함수 호출,*this로 플레이어에게 해당 객체 전달
		inv.erase(inv.begin() + index); // 시작 지점 + 인덱스 번호 위치 제거 
	}

	// 입력받은 아이템 사용한 아이템 - > 인벤토리에서 찾아서 지우기 
	//아이템 현재상황만 출력

	switch (index) //inv 안에있는 객체 
	{
	case 1: 
		HealthPotion * hpPotion = dynamic_cast<HealthPotion*>(inv[index]);
		if (hpPotion) {
			hpPotion->use(*this);       // HP 회복
			cout << hpPotion->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
			// 접근가능한 함수 불러와서 -= 1;
		break;

	case 2:
		AttackBoost * attackboost = dynamic_cast<AttackBoost*>(inv[index]);
		if (attackboost) {
			attackboost->use(*this);       // HP 회복
			cout << attackboost->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
			// 접근가능한 함수 불러와서 -= 1;

		break;

	case 3:
		ExperienceBoost * experienceboost = dynamic_cast<ExperienceBoost*>(inv[index]);
		if (experienceboost) {
			experienceboost->use(*this);       // HP 회복
			cout << experienceboost->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
			// 접근가능한 함수 불러와서 -= 1;
		break;

	default:
		cout << "잘못된 입력입니다. 숫자를 다시 입력해주세요 " << endl;
			
		break;
	}
}

	//아이템 갯수 계산식 필요함 


// 캐릭터가 아이템을 사용했을때 아이템이 부여하는 속성에 따라 스텟이 변해야함 - 병관,효정	
void Player::ChangeStatus(const Item& item)
{
	if (health <= MaxHealth * 0.4) // 현재 체력이 40% 이하일때 50% 확률로 아이템 사용
	{
		Random(50) //useItem() 함수 호출 
	}

	
		

// 인벤토리 내의 아이템을 사용하면 그에 따른 스탯이 증가해야함 - 효정


// 케릭터 생성 및 아이디 설정 - 효정 ok
//캐릭터 닉네임 입력

void Player::selectNickname(string nickname)
{
	re:
	cout << " * Character 닉네임을 입력해주세요 : ";
	cin >> nickname;

	if (nickname == " ")
	{
		cout << " * Character의 닉네임은 공백이 될 수없습니다. 다시 입력해주세요";
		goto re;
	}
	else
	{
		name = nickname;
	}
	
}
