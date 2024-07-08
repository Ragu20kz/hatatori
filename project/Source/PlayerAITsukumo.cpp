#include "PlayerAITsukumo.h"

PlayerAITsukumo::PlayerAITsukumo(){
	player = nullptr;
}

PlayerAITsukumo::~PlayerAITsukumo(){

}

void PlayerAITsukumo::SetPlayer(Player* inst){
	player = inst;
}

void PlayerAITsukumo::Update(){
	player->Input(VGet(1, 0, 0));
}
