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
	/// アイテムを再配置する
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

	bool isHold;//trueなら誰かが持ち歩いている状態
	int whoseNum;//誰が持っているか、-1なら誰も持っていない
	
	bool isThrow;//trueなら投げられている状態（当たるとスタン）

	bool isTerritory;//テリトリー上にあるかどうか

	int heavy;//重さ
	int score;//点数

	VECTOR vector;
	float speed;
};
