#include "PlayerAIOoki.h"
#include "ItemManager.h"
#include "Item.h"
#include "territory.h"

PlayerAIOoki::PlayerAIOoki()
{
	player       = nullptr;
	item         = nullptr;
	targetItem   = nullptr;
	targetPlayer = nullptr;

	info = PLAYER_INFO::DEFAULT;

	nextPos = VECTOR();

	attackCoolTime = 0.0f;
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
	switch (info) {
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

	if (attackCoolTime > 0.0f) {
		attackCoolTime -= 1.0f / 60.0f;
	}
	else {
		attackCoolTime = 0.0f;
	}
}

void PlayerAIOoki::Draw()
{
	DrawFormatString(200, 300, 0xFFFFFF, "state %d", (int)info);
	//DrawFormatString(200, 300, 0xFFFFFF, "%s", targetItem != nullptr ? "ARI" : "NULL");
}

void PlayerAIOoki::DefaultUpdate()
{
	const int ITEM_MAX   = 5;
	const auto& itemList = player->GetItemList();

	if (itemList.size() > ITEM_MAX) {
		targetItem = nullptr;
		info       = PLAYER_INFO::BACK;
		return;
	}

	//敵が持っているアイテム数、scoreを基準に選択する
	//FILDE_ITEMorTERRITOTY_ITEMに入る
	targetItem = nullptr;
	targetItem = item->GetFieldCloseItem(player->Position());
	if (targetItem != nullptr) {
		info = PLAYER_INFO::FILDE_ITEM;
	}
	else {
		if (player->GetItemList().size() > 0) {
			info = PLAYER_INFO::BACK;
		}
		else {
			HeightScorePlayer();
			if (targetPlayer == nullptr) {
				info = PLAYER_INFO::BACK;
			}
			else {
				info = PLAYER_INFO::TERRITOTY_ITEM;
			}
		}
	}
}

void PlayerAIOoki::Filde_ItemUpdate()
{
	nextPos = targetItem->Position();
	Navigation();
	//アイテムを取ったら
	//DEFAULTに入る
	Player* p = targetItem->GetHavPlayer();

	if (p == nullptr) {
		return;
	}

	if (p == player) {
		info = PLAYER_INFO::DEFAULT;
	}
	else {
		if (player->GetItemList().size() > 0) {
			targetPlayer = p;
			info         = PLAYER_INFO::THROW;
		}
		else {
			info = PLAYER_INFO::DEFAULT;
		}
	}

	//最大数持っていたら
	//BACKに入る
}

void PlayerAIOoki::Territoty_ItemUpdate()
{
	const VECTOR& pPos = player->GetCenterPos();
	Territory* t       = targetPlayer->GetTerritory();
	auto list          = t->GetItemList();
	if (t->IsInside(player->Position(), VGet(PLAYER_SIZE, PLAYER_SIZE, 0))) {
		float dis = 10000.0f;
		for (auto it = list.begin(); it != list.end(); it++) {
			Item* item = (*it);

			float d = VSize(item->GetCenterPos() - pPos);
			if (dis > d) {
				dis        = d;
				targetItem = item;
			}
		}
		nextPos = targetItem->Position();
	}

	Navigation();

	if (player->GetItemList().size() > 5 || list.size() <= 0) {
		info = PLAYER_INFO::BACK;
	}
}

void PlayerAIOoki::BackUpdate()
{
	Territory* t = player->GetTerritory();
	nextPos      = t->GetConterPos();
	Navigation();

	const VECTOR& cPos = t->GetConterPos();
	if (t->IsInside(player->Position(), VGet(PLAYER_SIZE, PLAYER_SIZE,0))) {
		info = PLAYER_INFO::DEFAULT;
		player->RandItemPut();
	}

	auto playerList    = FindGameObjects<Player>();
	const VECTOR& pPos = player->GetCenterPos();

	float dis = 10000.0f;
	for (auto it = playerList.begin(); it != playerList.end(); it++) {
		Player* nowp = (*it);
		if (nowp == player) {
			continue;
		}

		float d = VSize(nowp->GetCenterPos() - pPos);
		if (dis > d) {
			dis          = d;
			targetPlayer = nowp;
		}
	}

	const VECTOR& tPos = targetPlayer->GetCenterPos();
	if (VSize(tPos - pPos) < 500.0f && attackCoolTime <= 0.0f) {
		info = PLAYER_INFO::THROW;
	}
}

void PlayerAIOoki::ThrowUpdate()
{
	if (targetPlayer == nullptr || attackCoolTime > 0.0f) {
		if (player->GetItemList().size() > 0) {
			info = PLAYER_INFO::BACK;
		}
		else {
			info = PLAYER_INFO::DEFAULT;
		}
	}

	const VECTOR& pPos = player->Position();
	const VECTOR& tPos = targetPlayer->Position();
	VECTOR pos         = tPos - pPos;
	if (VSize(pos - pPos) > 250.0f) {
		pos = targetPlayer->GetInput() * (PLAYER_SIZE) + tPos;
		pos = pos - pPos;
	}
	player->ItemThrow(pos);

	attackCoolTime = 10.0f;

	//アイテムがあればBACKに入る
	//なければDEFAULTに入る
	if (player->GetItemList().size() > 0) {
		info = PLAYER_INFO::BACK;
	}
	else {
		info = PLAYER_INFO::DEFAULT;
	}
}

void PlayerAIOoki::HeightScorePlayer()
{
	auto playerList = FindGameObjects<Player>();
	int score       = 0;
	Player* p       = nullptr;
	for (auto it = playerList.begin(); it != playerList.end(); it++) {
		Player* nowp = (*it);
		if (nowp == player) {
			continue;
		}
		int s = nowp->GetTerritory()->score;
		if (score < s) {
			score = s;
			p     = nowp;
		}
	}
	targetPlayer = p;
}

void PlayerAIOoki::Navigation()
{
	player->Input(nextPos - player->Position());
}

void PlayerAIOoki::CloseItem()
{
	Item* selectItem = item->GetCloseItem(player->Position());
}

