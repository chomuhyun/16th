//효정
#include <iostream>
#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "GameManager.h"


//vector<Item*>inv; //추상클래스는 포인터 사용해야함 (player.h에 변경 요청)
GameManager gamemanager;

//필요한거
// 닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리

Player::Player(std::string name)
	: name(name), level(1), health(200), attack(30), experience(0),inv()
{}



//레벨 체력 공격력 경험치 포인터

//닉네임 골드 레벨 체력 MAX체력 공격 경험치 인벤토리
void Player::displayStatus()
{
	std::cout << " * Character status * " << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "닉네임 : " << name << std::endl;
	std::cout << "Level : " << level << std::endl;
	std::cout << "HP : " << health << std::endl;
	std::cout << "공격력 : " << attack << std::endl;
	std::cout << "경험치 : " << experience << std::endl;
	std::cout << "골드 : " << gold << std::endl;
	std::cout << "======================" << std::endl;

}

//Setter 함수
void Player::setAttack(int atk) // 공격
{
	attack = atk;
}

void Player::setGold(int coin)
{
	gold = coin;
}
	

void Player::setHealth(int hp)
{
	health = hp;
}

//
//void Player::setExperience(int exp)
//{
//	experience = exp;
//}


//아이템 사용 번호 선택 1.HP 2.공격력강화 3. 경험치 강화
void Player::useItem()
{
	int index;
	std::cin >> index;

	if (index < 0 || index >= inv.size())  // 인덱스 값이 0보다 작거나 인덱스 크기보다 큰경우 함수 종료
	{
		std::cout << "잘못된 인덱스 입니다."<< std::endl;
		return;
	}

	Item* item = inv[index];
	// vector<Item*>inv  안에있는 객체를 가리키는 포인터 선언
	//dynamic_cast로 item이 내가 원하는 자식 클래스가 맞는지 확인,아니라면 nullptr

	if (HealthPotion* hpPotion = dynamic_cast<HealthPotion*>(item))
	{
		hpPotion->use(*this); 
		hpPotion->lossItem();
		std::cout << hpPotion->getName() << "사용!"<< std::endl;
	}
	else if (AttackBoost* atkboost = dynamic_cast<AttackBoost*>(item))
	{
		atkboost->use(*this); 
		atkboost->lossItem();
		std::cout << atkboost->getName() << "사용!"<< std::endl;
	}
	else if (ExperienceBoost* expboost = dynamic_cast<ExperienceBoost*>(item))
	{
		expboost->use(*this); 
		expboost->lossItem();
		std::cout << expboost->getName() << "사용!"<< std::endl;
	}
	else
	{
		std::cout << "사용할수 있는 아이템이 없습니다." << std::endl;
		return;
	}

	//메모리 처리 (공통) 벡터 제거 + 메모리 해제
	delete inv[index];
	inv.erase(inv.begin() + (index - 1)); //인덱스는 0 번부터 시작
	
}




// 케릭터 생성 및 아이디 설정 - 효정 ok
//캐릭터 닉네임 입력

//void Player::selectNickname(string nickname)
//{
//	re:
//	std::cout << " * Character 닉네임을 입력해주세요 : ";
//	cin >> nickname;
//
//	if (nickname == " ")
//	{
//		std::cout << " * Character의 닉네임은 공백이 될 수없습니다. 다시 입력해주세요";
//		goto re;
//	}
//	else
//	{
//		name = nickname;
//	}
//	
//}
