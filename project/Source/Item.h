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
	/// <summary>
	/// �A�C�e�����Ĕz�u����
	/// </summary>
	void SetRandomPosition(); 

	void SetImage(int _image) { hImage = _image; }
	void SetIsHold(bool _set) { isHold = _set; }
	void SetPosition(const VECTOR& pos) { position = pos; }

	const bool IsThrow()const { return isThrow; }
	const bool IsHold()const { return isHold; }
	const int GetHeavy()const { return heavy; }
	const int GetScore()const { return score; }


	void SetThrow(VECTOR _vec);
	void Throw();

	void SetHold(bool _set) { isHold = _set; }
	bool IsHold() { return isHold; }

	bool IsThrow() { return isThrow; }

	int GetScore() { return score; }

	int GetKind() { return kind; }
private:
	int hImage;
	int kind;
	VECTOR position;

	bool isHold;//true�Ȃ�N�������������Ă�����
	int whoseNum;//�N�������Ă��邩�A-1�Ȃ�N�������Ă��Ȃ�
	
	bool isThrow;//true�Ȃ瓊�����Ă����ԁi������ƃX�^���j

	int heavy;//�d��
	int score;//�_��

	VECTOR vector;
	float speed;
};
