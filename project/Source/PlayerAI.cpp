#include "PlayerAI.h"
#include "ItemManager.h"
#include "Item.h"

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
}

void PlayerAI::Filde_ItemUpdate()
{
	//BACKに入る
}

void PlayerAI::Territoty_ItemUpdate()
{
	//BACKに入る
}

void PlayerAI::BackUpdate()
{
	//DEFAULTに入る
}

void PlayerAI::ThrowUpdate()
{
	//アイテムがあればBACKに入る
	//なければDEFAULTに入る
}

void PlayerAI::CloseItem()
{
	auto itemList    = item->GetItemList();
	Item* selectItem = itemList.front(); //listの頭を取得
	auto itr         = itemList.begin();
	float lenge      = VSquareSize(selectItem->Position() - player->Position());

	for (itr++; itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		float len     = VSquareSize(nowItem->Position() - player->Position());
		//距離比較
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
}
