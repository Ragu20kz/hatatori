#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class ItemManager;

class PlayerAI : public GameObject {
public:
	PlayerAI();
	~PlayerAI();
	void SetPlayer(Player* inst);
	void Start() override;
	void Update() override;
private:
	Player* player;
	ItemManager* item;

};