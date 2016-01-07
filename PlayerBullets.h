#pragma once
#include "BulletBasicClass.h"
#include "SpriteHolder.h" // we need that to upload the graphic onto our bullet
#include "LoadController.h"
#include "EnemyController.h"
#include "Player.h"
#include <string>

using namespace std;

class PlayerBullets : public BulletBasicClass
{
public:

	PlayerBullets(double, double, int, double, double, double);
	virtual void Move() override;
	virtual bool Collision() override;

	~PlayerBullets();

	SpriteHolder * GetBulletGraph() override;

private:

	SpriteHolder * BulletGraph;

	int qualityBoost;

	string tag;
};