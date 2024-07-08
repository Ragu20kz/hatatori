#include "PlayerAI.h"
#include "ItemManager.h"
#include "Item.h"

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
}

void PlayerAI::Filde_ItemUpdate()
{
	//BACK�ɓ���
}

void PlayerAI::Territoty_ItemUpdate()
{
	//BACK�ɓ���
}

void PlayerAI::BackUpdate()
{
	//DEFAULT�ɓ���
}

void PlayerAI::ThrowUpdate()
{
	//�A�C�e���������BACK�ɓ���
	//�Ȃ����DEFAULT�ɓ���
}

void PlayerAI::CloseItem()
{
	auto itemList    = item->GetItemList();
	Item* selectItem = itemList.front(); //list�̓����擾
	auto itr         = itemList.begin();
	float lenge      = VSquareSize(selectItem->Position() - player->Position());

	for (itr++; itr != itemList.end(); itr++) {
		Item* nowItem = (*itr);
		float len     = VSquareSize(nowItem->Position() - player->Position());
		//������r
		if (lenge > len) {
			selectItem = nowItem;
			lenge      = len;
		}
	}
}
