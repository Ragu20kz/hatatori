#pragma once
#include "../Library/gameObject.h"

class Item;

class ItemManager : public GameObject {
public:
	ItemManager();
	~ItemManager();
	void Update() override;
	void Draw() override;

	const std::list<Item*>& GetItemList() { return itemList; }
private:
	float timer;
	std::list<Item*> itemList;
};