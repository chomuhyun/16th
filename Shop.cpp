#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"

using namespace std;

Player player;
Inventory inventory;

    void buyitem(){  //플레이어가 가지고있는 인벤토리 배열에 아이템 추가 , 플레이어가 가지고있는 gold라는 변수에서 itemprice라는 변수를 빼준다
        int MXI = 10;
        int Buy = 0;
        int itemselect = 0;
        int itembuy = 0;
        int g = player.getGold();
        std::cout << "무엇을 구매하시겠습니까?" << endl;
        std::cout << " 1. 체력 포션 \n 2. 공격력 강화 \n 3. 경험치 강화 \n" << endl;
        std::cin >> itemselect;
        switch (itemselect) {//어떤 아이템을 살지 선택 - 몇개를 살지 선택 - 갯수*아이템 가격 만큼 골드 차감. - 플레이어 인벤토리에 push back - break
        case 1: (itemselect == 1)
            std::cout << "체력 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << endl;
            std::cin >> itembuy;
            HealthPotion
            g -= numberofHealthPotion * itembuy;
                player.Getinv().push_back(new HealthPotion("체력 포션", 50));
            break;
        case 2: (itemselect == 2)
            std::cout << "공격력 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << endl;
            std::cin >> itembuy;
            g -= numberofAttackBoost * itembuy;
                break;
        case 3: (itemselect == 3)
            cout << "경험치 강화를 선택하셨습니다. 몇개 구매하시겠습니까?" << endl;
            std::cin >> itembuy;
            g -= numberofExperienceBoost * itembuy;
                break;
        default:
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            continue;
        };

        void sellitem();
        {
        int MNI <= 1; // 아이템을 1개 미만으로 가지기는 불가능.
        int Sell > 0; // 아이템을 0개 넘게 팔기는 불가능.
        int g;
        g = player.getGold();
        g += (ItemPrice * 0.6);
        vector<Item*>inv;
        inv.erase(getName);
        cout << "몇개를 판매하시겠습니까?" << endl;
        cin >> Sell;
        for (int MNI; int Sell;)
        {
            if (int MNI > 0)
            {
                getGold += int(shopitemprice * Sell) * 0.6
            }
        }

    }

    void displayitems()
    {
        vector<Item> ShopList;{ new HealthPotion( name , 10 ), new AttackBoost( name , 10 ), new ExperienceBoost( naem , 20 ) };
        cout << "= = = 상점 물품 목록 = = =" << endl;
        cout << "[이름 : " << (name) << ", 가격 " << (shopitemprice) << "G]" << endl;
    }

