#pragma once
#include"..//Library/gameObject.h"
#include<vector>

class Territory;
class TerritoryManager :public GameObject {
public:
	TerritoryManager();
	~TerritoryManager();
	void Update()override;
	void Draw()override;

	Territory* SetTerritory(const VECTOR& _pos, const int& _num);
	void ItemCollider();
private:
	std::vector <Territory*> territory;
};