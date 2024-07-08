#include "PlayerAIOoki.h"

PlayerAIOoki::PlayerAIOoki()
{
	player = nullptr;
}

PlayerAIOoki::~PlayerAIOoki()
{
}

void PlayerAIOoki::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIOoki::Update()
{
	player->Input(VGet(1, 0, 0));
}
