#pragma once
#include <vector>

#include "BulletBasicClass.h"
#include "SpriteHolder.h"

using namespace std;


class BulletController
{
public:
	void static InsertNewBullet(BulletBasicClass *);
	void static MoveBullets();
	void static UpdateSpritesPosition(int);


	static vector <BulletBasicClass *>  ArrayOfBullets;

	static Player * player;

private:

	
};