#pragma once
#include "../Library/gameObject.h"

class Item : public GameObject
{
public:
	Item();
	~Item();
	void Create(int type, const VECTOR& pos);
	void Update();
	void Draw();
	const VECTOR& Position() {
		return position;
	}

	void SetImage(int _image) { hImage = _image; }

	void SetThrow(VECTOR _vec);
	void Throw();

	const int const GetKind();
private:
	int hImage;
	int kind;
	VECTOR position;

	bool isHold;//trueなら誰かが持ち歩いている状態
	int whoseNum;//誰が持っているか、-1なら誰も持っていない
	
	bool isThrow;//trueなら投げられている状態（当たるとスタン）

	int heavy;//重さ
	int score;//点数

	//飛ばし用仮置き
	VECTOR vector;
	float speed;
	float startTime;
	float endTime;
	float startPower;
	static const int ITEM_SIZE = 32;
};
