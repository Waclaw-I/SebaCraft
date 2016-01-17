#include "EnemyController.h"
#include <iostream>

using namespace std;

vector <EnemyShip *>  EnemyController::ArrayOfEnemies;


void EnemyController::InsertNewEnemyShip(EnemyShip * enemy)
{
	ArrayOfEnemies.push_back(enemy);
	DisplayController::InsertNewDrawableObject(enemy);
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

			// here we should insert a delay for each shoot
			if (ArrayOfEnemies[i]->SetTimeToShoot(0.0166)) ArrayOfEnemies[i]->Shoot();
				

			if (ArrayOfEnemies[i]->Get_IsAlive() == false)
			{
				ArrayOfEnemies[i]->GetMyGraph()->LogicIsDead();
				ArrayOfEnemies.erase(ArrayOfEnemies.begin() + i);
			}
		}
		
		
	}
}


void EnemyController::UpdateSpritesPosition(int i)
{
	ArrayOfEnemies[i]->GetMyGraph()->MySprite.setPosition(ArrayOfEnemies[i]->Get_x_Position(), ArrayOfEnemies[i]->Get_y_Position());
	ArrayOfEnemies[i]->GetMyGraph()->MySprite.setRotation(ArrayOfEnemies[i]->Get_Rotation());
	
}