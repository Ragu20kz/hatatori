#include "titleScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "config.h"

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
	const int font = GetFontSize();

	SceneBase::Draw();

	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));

	SetFontSize(font * 4);
	std::string title = "ƒ^ƒCƒgƒ‹";
	int size = GetDrawStringWidth(title.c_str(), (int)title.size());
	DrawString(SCREEN_WIDTH / 2 - size / 2, SCREEN_HEIGHT / 2, title.c_str(), 0xFFFFFF);

	SetFontSize(font);
}
