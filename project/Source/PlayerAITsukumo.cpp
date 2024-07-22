#include "PlayerAITsukumo.h"


PlayerAITsukumo::PlayerAITsukumo(){
	player = FindGameObject<Player>();
	territory = FindGameObject<TerritoryManager>();
	itemManager = FindGameObject<ItemManager>();
	
	angle = 0.0f;

	state = STATE::STOP;
}

PlayerAITsukumo::~PlayerAITsukumo(){

}

void PlayerAITsukumo::SetPlayer(Player* inst){
	player = inst;
}

void PlayerAITsukumo::Update(){


	//player->Input(VGet(1, 0, 0));

	GoingHomeMove();

}

void PlayerAITsukumo::GetItemMove(){
	VECTOR playerPos = player->Position();
	//item = itemManager->GetItemList();


}

void PlayerAITsukumo::GoingHomeMove(){
	VECTOR playerPos = player->Position();
	VECTOR territoryPos = territory->GetPosition(3);
	//プレイヤーを追いかける
	if (!CollisionDetectionPlayer(playerPos, territoryPos, 50)) {
		//後でやる
		angle = atan2((double)playerPos.y - territoryPos.y,
			(double)playerPos.x - territoryPos.x);
		VECTOR velocity; //速度
		velocity.x = 2.0f * cosf(angle);
		velocity.y = 2.0f * sinf(angle);
		player->Input(velocity);
	}

}

bool PlayerAITsukumo::CollisionDetectionPlayer(VECTOR _player, VECTOR _num, int _size)
{
	if (_player.x < _num.x + _size && _player.x + _size> _num.x &&
		_player.y < _num.y + _size && _player.y + _size> _num.y) {
		return true;
	}
	return false;
}
