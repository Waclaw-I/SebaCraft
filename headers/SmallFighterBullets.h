#pragma once
#include "BulletBasicClass.h"
#include "Player.h"

class SmallFighterBullets : public BulletBasicClass
{
public:

	SmallFighterBullets(double, double, int, double, double, double);

	virtual bool CollisionWithPlayer(Player *) override;

	~SmallFighterBullets();


private:


	int qualityBoost;

	string tag;
};
