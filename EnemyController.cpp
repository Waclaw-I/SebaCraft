#include "EnemyController.h"

vector <EnemyShip *>  EnemyController::ArrayOfEnemies;


void EnemyController::InsertNewEnemyShip(EnemyShip * enemy)
{
	ArrayOfEnemies.push_back(enemy);
}

void EnemyController::MoveEnemyShips()
{
	for (int i = 0; i < ArrayOfEnemies.size(); i++)
	{
		ArrayOfEnemies[i]->Move();
		if (ArrayOfEnemies[i]->Get_IsAlive() == false)
		{
			ArrayOfEnemies.erase(ArrayOfEnemies.begin() + i);
		}
		
	}
}