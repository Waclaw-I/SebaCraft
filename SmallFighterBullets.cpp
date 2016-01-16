#include "SmallFighterBullets.h"
#include "LoadController.h"

#include <iostream>
using namespace std;

SmallFighterBullets::SmallFighterBullets(double spawn_x, double spawn_y, int damage, double speed, double duration, double rotation) :
	BulletBasicClass(spawn_x, spawn_y, damage, speed, duration, rotation), tag("EnemyBullet")

{
	myGraph = new SpriteHolder(LoadController::BulletTextureArray[1], LoadController::BulletTextureArray[1].Get_x(), LoadController::BulletTextureArray[1].Get_y(), rotation, 1);
	myGraph->MySprite.setPosition(spawnPoint_x, spawnPoint_y);

	qualityBoost = -5; // slight advance in comparision to our enemies
	quality += qualityBoost;
}

bool SmallFighterBullets::CollisionWithPlayer(Player * player)
{
	if (quality > 20)
	{

		double x_start = player->Get_x_Position() - (player->GetSize_x() / 2);
		double x_end = x_start + player->GetSize_x();
		double y_start = player->Get_y_Position() - (player->GetSize_y() / 2);
		double y_end = y_start + player->GetSize_y();

		if ((position_x >= x_start) && (position_x <= x_end))
			if ((position_y >= y_start) && (position_y <= y_end))
			{
				player->LooseHealth(damage);
				return true;
			}
		return false;
	}
	else return false;
}
	

SmallFighterBullets::~SmallFighterBullets()
{
	delete this->myGraph;
}
