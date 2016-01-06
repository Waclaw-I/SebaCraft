#pragma once

#include "EnemyShip.h"

class EnemyController
{
public:

	void static InsertNewEnemyShip(EnemyShip *);
	void static MoveEnemyShips(Player &);

	static vector <EnemyShip *> ArrayOfEnemies;
};