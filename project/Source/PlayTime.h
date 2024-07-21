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
	int time;      //����
	int timeFrame;

	int imageNumber; //�����摜
	int imageTime;   //TIME�摜

	bool activeTime; //���Ԃ����炷���ǂ���
};