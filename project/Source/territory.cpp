#include "territory.h"

namespace {
	static const int BOX_SIZE_X = 150;
	static const int BOX_SIZE_Y = 200;
}

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
	DrawBox(positon.x, positon.y, positon.x + BOX_SIZE_X, positon.y + BOX_SIZE_Y, color, true);
	DrawFormatString(positon.x, positon.y, 0x00ffff, "[%d]:score:%d", number, score);
}