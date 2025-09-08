//효정
#include <iostream>
#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "GameManager.h"


using namespace std;


//vector<Item*>inv; //추상클래스는 포인터 사용해야함 (player.h에 변경 요청)
GameManager gamemanager;

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

//Setter 함수
void Player::setGold(int coin)
{
	gold = coin;
}
	

void Player::setHealth(int hp)
{
	health = hp;
}


void Player::setExperience(int exp)
{
	experience = exp;
}


//아이템 사용 번호 선택 1.HP 2.공격력강화 3. 경험치 강화
void Player::useItem(int Index) //입력받은값에 클래스를 가지고온확률이 큼
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
			hpPotion->lossItem(); // 아이템 수량 -1 
			cout << hpPotion->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
			// 접근가능한 함수 불러와서 -= 1;	
		}
		break;
	case 2:
		AttackBoost * attackboost = dynamic_cast<AttackBoost*>(inv[index]);
		if (attackboost) {
			attackboost->use(*this);       // 공격력 강화
			attackboost->lossItem(); // 아이템 수량 -1 
			cout << attackboost->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
			// 접근가능한 함수 불러와서 -= 1;
		}
		break;
		
	case 3:
		ExperienceBoost * experienceboost = dynamic_cast<ExperienceBoost*>(inv[index]);
		if (experienceboost) {
			experienceboost->use(*this);       // 경험치 강화
			experienceboost->lossItem(); // 아이템 수량 -1 
			cout << experienceboost->getName() << " 사용 완료!\n";
			delete inv[index];          // 메모리 해제
			inv.erase(inv.begin() + index); // 벡터에서 제거
		}
		break;

	case 0:
		gamemanager.selectAction();
		break;

	default:
		cout << "잘못된 입력입니다. 숫자를 다시 입력해주세요 " << endl;

		break;
	
	}
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
