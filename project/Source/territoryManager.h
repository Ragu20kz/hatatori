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
	void ItemCollider(); //アイテム乗っている数判定
	void DebugGUI(); //デバッグ用のGUIを書いとく
	const int const GetScore(int _num); //今のスコア
	const int const GetItem(int _num); //乗っているアイテム数
	const VECTOR const GetPosition(int _num); //陣地座標
private:
	std::vector <Territory*> territory;
};