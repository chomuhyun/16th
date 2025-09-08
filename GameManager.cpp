#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Shop.h" //헤더가 필요한 상황
#include <memory>
#include <vector>
#include "GameManager.h"
#include "Inventory.h"

using namespace std;

Inventory inventory;

void GameManager::GameStart()
{
	string nickname;
	cout << "=======================================\n" << endl;
	cout << "16조 전사의 모험에 오신것을 환영합니다!\n" << endl;
	cout << "=======================================\n" << endl;
	cout << "\n" << endl;
	cout << "케릭터 생성을 위해 이름을 입력해주세요!\n" << endl;
	cin >> nickname;
	cout << "\n" << endl;
	cout << "케릭터 이름 : " << nickname << endl;
	cout << "=======================================\n" << endl;
	cout << "환영합니다!" << nickname << "님!\n 원하는 선택지를 고르세요 !" << endl;
	cout << "=======================================\n" << endl;
	system("cls");
	selectAction();
}
   
void GameManager::selectAction() 
{
	int selectaction;
	int selectPotion;
	cout << "==============원하시는 선택지를 골라주세요==============\n" << endl;
	cout << "전투 - 1.\n 상점 - 2.\n 가방 확인 - 3.\n 스텟 관리 - 4.\n" << endl;
	cin >> selectaction;
	switch (selectaction)
	{
	case 1:
		system("cls");
		battle();
		break;
	case 2:
		system("cls");
		visitShop();
		break;
	case 3:
		system("cls");
		displayInventory();
	case 4:
		system("cls");
		cout << "==============원하시는 선택지를 골라주세요==============\n" << endl;
		cout << "체력 포션 - 1.\n 공격력 증가 포션 - 2.\n 경험치 포션 - 3.\n 나가기 - 0.\n" << endl;
		player.useItem(selectPotion);
	default:
		break;
	}
}

void GameManager::visitShop()
{
	system("cls");
	//상점으로 넘어왔고 물품리스트 를 불러오고 이름과 가격을 출력해야함
	//출력창에서 구매, 판매 로 넘어가야 되고 구매 판매기능이 끝나면 인벤토리 확인 및 상점 나가기가 되어야함
}

void GameManager::displayInventory()
{
	cout << "============Inventory=============\n" << endl;
	player.Getinv();
	cout << "============Inventory=============\n" << endl;
	cout << "\n" << endl;
	cout << "나가기 - 3.\n" << endl;
	int displayinv; //키보드 i 를 눌럿을때로 하고 싶지만 일단 숫자로...
	cin >> displayinv;
	if (displayinv == 3)
	{
		system("cls");
		selectAction();
	}

	//인벤토리창을 닫는 기능이 필요함 창을 닫으면 전투를 할지 상점을 갈지 선택할수있어야함 
	// i 버튼을 누르면 인벤토리 창이 뜰수 있게해야하는데 인벤토리 배열과,
	// 그 아이템을 나열하는 출력창이 필요함
}

void GameManager::generateMonster()
{
	system("cls");
	nearbyMonster = unique_ptr<Monster>();
	cout << "몬스터 : " << nearbyMonster->getName() << "가(이) 나타났습니다!" << endl;
}

void GameManager::battle()
{
	system("cls");
}

void GameManager::generateBossMonster()
{

}