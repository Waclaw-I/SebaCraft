#pragma once

#include "SpriteHolder.h"


class Player;


class BulletBasicClass
{

public:

	BulletBasicClass(double, double, int, double, double, double);
	virtual ~BulletBasicClass(); // virtual destructor will asure that every destructor of child classes ll be executed

	virtual void Move();
	virtual double GetDuration();
	virtual bool Collision();
	virtual bool CollisionWithPlayer(Player *);
	void DecreaseDuration(double);

	virtual SpriteHolder * GetBulletGraph() { return BulletGraph; } // this method ll be overrided

	double GetPosition_x();
	double GetPosition_y();
	double GetRotation();
	int GetQuality();

protected:

	double position_x;
	double position_y;

	double spawnPoint_x;
	double spawnPoint_y;

	int damage;
	double speed;
	double duration;
	double rotation;

	int quality; // if lower than 2o (%) our bullet will miss the target

	SpriteHolder * BulletGraph; // we need this just to complete the definition of GetBulletGraph method

};