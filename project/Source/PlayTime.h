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
	int time;      //ŠÔ
	int timeFrame;

	int imageNumber; //”š‰æ‘œ
	int imageTime;   //TIME‰æ‘œ

	bool activeTime; //ŠÔ‚ğŒ¸‚ç‚·‚©‚Ç‚¤‚©
};