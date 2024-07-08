#include "ItemManager.h"
#include "Item.h"

ItemManager::ItemManager()
{
	timer = 120;
	hImage = LoadGraph("data/textures/item.png");

	itemList.clear();
	for (int i = 0; i < 10; i++) {
		Item* item = new Item();
		item->SetImage(hImage);
		itemList.emplace_back(item);
	}
}

ItemManager::~ItemManager()
{
	for (auto& i : itemList) {
		delete i;
	}

	itemList.clear();
	
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
}

void ItemManager::Update()
{
	for (auto& i : itemList) {
		i->Update();
	}
}

void ItemManager::Draw()
{
	for (auto& i : itemList) {
		i->Draw();
	}
}

Item* ItemManager::GetCloseItem(const VECTOR& _pos)
{
	Item* selectItem = itemList.front(); //list‚Ì“ª‚ðŽæ“¾
	auto itr         = itemList.begin();
	float lenge      = VSquareSize(selectItem->Position() - _pos);

	for (itr++; itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		float len     = VSquareSize(nowItem->Position() - _pos);
		//‹——£”äŠr
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
	//ˆê”Ô‹ß‚¢ƒAƒCƒeƒ€
	return selectItem;
}

void ItemManager::Create()
{
	if (--timer <= 0) {
		timer = 120;
		Item* item = new Item();
		itemList.emplace_back(item);
	}
}
