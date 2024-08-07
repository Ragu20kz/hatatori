#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "Player.h"
#include "PlayerAI.h"
#include "ItemManager.h"
#include "config.h"

#include "PlayerAIItou.h"
#include "PlayerAIOoki.h"
#include "PlayerAIHiguti.h"
#include "PlayerAITsukumo.h"
#include "PlayerAISyuu.h"

#include "territoryManager.h"
#include "PlayTime.h"
#include "Score.h"

PlayScene::PlayScene()
{
	TerritoryManager* territory = Instantiate<TerritoryManager>();
	Instantiate<ItemManager>();
	time = Instantiate<PlayTime>();

	Player* inst[PLAYER_NUM];
	for (int i = 0; i < PLAYER_NUM; i++) {
		inst[i] = Instantiate<Player>();
		inst[i]->SetChara(i);
		SetDrawOrder(inst[i], 10000);
	}
	
	PlayerAIHiguti* p1	= Instantiate<PlayerAIHiguti>();
	PlayerAIOoki* p2	= Instantiate<PlayerAIOoki>();
	PlayerAITsukumo* p3 = Instantiate<PlayerAITsukumo>();
	PlayerAISyuu* p4	= Instantiate<PlayerAISyuu>();
	PlayerAIItou* p5	= Instantiate<PlayerAIItou>();
	p1->SetPlayer(inst[0]);
	p2->SetPlayer(inst[1]);
	p3->SetPlayer(inst[2]);
	p4->SetPlayer(inst[3]);
	p5->SetPlayer(inst[4]);
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}
	SceneBase::Update();

	if (time->IsTimeUp()) {
		auto playerList = FindGameObjects<Player>();
		playerList.sort([](Player* a, Player* b) { return a->GetTerritory()->score > a->GetTerritory()->score; });
		Score* s = Score::GetInstance();
		for (auto it = playerList.begin(); it != playerList.end(); it++) {
			SCORE_INFO si;
			si.playerNun = (*it)->GetType();
			si.score = (*it)->GetScore();
			s->AddScore(si);
		}
		SceneManager::ChangeScene("ResultScene");
	}
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	//WALL��`��
	DrawBox(0, 0, WALL_SIZE, SCREEN_HEIGHT, COLOR_GRAY, true);
	DrawBox(0, 0, SCREEN_WIDTH, WALL_SIZE, COLOR_GRAY, true);
	DrawBox(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SCREEN_HEIGHT-WALL_SIZE, COLOR_GRAY, true);
	DrawBox(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIDTH-WALL_SIZE, 0, COLOR_GRAY, true);
	
//	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
//	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
