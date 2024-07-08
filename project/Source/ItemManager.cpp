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
}

void ItemManager::Draw()
{
	for (auto& i : itemList) {
		i->Draw();
	}
}

void ItemManager::Create()
{
	if (--timer <= 0) {
		timer = 120;
		Item* item = new Item();
		itemList.emplace_back(item);
	}
}
