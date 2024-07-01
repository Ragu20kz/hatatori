#pragma once
#include "../Library/gameObject.h"

class Item : public GameObject
{
public:
	Item();
	~Item();
	void Create(int type, VECTOR pos);
	void Update();
	void Draw();
	VECTOR Position() {
		return position;
	}

	void SetImage(int _image) { hImage = _image; }
private:
	int hImage;
	int kind;
	VECTOR position;
};
