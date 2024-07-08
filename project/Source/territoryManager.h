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
	void SetTerritory(VECTOR _pos,int _num);
	void ItemCollider(); //�A�C�e������Ă��鐔����
	void DebugGUI(); //�f�o�b�O�p��GUI�������Ƃ�
private:
	std::vector <Territory*> territory;
};