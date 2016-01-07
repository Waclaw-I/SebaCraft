#include "PlayerBullets.h"

#include <iostream>

using namespace std;

PlayerBullets::PlayerBullets(double spawn_x, double spawn_y, int damage, double speed, double duration, double rotation) : 
							BulletBasicClass(spawn_x, spawn_y, damage, speed, duration, rotation), tag("PlayerBullet")

{
	BulletGraph = new SpriteHolder(LoadController::BulletTextureArray[0], LoadController::BulletTextureArray[0].Get_x(), LoadController::BulletTextureArray[0].Get_y(), rotation, 1);
	BulletGraph->MySprite.setPosition(spawnPoint_x, spawnPoint_y);

	qualityBoost = 5; // slight advance in comparision to our enemies
	quality += qualityBoost;
}

void PlayerBullets::Move() // temp
{
	if ((rotation >= 0) && (rotation < 90))					// +/+ quarter
	{
		position_x += speed *((90 - rotation) / 90);
		position_y += speed *(rotation / 90);
	}
	if ((rotation >= 90) && (rotation < 180))					// +/- quarter
	{
		position_x -= speed *((rotation - 90) / 90);
		position_y += speed *((180 - rotation) / 90);
	}
	if ((rotation >= 180) && (rotation < 270))					// -/- quarter
	{
		position_x -= speed *((270 - rotation) / 90);
		position_y -= speed *((rotation - 180) / 90);
	}
	if ((rotation >= 270) && (rotation < 360))					// -/+ quarter
	{
		position_x += speed *((rotation - 270) / 90);
		position_y -= speed *((360 - rotation) / 90);
	}
}

bool PlayerBullets::Collision()
{
	if (quality > 20)
	{
		for (int i = 0; i < EnemyController::ArrayOfEnemies.size(); i++)
		{
			double x_start = EnemyController::ArrayOfEnemies[i]->Get_x_Position() - (EnemyController::ArrayOfEnemies[i]->GetSize_x() / 2);
			double x_end = x_start + EnemyController::ArrayOfEnemies[i]->GetSize_x();
			double y_start = EnemyController::ArrayOfEnemies[i]->Get_y_Position() - (EnemyController::ArrayOfEnemies[i]->GetSize_y() / 2);
			double y_end = y_start + EnemyController::ArrayOfEnemies[i]->GetSize_y();

			if ((position_x >= x_start) && (position_x <= x_end))
				if ((position_y >= y_start) && (position_y <= y_end))
				{
					EnemyController::ArrayOfEnemies[i]->LooseHealth(damage);
					return true;
				}


		}
	}
	return false;
}

SpriteHolder * PlayerBullets::GetBulletGraph()
{
	return BulletGraph;
	
}

PlayerBullets::~PlayerBullets()
{
	delete BulletGraph; // we need to free memory occupied by the graphic of the bullet
}