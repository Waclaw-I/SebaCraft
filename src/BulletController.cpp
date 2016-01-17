#include "BulletController.h"
#include "DisplayController.h"

#include <iostream>

using namespace std;

 vector <BulletBasicClass *>  BulletController::ArrayOfBullets;
 Player * BulletController::player;

void BulletController::InsertNewBullet(BulletBasicClass * bullet)
{
	ArrayOfBullets.push_back(bullet);
}

void BulletController::MoveBullets()
{
	for (int i = 0; i < ArrayOfBullets.size(); i++)
	{
		ArrayOfBullets[i]->DecreaseDuration(0.0166);
		if (ArrayOfBullets.size() > 0) UpdateSpritesPosition(i);
		ArrayOfBullets[i]->Move();
		if (ArrayOfBullets[i]->Collision() || ArrayOfBullets[i]->CollisionWithPlayer(player))
		{
			ArrayOfBullets[i]->GetMyGraph()->LogicIsDead();
			ArrayOfBullets.erase(ArrayOfBullets.begin() + i);
			continue;
		}
		
		if (ArrayOfBullets[i]->GetDuration() <= 0)
		{
			ArrayOfBullets[i]->GetMyGraph()->LogicIsDead();
			ArrayOfBullets.erase(ArrayOfBullets.begin() + i);
		}
		
	}
}

void BulletController::UpdateSpritesPosition(int i)
{
	ArrayOfBullets[i]->GetMyGraph()->MySprite.setPosition(ArrayOfBullets[i]->GetPosition_x(), ArrayOfBullets[i]->GetPosition_y());
	ArrayOfBullets[i]->GetMyGraph()->MySprite.setRotation(ArrayOfBullets[i]->GetRotation());
}
