#include "PlayerBullets.h"

#include <iostream>

using namespace std;

PlayerBullets::PlayerBullets(double spawn_x, double spawn_y, int damage, double speed, double duration) : 
							BulletBasicClass(spawn_x, spawn_y, damage, speed, duration), tag("PlayerBullet")

{
	BulletGraph = new SpriteHolder(LoadController::BulletTextureArray[0], LoadController::BulletTextureArray[0].Get_x(), LoadController::BulletTextureArray[0].Get_y(), 90, 1);
	BulletGraph->MySprite.setPosition(spawnPoint_x, spawnPoint_y);
}

void PlayerBullets::Move(int rotation) // temp
{
	position_x += speed;
	duration -= 0.01; // something about 10 seconds
}

SpriteHolder * PlayerBullets::GetBulletGraph()
{
	return BulletGraph;
	
}

PlayerBullets::~PlayerBullets()
{
	delete BulletGraph; // we need to free memory occupied by the graphic of the bullet
}