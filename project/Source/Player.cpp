#include "Player.h"
#include "config.h"

#include"territoryManager.h"

Player::Player()
{
	position = VECTOR();
	hImage   = -1;
	input    = VECTOR();
	score = 0;
	type = -1;

	speedBuff = 1.0f;
	weightMax = 10;//‰¼
	stanTime = 0.0f;
	stanInvalid = 0;
	nowStan = false;
	weight = 0;
	speedBuffItem = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	//position += input * 3.0f*speedBuff;
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
	t->SetTerritory(territoyPos, id);
}

void Player::Input(VECTOR dir)
{
	dir.z = 0;
	input = VNorm(dir);
}

void Player::SetSpeed()
{
	if (weight < weightMax) {
		speedBuff = 1.0f + (speedBuffItem / 100);
	}
	else {
		float debuff = weight - weightMax;
		debuff /= 100;
		speedBuff = 1.0f - debuff;
	}
}
