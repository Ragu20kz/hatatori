#include "PlayerAI.h"

PlayerAI::PlayerAI()
{
	player = nullptr;
}

PlayerAI::~PlayerAI()
{
}

void PlayerAI::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAI::Update()
{
	player->Input(VGet(1, 0, 0));
}
