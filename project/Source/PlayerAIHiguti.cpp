#include "PlayerAIHiguti.h"

PlayerAIHiguti::PlayerAIHiguti()
{
	player = nullptr;
}

PlayerAIHiguti::~PlayerAIHiguti()
{
}

void PlayerAIHiguti::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIHiguti::Update()
{
	player->Input(VGet(1, 0, 0));
}
