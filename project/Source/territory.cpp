#include "territory.h"
#include"config.h"

Territory::Territory()
{
	positon.x = 0;
	positon.y = 0;
	score = 0;
	number = 0;
	color = 0xff0000;
}

Territory::~Territory()
{
}

void Territory::Update()
{
}

void Territory::Draw()
{
	DrawBox(positon.x, positon.y, positon.x + TERRITORY_SIZE_X, positon.y + TERRITORY_SIZE_Y, color, false);


	DrawFormatString(positon.x, positon.y, 0x00ffff, "[%d]:score:%d", number, score);
}