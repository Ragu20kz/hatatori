#pragma once
#include "../Library/gameObject.h"
#include "Player.h"

class ItemManager;
class Item;

enum class PLAYER_INFO {
	DEFAULT = 0,    //�ʏ펞
	FILDE_ITEM,     //�t�B�[���h�̃A�C�e�������ɍs��
	TERRITOTY_ITEM, //����̃A�C�e�������ɍs��
	BACK,           //�����̃e���g���[�ɖ߂�
	THROW,          //����𓊂���
};

class PlayerAIOoki : public GameObject {
public:
	PlayerAIOoki();
	~PlayerAIOoki();
	void SetPlayer(Player* inst);
	void Start() override;
	void Update() override;
private:
	Player* player;
	ItemManager* item;
	Item* targetItem;
	Player* targetPlayer;

	PLAYER_INFO info;

	VECTOR nextPos;

	void DefaultUpdate();
	void Filde_ItemUpdate();
	void Territoty_ItemUpdate();
	void BackUpdate();
	void ThrowUpdate();

	void Navigation();

	void CloseItem();
};