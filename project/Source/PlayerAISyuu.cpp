#include "PlayerAISyuu.h"

PlayerAISyuu::PlayerAISyuu()
{
	player = nullptr;
}

PlayerAISyuu::~PlayerAISyuu()
{
}

void PlayerAISyuu::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAISyuu::Update()
{
	player->Input(VGet(1, 0, 0));
}
