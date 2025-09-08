#pragma once
#include <memory>
#include "Shop.h"
class Shop;

class GameManager
{
public:
	GameManager() {}
	~GameManager() {}

	void GameStart();

	void selectAction();

	void visitShop();

	void displayInventory();

	void generateMonster();

	void battle();

	void generateBossMonster();
private:
	
	Player player;
	Shop shop;
	//unique_ptr<Monster> nearbyMonster;
};
