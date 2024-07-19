#include "PlayerAIItou.h"
#include "ItemManager.h"
#include "Item.h"
PlayerAIItou::PlayerAIItou()
{
	player = nullptr;
	itemM = FindGameObject<ItemManager>();
	move = VGet(-1, 0, 0);
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
		player->ItemPut();

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
	move = VNorm(nearPos - player->Position());
}
