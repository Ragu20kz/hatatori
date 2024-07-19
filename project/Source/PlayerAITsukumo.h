#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include "territory.h"

class PlayerAITsukumo : public GameObject {
public:
	PlayerAITsukumo();
	~PlayerAITsukumo();
	void SetPlayer(Player* inst);
	void Update();

private:
	Player* player;
	Territory* territory;

	enum class STATE {
		STOP,
		PLAY,
		GO,
		HOME,
		END,
	};
	STATE state;

	void GetItemMove(); 
	void GoingHomeMove();

};
