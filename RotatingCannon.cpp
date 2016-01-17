#include "RotatingCannon.h"
#include "EnemyController.h"
#include <vector>
#include <cmath>
#include <iostream>

//utility function : todo - take it to the separate file
float calculateDistance(float x1, float y1, float x2, float y2)
{
	using std::sqrt;
	using std::pow;
	return sqrt( (pow(x1 - x2, 2) + (pow(y1 - y2, 2) )));
}

RotatingCannon::RotatingCannon(Player* _player, 
				   float _rangeToAttack, float _fireRate, int _attackPower,
				   ShootingMode _mode) 
	:
	player(_player),
	rangeToAttack(_rangeToAttack),
	fireRate(_fireRate),
	attackPower(_attackPower),
	shootingMode(_mode),
	timeToShoot(0),
	theNearestDistance(std::numeric_limits<float>::infinity()),
	theNearestTarget(nullptr)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[4], 
								LoadController::ShipTexturesArray[4].Get_x(), 
								LoadController::ShipTexturesArray[4].Get_y(), 90, 1);
	setBulletSpawnPoints(28, 7, 28, -7);
	calculateSpawnPoints();
}

RotatingCannon::~RotatingCannon()
{
	delete myGraph;
}

void RotatingCannon::rotate()
{
	float cannonX = player->Get_x_Position();
	float cannonY = player->Get_y_Position();
	float targetX = currentTarget->Get_x_Position();

	float targetY = currentTarget->Get_y_Position();

	rotation = atan2(cannonY - targetY, cannonX - targetX) * (180/3.14);
	rotation += 180;
	myGraph->MySprite.setRotation(rotation);
}

void RotatingCannon::shoot()
{
		float cannonX = player->Get_x_Position();
		float cannonY = player->Get_y_Position();
		calculateSpawnPoints();

		PlayerBullets * bullet1 = new PlayerBullets(cannonX + rotatedBulletSpawnPoint1_x, cannonY + rotatedBulletSpawnPoint1_y, attackPower, 10, 2, rotation);
		BulletController::InsertNewBullet(bullet1);
		DisplayController::InsertNewDrawableObject(bullet1);
		
		PlayerBullets * bullet2 = new PlayerBullets(cannonX + rotatedBulletSpawnPoint2_x, cannonY + rotatedBulletSpawnPoint2_y, attackPower, 10, 2, rotation);
		BulletController::InsertNewBullet(bullet2);
		DisplayController::InsertNewDrawableObject(bullet2);
}

EnemyShip* RotatingCannon::scanToFindNearest()
{
	float cannonX = player->Get_x_Position();
	float cannonY = player->Get_y_Position();

	theNearestDistance = std::numeric_limits<float>::infinity();
	std::vector<EnemyShip*>& enemies = EnemyController::ArrayOfEnemies;
	for (auto & ship : enemies) // super dooper c++11 feature	
	{	
		float shipX = ship->Get_x_Position();
		float shipY = ship->Get_y_Position();
		float distance = calculateDistance(shipX, shipY, cannonX, cannonY);
		if (distance < theNearestDistance) 
		{
			theNearestTarget = ship;
			theNearestDistance = distance;
		}
	}

	if (theNearestDistance) 
		return theNearestTarget;
	else
		return nullptr;

}

bool RotatingCannon::isTargetInRange() 
{
	if(currentTarget) 
	{
		float cannonX = player->Get_x_Position();
		float cannonY = player->Get_y_Position();
		float targetX = currentTarget->Get_x_Position();
		float targetY = currentTarget->Get_y_Position();
		if(calculateDistance(cannonX, cannonY, targetX, targetY) < rangeToAttack)
			return true;
	}
	return false;
}

void RotatingCannon::changeTarget(EnemyShip* newTarget)
{
	currentTarget = newTarget;
}

void RotatingCannon::update() 
{
	switch (shootingMode) {
		case theNearest:
		{
			changeTarget(scanToFindNearest());
			if (isTargetInRange()) {
				rotate();
				if (setTimeToShoot(0.0166)) shoot();
			}
			break;
		}
		case toDeath:

			break;
		default:
			break;
	}
}

void RotatingCannon::calculateSpawnPoints() 
{
	rotatedBulletSpawnPoint1_x = BulletSpawnPoint1.Get_x() * cos(getRotationInRadians()) - BulletSpawnPoint1.Get_y() * sin(getRotationInRadians());
	rotatedBulletSpawnPoint1_y = BulletSpawnPoint1.Get_x() * sin(getRotationInRadians()) + BulletSpawnPoint1.Get_y() * cos(getRotationInRadians());

	rotatedBulletSpawnPoint2_x = BulletSpawnPoint2.Get_x() * cos(getRotationInRadians()) - BulletSpawnPoint2.Get_y() * sin(getRotationInRadians());
	rotatedBulletSpawnPoint2_y = BulletSpawnPoint2.Get_x() * sin(getRotationInRadians()) + BulletSpawnPoint2.Get_y() * cos(getRotationInRadians());
}

void RotatingCannon::setBulletSpawnPoints(int x1, int y1, int x2, int y2)
{
	BulletSpawnPoint1.Set_x(x1);
	BulletSpawnPoint1.Set_y(y1);
	BulletSpawnPoint2.Set_x(x2);
	BulletSpawnPoint2.Set_y(y2);
}

double RotatingCannon::getRotationInRadians()
{
	return (rotation * (3.14 / 180));
}

bool RotatingCannon::setTimeToShoot(double amount) 
{ 
	if (timeToShoot <= fireRate) 
	{ 
		timeToShoot += amount;
		return false;
		
	}
	else 
	{
		
		timeToShoot = 0;
		return true;
	}
}