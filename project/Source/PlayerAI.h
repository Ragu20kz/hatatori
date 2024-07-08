#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class ItemManager;

enum class PLAYER_INFO {
	DEFAULT = 0,
	FILDE_ITEM,
	TERRITOTY_ITEM,
	BACK,
	THROW,
};

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

	PLAYER_INFO info;

	VECTOR nextPos;

	void CloseItem();
};