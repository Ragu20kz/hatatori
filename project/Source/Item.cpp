#include "Item.h"
#include "config.h"

Item::Item()
{
	hImage   = 0;
	kind     = rand() % 5;
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - WALL_SIZE - 200 - 32)), 0.0f);
	vector   = VGet(0, 0.3f, 0);
	speed    = 5.0f;

	startTime  = 0.0f;
	endTime    = 0.0f;
	startPower = 0.0f;

	isHold   = false;
	whoseNum = -1;

	isThrow = false;

	isTerritory = false;

	havPlayer = nullptr;

	heavy = 2;
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
	/*if (CheckHitKey(KEY_INPUT_UP)) {
		SetThrow(VGet(-10.0f, -10.0f, 0));
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		SetThrow(VGet(0, 10.0f, 0));
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		SetThrow(VGet(10.0f, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		SetThrow(VGet(-10.0f, 0, 0));
	}*/
	Throw();
}

void Item::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, kind * 36 + 2, 2, 32, 32, hImage, TRUE);
	//DrawFormatString((int)position.x, (int)position.y, 0xff0000, "%.1f", speed);
	DrawFormatString((int)position.x, (int)position.y, 0xFFFFFF, "%s", isTerritory ?  "YES" : "NO");
}

const VECTOR Item::GetCenterPos()
{
	return position + VGet((float)(ITEM_SIZE / 2), (float)(ITEM_SIZE / 2),0);
}

void Item::SetThrow(const VECTOR& _vec)
{
	vector     = VNorm(_vec);
	startPower = 10.0f;
	startTime  = 0;
	endTime    = 3.0f;
	isThrow    = true;
}

void Item::ThrowReset() {
	speed     = 0.0f;
	isThrow   = false;
	havPlayer = nullptr;
}

void Item::Throw()
{
	if (!isThrow) {
		return;
	}

	float rate = startTime / endTime;
	startTime += 1.0f / 60.0f;

	if (rate > 1.0f) {
		ThrowReset();
		return;
	}

	speed = -startPower * rate + startPower;
	if (speed <= 0.0f) {
		ThrowReset();
		return;
	}

	if (position.x <= WALL_SIZE || position.x + ITEM_SIZE >= SCREEN_WIDTH  - WALL_SIZE ||
		position.y <= WALL_SIZE || position.y + ITEM_SIZE >= SCREEN_HEIGHT - WALL_SIZE) {
		vector     = VNorm(vector * -1);
		startPower = 0.0f;
		startTime  = 0.0f;
		endTime    = 1.0f;
		speed      = 10.0f;
	}

	float r = atan2f(vector.y, vector.x);
	position.x += cosf(r) * speed;
	position.y += sinf(r) * speed;
}

void Item::SetRandomPosition()
{
	position = VGet((float)(rand() % (SCREEN_WIDTH - 32)), (float)(rand() % (SCREEN_HEIGHT - WALL_SIZE - 200 - 32)), 0.0f);
}
