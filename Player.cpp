
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "GameManager.h"
#include <string>

using namespace std;

Player::Player(std::string name)
    : name(name), level(1), health(200), MaxHealth(200), gold(100), attack(30), experience(0), inv()
{
    inv.push_back(new HealthPotion("체력 포션", 50, 1, 10));
    inv.push_back(new AttackBoost("공격력 증가 포션", 10, 1, 20));
    inv.push_back(new ExperienceBoost("경험치 증가 포션", 20, 1, 30));

}

/*std::string Player::InputName(string Name)
{
    //조건이 아니라면
    while (Name.empty())
    {
        cout << "공백은 입력할 수 없습니다. 다시 입력해주세요!" << endl;
    }
    //조건에 맞다면
    name = Name;
    return name;
}
*/

//Setter 함수
void Player::setAttack(int atk)
{
    attack = atk;
}

void Player::setGold(int coin)
{
    gold = coin;
}

void Player::setHealth(int hp)
{
    health = hp;
}

void Player::displayStatus()
{
    cout << " \n" << endl;
    cout << " ======================" << endl;
    cout << "  * Character status * " << endl;
    cout << " ======================" << endl;
    cout << " 닉네임 : " << name << endl;
    cout << " Level : " << level << endl;
    cout << " HP : " << health << endl;
    cout << " 공격력 : " << attack << endl;
    cout << " 경험치 : " << experience << endl;
    cout << " 골드 : " << gold << endl;
    cout << " ======================" << endl;
    cout << " \n" << endl;

}

void Player::levelUp() // 레벨업시 체력 풀 회복
{

    if (level >= 10)
    {
        cout << "최대 레벨입니다!" << endl;
        return;
    }
    else
    {
        level += 1;
        MaxHealth += (level * 20);  // 레벨에 20곱한 값만큼 최대체력증가
        attack += (level * 5);     // 레벨에 5곱한 값만큼 공격력증가
        health = MaxHealth;

        cout << "레벨업! 현재 레벨:" << level << endl;
    }
}

void Player::addExperience(int amount) // 경험치
{
    experience += amount;

    if (experience >= 100)
    {
        experience -= 100;
        levelUp();

        cout << "+" << amount << "경험치를 획득했습니다! 현재 경험치:" << experience << endl;
    }
}

void Player::battle()  // 전투 승리시 골드 50획득
{
    bool win = TurnBattleFromPlayer(*this); //승패 결과 bool받아옴

       if (win) 
   {
       int rewardGold = (rand() % 2 == 0) ? 10 : 20; //rand = 0 이상 임의 정수(난수) 조건 비교 참10 : 거짓20
       addExperience(50);
       gold += rewardGold;
       cout << "보상 획득! +"<< rewardGold <<"골드, +50 경험치 "<< "현재 골드" << gold << endl;
   }
      else
      {
         health = MaxHealth / 2;
         cout << " 플레이어가 사망하였습니다."<< health << " 의 체력 회복 후 마을로 귀환합니다!" << endl;
      }    
 }


void Player::useItem()
{
    int input;
    std::cin >> input;

    Item* selectedItem = nullptr;
    int index = -1;

    auto& inventory = Getinv();

    for (int i = 0; i < inventory.size(); i++)
    {
         if (input == 1 && dynamic_cast<HealthPotion*>(inventory[i])) {
             selectedItem = inventory[i];
             index = i;
             break;
         }          
        
        else if (input == 2 && dynamic_cast<AttackBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 3 && dynamic_cast<ExperienceBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 0) {
            return;
        }
    }
    
    if (selectedItem == nullptr && input != 0) {
        std::cout << "해당 아이템이 없습니다." << std::endl;
        return;
    }

    selectedItem->use(*this); //아이템 사용

    if (health >= MaxHealth && input == 1 ) //현재체력이 최대 체력보다 크고, input이 1일때
    {
        std::cout << "체력이 가득 찼습니다! 포션을 사용할 수 없습니다." << endl;
        return;
    }
    else 
    {
        selectedItem->lossItem();
    }

    if (selectedItem->getCount() <= 0) // 아이템 수량이 0보다 작을때 객체를 지운다
    {
        delete selectedItem; //동적 할당된 객체 메모리 해제
        inventory.erase(inventory.begin() + index); //인벤토리에서 제거
        return;
    }
}

