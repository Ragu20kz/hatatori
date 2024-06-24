#pragma once
#include"..//Library/gameObject.h"

class Territory :public GameObject{
public:
	Territory();
	~Territory();
	void Update()override;
	void Draw()override;

	VECTOR positon;
	int color;
};