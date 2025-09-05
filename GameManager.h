#pragma once
#include <memory>

class GameManager
{
public:
	GameManager();
	~GameManager();

	void generateMonster();
	void battle();

	void generateBossMonster(){}

	void selectAction(){}

	void visitShop(){}

	void displayInventory(){}


private:
	Player player;
	unique_ptr<Monster> nearbyMonster;
};
