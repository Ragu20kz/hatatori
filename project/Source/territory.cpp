#include "territory.h"
#include"config.h"

Territory::Territory()
{
	positon.x = 0;
	positon.y = 0;
	score     = 0;
	number    = 0;
	color     = 0xff0000;
	itemList.clear();
}

Territory::~Territory()
{
	itemList.clear();
}

void Territory::Update()
{
}

void Territory::Draw()
{
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
	DrawBox((int)positon.x, (int)positon.y, (int)(positon.x + TERRITORY_SIZE_X), (int)(positon.y + TERRITORY_SIZE_Y), color, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatString((int)positon.x, (int)positon.y, 0x00ffff, "[%d]:score:%d", number, score);
	DrawFormatString((int)positon.x, (int)(positon.y + 30), 0x00ffff, "[%d]:ŠŽ”:%d", number, itemList.size());
}

const VECTOR Territory::GetConterPos()
{
	return (positon + VGet((float)(TERRITORY_SIZE_X / 2), (float)(TERRITORY_SIZE_Y / 2), 0.0f));
}

void Territory::AddItemList(Item* _item)
{
	itemList.emplace_back(_item);
}

void Territory::ResetItemList()
{
	itemList.clear();
}

bool Territory::IsInside(const VECTOR& _pos, const VECTOR& _size)
{
	if (positon.x + TERRITORY_SIZE_X > _pos.x && positon.x < _pos.x + _size.x &&
		positon.y + TERRITORY_SIZE_Y > _pos.y && positon.y < _pos.y + _size.y) {
		return true;
	}
	return false;
}
