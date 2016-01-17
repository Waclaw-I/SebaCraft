#pragma once
#include "EnemyShip.h"


class EnemyShip;

class Medivac : public EnemyShip
{
public:

	Medivac(double, double, double, double, double, int, double, double, double);
	Medivac(double, double);
	~Medivac();

private:
};