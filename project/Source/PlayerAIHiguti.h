#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class PlayerAIHiguti : public GameObject {
public:
	PlayerAIHiguti();
	~PlayerAIHiguti();
	void SetPlayer(Player* inst);
	void Update();
private:
	Player* player;
};