#include "territoryManager.h"
#include"territory.h"

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
}
