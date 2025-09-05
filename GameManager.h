#pragma once
#include <memory>

class GameManager
{
public:
	void selectAction(){}

	void visitShop(){}

	void displayInventory(){}

	void generateMonster(){}

	void battle(){}

	void generateBossMonster(){}
private:
	Player player;
	unique_ptr<Monster> nearbyMonster;
};
