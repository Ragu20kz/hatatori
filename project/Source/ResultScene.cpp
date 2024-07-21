#include "ResultScene.h"
#include "config.h"

#include "Player.h"
#include "Score.h"

ResultScene::ResultScene()
{
	playerList.clear();

	Player* inst[PLAYER_NUM];
	for (int i = 0; i < PLAYER_NUM; i++) {
		inst[i] = Instantiate<Player>();
		inst[i]->SetChara(i);
		SetDrawOrder(inst[i], 10000);
	}

	Score* score = Score::GetInstance();
	auto list    = score->GetList();
	for (auto it = list.begin(); it != list.end(); it++) {
		const SCORE_INFO& s = (*it);
		playerList.emplace_back(inst[s.playerNun]);
	}
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
		Score::GetInstance()->Reset();
	}
}

void ResultScene::Draw()
{
	int y = 0;
	for (auto it = playerList.begin(); it != playerList.end(); it++) {
		Player* p = (*it);
		VECTOR pos = VGet(500.0f, (float)(200 + (70 * y)), 0);
		DrawFormatString((int)pos.x, (int)pos.y, 0xFFFFFF, "%dˆÊ", y + 1);
		p->SetPos(pos + VGet(50.0f, 0, 0));
		y++;
	}

	SceneBase::Draw();

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
