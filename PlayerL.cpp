//효정
#include <iostream>
#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

#include <cstdlib> //rand 사용
#include <ctime> // time 사용


using namespace std;


vector<Item>inv; //인벤토리 클래스를 사용하는 벡터배열 (player.h에 추가 요청)


//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

Player::Player(string name):name(name),
	level(1),
	health(200), 
	attack(30), 
	experience(0),
	inv(){} // 이따 복습 


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


bool r = false; // player.h 추가 변수 랜덤 함수 사용시 필요

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


// 캐릭터가 아이템을 사용했을때 아이템이 부여하는 속성에 따라 스텟이 변해야함 - 병관,효정	
void Player::ChangeStatus(const Item& item)
{
	void Player::Random(int random);
	if (health <= MaxHealth * 0.4)
	{

	}

	//아이템을 찾아서 지움, 아이템 속성에따라 스탯변경 / 아이템사용(체력이 40 % 이하) 50%
	if (inv.size() > 0)
	{
		for (int i = 0; i < inv.size(); i++) 
		{
			if (inv[i].getName() == Item.getName) // 대기
			{
				inv.erase(inv.begin() + i);
			}
		}
		
	}
	
}


void HealthPotion::use(player: Player*)

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
