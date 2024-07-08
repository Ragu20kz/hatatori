#pragma once
#include"..//Library/gameObject.h"

class Territory :public GameObject{
public:
	Territory();
	~Territory();
	void Update()override;
	void Draw()override;

	VECTOR positon; //座標
	int color; //色
	int score; //スコア(アイテム乗ってる数)
	int number; //何番の陣地か
};