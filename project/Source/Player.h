#pragma once
#include "../Library/gameObject.h"

class ItemManager;
class Item;
class Territory;

namespace {
	static const int PLAYER_SIZE = 32;
}

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void SetChara(int id);
	void SetPos(const VECTOR& _pos) { position = _pos; }

	const VECTOR& Position()              { return position; }
	const VECTOR GetCenterPos();
	const VECTOR& TerritoryPos()          { return territoryPos; }
	const VECTOR& GetInput()              { return input; }
	bool IsStun()                         { return nowStun; }
	const std::list<Item*>& GetItemList() { return itemList; }
	const int& GetType()                  { return type; }

	const int GetScore();

	void Input(VECTOR dir);

	/// <summary>
	/// speedBuffを変更する
	/// </summary>
	void SetSpeed();

	/// <summary>
	/// アイテムにあたった時の処理
	/// </summary>
	void ItemHit();

	/// <summary>
	/// アイテムを投げる処理
	/// </summary>
	void ItemThrow(const VECTOR& _vec);

	/// <summary>
	/// アイテムを散らばらせる処理
	/// </summary>
	void ItemScatter();

	/// <summary>
	/// アイテムを置く処理
	/// </summary>
	void ItemPut();

	/// <summary>
	/// アイテムを置く処理
	/// </summary>
	void RandItemPut();

	Territory* GetTerritory() { return territory; }
private:
	Territory* territory;
	ItemManager* itemManager;
	std::list<Item*> itemList;

	VECTOR territoryPos;
	VECTOR position;
	int hImage;			
	VECTOR input;
	int score;
	int type;

	float speedBuff;	//スピード倍率、デフォルトは1.0f
	int weightMax;		//重さ上限、これ以上増えると遅くなるよ
	int weight;			//現在の重さ
	float stunTime;		//スタン時間
	bool nowStun;		//今スタンしているか、していればtrue
};