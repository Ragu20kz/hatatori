#include "territory.h"
#include"config.h"

Territory::Territory()
{
	positon.x = 0;
	positon.y = 0;
	score     = 0;
	number    = 0;
	color     = 0xff0000;
	haveItem  = 0;
}

Territory::~Territory()
{
}

void Territory::Update()
{
}

void Territory::Draw()
{
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
	DrawBox(positon.x, positon.y, positon.x + TERRITORY_SIZE_X, positon.y + TERRITORY_SIZE_Y, color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatString(positon.x, positon.y, 0x00ffff, "[%d]:score:%d", number, score);
	DrawFormatString(positon.x, positon.y + 30, 0x00ffff, "[%d]:èäéùêî:%d", number, haveItem);
}

const VECTOR Territory::GetConterPos()
{
	return (positon + VGet((float)(TERRITORY_SIZE_X / 2), (float)(TERRITORY_SIZE_Y / 2), 0.0f));
}
