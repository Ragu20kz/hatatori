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
	int picY;
	VECTOR input;
	int score;
	int type;
};