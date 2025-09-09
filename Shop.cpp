#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"
#include "GameManager.h"

using namespace std;

class Item;

Player player;
GameManager gamemanager;
HealthPotion h();
AttackBoost a();
ExperienceBoost e();

int Shopmenu;

Shop::Shop(Player& p)
    : player(p)
{
    ShopList.push_back(new HealthPotion("체력 포션", 50, 1, 10));
    ShopList.push_back(new AttackBoost("공격력 증가 포션", 10, 1, 20));
    ShopList.push_back(new ExperienceBoost("경험치 증가 포션", 20, 1, 30));
}
void Shop::buyitem()
{  //플레이어가 가지고있는 인벤토리 배열에 아이템 추가 , 플레이어가 가지고있는 gold라는 변수에서 itemprice라는 변수를 빼준다
    int MXI = 10;
    int Buy = 0;
    int itemselect = 0; //아이템 선택
    int itembuy = 0; //아이템 구매 수량
    int g = player.getGold();
    std::cout << "무엇을 구매하시겠습니까?" << std::endl;
    std::cout << " 1. 체력 포션 \n 2. 공격력 강화 \n 3. 경험치 강화 \n" << std::endl;
    std::cin >> itemselect;
    switch (itemselect)
    {//어떤 아이템을 살지 선택 - 몇개를 살지 선택 - 갯수*아이템 가격 만큼 골드 차감. - 플레이어 인벤토리에 push back - break
    case 1:
    {
        std::cout << "체력 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cin >> itembuy;
        HealthPotion h("체력 포션", 50, 1 ,10);
        g -= h.gainItem() * itembuy;
        player.Getinv().push_back(new HealthPotion("체력 포션", 50, 1, 10));
        break;
    }
    case 2:
    {
        std::cout << "공격력 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cin >> itembuy;
        AttackBoost a("공격력 증가 포션", 10, 1, 20);
        g -= a.gainItem() * itembuy;
    }
    break;
    case 3:
    {
        std::cout << "경험치 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cin >> itembuy;
        ExperienceBoost e("경험치 증가 포션", 20, 1, 30);
        g -= e.gainItem() * itembuy;
        break;
    }
    default:
        std::cout << "잘못된 선택입니다. 다시 선택해주세요." << std::endl;
        break;
    }
};

void Shop::sellitem()
{

    //int MNI <= 1; // 아이템을 1개 미만으로 가지기는 불가능.
    //int Sell > 0; // 아이템을 0개 넘게 팔기는 불가능.
    //int g;
    //g = player.getGold();
    //g += (ItemPrice * 0.6);
    //vector<Item*>inv;
    //inv.erase(getName);
    //cout << "몇개를 판매하시겠습니까?" << endl;
    //cin >> Sell;
    //for (int MNI; int Sell;)
    //{
    //    if (int MNI > 0)
    //    {
    //        getGold += int(shopitemprice * Sell) * 0.6
    //    }
    //}

};
void Shop::displayitem()
{
    int Shopmenu;

    while (true)
    {
       /* cout << "\n= = = 상점 물품 목록 = = =\n";
        for (int i = 0; i < (int)ShopList.size(); ++i) {
            Item* ip = ShopList[i];
            cout << i + 1 << ". [이름: " << ip->getName()
                << ", 가격: " << ip->getPrice() << "G]\n" << endl;
        }*/

        std::cout << " 메뉴를  선택해주세요 "<< std::endl;
        std::cout << "1.포션 구매하기" << std::endl;
        std::cout << "2.포션 판매하기" << std::endl;
        std::cout << "3.포션상점 나가기" << std::endl;

        std::cin >> Shopmenu;
        switch (Shopmenu)
        {
        case 1:
            buyitem();
            break;
        case 2:
            sellitem();
            break;
        case 3:
            gamemanager.selectAction();
            break;
        default:
            std::cout << "잘못된 입력입니다." << std::endl;
            break;
        };
    };
};