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
		ArrayOfBullets[i]->Move(90);
	}
}