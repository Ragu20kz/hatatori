#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage   = 0;
	kind     = rand() % 5;
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - WALL_SIZE - 200 - 32)), 0.0f);
	
	isHold = false;
	isThrow = false;

	heavy = 0;
	score = 0;
	whoseNum = -1;
	
	vector = VGet(0, 0.0f, 0);
	speed = 5.0f;
	startTime = 0;
	endTime = 0;
	startPower = 0;
}

Item::~Item()
{
}

void Item::Create(int type, const VECTOR& pos)
{
}

void Item::Update()
{
	if (CheckHitKey(KEY_INPUT_UP)) {
		SetThrow(VGet(0,- 5.0f, 0));
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		SetThrow(VGet(0, 5.0f, 0));
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		SetThrow(VGet(5.0f, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		SetThrow(VGet(-5.0f, 0, 0));
	}
	Throw();
}

void Item::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, kind * 36 + 2, 2, 32, 32, hImage, TRUE);
	//DrawFormatString((int)position.x, (int)position.y, 0xff0000, "%.1f", speed);
}

void Item::SetThrow(VECTOR _vec)
{
	vector = _vec;
	startPower = VSize(vector);
	startTime = 0;
	endTime = 5.0f;
}

void Item::Throw()
{
	float rate = startTime / endTime;
	startTime += 1.0f / 60.0f;
	
	speed = (0 - startPower) * rate + startPower;

	if (speed > 0) {
		speed -= 0.1f;
	}
	else {
		speed = 0;
	}

	//•Ç”»’è(‚¿‚å‚Á‚Æ’µ‚Ë•Ô‚·)
	if (position.x < WALL_SIZE || position.x + ITEM_SIZE > SCREEN_WIDTH  - WALL_SIZE ||
		position.y < WALL_SIZE || position.y + ITEM_SIZE > SCREEN_HEIGHT - WALL_SIZE) {
		vector = VGet(0, 0, 0) - vector;
		startPower = VSize(vector) /10.0f;
		startTime = 0;
		endTime = 1.0f;
	}


	position.x += cos(atan2f(vector.y, vector.x)) * speed;
	position.y += sin(atan2f(vector.y, vector.x)) * speed;
}

int const Item::GetKind()
{
	return kind;
}
