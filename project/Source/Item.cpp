#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage = LoadGraph("data/textures/item.png");
	kind = rand() % 5;
	position = VGet(rand() % (SCREEN_WIDTH - 32), rand() % (SCREEN_HEIGHT - 32), 0);
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
	DrawRectGraph(position.x, position.y, kind * 36 + 2, 2, 32, 32, hImage, TRUE);
}
