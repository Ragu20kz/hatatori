#pragma once
#include"..//Library/gameObject.h"

class Item;

class Territory :public GameObject{
public:
	Territory();
	~Territory();
	void Update()override;
	void Draw()override;

	const VECTOR GetConterPos();

	const std::list<Item*>& GetItemList() { return itemList; }
	void AddItemList(Item* _item);
	void ResetItemList();
	
	VECTOR positon;
	int color;
	int score;
	int number;
private:
	std::list<Item*> itemList;
};