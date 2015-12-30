#pragma once
#include "BulletBasicClass.h"
#include "SpriteHolder.h" // we need that to upload the graphic onto our bullet
#include "LoadController.h"
#include "Player.h"
#include <string>

using namespace std;

class PlayerBullets : public BulletBasicClass
{
public:

	PlayerBullets(double, double, int, double, double);
	virtual void Move(int) override;

	~PlayerBullets();

	SpriteHolder * GetBulletGraph() override;

private:

	SpriteHolder * BulletGraph;

	string tag;
};