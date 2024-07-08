#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class ItemManager;

enum class PLAYER_INFO {
	DEFAULT = 0,    //通常時
	FILDE_ITEM,     //フィールドのアイテムを取りに行く
	TERRITOTY_ITEM, //相手のアイテムを取りに行く
	BACK,           //自分のテリトリーに戻る
	THROW,          //相手を投げる
};

class PlayerAI : public GameObject {
public:
	PlayerAI();
	~PlayerAI();
	void SetPlayer(Player* inst);
	void Start() override;
	void Update() override;
private:
	Player* player;
	ItemManager* item;

	PLAYER_INFO info;

	VECTOR nextPos;

	void DefaultUpdate();
	void Filde_ItemUpdate();
	void Territoty_ItemUpdate();
	void BackUpdate();
	void ThrowUpdate();

	void CloseItem();
};