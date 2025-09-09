#pragma once
#include <memory>
#include "Shop.h"

class GameManager
{
public:
	GameManager() : player(), shop(player) {}
	~GameManager() {}
	
	string nickname;
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
