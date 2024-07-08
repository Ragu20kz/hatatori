#include "PlayerAIItou.h"

PlayerAIItou::PlayerAIItou()
{
	player = nullptr;
}

PlayerAIItou::~PlayerAIItou()
{
}

void PlayerAIItou::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIItou::Update()
{
	player->Input(VGet(1, 0, 0));
}
