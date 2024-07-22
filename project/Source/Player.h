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
	/// speedBuff��ύX����
	/// </summary>
	void SetSpeed();

	/// <summary>
	/// �A�C�e���ɂ����������̏���
	/// </summary>
	void ItemHit();

	/// <summary>
	/// �A�C�e���𓊂��鏈��
	/// </summary>
	void ItemThrow(const VECTOR& _vec);

	/// <summary>
	/// �A�C�e�����U��΂点�鏈��
	/// </summary>
	void ItemScatter();

	/// <summary>
	/// �A�C�e����u������
	/// </summary>
	void ItemPut();

	/// <summary>
	/// �A�C�e����u������
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

	float speedBuff;	//�X�s�[�h�{���A�f�t�H���g��1.0f
	int weightMax;		//�d������A����ȏ㑝����ƒx���Ȃ��
	int weight;			//���݂̏d��
	float stunTime;		//�X�^������
	bool nowStun;		//���X�^�����Ă��邩�A���Ă����true
};