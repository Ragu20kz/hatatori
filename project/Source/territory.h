#pragma once
#include"..//Library/gameObject.h"

class Territory :public GameObject{
public:
	Territory();
	~Territory();
	void Update()override;
	void Draw()override;

	const VECTOR GetConterPos();

	VECTOR positon;
	int color;
	int score;
	int number;
};