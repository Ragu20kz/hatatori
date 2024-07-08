#include "PlayerAI.h"
#include "ItemManager.h"
#include "Item.h"

PlayerAI::PlayerAI()
{
	player = nullptr;
	item   = nullptr;

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
	


	//player->Input(VGet(1, 0, 0));
}

void PlayerAI::CloseItem()
{
	auto itemList    = item->GetItemList();
	Item* selectItem = itemList.front(); //list‚Ì“ª‚ðŽæ“¾
	auto itr         = itemList.begin();
	float lenge      = VSquareSize(selectItem->Position() - player->Position());

	for (itr++; itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		float len     = VSquareSize(nowItem->Position() - player->Position());
		//‹——£”äŠr
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
}
