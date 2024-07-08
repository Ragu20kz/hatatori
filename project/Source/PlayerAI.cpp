#include "PlayerAI.h"
#include "ItemManager.h"
#include "Item.h"
#include "territory.h"

PlayerAI::PlayerAI()
{
	player = nullptr;
	item   = nullptr;

	info = PLAYER_INFO::DEFAULT;

	nextPos = VECTOR();
}

PlayerAI::~PlayerAI()
{
}

void PlayerAI::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAI::Start()
{
	item = FindGameObject<ItemManager>();
}

void PlayerAI::Update()
{
	switch (info)
	{
	case PLAYER_INFO::DEFAULT:
		DefaultUpdate();
		break;
	case PLAYER_INFO::FILDE_ITEM:
		Filde_ItemUpdate();
		break;
	case PLAYER_INFO::TERRITOTY_ITEM:
		Territoty_ItemUpdate();
		break;
	case PLAYER_INFO::BACK:
		BackUpdate();
		break;
	case PLAYER_INFO::THROW:
		ThrowUpdate();
		break;
	}
}

void PlayerAI::DefaultUpdate()
{
	//敵が持っているアイテム数、scoreを基準に選択する
	//FILDE_ITEMorTERRITOTY_ITEMに入る

	//
}

void PlayerAI::Filde_ItemUpdate()
{
	Navigation();
	//アイテムを取ったら
	//DEFAULTに入る

	//最大数持っていたら
	//BACKに入る
}

void PlayerAI::Territoty_ItemUpdate()
{
	Navigation();
	//アイテムを取ったら
	//DEFAULTに入る

	//最大数持っていたら
	//BACKに入る
}

void PlayerAI::BackUpdate()
{
	//DEFAULTに入る
	Territory* t = player->GetTerritory();

	nextPos = t->GetConterPos();
	Navigation();
}

void PlayerAI::ThrowUpdate()
{
	//アイテムがあればBACKに入る
	//なければDEFAULTに入る
}

void PlayerAI::Navigation()
{
	player->Input(nextPos - player->Position());
}

void PlayerAI::CloseItem()
{
	Item* selectItem = item->GetCloseItem(player->Position());
}
