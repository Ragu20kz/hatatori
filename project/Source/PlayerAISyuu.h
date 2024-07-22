#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include "territory.h"
#include "territoryManager.h"
#include "ItemManager.h"
#include "../Library/gameObject.h"


class Item;
class TerritoryManager;

class PlayerAISyuu : public GameObject
{
public:
    PlayerAISyuu();
    ~PlayerAISyuu();
    void SetPlayer(Player* inst);
    void Update();

private:
    Player* player;
    ItemManager* item;
    TerritoryManager* territoryManager;
    Item* targetItem;
    VECTOR move;
    void NearItem();

    enum State
    {
        COLLECTING_ITEM,
        RETURNING_TO_BASE
    } state;
};