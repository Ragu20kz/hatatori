#include "ResultScene.h"
#include "config.h"

#include "Player.h"
#include "Score.h"

#include"territory.h"

namespace {
	std::list<int> nowScore;
}

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
	int a = 0;
	for (auto it = list.begin(); it != list.end(); it++) {
		const SCORE_INFO& s = (*it);
		playerList.emplace_back(inst[s.playerNun]);
		nowScore.emplace_back(s.score);
		a++;
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
		p->SetPos(pos + VGet(-50.0f, 0, 0));
		y++;
	}
	y = 0;
	for (auto it : nowScore) {
		VECTOR pos = VGet(500.0f, (float)(200 + (70 * y)), 0);
		int a = it;
		DrawFormatString((int)pos.x, (int)pos.y, 0xFFFFFF, "score:%d", a);
		y++;
	}

	SceneBase::Draw();

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
