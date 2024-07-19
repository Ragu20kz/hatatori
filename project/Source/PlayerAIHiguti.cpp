#include "PlayerAIHiguti.h"
#include"ItemManager.h"
#include"Item.h"
#include"territoryManager.h"
#include"config.h"

#include"debugScreen.h"

namespace {
	static const float ITEM_DISTANCE_NORM = 150.0f;
}

PlayerAIHiguti::PlayerAIHiguti()
{
	player = nullptr;
	item = nullptr;
	state = STATE::IDLE;
	
}

PlayerAIHiguti::~PlayerAIHiguti()
{
}

void PlayerAIHiguti::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIHiguti::Update()
{
	//player->Input(VGet(0, 0, 0));

	switch (state)
	{
	case PlayerAIHiguti::STATE::IDLE:
		state = STATE::SEARCH;
		break;
	case PlayerAIHiguti::STATE::SEARCH:
		Search();
		break;
	case PlayerAIHiguti::STATE::CATCH:
		Catch();
		break;
	case PlayerAIHiguti::STATE::ATTACK:
		player->Input(VGet(0, 0, 0));
		break;
	case PlayerAIHiguti::STATE::GOAL:
		Goal();
		break;
	default:
		break;
	}

	DebugPrintf(15, 430, "state:%d", state);
}

void PlayerAIHiguti::Search()
{
	ItemManager* itemM = FindGameObject<ItemManager>();
	VECTOR pPos = player->Position();
	float dis = 1500;

	for (auto it : itemM->GetItemList()) {
		VECTOR iPos = it->Position();

		if (IsItem(iPos)) {
			continue;
		}
		if (it->IsHold()) {
			continue;
		}
		if (dis > VSize(VSub(pPos, iPos))) {
			dis = VSize(VSub(pPos, iPos)); 
			item = it;
			target = iPos;
		}
	}
	state = STATE::CATCH;
}

void PlayerAIHiguti::Catch()
{
	VECTOR sub = target - player->Position();
	VECTOR move = VScale(VNorm(sub), VSize(sub) / 10);
	player->Input(move);
	
	if (item->IsHold()) {
		Search();
		if (VSize(VSub(player->Position(), target)) < ITEM_DISTANCE_NORM) {
			state = STATE::CATCH;
		}
		else {
			state = STATE::GOAL;
		}
	}

	float dis = VSize(VSub(player->Position(), target));
}

void PlayerAIHiguti::Attack()
{
}

void PlayerAIHiguti::Goal()
{
	TerritoryManager* terM = FindGameObject<TerritoryManager>();
	VECTOR sub = terM->GetPosition(0) - player->Position();
	VECTOR move = VScale(VNorm(sub), VSize(sub) / 10);
	player->Input(move);

	if (VSize(VSub(player->Position(), terM->GetPosition(0))) < 5.0f) {
		//player->ItemThrow();
		state = STATE::SEARCH;
	}
}

bool PlayerAIHiguti::IsItem(VECTOR _pos)
{
	TerritoryManager* terM = FindGameObject<TerritoryManager>();

	VECTOR boxPos = terM->GetPosition(0);
	if (_pos.x  < boxPos.x + TERRITORY_SIZE_X && _pos.x + 32 > boxPos.x &&
		_pos.y < boxPos.y + TERRITORY_SIZE_Y && _pos.y + 32 > boxPos.y) {
		return true;
	}
	return false;
}
