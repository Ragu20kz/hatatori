#include "PlayerAI.h"
#include "ItemManager.h"

PlayerAI::PlayerAI()
{
	player = nullptr;
	item   = nullptr;
}

PlayerAI::~PlayerAI()
{
}

void PlayerAI::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAI::Start()
{
	item = FindGameObject<ItemManager>();
}

void PlayerAI::Update()
{
	//player->Input(VGet(1, 0, 0));
}
