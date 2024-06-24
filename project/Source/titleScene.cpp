#include "titleScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"

int inc(int a)
{
	if (a >= 3)
		return a;
	return inc(a + 1);
}

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PlayScene");
	}

	SceneBase::Update();
}


void TitleScene::Draw()
{
	int n = inc(0);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "N=%d", n);
	SceneBase::Draw();
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
