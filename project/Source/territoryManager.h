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
	void ItemCollider(); //�A�C�e������Ă��鐔����
	void DebugGUI(); //�f�o�b�O�p��GUI�������Ƃ�
	const VECTOR GetPosition(int _num); //�w�n���W
	const int GetScore(int _num); //���̃X�R�A
	const int GetItem(int _num); //����Ă���A�C�e����
private:
	std::vector <Territory*> territory;
};