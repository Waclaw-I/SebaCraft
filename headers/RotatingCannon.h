#pragma once

#include "DrawableObject.h"
#include "PlayerBullets.h"
#include "EnemyShip.h"
#include "SpawnPoint.h"
#include "Player.h"

class EnemyShip;

enum ShootingMode { toDeath, theNearest };

class RotatingCannon : public DrawableObject {
public:
	RotatingCannon(Player* _player,
				   float _rangeToAttack, float _fireRate, int _attackPower = 5,
				   ShootingMode _mode = toDeath);

	~RotatingCannon();

	void rotate();

	void shoot();
	bool setTimeToShoot(double amount);

	EnemyShip* scanToFindNearest();
	bool isTargetInRange();
	void changeTarget(EnemyShip* newTarget);

	void update();

	void calculateSpawnPoints();
	void setBulletSpawnPoints(int, int, int, int);
	double getRotationInRadians();

private:
	ShootingMode shootingMode;
	EnemyShip* currentTarget;
	Player* player;

	EnemyShip* theNearestTarget;
	float theNearestDistance;

	float rangeToAttack;
	float timeToShoot;
	float fireRate;
	int attackPower;
	
	float x;
	float y;
	float rotation;

	SpawnPoint BulletSpawnPoint1;
	SpawnPoint BulletSpawnPoint2;

	double rotatedBulletSpawnPoint1_x;
	double rotatedBulletSpawnPoint1_y;
	double rotatedBulletSpawnPoint2_x;
	double rotatedBulletSpawnPoint2_y;
};