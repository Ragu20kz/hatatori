#include "PlayerAITsukumo.h"


PlayerAITsukumo::PlayerAITsukumo(){
	player = FindGameObject<Player>();
	territory = player->GetTerritory();

	state = STATE::STOP;
}

PlayerAITsukumo::~PlayerAITsukumo(){

}

void PlayerAITsukumo::SetPlayer(Player* inst){
	player = inst;
}

void PlayerAITsukumo::Update(){


	player->Input(VGet(1, 0, 0));
}

void PlayerAITsukumo::GetItemMove(){

}

void PlayerAITsukumo::GoingHomeMove(){
	//territory->Get
}
