#pragma once
#include "EnemyShip.h"


class Medivac : public EnemyShip
{
public:

	Medivac(double, double, double, double, double, int, double, double, double);
	SpriteHolder * Get_MyGraph() override;

private:
};