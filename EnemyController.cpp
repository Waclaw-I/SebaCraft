#include "EnemyController.h"
#include <iostream>

using namespace std;

vector <EnemyShip *>  EnemyController::ArrayOfEnemies;


void EnemyController::InsertNewEnemyShip(EnemyShip * enemy)
{
	ArrayOfEnemies.push_back(enemy);
}

void EnemyController::MoveEnemyShips(Player * player)
{
	for (int i = 0; i < ArrayOfEnemies.size(); i++)
	{
		ArrayOfEnemies[i]->FollowPlayer(player);
		ArrayOfEnemies[i]->Move();
		if (ArrayOfEnemies[i]->Get_IsAlive() == false)
		{
			delete ArrayOfEnemies[i];
			ArrayOfEnemies.erase(ArrayOfEnemies.begin() + i);
		}
		
	}
}