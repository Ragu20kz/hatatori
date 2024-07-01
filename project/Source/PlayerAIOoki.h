#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class PlayerAIOoki : public GameObject {
public:
	PlayerAIOoki();
	~PlayerAIOoki();
	void SetPlayer(Player* inst);
	void Update();
private:
	Player* player;
};