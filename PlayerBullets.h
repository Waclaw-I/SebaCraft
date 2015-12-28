#pragma once
#include "BulletBasicClass.h"
#include "Player.h"
#include <string>

using namespace std;

class PlayerBullets : public BulletBasicClass
{
public:

	PlayerBullets(double, double, int, double, double);
	virtual void Move(int) override;

private:

	string tag;
};