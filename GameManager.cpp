#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Shop.h" //헤더가 필요한 상황
#include <memory>
#include <vector>
#include "GameManager.h"
using namespace std;
   
void GameManager::selectAction() 
{
	int selectaction;
	cout << "==============Battle or Shop================" << endl;
	cout << "전투 - 1.\n 상점 - 2.\n " << endl;
	cin >> selectaction;
	switch (selectaction)
	{
	case 1:
		battle();
		break;
	case 2:
		visitShop();
		break;
	default:
		break;
	}
}

void GameManager::visitShop()
{
	cout << "상점에 입장 하시겠습니까? Y/1 N/2\n " << endl;
	// 상점에 입장할것인지 입력 받은 후에 상점페이지로 넘어갈수 있는 함수필요
	// 만약 상점에 입장하는 입력값을 받았다면 함수호출
	// 그렇지 않다면 다시 전투를 할지 상점을 갈지 선택하는 함수 필요
}

void GameManager::displayInventory()
{
	int displayinv; //키보드 i 를 눌럿을때로 하고 싶지만 일단 숫자로...
	cin >> displayinv;
	switch (displayinv)
	{
	case 5:
		cout << "============Inventory=============\n" << endl;
		cout << /*현재 플레이어가 가지고 있는 아이템 배열을 불러와야댐*/ << endl;
		cout << "============Inventory=============\n" << endl;
		break;
	case 6:
		selectAction();
	default:
		break;
	}

	//인벤토리창을 닫는 기능이 필요함 창을 닫으면 전투를 할지 상점을 갈지 선택할수있어야함 

	// i 버튼을 누르면 인벤토리 창이 뜰수 있게해야하는데 인벤토리 배열과,
	// 그 아이템을 나열하는 출력창이 필요함
}

void GameManager::generateMonster()
{
	
	nearbyMonster = unique_ptr<Monster>();
	cout << "몬스터 : " << nearbyMonster->getName() << "가(이) 나타났습니다!" << endl;
}

void GameManager::battle()
{

}

void GameManager::generateBossMonster()
{

}