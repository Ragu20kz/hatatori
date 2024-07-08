#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include <DxLib.h>
#include "Player.h"
#include "PlayerAI.h"
#include "ItemManager.h"
#include "config.h"

#include"territoryManager.h"

PlayScene::PlayScene()
{
	TerritoryManager* territory = Instantiate<TerritoryManager>();
	Instantiate<ItemManager>();

	Player* inst[PLAYER_NUM];
	for (int i = 0; i < PLAYER_NUM; i++) {
		inst[i] = Instantiate<Player>();
		inst[i]->SetChara(i);
		SetDrawOrder(inst[i], 10000);
	}
	PlayerAI* ai = Instantiate<PlayerAI>();
	ai->SetPlayer(inst[0]);
	
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
