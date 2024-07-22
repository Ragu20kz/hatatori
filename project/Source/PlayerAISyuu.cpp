#include "PlayerAISyuu.h"
#include "ItemManager.h"
#include "Item.h"
#include "territoryManager.h"

PlayerAISyuu::PlayerAISyuu()
{
    player = nullptr;
    item = FindGameObject<ItemManager>();
    territoryManager = FindGameObject<TerritoryManager>();
    move = VGet(0, 0, 0);
    targetItem = nullptr;
    state = COLLECTING_ITEM; // 初期状態はアイテム収集中
}

PlayerAISyuu::~PlayerAISyuu()
{
}

void PlayerAISyuu::SetPlayer(Player* inst)
{
    player = inst;
}

void PlayerAISyuu::Update()
{
    if (!player || !item || !territoryManager)
    {
        return;
    }

    switch (state)
    {
    case COLLECTING_ITEM:

        if (targetItem)
        {
            move = VNorm(targetItem->Position() - player->Position());

            if (VSize(player->Position() - targetItem->Position()) < ITEM_SIZE)
            {
                player->ItemHit();
                state = RETURNING_TO_BASE;
            }
        }
        NearItem();
        break;

    case RETURNING_TO_BASE:
        move = VNorm(player->TerritoryPos() - player->Position());
        if (VSize(player->Position() - player->TerritoryPos()) < PLAYER_SIZE)
        {
            player->ItemPut();
            state = COLLECTING_ITEM;
        }
        break;

    default:
        break;
    }

    player->Input(move);
}

void PlayerAISyuu::NearItem()
{
    if (!targetItem || targetItem->IsHold() || targetItem->IsThrow())
    {
        VECTOR territoryPos = player->TerritoryPos();
        float nearSize = FLT_MAX;
        for (auto& item : item->GetItemList())
        {
            if (item->IsHold())
            {
                continue;
            }
            if (item->IsThrow())
            {
                continue;
            }
            float dist = VSize(item->Position() - territoryPos);
            if (nearSize > dist)
            {
                nearSize = dist;
                targetItem = item;
            }
        }
    }
}