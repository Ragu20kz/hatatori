#pragma once
#include"..//Library/gameObject.h"

class Territory :public GameObject{
public:
	Territory();
	~Territory();
	void Update()override;
	void Draw()override;

	VECTOR positon; //���W
	int color; //�F
	int score; //�X�R�A(�A�C�e������Ă鐔)
	int number; //���Ԃ̐w�n��
};