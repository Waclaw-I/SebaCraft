#pragma once
#include "EnemyController.h"

#include "EnemyShip.h"
#include "SpawnPoint.h"
#include "SmallFighter.h"
#include "Medivac.h"

class SpaceStation : public EnemyShip
{
public:
	SpaceStation(double, double);
	~SpaceStation();
	SpriteHolder * Get_MyGraph() override;

	void CalculateSpawnPoints() override;

	void SetShipSpawnPoints(int, int, int, int);


	void SpawnSmallFighter();
	void SpawnMedivac();

	void RotateLeft() override;
	void RotateRight() override;

private:

	SpawnPoint smallFighterSpawnPoint;
	SpawnPoint medivacSpawnPoint;

	double rotatedSmallFighterSP_x; // we need those to spawn bullets properly
	double rotatedSmallFighterSP_y;
	double rotatedMedivacSP_x;
	double rotatedMedivacSP_y;

};