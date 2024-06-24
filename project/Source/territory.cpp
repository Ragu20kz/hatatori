#include "territory.h"

namespace {
	static const int BOX_SIZE_X = 200;
	static const int BOX_SIZE_Y = 200;
}

Territory::Territory()
{
	positon.x = 0;
	positon.y = 0;
	score = 0;
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
	DrawFormatString(positon.x, positon.y, 0xff00ff, "score:%d", score);
}