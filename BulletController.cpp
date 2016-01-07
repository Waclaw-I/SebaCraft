#include "BulletController.h"

#include <iostream>

using namespace std;

 vector <BulletBasicClass *>  BulletController::ArrayOfBullets;

void BulletController::InsertNewBullet(BulletBasicClass * bullet)
{
	ArrayOfBullets.push_back(bullet);
}

void BulletController::MoveBullets()
{
	for (int i = 0; i < ArrayOfBullets.size(); i++)
	{
		ArrayOfBullets[i]->Move();
		if (ArrayOfBullets[i]->Collision())
		{
			delete ArrayOfBullets[i];
			ArrayOfBullets.erase(ArrayOfBullets.begin() + i);
		}
		ArrayOfBullets[i]->DecreaseDuration(0.0166);
		if (ArrayOfBullets[i]->GetDuration() < 0)
		{
			delete ArrayOfBullets[i];
			ArrayOfBullets.erase(ArrayOfBullets.begin() + i);
		}
	}
}
