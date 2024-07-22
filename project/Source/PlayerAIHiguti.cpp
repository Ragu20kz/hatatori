#include "PlayerAIHiguti.h"
#include"ItemManager.h"
#include"Item.h"
#include"territoryManager.h"
#include"config.h"

#include"debugScreen.h"

namespace {
	static const float ITEM_DISTANCE_NORM = 250.0f;
}

PlayerAIHiguti::PlayerAIHiguti()
{
	player	= nullptr;
	item	= nullptr;
	state	= STATE::IDLE;
	target	= VGet(0, 0, 0);
	move	= VGet(0, 0, 0);
	notItem = false;
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
		Attack();
		break;
	case PlayerAIHiguti::STATE::GOAL:
		Goal();
		break;
	default:
		break;
	}
	player->Input(move);
}

void PlayerAIHiguti::Search()
{
	ItemManager* itemM = FindGameObject<ItemManager>();
	VECTOR pPos = player->Position();
	float dis = 10000;
	notItem = true;
	for (auto it : itemM->GetItemList()) {
		if (!it->IsHold()) {
			notItem = false;
		}
		VECTOR iPos = it->Position();
		if (IsItem(iPos)) {
			continue;
		}
		if (it->IsThrow()) {
			continue;
		}
		if (it->IsHold() && it->GetHavPlayer() == player) {
			continue;
		}
		if (!notItem) {
			if (it->IsHold() && it->GetHavPlayer() != player) {
				continue;
			}
		}
		
		if (dis > VSize(VSub(pPos, iPos))) {
			dis = VSize(VSub(pPos, iPos)); 
			item = it;
			target = iPos;
		}
	}

	if (item != nullptr) {
		state = STATE::CATCH;
	}
}

void PlayerAIHiguti::Catch()
{
	VECTOR sub = target - player->Position();
	move = VScale(VNorm(sub), VSize(sub) / 10);

	if (item->IsHold() && item->GetHavPlayer() != player) {
		if (notItem) {
			state = STATE::GOAL;
		}
		else {
			state = STATE::SEARCH;
		}
		
	}

	if (item->IsHold() && item->GetHavPlayer() == player) {
		Search();
		float dis = VSize(VSub(player->Position(), target));
		if (dis > ITEM_DISTANCE_NORM) {
			if (notItem) {
				state = STATE::GOAL;
			}
			else {
				state = STATE::CATCH;
			}
		}
		else {
			state = STATE::GOAL;
		}
	}

}

void PlayerAIHiguti::Goal()
{
	VECTOR boxPos = player->TerritoryPos();
	VECTOR pPos   = player->Position();
	VECTOR boxCenter = VGet(boxPos.x + TERRITORY_SIZE_X / 2, boxPos.y + TERRITORY_SIZE_Y / 2 ,0);

	VECTOR sub = boxCenter - pPos;
	move = VScale(VNorm(sub), VSize(sub) / 10);

	if (pPos.x  < boxPos.x + TERRITORY_SIZE_X && pPos.x + 32 > boxPos.x &&
		pPos.y  < boxPos.y + TERRITORY_SIZE_Y && pPos.y + 32 > boxPos.y + TERRITORY_SIZE_Y/2) {
		player->ItemPut();
		state = STATE::SEARCH;
	}
}

void PlayerAIHiguti::Attack()
{
	//player->ItemThrow(target);
	target = VECTOR();
	state = STATE::SEARCH;
}

bool PlayerAIHiguti::IsItem(VECTOR _pos)
{
	VECTOR boxPos = player->TerritoryPos();
	if (_pos.x  < boxPos.x + TERRITORY_SIZE_X && _pos.x + 32 > boxPos.x &&
		_pos.y  < boxPos.y + TERRITORY_SIZE_Y && _pos.y + 32 > boxPos.y) {
		return true;
	}
	return false;
}

void PlayerAIHiguti::Walk()
{
	float speed = 5.0f;
	VECTOR pPos = player->Position();
	if (pPos.x < WALL_SIZE) {
		move = VGet(speed, -speed, 0);
	}
	if (pPos.x + 32 > SCREEN_WIDTH - WALL_SIZE) {
		move = VGet(-speed, speed, 0);
	}
	if (pPos.y < WALL_SIZE) {
		move = VGet(speed, speed, 0);
	}
	if (pPos.y + 32 > SCREEN_HEIGHT - WALL_SIZE) {
		move = VGet(-speed, -speed, 0);
	}
}