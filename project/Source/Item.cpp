#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage   = 0;
	kind     = rand() % 5;
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - WALL_SIZE - 200 - 32)), 0.0f);
	vector   = VGet(0, 0.3f, 0);
	speed    = 5.0f;

	isHold   = false;
	whoseNum = -1;

	isThrow = false;

	heavy = 0;
	score = 1;
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
		SetThrow(VGet(0, -0.1f, 0));
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		SetThrow(VGet(0, 5.0f, 0));
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		SetThrow(VGet(10.0f, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		SetThrow(VGet(-20.0f, 0, 0));
	}
	Throw();
}

void Item::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, kind * 36 + 2, 2, 32, 32, hImage, TRUE);
	DrawFormatString((int)position.x, (int)position.y, 0xff0000, "%.1f", speed);
}

const VECTOR Item::GetCenterPos()
{
	return position + VGet((float)(ITEM_SIZE / 2), (float)(ITEM_SIZE / 2),0);
}

float startTime = 0;
float endTime = 0;
float startPower = 0;
static const int ITEM_SIZE = 32;

void Item::SetThrow(VECTOR _vec)
{
	vector = _vec;
	startPower = VSize(vector);
	startTime = 0;
	endTime = 5.0f;
	isThrow = true;
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
		isThrow = false;
	}

	if (position.x < WALL_SIZE || position.x + ITEM_SIZE > SCREEN_WIDTH - WALL_SIZE ||
		position.y < WALL_SIZE || position.y + ITEM_SIZE > SCREEN_HEIGHT - WALL_SIZE) {
		vector     = VGet(0, 0, 0) - vector;
		startPower = VSize(vector) /10.0f;
		startTime  = 0;
		endTime    = 1.0f;
	}

	position.x += cosf(atan2f(vector.y, vector.x)) * speed;
	position.y += sinf(atan2f(vector.y, vector.x)) * speed;
}

void Item::SetRandomPosition()
{
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - WALL_SIZE - 200 - 32)), 0.0f);
}
