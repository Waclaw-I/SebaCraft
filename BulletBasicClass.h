#pragma once

#include "SpriteHolder.h"

class BulletBasicClass
{

public:

	BulletBasicClass(double, double, int, double, double);
	virtual ~BulletBasicClass(); // virtual destructor will asure that every destructor of child classes ll be executed

	virtual void Move(int);
	virtual double GetDuration();

	virtual SpriteHolder * GetBulletGraph() { return BulletGraph; } // this method ll be overrided

	double GetPosition_x();
	double GetPosition_y();

protected:

	double position_x;
	double position_y;

	double spawnPoint_x;
	double spawnPoint_y;

	int damage;
	double speed;
	double duration;

	SpriteHolder * BulletGraph; // we need this just to complete the definition of GetBulletGraph method

};