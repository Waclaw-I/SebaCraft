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

RotatingCannon::RotatingCannon(Player* _player, float _onPlayerX, float _onPlayerY, 
				   float _rangeToAttack, float _fireRate, 
				   ShootingMode _mode) 
	:
	player(_player),
	onPlayerX(_onPlayerX),
	onPlayerY(_onPlayerY),
	rangeToAttack(_rangeToAttack),
	shootingMode(_mode),
	theNearestDistance(std::numeric_limits<float>::infinity()),
	theNearestTarget(nullptr)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[4], 
								LoadController::ShipTexturesArray[4].Get_x(), 
								LoadController::ShipTexturesArray[4].Get_y(), 90, 1);
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


	float rotation = atan2(cannonY - targetY, cannonX - targetX) * (180/3.14);
	rotation += 180;
	myGraph->MySprite.setRotation(rotation);
}

void RotatingCannon::shoot()
{}

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
			}
			break;
		}
		case toDeath:

			break;
		default:
			break;
	}
}