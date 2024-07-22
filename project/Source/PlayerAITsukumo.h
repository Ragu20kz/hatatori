#pragma once
#include "../Library/gameObject.h"
#include "Player.h"
#include "territory.h"
#include "ItemManager.h"
#include "territoryManager.h"

class Item;
class TerritoryManager;

class PlayerAITsukumo : public GameObject {
public:
	PlayerAITsukumo();
	~PlayerAITsukumo();
	void SetPlayer(Player* inst);
	void Update();

private:
	Player* player;
	TerritoryManager* territory;
	ItemManager* itemManager;
	ItemManager* item;

	enum class STATE {
		STOP,
		PLAY,
		GO,
		HOME,
		END,
	};
	STATE state;

	float angle;

	void GetItemMove(); 
	void GoingHomeMove();

	bool CollisionDetectionPlayer(VECTOR _player, VECTOR _num, int _size);

};
