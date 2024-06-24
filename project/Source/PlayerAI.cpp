#include "PlayerAI.h"

PlayerAI::PlayerAI()
{
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
