#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class PlayerAITsukumo : public GameObject {
public:
	PlayerAITsukumo();
	~PlayerAITsukumo();
	void SetPlayer(Player* inst);
	void Update();

private:
	Player* player;

};
