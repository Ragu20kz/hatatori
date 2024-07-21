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
	Item* selectItem = itemList.front(); //listの頭を取得
	auto itr         = itemList.begin();
	float lenge      = VSquareSize(selectItem->Position() - _pos);

	for (itr++; itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		float len     = VSquareSize(nowItem->Position() - _pos);
		//距離比較
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
	//一番近いアイテム
	return selectItem;
}

Item* ItemManager::GetFieldCloseItem(const VECTOR& _pos)
{
	Item* selectItem = nullptr; 
	float lenge      = 0.0f;

	for (auto itr = itemList.begin(); itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		if (nowItem->IsHold() || nowItem->IsTerritory() || nowItem->IsThrow()) {
			continue;
		}

		if (selectItem == nullptr) {
			selectItem = nowItem;
			lenge      = VSquareSize(nowItem->Position() - _pos);
			continue;
		}

		float len = VSquareSize(nowItem->Position() - _pos);
		//距離比較
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
	//一番近いアイテム
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
