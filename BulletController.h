#pragma once
#include <vector>

#include "BulletBasicClass.h"

using namespace std;


class BulletController
{
public:
	void static InsertNewBullet(BulletBasicClass *);
	void static MoveBullets();

	static vector <BulletBasicClass *>  ArrayOfBullets;
};