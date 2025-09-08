#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Shop
{
public:
	string shopitemname;
	int shopitemprice;

	void buyitem() {};
	void sellitem() {};
	void displayitem() {};
private:
	vector<Item> ShopList;

};
