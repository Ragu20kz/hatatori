#pragma once
#include "../Library/gameObject.h"

class Player : public GameObject {
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void SetChara(int id);
	VECTOR Position() {
		return position;
	}
	void Input(VECTOR dir);

	/// <summary>
	/// speedBuff��ύX����
	/// </summary>
	void SetSpeed();
private:
	VECTOR position;
	int hImage;			
	VECTOR input;
	int score;
	int type;

	float speedBuff;	//�X�s�[�h�{���A�f�t�H���g��1.0f
	int weightMax;		//�d������A����ȏ㑝����ƒx���Ȃ��
	int weight;			//���݂̏d��
	float stanTime;		//�X�^������
	bool nowStan;		//���X�^�����Ă��邩�A���Ă����true
	int stanInvalid;	//�X�^�������񐔁A�����ێ�����\�������邽�߂Ƃ肠����int
	int speedBuffItem;	//�X�s�[�h�o�t�A�C�e����
};