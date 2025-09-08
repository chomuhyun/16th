#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Shop
{
public:
	string shopitemname; //아이템 이름
	int shopitemprice; //아이템 가격

	void buyitem() {}; //아이템 구매
	void sellitem() {}; //아이템 판매
	void displayitem() {}; //아이템 출력
private:
	vector<Item> ShopList;

};
