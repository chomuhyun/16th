#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

class item
{
public:

void buyitem()
{
    gold -= ItemPrice;
    avaliableitems.push_back(HealthPotion);
}

void sellitem()
{
        gold += (ItemPrice * 0.6)
}

void displayitems()
{
    cout << "
}

private:
    string name_;
    int item
    vector<shop*> availableitems{ HealthPotion , AttackBoost }
}


vector<item*> inventory{}

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