#pragma once
#include "../Library/sceneBase.h"
#include <list>

class Player;

class ResultScene : public SceneBase {
public:
	ResultScene();
	~ResultScene();
	void Update() override;
	void Draw() override;
private:
	std::list<Player*> playerList;
};
