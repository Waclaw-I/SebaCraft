#pragma once

#include "DrawableObject.h"
#include "PlayerBullets.h"
#include "EnemyShip.h"
#include "Player.h"

class EnemyShip;

enum ShootingMode { toDeath, theNearest };

class RotatingCannon : public DrawableObject {
public:
	RotatingCannon(Player* _player, float _onPlayerX, float _onPlayerY, 
				   float _rangeToAttack, float _fireRate, 
				   ShootingMode _mode = toDeath);

	~RotatingCannon();

	void rotate();

	void shoot();

	EnemyShip* scanToFindNearest();
	bool isTargetInRange();
	void changeTarget(EnemyShip* newTarget);

	void update();


private:
	ShootingMode shootingMode;
	EnemyShip* currentTarget;
	Player* player;

	EnemyShip* theNearestTarget;
	float theNearestDistance;

	float rangeToAttack;
	float timeToShoot;
	float fireRate;
	
	float x;
	float y;
	const float onPlayerX;
	const float onPlayerY;
};