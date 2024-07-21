#pragma once
#include "../Library/sceneBase.h"

class PlayTime;

class PlayScene : public SceneBase {
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private:
	PlayTime* time;
};