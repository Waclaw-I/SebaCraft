#pragma once

#include "EnemyShip.h"
#include "Player.h"

class Player;
class EnemyShip; // dont know why it suddenly demands redeclarations

class EnemyController
{
public:

	void static InsertNewEnemyShip(EnemyShip *);
	void static MoveEnemyShips(Player *);

	static vector <EnemyShip *> ArrayOfEnemies;
};