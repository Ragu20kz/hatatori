#include "PlayerAI.h"
#include "ItemManager.h"
#include "Item.h"
#include "territory.h"

PlayerAI::PlayerAI()
{
	player = nullptr;
	item   = nullptr;

	info = PLAYER_INFO::DEFAULT;

	nextPos = VECTOR();
}

PlayerAI::~PlayerAI()
{
}

void PlayerAI::SetPlayer(Player* inst)
{
	player = inst;
}

void PlayerAI::Start()
{
	item = FindGameObject<ItemManager>();
}

void PlayerAI::Update()
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

void PlayerAI::DefaultUpdate()
{
	//�G�������Ă���A�C�e�����Ascore����ɑI������
	//FILDE_ITEMorTERRITOTY_ITEM�ɓ���

	//
}

void PlayerAI::Filde_ItemUpdate()
{
	Navigation();
	//�A�C�e�����������
	//DEFAULT�ɓ���

	//�ő吔�����Ă�����
	//BACK�ɓ���
}

void PlayerAI::Territoty_ItemUpdate()
{
	Navigation();
	//�A�C�e�����������
	//DEFAULT�ɓ���

	//�ő吔�����Ă�����
	//BACK�ɓ���
}

void PlayerAI::BackUpdate()
{
	//DEFAULT�ɓ���
	Territory* t = player->GetTerritory();

	nextPos = t->GetConterPos();
	Navigation();
}

void PlayerAI::ThrowUpdate()
{
	//�A�C�e���������BACK�ɓ���
	//�Ȃ����DEFAULT�ɓ���
}

void PlayerAI::Navigation()
{
	player->Input(nextPos - player->Position());
}

void PlayerAI::CloseItem()
{
	Item* selectItem = item->GetCloseItem(player->Position());
}
