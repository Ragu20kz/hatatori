#include "Player.h"
#include "config.h"

#include"territoryManager.h"
#include "ItemManager.h"
#include "Item.h"

Player::Player()
{
	territory = nullptr;

	position = VECTOR();
	hImage   = -1;
	input    = VECTOR();
	score = 0;
	type = -1;

	speedBuff = 1.0f;
	weightMax = 10;//仮
	stanTime = 0.0f;
	nowStan = false;
	weight = 0;

	itemList.clear();
	itemManager = FindGameObject<ItemManager>();

}

Player::~Player()
{
	itemList.clear();

}


void Player::Update()
{

	if (!nowStan) {
		position += input * 3.0f*speedBuff;
	}
	ItemHit();
	for (auto& item : itemList) {
		item->SetPosition(position);
	}

	////////////////////
	if (CheckHitKey(KEY_INPUT_1)) {
		nowStan = true;
	}
	if (CheckHitKey(KEY_INPUT_2)) {
		nowStan = false;
	}
	if (CheckHitKey(KEY_INPUT_3)) {
		ItemThrow();
	}
	if (CheckHitKey(KEY_INPUT_4)) {
		ItemScatter();
	}


}

void Player::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 2, 2, 32, 32, hImage, TRUE);
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

	VECTOR territoyPos = VGet(0, 0, 0);
	int boxSizeX = TERRITORY_SIZE_X;
	int boxSizeY = TERRITORY_SIZE_Y;

	switch (id) {
	case 0:
		hImage = LoadGraph("data/textures/player1.png");
		position = VGet(WALL_SIZE, 
						SCREEN_HEIGHT - WALL_SIZE - boxSizeY , 0);
		territoyPos = position;
		position.y -= 32;
		break;
	case 1:
		hImage = LoadGraph("data/textures/player2.png");
		position = VGet(WALL_SIZE + boxSizeX + 125,
						SCREEN_HEIGHT - WALL_SIZE - boxSizeY, 0);
		territoyPos = position;
		position.y -= 32;
		break;
	case 2:
		hImage = LoadGraph("data/textures/player3.png");
		position = VGet(WALL_SIZE + boxSizeX * 2 + 250,
						SCREEN_HEIGHT - WALL_SIZE - boxSizeY, 0);
		territoyPos = position;
		position.y -= 32;
		break;
	case 3:
		hImage = LoadGraph("data/textures/player4.png");
		position = VGet(SCREEN_WIDTH - (WALL_SIZE + boxSizeX) - 250,
						SCREEN_HEIGHT - WALL_SIZE - boxSizeY, 0);
		territoyPos = position;
		position.y -= 32;
		break;
	case 4:	hImage = LoadGraph("data/textures/player5.png");
		position = VGet(SCREEN_WIDTH-(WALL_SIZE + boxSizeX), 
						SCREEN_HEIGHT - WALL_SIZE - boxSizeY, 0);
		territoyPos = position;
		position.y -= 32;
		break;

	}
	TerritoryManager* t = FindGameObject<TerritoryManager>();
	territory = t->SetTerritory(territoyPos, id);
}

void Player::Input(VECTOR dir)
{
	dir.z = 0;
	input = VNorm(dir);
}

void Player::SetSpeed()
{
	if (weight > weightMax) {
		float debuff = weight - weightMax;
		debuff /= 100;
		speedBuff = 1.0f - debuff;
	}
}

void Player::ItemHit()
{
	for (auto& item : itemManager->GetItemList()) {
		VECTOR posSub = item->Position() - position;
		//当たっていないので飛ばす
		if (VSize(posSub) > ILUST_RADIUS * 4) {
			continue;
		}
		//誰かが持ち歩いているなら飛ばす
		if (item->IsHold()) {
			continue;
		}
		//スタン中は飛ばす
		if (nowStan) {
			continue;
		}

		//アイテムに当たったら
		//投げられているアイテムなら
		//スタンする処理
		if (item->IsThrow()) {
			nowStan = true;
			ItemScatter();
		}
		//拾う処理
		else {
			weight += item->GetHeavy();
			item->SetIsHold(true);
			itemList.emplace_back(item);

		}
	}


}

void Player::ItemThrow()
{
	//手持ちのアイテムを投げる処理
	if (itemList.size() <= 0) {
		return;
	}
	//動きはItemで処理する
	itemList.front()->SetThrow(VGet(5,0,0));
	itemList.front()->SetIsHold(false);

	itemList.pop_front();
}

void Player::ItemScatter()
{
	//手持ちのアイテム全てなくす
	for (auto& item : itemList) {
		item->SetIsHold(false);
		item->SetRandomPosition();
	}
	itemList.clear();
}
