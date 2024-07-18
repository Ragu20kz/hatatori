#include "PlayerAIOoki.h"
#include "ItemManager.h"
#include "Item.h"
#include "territory.h"

PlayerAIOoki::PlayerAIOoki()
{
	player = nullptr;
	item = nullptr;

	info = PLAYER_INFO::DEFAULT;

	nextPos = VECTOR();
}

PlayerAIOoki::~PlayerAIOoki()
{
}

void PlayerAIOoki::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIOoki::Start()
{
	item = FindGameObject<ItemManager>();
}

void PlayerAIOoki::Update()
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

void PlayerAIOoki::DefaultUpdate()
{
	//敵が持っているアイテム数、scoreを基準に選択する
	//FILDE_ITEMorTERRITOTY_ITEMに入る

	//
}

void PlayerAIOoki::Filde_ItemUpdate()
{
	Navigation();
	//アイテムを取ったら
	//DEFAULTに入る

	//最大数持っていたら
	//BACKに入る
}

void PlayerAIOoki::Territoty_ItemUpdate()
{
	Navigation();
	//アイテムを取ったら
	//DEFAULTに入る

	//最大数持っていたら
	//BACKに入る
}

void PlayerAIOoki::BackUpdate()
{
	//DEFAULTに入る
	Territory* t = player->GetTerritory();

	nextPos = t->GetConterPos();
	Navigation();
}

void PlayerAIOoki::ThrowUpdate()
{
	//アイテムがあればBACKに入る
	//なければDEFAULTに入る
}

void PlayerAIOoki::Navigation()
{
	player->Input(nextPos - player->Position());
}

void PlayerAIOoki::CloseItem()
{
	Item* selectItem = item->GetCloseItem(player->Position());
}

