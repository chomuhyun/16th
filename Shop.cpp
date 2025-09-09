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

int Shopmenu;

Shop::Shop(Player& p)
    : player(p)
{
    ShopList.push_back(new HealthPotion("체력 포션", 50, 1, 10));
    ShopList.push_back(new AttackBoost("공격력 증가 포션", 10, 1, 20));
    ShopList.push_back(new ExperienceBoost("경험치 증가 포션", 20, 1, 30));
};

Shop::~Shop() {
    for (auto item : ShopList) delete item;
}

void Shop::buyitem()
{

    int itemselect = 0; //아이템 선택
    int itembuy = 0; //아이템 구매 수량
    std::cout << "==============================" << std::endl;
    std::cout << "II 무엇을 구매하시겠습니까? II" << std::endl;
    std::cout << "II  1. 체력 포션            II\nII  2. 공격력 강화 포션     II\nII  3. 경험치 강화 포션     II\nII  4. 뒤로 가기            II" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
    std::cout << " >>> ";
    std::cin >> itemselect; // 아이템 선택
    
    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("체력 포션", 50, 1, 10);
        std::cout << "체력 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        system("cls");
        double total = h.getPrice() * itembuy; // total = 물건 가격 * 아이템 구매 수량
        if (player.getGold() < total)
        {
            std::cout << "===========================" << std::endl;
            std::cout << "II !!골드가 부족합니다!! II" << std::endl;
            std::cout << "II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - h.getPrice() * itembuy);
            std::cout << "[남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "체력 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                HealthPotion* newPotion = new HealthPotion("체력 포션", 50, itembuy, 10);
                player.Getinv().push_back(newPotion);
            }
        }
        break;
    }
    case 2:
    {
        AttackBoost a("공격력 증가 포션", 10, 1, 20);
        std::cout << "공격력 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        double total = a.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << "===========================" << std::endl;
            std::cout << "II !!골드가 부족합니다!! II" << std::endl;
            std::cout << "II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - a.getPrice() * itembuy);
            std::cout << "[남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "공격력 증가 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                AttackBoost* newATKPotion = new AttackBoost("공격력 증가 포션", 10, itembuy, 20);
                player.Getinv().push_back(newATKPotion);
            }
        break;
        }
    }
    case 3:
    {
        ExperienceBoost e("경험치 증가 포션", 20, 1, 30);
        std::cout << "경험치 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        double total = e.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << "===========================" << std::endl;
            std::cout << "II !!골드가 부족합니다!! II" << std::endl;
            std::cout << "II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - e.getPrice() * itembuy);
            std::cout << "[남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "경험치 증가 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ExperienceBoost* newEXPPotion = new ExperienceBoost("경험치 증가 포션", 20, itembuy, 30);
                player.Getinv().push_back(newEXPPotion);
        }
        break;
        }
    }
    case 4:
    {
        system("cls");
        std::cout << "메뉴 선택으로 돌아갑니다." << endl;
        displayitem();
    }
    default:
        break;
    }
}
    
 

void Shop::sellitem()
{
    int itemselect = 0; //아이템 선택
    int itemsell = 0; //아이템 판매 수량
    std::cout << "==============================" << std::endl;
    std::cout << "II 무엇을 판매하시겠습니까? II" << std::endl;
    std::cout << "II  1. 체력 포션            II\nII  2. 공격력 강화 포션     II\nII  3. 경험치 강화 포션     II\nII  4. 뒤로 가기            II" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
    std::cout << " >>> ";
    std::cin >> itemselect;

    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("체력 포션", 50, 1, 10);
        std::cout << "체력 포션을 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << " 판매할 갯수 >>> ";
        std::cin >> itemsell; //판매할 아이템 수량
        system("cls");
        double total = ((h.getPrice() * itemsell) * 0.6);
        player.setGold(player.getGold() + total);
        std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
        for (int i = 0, erased = 0; i < player.Getinv().size() && erased < itemsell; )
        {//해당 타입의 아이템을 판매 수량만큼 삭제하는 코드
            Item* item = player.Getinv()[i];
            if (dynamic_cast<HealthPotion*>(item)) 
            {
                delete item;
                player.Getinv().erase(player.Getinv().begin() + i);
                ++erased;
            }
            else
            {
               ++i;
            }
        }
        
        break;
    }
    case 2:
    {
        AttackBoost a("공격력 증가 포션", 10, 1, 20);
        std::cout << "공격력 강화를 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << " 판매할 갯수 >>> ";
        std::cin >> itemsell;
        system("cls");
        double total = ((a.getPrice() * itemsell) * 0.6);
        player.setGold(player.getGold() + total);
        std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
        std::cout << "[남은 골드 : " << player.getGold() << "G]" << std::endl;
        for (int i = 0, erased = 0; i < player.Getinv().size() && erased < itemsell; )
        {//해당 타입의 아이템을 판매 수량만큼 삭제하는 코드
            Item* item = player.Getinv()[i];
            if (dynamic_cast<AttackBoost*>(item))
            {
                delete item;
                player.Getinv().erase(player.Getinv().begin() + i);
                ++erased;
            }
            else
            {
                ++i;
            }
        }
        break;
    }
    case 3:
    {
        ExperienceBoost e("경험치 증가 포션", 20, 1, 30);
        std::cout << "경험치 강화를 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << " 판매할 갯수 >>> ";
        std::cin >> itemsell;
        system("cls");
        double total = ((e.getPrice() * itemsell) * 0.6);
        player.setGold(player.getGold() + total);
        std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
        std::cout << "[남은 골드 : " << player.getGold() << "G]" << std::endl;
        for (int i = 0, erased = 0; i < player.Getinv().size() && erased < itemsell; )
        {
            Item* item = player.Getinv()[i];
            if (dynamic_cast<ExperienceBoost*>(item))
            {
                delete item;
                player.Getinv().erase(player.Getinv().begin() + i);
                ++erased;
            }
            else
            {
                ++i;
            }
        }
        break;
    }
    case 4:
    {
        std::cout << "메뉴 선택으로 돌아갑니다." << endl;
        system("cls");
        displayitem();
    }
    default:
        std::cout << "잘못된 선택입니다. 다시 선택해주세요." << std::endl;
        break;
    }
};
void Shop::displayitem()
{
    int Shopmenu;

    while (true)
    {
        cout << "\n=!=!=!=!=!상점 물품 목록!=!=!=!=!=\n";
        for (int i = 0; i < (int)ShopList.size(); ++i) {
            Item* ip = ShopList[i];
            cout << i + 1 << ". [이름: " << ip->getName()
                << ", 가격: " << ip->getPrice() << "G]\n" << endl;
        }
        std::cout << "[현재 골드 : " << player.getGold() << "G]" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "II 메뉴를  선택해주세요 II"<< std::endl;
        std::cout << "II   1.포션 구매하기    II" << std::endl;
        std::cout << "II   2.포션 판매하기    II" << std::endl;
        std::cout << "II   3.포션상점 나가기  II" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << " >>> ";
        std::cin >> Shopmenu;
        switch (Shopmenu)
        {
        case 1:
            system("cls");
            buyitem();
            break;
        case 2:
            system("cls");
            sellitem();
            break;
        case 3:
            return;
            std::cout << "상점을 나갑니다." << endl;
            break;
        default:
            std::cout << "잘못된 입력입니다." << std::endl;
            break;
        };
    };
};