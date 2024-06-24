#pragma once
#include "../Library/gameObject.h"

class ItemManager : public GameObject {
public:
	ItemManager();
	~ItemManager();
	void Update() override;
private:
	float timer;
};