#include "PlayerAIOoki.h"
#include "ItemManager.h"
#include "Item.h"
#include "territory.h"

PlayerAIOoki::PlayerAIOoki()
{
	player = nullptr;
	item = nullptr;

	info = PLAYER_INFO::DEFAULT;

	nextPos = VECTOR();
}

PlayerAIOoki::~PlayerAIOoki()
{
}

void PlayerAIOoki::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAIOoki::Start()
{
	item = FindGameObject<ItemManager>();
}

void PlayerAIOoki::Update()
{
	switch (info)
	{
	case PLAYER_INFO::DEFAULT:
		DefaultUpdate();
		break;
	case PLAYER_INFO::FILDE_ITEM:
		Filde_ItemUpdate();
		break;
	case PLAYER_INFO::TERRITOTY_ITEM:
		Territoty_ItemUpdate();
		break;
	case PLAYER_INFO::BACK:
		BackUpdate();
		break;
	case PLAYER_INFO::THROW:
		ThrowUpdate();
		break;
	}
}

void PlayerAIOoki::DefaultUpdate()
{
	//�G�������Ă���A�C�e�����Ascore����ɑI������
	//FILDE_ITEMorTERRITOTY_ITEM�ɓ���

	//
}

void PlayerAIOoki::Filde_ItemUpdate()
{
	Navigation();
	//�A�C�e�����������
	//DEFAULT�ɓ���

	//�ő吔�����Ă�����
	//BACK�ɓ���
}

void PlayerAIOoki::Territoty_ItemUpdate()
{
	Navigation();
	//�A�C�e�����������
	//DEFAULT�ɓ���

	//�ő吔�����Ă�����
	//BACK�ɓ���
}

void PlayerAIOoki::BackUpdate()
{
	//DEFAULT�ɓ���
	Territory* t = player->GetTerritory();

	nextPos = t->GetConterPos();
	Navigation();
}

void PlayerAIOoki::ThrowUpdate()
{
	//�A�C�e���������BACK�ɓ���
	//�Ȃ����DEFAULT�ɓ���
}

void PlayerAIOoki::Navigation()
{
	player->Input(nextPos - player->Position());
}

void PlayerAIOoki::CloseItem()
{
	Item* selectItem = item->GetCloseItem(player->Position());
}

