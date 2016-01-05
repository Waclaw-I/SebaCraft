#include "PlayerBullets.h"

#include <iostream>

using namespace std;

PlayerBullets::PlayerBullets(double spawn_x, double spawn_y, int damage, double speed, double duration, double rotation) : 
							BulletBasicClass(spawn_x, spawn_y, damage, speed, duration, rotation), tag("PlayerBullet")

{
	BulletGraph = new SpriteHolder(LoadController::BulletTextureArray[0], LoadController::BulletTextureArray[0].Get_x(), LoadController::BulletTextureArray[0].Get_y(), 90, 1);
	BulletGraph->MySprite.setPosition(spawnPoint_x, spawnPoint_y);
}

void PlayerBullets::Move() // temp
{
	if ((rotation >= 0) && (rotation <= 90))					// +/+ quarter
	{
		position_x += speed *((90 - rotation) / 90);
		position_y += speed *(rotation / 90);
	}
	if ((rotation >= 90) && (rotation <= 180))					// +/- quarter
	{
		position_x -= speed *((rotation - 90) / 90);
		position_y += speed *((180 - rotation) / 90);
	}
	if ((rotation >= 180) && (rotation <= 270))					// -/- quarter
	{
		position_x -= speed *((270 - rotation) / 90);
		position_y -= speed *((rotation - 180) / 90);
	}
	if ((rotation >= 270) && (rotation <= 360))					// -/+ quarter
	{
		position_x += speed *((rotation - 270) / 90);
		position_y -= speed *((360 - rotation) / 90);
	}
}

SpriteHolder * PlayerBullets::GetBulletGraph()
{
	return BulletGraph;
	
}

PlayerBullets::~PlayerBullets()
{
	delete BulletGraph; // we need to free memory occupied by the graphic of the bullet
}