#pragma once
#include "../Library/gameObject.h"

class PlayTime : public GameObject
{
public:
	PlayTime();
	~PlayTime();
	void Update()override;
	void Draw()override;

	bool SetActiveTime(bool active);
	int GetCountTime() const { return time; }

	bool IsTimeUp();

private:
	int time;      //時間
	int timeFrame;

	int imageNumber; //数字画像
	int imageTime;   //TIME画像

	bool activeTime; //時間を減らすかどうか
};