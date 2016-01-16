#include "PlayerBullets.h"

#include <iostream>

using namespace std;

PlayerBullets::PlayerBullets(double spawn_x, double spawn_y, int damage, double speed, double duration, double rotation) : 
							BulletBasicClass(spawn_x, spawn_y, damage, speed, duration, rotation), tag("PlayerBullet")

{
	myGraph = new SpriteHolder(LoadController::BulletTextureArray[0], LoadController::BulletTextureArray[0].Get_x(), LoadController::BulletTextureArray[0].Get_y(), rotation, 1);
	myGraph->MySprite.setPosition(spawnPoint_x, spawnPoint_y);

	qualityBoost = 5; // slight advance in comparision to our enemies
	quality += qualityBoost;
}

PlayerBullets::~PlayerBullets(){}


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


