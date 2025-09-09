#pragma once
#include <memory>
#include "Shop.h"
#include "Monster.h"


class GameManager
{
public:
	GameManager(std::string nickname = "Default")
		: player(nickname), shop(player) 
	{
	}
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
	//Monster monster;
	//unique_ptr<Monster> nearbyMonster;
};
