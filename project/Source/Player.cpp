#include "Player.h"
#include "config.h"

#include"territoryManager.h"
#include "territory.h"
#include "ItemManager.h"
#include "Item.h"

Player::Player()
{
	territory = nullptr;

	position = VECTOR();
	hImage   = -1;
	input    = VECTOR();
	score    = 0;
	type     = -1;

	speedBuff = 1.0f;
	weightMax = 10;//仮
	stunTime  = 0.0f;
	nowStun   = false;
	weight    = 0;

	itemList.clear();
	itemManager  = FindGameObject<ItemManager>();
	territoryPos = VECTOR();
}

Player::~Player()
{
	if (hImage > 0) {
		DeleteGraph(hImage);
		hImage = -1;
	}
	itemList.clear();
}

void Player::Update()
{
	if (!nowStun) {
		position += input * 3.0f * speedBuff;
	}
	else {
		stunTime -= 1.0f / 60.0f;
		if (stunTime <= 0.0f) {
			stunTime = 0.0f;
			nowStun  = false;
		}
		return;
	}
	ItemHit();
	VECTOR v = position + (input * -1.0f * ITEM_SIZE);
	for (auto& item : itemList) {
		item->SetPosition(v);
	}

	////////////////////
	if (CheckHitKey(KEY_INPUT_1)) {
		nowStun = true;
	}
	if (CheckHitKey(KEY_INPUT_2)) {
		nowStun = false;
	}
	if (CheckHitKey(KEY_INPUT_3)) {
		ItemThrow(VGet(5, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_4)) {
		ItemScatter();
	}
}

void Player::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 2, 2, PLAYER_SIZE, PLAYER_SIZE, hImage, TRUE);
	char s[32];
	sprintf_s<32>(s, "SCORE %6d", score);
	int x = 0;
	int y = 0;
	switch (type) {
	case 0:
		x = 20;
		y = 20;
		break;
	case 1:
		x = SCREEN_WIDTH-128;
		y = 20;
		break;
	case 2:
		x = 20;
		y = SCREEN_HEIGHT-40;
		break;
	case 3:
		x = SCREEN_WIDTH - 128;
		y = SCREEN_HEIGHT - 40;
		break;
	case 4:
		x = 0;
		y = 0;
		break;
	default:
		break;
	};
	//DrawString(x, y, s, GetColor(255, 255, 255), 0);
}

void Player::SetChara(int id)
{
	type = id;

	territoryPos = VGet(0, 0, 0);
	int boxSizeX = TERRITORY_SIZE_X;
	int boxSizeY = TERRITORY_SIZE_Y;

	switch (id) {
	case 0:
		hImage = LoadGraph("data/textures/player1.png");
		position = VGet((float)WALL_SIZE, 
			(float)(SCREEN_HEIGHT - WALL_SIZE - boxSizeY) , 0);
		break;
	case 1:
		hImage = LoadGraph("data/textures/player2.png");
		position = VGet((float)(WALL_SIZE + boxSizeX + 125),
			(float)(SCREEN_HEIGHT - WALL_SIZE - boxSizeY), 0);
		break;
	case 2:
		hImage = LoadGraph("data/textures/player3.png");
		position = VGet((float)(WALL_SIZE + boxSizeX * 2 + 250),
			(float)(SCREEN_HEIGHT - WALL_SIZE - boxSizeY), 0);
		break;
	case 3:
		hImage = LoadGraph("data/textures/player4.png");
		position = VGet((float)(SCREEN_WIDTH - (WALL_SIZE + boxSizeX) - 250),
			(float)(SCREEN_HEIGHT - WALL_SIZE - boxSizeY), 0);
		break;
	case 4:	hImage = LoadGraph("data/textures/player5.png");
		position = VGet((float)(SCREEN_WIDTH -(WALL_SIZE + boxSizeX)),
			(float)(SCREEN_HEIGHT - WALL_SIZE - boxSizeY), 0);
		break;

	}
	territoryPos  = position;
	position.y   -= 32;

	TerritoryManager* t = FindGameObject<TerritoryManager>();
	territory           = t->SetTerritory(territoryPos, id);
}

const VECTOR Player::GetCenterPos()
{
	return position + VGet((float)(PLAYER_SIZE / 2), (float)(PLAYER_SIZE / 2), 0);
}

void Player::Input(VECTOR dir)
{
	dir.z = 0;
	input = VNorm(dir);
}

void Player::SetSpeed()
{
	if (weight > weightMax) {
		float debuff = (float)(weight - weightMax);
		debuff /= 100;
		speedBuff = 1.0f - debuff;
	}
}

void Player::ItemHit()
{
	for (auto& item : itemManager->GetItemList()) {
		VECTOR posSub = item->GetCenterPos() - position;
		//当たっていないので飛ばす
		if (VSize(posSub) > ILUST_RADIUS) {
			continue;
		}
		//誰かが持ち歩いているなら飛ばす
		if (item->IsHold()) {
			continue;
		}

		//アイテムに当たったら
		//投げられているアイテムなら
		//スタンする処理
		if (item->IsThrow()) {
			//スタン中は飛ばす
			stunTime = 2.0f;
			nowStun  = true;
			ItemScatter();
			return;
		}
		//拾う処理
		else {
			weight += item->GetHeavy();
			item->SetIsHold(true);
			item->SetHavPlayer(this);
			itemList.emplace_back(item);
		}
	}
}

void Player::ItemThrow(const VECTOR& _vec)
{
	//手持ちのアイテムを投げる処理
	if (itemList.size() <= 0) {
		return;
	}
	Item* i = itemList.front();

	//動きはItemで処理する
	i->SetThrow(_vec);
	i->SetIsHold(false);
	i->SetHavPlayer(nullptr);
	itemList.pop_front();
}

void Player::ItemScatter()
{
	//手持ちのアイテム全てなくす
	for (auto& item : itemList) {
		item->SetRandomPosition();
		item->SetIsHold(false);
		item->SetHavPlayer(nullptr);
	}
	itemList.clear();
}

void Player::ItemPut()
{
	for (auto& item : itemList) {
		item->SetPosition(territoryPos);
		item->SetIsHold(false);
		item->SetHavPlayer(nullptr);
	}
	itemList.clear();
}

void Player::RandItemPut()
{
	const int RAND_NUM_MAX = 20;

	for (auto& item : itemList) {
		int x = rand() % (TERRITORY_SIZE_X - ITEM_SIZE);
		int y = rand() % (TERRITORY_SIZE_Y - ITEM_SIZE);
		item->SetPosition(territory->positon + VGet((float)x, (float)y, 0.0f));
		item->SetIsHold(false);
		item->SetHavPlayer(nullptr);
	}
	itemList.clear();
}
