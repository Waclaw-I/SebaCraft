#pragma once

#include "DrawableObject.h"
#include "PlayerBullets.h"

enum ShootingMode { toDeath, theNearest };

class RotatingCannon : public DrawableObject {
public:
	RotatingCannon(float _onPlayerX, float _onPlayerY, 
				   float _rangeToAttack, float _fireRate, 
				   ShootingMode _mode = toDeath);

	~RotatingCannon();

	void move(float _x, float _y);

	void shoot();

	void scanToFindNearest();
	bool isTargetInRange(DrawableObject* target);
	void changeTarget(DrawableObject* newTarget);

	float getOnPlayerX();
	float getOnPlayerY();


private:
	ShootingMode shootingMode;
	DrawableObject* currentTarget;
	float rangeToAttack;
	float timeToShoot;
	float fireRate;
	
	float x;
	float y;
	const float onPlayerX;
	const float onPlayerY;
};