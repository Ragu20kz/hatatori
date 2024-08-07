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

	Item* GetCloseItem(const VECTOR& _pos);
	Item* GetFieldCloseItem(const VECTOR& _pos);
private:
	void Create();
	int hImage;

	float timer;
	std::list<Item*> itemList;
};