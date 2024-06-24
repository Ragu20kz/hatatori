#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage   = LoadGraph("data/textures/item.png");
	kind     = rand() % 5;
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - 32)), 0.0f);
}

Item::~Item()
{
}

void Item::Create(int type, VECTOR pos)
{
}

void Item::Update()
{
}

void Item::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, kind * 36 + 2, 2, 32, 32, hImage, TRUE);
}
