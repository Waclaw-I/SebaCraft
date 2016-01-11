#pragma once
#include "EnemyShip.h"
#include "LoadController.h"

class SmallFighter : public EnemyShip
{

public:
	SmallFighter(double, double, double, double, double, int, double, double, double);
	SmallFighter(double, double);
	~SmallFighter();
	SpriteHolder * Get_MyGraph() override;

private:

};