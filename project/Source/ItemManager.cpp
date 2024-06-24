#include "ItemManager.h"
#include "Item.h"

ItemManager::ItemManager()
{
	timer = 120;
	for (int i = 0; i < 10; i++) {
		Instantiate<Item>();
	}
}

ItemManager::~ItemManager()
{
}

void ItemManager::Update()
{
	std::list<Item*> items = SceneManager::CurrentScene()->FindGameObjects<Item>();
	if (items.size() >= 10)
		return;
	if (--timer <= 0) {
		timer = 120;
		Instantiate<Item>();
	}
}
