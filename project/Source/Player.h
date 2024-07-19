#pragma once
#include "../Library/gameObject.h"

class ItemManager;
class Item;
class Territory;

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void SetChara(int id);
	const VECTOR& Position() {
		return position;
	}

	const VECTOR GetCenterPos();

	const VECTOR& TerritoryPos() {
		return territoryPos;
	}

	const VECTOR& GetInput() { return input; }

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
	float stanTime;		//スタン時間
	bool nowStan;		//今スタンしているか、していればtrue
};