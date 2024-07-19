#pragma once
#include "../Library/gameObject.h"

namespace {
	static const int ITEM_SIZE = 32;
}

class Player;

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

	const VECTOR GetCenterPos();

	/// <summary>
	/// �A�C�e�����Ĕz�u����
	/// </summary>
	void SetRandomPosition(); 

	void SetImage(int _image) { hImage = _image; }
	void SetIsHold(bool _set) { isHold = _set; }
	void SetPosition(const VECTOR& pos) { position = pos; }

	const bool IsThrow()     const { return isThrow; }
	const bool IsHold()      const { return isHold; }
	const bool IsTerritory() const { return isTerritory; }
	const int  GetHeavy()    const { return heavy; }
	const int  GetScore()    const { return score; }
	Player*    GetHavPlayer()      { return havPlayer; }

	void SetThrow(VECTOR _vec);
	void Throw();

	void SetHold(bool _set)            { isHold      = _set; }
	void SetTerritory(bool _set)       { isTerritory = _set;}
	void SetHavPlayer(Player* _player) { havPlayer   = _player; }

	int GetKind() { return kind; }
private:
	int hImage;
	int kind;
	VECTOR position;

	Player* havPlayer;

	bool isHold;//true�Ȃ�N�������������Ă�����
	int whoseNum;//�N�������Ă��邩�A-1�Ȃ�N�������Ă��Ȃ�
	
	bool isThrow;//true�Ȃ瓊�����Ă����ԁi������ƃX�^���j

	bool isTerritory;//�e���g���[��ɂ��邩�ǂ���

	int heavy;//�d��
	int score;//�_��

	VECTOR vector;
	float speed;
};
