#pragma once
#include "../Library/gameObject.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void SetChara(int id);
	VECTOR Position() {
		return position;
	}
	void Input(VECTOR dir);
private:
	VECTOR position;
	int hImage;			
	VECTOR input;
	int score;
	int type;

	float speedBuff;	//スピード倍率、デフォルトは1.0f
	int weightMax;		//重さ上限、これ以上増えると遅くなるよ
	float stanTime;		//スタン時間
	int stanInvalid;	//スタン無効回数、複数個保持する可能性があるためとりあえずint
};