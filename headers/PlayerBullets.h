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
	virtual bool Collision() override;

	~PlayerBullets();


private:


	int qualityBoost;

	string tag;
};