#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class PlayerAISyuu : public GameObject {
public:
	PlayerAISyuu();
	~PlayerAISyuu();
	void SetPlayer(Player* inst);
	void Update();
private:
	Player* player;
};