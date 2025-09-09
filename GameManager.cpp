#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Shop.h" 
#include <memory>
#include <vector>
#include "GameManager.h"
#include "Inventory.h"

using namespace std;



void GameManager::GameStart()
{
	string NickName;
	cout << " =======================================\n" << endl;
	cout << " 16조 전사의 모험에 오신것을 환영합니다!\n" << endl;
	cout << " =======================================\n" << endl;
	cout << "\n" << endl;
	cout << " 케릭터 생성을 위해 이름을 입력해주세요!\n" << endl;
	cout << " >>>";
	cin >> NickName;
	player = Player(NickName);
	cout << "\n" << endl;
	cout << " 케릭터 이름 : " << player.getCharacterName() <<"\n" << endl;
	cout << " =======================================\n" << endl;
	cout << " 환영합니다! " << player.getCharacterName() << " 님! 모험이 시작됩니다 !\n" << endl;
	cout << " =======================================\n" << endl;
	selectAction();
}
   
void GameManager::selectAction() 
{
	HealthPotion hp("체력 포션",50, 1, 10);
	AttackBoost ab("공격력 증가 포션" , 50, 1, 20);
	ExperienceBoost exp("경험치 증가 포션" ,50, 1, 30);
	int selectaction;
	cout << " ==============원하시는 선택지를 골라주세요==============\n" << endl;
	cout << " 전투 - 1.\n 상점 - 2.\n 가방 확인 - 3.\n 스텟 관리 - 4.\n" << endl;
	cin >> selectaction;
	switch (selectaction)
	{
	case 1:
		system("cls");
		TurnBattle(player.getMaxHealth(),player.getAttack(),player.getLevel());
		break;
	case 2:
		system("cls");
		visitShop();
		break;
	case 3:
		system("cls");
		displayInventory();
		break;
	case 4:
	{
		system("cls");
		cout << " ==============원하시는 선택지를 골라주세요==============\n" << endl;
		cout << " 체력 포션 - 1.\n 공격력 증가 포션 - 2.\n 경험치 포션 - 3.\n 나가기 - 0.\n" << endl;
		cout << " ========================================================" << endl;
		cout << " 현재 보유 포션 목록 \n" << endl;
		Inventory inv;
		inv.PrintCurrentItemAndGold(player, hp, ab, exp);
		player.useItem();
		player.displayStatus();
		selectAction();
	}
		break;
	default:
		break;
	}
}

void GameManager::visitShop()
{
	system("cls");
	cout << " ==========상점에 오신것을 환영합니다!==========\n" << endl;
	shop.displayitem();
	system("cls");
	selectAction();
}

void GameManager::displayInventory()
{
	cout << " ============Inventory=============\n" << endl;
	auto& inv = player.Getinv();
	if (inv.empty()) 
	{
		cout << " 인벤토리가 비어 있습니다.\n" << endl;
	}
	else {
		for (size_t i = 0; i < inv.size(); ++i) {
			cout << i + 1 << ".  아이템 이름 : " << inv[i]->getName() << " \n아이템 개수 : " << inv[i]->getCount() << " 개 \n" << endl;
		}
	}
	cout << " ============Inventory=============\n" << endl;
	cout << "\n" << endl;
	cout << " 나가기 - 3.\n" << endl;
	
	int displayinv;
	cin >> displayinv;
	if (displayinv == 3)
	{
		system("cls");
		selectAction();
	}
}

void GameManager::generateMonster()
{
	system("cls");
	//nearbyMonster = unique_ptr<Monster>();
	//cout << "몬스터 : " << nearbyMonster->getName() << "가(이) 나타났습니다!" << endl;
}

void GameManager::battle()
{
	system("cls");
}

void GameManager::generateBossMonster()
{

}