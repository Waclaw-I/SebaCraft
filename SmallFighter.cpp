#include "SmallFighter.h"
#include "SmallFighterBullets.h"

#include <cstdlib>

#include <iostream>
using namespace std;

SmallFighter::SmallFighter(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation, double scale = 1) :
	EnemyShip(spawn_x, spawn_y, acc, m_health, m_speed, att_pow, fire_rate, rotation)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[2], LoadController::ShipTexturesArray[2].Get_x(), LoadController::ShipTexturesArray[2].Get_y(), rotation, scale);
	myGraph->MySprite.setPosition(spawn_x, spawn_y);

	
	MainCannonOneShooted = false;

	this->size_x = myGraph->Get_hitboxSize_x();
	this->size_y = myGraph->Get_hitboxSize_y();

	SetBulletSpawnPoints(32, 10, 32, -10);
	CalculateSpawnPoints();

	accelerationDistance = 150; // our SmallFighter is supposed to sit on our back! He wont slow down until he gets this close to the Player
}

SmallFighter::SmallFighter(double spawn_x, double spawn_y): EnemyShip(spawn_x, spawn_y, 0.2, 100, 2.5, 1, 1, 90)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[2], LoadController::ShipTexturesArray[2].Get_x(), LoadController::ShipTexturesArray[2].Get_y(), rotation, 1);
	myGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = myGraph->Get_hitboxSize_x();
	this->size_y = myGraph->Get_hitboxSize_y();

	SetBulletSpawnPoints(32, 10, 32, -10);
	CalculateSpawnPoints();

	accelerationDistance = 150;
}

SmallFighter::~SmallFighter()
{
	delete myGraph;
	delete hpBar;
}


void SmallFighter::CalculateSpawnPoints()
{
	rotatedBulletSpawnPoint1_x = BulletSpawnPoint1.Get_x() * cos(GetRotationInRadians()) - BulletSpawnPoint1.Get_y() * sin(GetRotationInRadians());
	rotatedBulletSpawnPoint1_y = BulletSpawnPoint1.Get_x() * sin(GetRotationInRadians()) + BulletSpawnPoint1.Get_y() * cos(GetRotationInRadians());

	rotatedBulletSpawnPoint2_x = BulletSpawnPoint2.Get_x() * cos(GetRotationInRadians()) - BulletSpawnPoint2.Get_y() * sin(GetRotationInRadians());
	rotatedBulletSpawnPoint2_y = BulletSpawnPoint2.Get_x() * sin(GetRotationInRadians()) + BulletSpawnPoint2.Get_y() * cos(GetRotationInRadians());
}

void SmallFighter::SetBulletSpawnPoints(int x1, int y1, int x2, int y2)
{
	BulletSpawnPoint1.Set_x(x1);
	BulletSpawnPoint1.Set_y(y1);
	BulletSpawnPoint2.Set_x(x2);
	BulletSpawnPoint2.Set_y(y2);
}

void SmallFighter::Shoot()
{
	CalculateSpawnPoints();
	//if (MainCannonOneShooted == false)
	//{
		SmallFighterBullets * bullet1 = new SmallFighterBullets(x + rotatedBulletSpawnPoint1_x, y + rotatedBulletSpawnPoint1_y, attackPower, 10, 2, rotation);
		BulletController::InsertNewBullet(bullet1);
		DisplayController::InsertNewDrawableObject(bullet1);
		
	//}
	//else
	//{
		SmallFighterBullets * bullet2 = new SmallFighterBullets(x + rotatedBulletSpawnPoint2_x, y + rotatedBulletSpawnPoint2_y, attackPower, 10, 2, rotation);
		BulletController::InsertNewBullet(bullet2);
		DisplayController::InsertNewDrawableObject(bullet2);
	//}
}
