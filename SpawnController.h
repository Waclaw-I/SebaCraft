#pragma once
#include "SpaceStation.h"

class SpawnController
{
public:
	static void SpawnEnemies(SpaceStation *);
private:
	static double timeToSpawn;
	static double timeTick;
};