#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"

using namespace std;
//전투에서 승리한 골드로 상점에서 아이템을 구매할 수 있어야되고 구매한 아이템은 인벤토리에 보관되어야함.
//상점에서 아이템은 단일,다수의 갯수를 구매할 수 있어야함
//캐릭터가 가지고있는 아이템을 상점에 판매할수있어야하고 일정 퍼센테이지만큼 판매되어야함
//상점에 판매되고있는 아이템에 목록을 띄우는 창을 만들어야함

/*
1.구매 buy
1 - 1. 상품목록 보여주기.   shoplist
1 - 2. 한개 혹은 다수 구매 가능   반복문
1 - 3. 구매와 동시에 수량에 비례해서 골드가 소멸되어야함   반복문+연산자
2.판매 sell
2 - 1. 한개 혹은 다수 판매 가능   sellitem
2 - 2. 판매와 동시에 인벤토리에서 소멸되어야함   ~inventory
2 - 3. 소멸되고 일정량의 돈을 받음  ~inventory , getGold

- --

1. 상품목록 출력(물건 이름과 ID와 가격 출력)
2. 유저에게 구매할 상품에대한 입력을 받음. (입력)
3. 플레이어가 소지한 골드를 확인하고 모자르면 취소
4. 골드를 다시 확인하고 물건 가격보다 높으면 소지 골드 - 물건
5. 플레이어 인벤토리에 구매한 물건이 들어감
*/

Item* item = new HealthPotion();
Player player;
Inventory inventory;

class Shop
{
public:

    void buyitem()  //플레이어가 가지고있는 인벤토리 배열에 아이템 추가 , 플레이어가 가지고있는 gold라는 변수에서 itemprice라는 변수를 빼준다
    {
        int MXI = 10;
        int Buy = 0;
        int g;
        g = player.getGold();
        g -= ItemPrice;
        vector<Item*>inv;                   // 캐릭터 인벤토리 배열 없음.
        inv.push_back(itemname_);
        cout << "몇개를 구매하시겠습니까?" << endl;
        cin >> Buy;
        for (int Buy; Buy <= MXI;)
        {
            g -= ItemPrice * Buy;
        }
        
    }

    void sellitem()
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
                getGold += int(ItemPrice * Sell) * 0.6
            }
        }

    }

    void displayitems()
    {

        vector<inv*> ShopList{ new HealthPotion( name , 10 ), new AttackBoost( name , 5 ), new Shop};
        pitems_
        cout << "= = = 상점 물품 목록 = = =" << endl;
        cout << "[이름 : " << (itemname_) << ", 가격 " << (ItemPrice) << "G]" << endl;
    }

};



/*
2. **상점 시스템**
 1번.
-전투가 끝나면 “상점을 방문하시겠습니까 ? (Y / N)” 물어보기

 2번.
- 상점에서는 골드로 아이템을 구매 / 판매 가능(아이템 목록은 자유롭게!) ..
- 플레이어는 골드를 사용해서 아이템을 구매
- 구매 아이템은 인벤토리에 즉시 추가
- 플레이어는 보유한 아이템을 골드로 판매 * *(판매 가격은 구입 원가의 60 % !) * *
- 판매된 아이템은 인벤토리에서 즉시 제거 - 2번

 3번.
- “체력 물약 10 Gold”, “공격력 강화 15 Gold”처럼 가격을 정해놓기!
- 구매 즉시 인벤토리에 들어오며, 판매 시 아이템이 소멸되고 골드 획득! - 3번

 4번.
- 즉, 상점 시스템을 추가한다는 것은 곧 인벤토리도 있어야겠네요 ?
- 캐릭터 클래스의 멤버 변수를 참고해보세요! - 4번

//////////////////////////////////////////////////////////////////////////////////

 1번.
- 전투가 끝나고 상점을 방문하시겠습니까 - bool isBettleFinish = true ?

 2번.
- 플레이어 골드 - PlayerGold 물품 구매&판매 - Additem , RemoveItem
- 물품 출력 - void ??
- 인벤토리 - 상점을 열었을때 Inventory를 불러옴.

 3번.
- 체력물약, 허브, 공격력강화, 방어력강화
- 구매 - inv(플레이어 골드 -= 아이템 가격 )
- 판매 - inv(플레이어 골드 += 0.6아이템가격*플레이어골드)

 4번.
- Inventory? Character?
*/