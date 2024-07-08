#include "territoryManager.h"
#include"territory.h"
#include"config.h"
#include"ItemManager.h"
#include"Item.h"

#include "../ImGui/imgui_impl_dxlib.hpp"

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
	for (int i = 0; i < territory.size(); i++) {
		ItemCollider();
	}
	//DebugGUI();
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

void TerritoryManager::ItemCollider()
{
	ItemManager* item = FindGameObject<ItemManager>();
	item->GetItemList();
	int score = 0;

	for (int i = 0; i < territory.size(); i++) {
		VECTOR boxPos = territory[i]->positon;
		for (auto it : item->GetItemList()) {
			VECTOR itemPos = it->Position();
			if (itemPos.x < boxPos.x + TERRITORY_SIZE_X && itemPos.x + 32 > boxPos.x &&
				itemPos.y < boxPos.y + TERRITORY_SIZE_Y && itemPos.y + 32 > boxPos.y) {
				score += 1;
			}
		}
		territory[i]->score = score;
		score = 0;
	}
}

void TerritoryManager::DebugGUI()
{
	ImGui::Begin("BOX");
	for (int i = 0; i < territory.size(); i++) {
		std::string num = std::to_string(i) + ":x";
		ImGui::SliderFloat(num.c_str(), &territory[i]->positon.x, 0, 1280);
		num = std::to_string(i) + ":y";
		ImGui::SliderFloat(num.c_str(), &territory[i]->positon.y, 0, 720);
	}
	ImGui::End();
}
