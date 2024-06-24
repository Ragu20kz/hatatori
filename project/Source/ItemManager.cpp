#include "ItemManager.h"
#include "Item.h"

ItemManager::ItemManager()
{
	timer = 120;

	itemList.clear();
	for (int i = 0; i < 10; i++) {
		Item* item = new Item();
		itemList.emplace_back(item);
	}
}

ItemManager::~ItemManager()
{
	for (auto& i : itemList) {
		delete i;
	}

	itemList.clear();
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
