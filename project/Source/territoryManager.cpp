#include "territoryManager.h"
#include"territory.h"
#include"config.h"

TerritoryManager::TerritoryManager()
{
	for (int i = 0; i < 5; i++)
	{
		Territory*t =  new Territory();
		territory.emplace_back(t);
	}
}

TerritoryManager::~TerritoryManager()
{
}

void TerritoryManager::Update()
{
}

void TerritoryManager::Draw()
{
	for (int i = 0; i < territory.size(); i++){
		territory[i]->Draw();
	}
}

void TerritoryManager::SetTerritory(VECTOR _pos, int _num)
{
	territory[_num]->positon = _pos;
	territory[_num]->number = _num;

	switch (_num)
	{
	case 0:
		territory[_num]->color = COLOR_RED;
		break;
	case 1:
		territory[_num]->color = COLOR_BLUE;
		break;
	case 2:
		territory[_num]->color = COLOR_GREEN;
		break;
	case 3:
		territory[_num]->color = COLOR_PURPLE;
		break;
	case 4:
		territory[_num]->color = COLOR_YELLOW;
		break;
	}
}
