#include <iostream>
#include "Monster.h"
#include "Player.h"
#include <memory>
#include <vector>
using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void generateMonster();
	void battle();


	int generateBossMonster()
	{

	}

	void visitShop()
	{

	}

	void displayInventory()
	{

	}

private:
	Player player;
	unique_ptr<Monster> nearbyMonster;
};

void GameManager::generateMonster()
{
	nearbyMonster = unique_ptr<Monster>();
	cout << "¸ó½ºÅÍ : " << nearbyMonster->getName() << "°¡(ÀÌ) ³ªÅ¸³µ½À´Ï´Ù!" << endl;
}

void GameManager::battle()
{

}

GameManager::GameManager() : player("Hero", 1, 200, 30, 0)
{

}


GameManager::~GameManager()
{
}

// ½Â¿ø´Ô ¹Ùº¸ !!!~~~