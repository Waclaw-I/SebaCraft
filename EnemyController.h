#pragma once

#include "EnemyShip.h"

class EnemyController
{
public:

	void static InsertNewEnemyShip(EnemyShip *);
	void static MoveEnemyShips();

	static vector <EnemyShip *> ArrayOfEnemies;
};