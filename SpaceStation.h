#pragma once
#include "EnemyShip.h"

class SpaceStation : public EnemyShip
{
public:
	SpaceStation(double, double);
	~SpaceStation();
	SpriteHolder * Get_MyGraph() override;

private:


};