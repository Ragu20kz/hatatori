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

	bool IsInside(const VECTOR& _pos, const VECTOR& _size);
	
	VECTOR positon;
	int color;
	int score;
	int number;
private:
	std::list<Item*> itemList;
};