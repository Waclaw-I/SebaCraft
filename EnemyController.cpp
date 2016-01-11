#include "EnemyController.h"
#include <iostream>

using namespace std;

vector <EnemyShip *>  EnemyController::ArrayOfEnemies;


void EnemyController::InsertNewEnemyShip(EnemyShip * enemy)
{
	ArrayOfEnemies.push_back(enemy);
	DisplayController::InsertNewSprite(enemy->Get_MyGraph());
}

void EnemyController::MoveEnemyShips(Player * player)
{
	for (int i = 0; i < ArrayOfEnemies.size(); i++)
	{
		if (ArrayOfEnemies.size() > 0) UpdateSpritesPosition(i);

		if (i == 0) ArrayOfEnemies[i]->RotateRight();
		else
		{
			ArrayOfEnemies[i]->FollowPlayer(player);
			ArrayOfEnemies[i]->Move();

			if (ArrayOfEnemies[i]->Get_IsAlive() == false)
			{
				ArrayOfEnemies[i]->Get_MyGraph()->LogicIsDead();
				delete ArrayOfEnemies[i];
				ArrayOfEnemies.erase(ArrayOfEnemies.begin() + i);
			}
		}
		
		
	}
}

void EnemyController::UpdateSpritesPosition(int i)
{
	ArrayOfEnemies[i]->Get_MyGraph()->MySprite.setPosition(ArrayOfEnemies[i]->Get_x_Position(), ArrayOfEnemies[i]->Get_y_Position());
	ArrayOfEnemies[i]->Get_MyGraph()->MySprite.setRotation(ArrayOfEnemies[i]->Get_Rotation());
	
}