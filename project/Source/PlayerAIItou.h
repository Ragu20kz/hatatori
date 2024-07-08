#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class PlayerAIItou : public GameObject {
public:
	PlayerAIItou();
	~PlayerAIItou();
	void SetPlayer(Player* inst);
	void Update();
private:
	Player* player;
};