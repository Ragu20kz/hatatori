#include "PlayerAIItou.h"
#include "ItemManager.h"
#include "Item.h"
PlayerAIItou::PlayerAIItou()
{
	player = nullptr;
	itemM = FindGameObject<ItemManager>();
	move = VGet(-1, 0, 0);
	itemDist = 0;
}

PlayerAIItou::~PlayerAIItou()
{
}

void PlayerAIItou::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIItou::Update()
{
	SearchNearItem();
	player->Input(move);
	if (player->Position().x > player->TerritoryPos().x
		&& player->Position().y > player->TerritoryPos().y) {
		player->RandItemPut();

	}
	
}

void PlayerAIItou::SearchNearItem()
{
	VECTOR nearPos = player->TerritoryPos();
	nearPos += VGet(75, 100, 0);
	float nearSize = 1000.0f;
	for (auto& item : itemM->GetItemList()) {
		if (item->IsHold()) {
			continue;
		}
		if (item->IsThrow()) {
			continue;
		}
		if (VSize(item->Position() - nearPos) < 75) {
			continue;
		}
		if (nearSize > VSize(item->Position() - player->Position())) {
			nearSize = VSize(item->Position() - player->Position());
			nearPos = item->Position();
		}
	}
	itemDist = VSize(nearPos - player->Position());
	move = VNorm(nearPos - player->Position());
}

void PlayerAIItou::BackHome()
{
	if(itemDist<40){
		return;
	}
	if (player->GetWeight() < 2) {
		return;
	}

	move = VNorm(player->TerritoryPos() - player->Position());

}
