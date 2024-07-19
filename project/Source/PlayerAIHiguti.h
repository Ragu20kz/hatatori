#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class Item;
class PlayerAIHiguti : public GameObject {
public:
	PlayerAIHiguti();
	~PlayerAIHiguti();
	void SetPlayer(Player* inst);
	void Update();
private:
	Player* player;
	Item* item;

	enum class STATE {
		IDLE,
		SEARCH,
		CATCH,
		ATTACK,
		GOAL,
	};
	STATE state;

	void Search();
	void Catch();
	void Attack();
	void Goal();

	bool IsItem(VECTOR _pos);
	VECTOR target;
};