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
	DebugGUI();
}

void TerritoryManager::Draw()
{
	for (int i = 0; i < territory.size(); i++){
		territory[i]->Draw();
	}

	//DrawFormatString(0, 50, 0xffff00, "[2]score:%d ŒÂ”:%d", GetScore(2), GetItem(2));
}

Territory* TerritoryManager::SetTerritory(const VECTOR& _pos, const int& _num)
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
	return territory[_num];
}

void TerritoryManager::ItemCollider()
{
	ItemManager* item = FindGameObject<ItemManager>();

	for (int i = 0; i < territory.size(); i++) {
		territory[i]->score = 0;
		territory[i]->ResetItemList();
	}

	for (auto it : item->GetItemList()) {
		if (it->IsHold() || it->IsThrow()) {
			continue;
		}

		for (int i = 0; i < territory.size(); i++) {
			VECTOR boxPos  = territory[i]->positon;
			VECTOR itemPos = it->Position();
			if (itemPos.x < boxPos.x + TERRITORY_SIZE_X && itemPos.x + ITEM_SIZE > boxPos.x &&
				itemPos.y < boxPos.y + TERRITORY_SIZE_Y && itemPos.y + ITEM_SIZE > boxPos.y) {
				territory[i]->score += 100 * it->GetKind();
				territory[i]->AddItemList(it);
				it->SetTerritory(true);
				break;
			}
			else
				it->SetTerritory(false);
		}
	}
}

void TerritoryManager::DebugGUI()
{
	/*ImGui::Begin("BOX");
	for (int i = 0; i < territory.size(); i++) {
		std::string num = std::to_string(i) + ":x";
		ImGui::SliderFloat(num.c_str(), &territory[i]->positon.x, 0, 1280);
		num = std::to_string(i) + ":y";
		ImGui::SliderFloat(num.c_str(), &territory[i]->positon.y, 0, 720);
	}
	ImGui::End();*/
}

int const TerritoryManager::GetScore(int _num)
{
	if (territory[_num] == nullptr) {
		return 0;
	}
	return territory[_num]->score;
}

int const TerritoryManager::GetItem(int _num)
{
	if (territory[_num] == nullptr) {
		return 0;
	}
	return territory[_num]->GetItemList().size();
}

VECTOR const TerritoryManager::GetPosition(int _num)
{
	if (territory[_num] == nullptr) {
		return VGet(0,0,0);
	}
	return territory[_num]->positon;
}
