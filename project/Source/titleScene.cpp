#include "titleScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "config.h"

TitleScene::TitleScene()
{
	himage = LoadGraph("data/textures/captureTheFlag.png");
}

TitleScene::~TitleScene()
{
	if (himage > 0) {
		DeleteGraph(himage);
	}
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

	//DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));

	SetFontSize(font * 4);
	std::string title = "Push [P]Key To Play";//ƒ^ƒCƒgƒ‹
	int size = GetDrawStringWidth(title.c_str(), (int)title.size());
	DrawString(SCREEN_WIDTH / 2 - size / 2, SCREEN_HEIGHT / 2, title.c_str(), 0xFFFFFF);

	SetFontSize(font);

	DrawRectGraph(SCREEN_WIDTH / 2 - size / 2, SCREEN_HEIGHT / 2-100, 0, 0, 240, 98, himage,false);

}
