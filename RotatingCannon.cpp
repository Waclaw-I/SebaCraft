#include "RotatingCannon.h"

RotatingCannon::RotatingCannon(float _onPlayerX, float _onPlayerY, 
				   float _rangeToAttack, float _fireRate, 
				   ShootingMode _mode) 
	:
	onPlayerX(_onPlayerX),
	onPlayerY(_onPlayerY)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[4], 
								LoadController::ShipTexturesArray[4].Get_x(), 
								LoadController::ShipTexturesArray[4].Get_y(), 90, 1);
}

RotatingCannon::~RotatingCannon()
{
	delete myGraph;
}

void RotatingCannon::move(float _x, float _y)
{}

void RotatingCannon::shoot()
{}

void RotatingCannon::scanToFindNearest()
{}

bool RotatingCannon::isTargetInRange(DrawableObject* target) 
{}

void RotatingCannon::changeTarget(DrawableObject* newTarget)
{}

float RotatingCannon::getOnPlayerX()
{}

float RotatingCannon::getOnPlayerY()
{}