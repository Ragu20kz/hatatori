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
private:
	int hImage;
	int kind;
	VECTOR position;

	bool isHold;//true�Ȃ�N�������������Ă�����
	int whoseNum;//�N�������Ă��邩�A-1�Ȃ�N�������Ă��Ȃ�
	
	bool isThrow;//true�Ȃ瓊�����Ă����ԁi������ƃX�^���j

	int heavy;//�d��
	int score;//�_��
};
