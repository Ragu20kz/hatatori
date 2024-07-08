#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class ItemManager;

class PlayerAIItou : public GameObject {
public:
	PlayerAIItou();
	~PlayerAIItou();
	void SetPlayer(Player* inst);
	void Update();
private:
	void SearchNearItem();

	Player* player;
	ItemManager* itemM;

	VECTOR move;
};