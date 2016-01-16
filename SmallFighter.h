#pragma once
#include "EnemyShip.h"
#include "LoadController.h"

class SmallFighter : public EnemyShip
{

public:
	SmallFighter(double, double, double, double, double, int, double, double, double);
	SmallFighter(double, double);
	~SmallFighter();
	void Shoot() override;

	void CalculateSpawnPoints() override;

	void SetBulletSpawnPoints(int, int, int, int);


private:

	SpawnPoint BulletSpawnPoint1;
	SpawnPoint BulletSpawnPoint2;

	double rotatedBulletSpawnPoint1_x; // we need those to spawn bullets properly
	double rotatedBulletSpawnPoint1_y;
	double rotatedBulletSpawnPoint2_x;
	double rotatedBulletSpawnPoint2_y;

	bool MainCannonOneShooted;

};