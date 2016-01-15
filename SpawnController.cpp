#include "SpawnController.h"

double SpawnController::timeToSpawn = 5;
double SpawnController::timeTick = 0.0166;

void SpawnController::SpawnEnemies(SpaceStation * station)
{
	if (timeToSpawn <= 0)
	{
		station->SpawnMedivac();
		station->SpawnSmallFighter();
		timeToSpawn = 5;
	}
	else timeToSpawn -= timeTick;
}