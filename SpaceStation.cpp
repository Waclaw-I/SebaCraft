#include "SpaceStation.h"
#include <iostream>

using namespace std;


SpaceStation::SpaceStation(double rotationSpeed, double scale) : EnemyShip(0, 0, 0, 500, 0, 0, 0, 90)
{
	MyGraph = new SpriteHolder(LoadController::ShipTexturesArray[3], LoadController::ShipTexturesArray[3].Get_x(), LoadController::ShipTexturesArray[3].Get_y(), rotation, scale);
	MyGraph->MySprite.setPosition(spawn_x, spawn_y);

	//MyGraph->MySprite.setOrigin(447, 448);

	cout << "Romiary stacji: x: " << MyGraph->Get_graphSize_x() << "	y: " << MyGraph->Get_graphSize_y() << endl;
	cout << "Romiary hitbox: x: " << MyGraph->Get_hitboxSize_x() << "	y: " << MyGraph->Get_hitboxSize_y() << endl;
	cout << "Srodek stacji: x: " << MyGraph->Get_x_center() << "	y: " << MyGraph->Get_y_center() << endl;


	this->rotationSpeed = rotationSpeed;
	SetShipSpawnPoints(-78, 1, 1, 78); // for this specific sprite
	CalculateSpawnPoints(); 

}

SpaceStation::~SpaceStation()
{
	delete MyGraph;
}

SpriteHolder * SpaceStation::Get_MyGraph() { return MyGraph; }

void SpaceStation::RotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;

	CalculateSpawnPoints();
}

void SpaceStation::RotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;

	CalculateSpawnPoints();
}


void SpaceStation::CalculateSpawnPoints()
{
	rotatedSmallFighterSP_x = smallFighterSpawnPoint.Get_x() * cos(GetRotationInRadians()) - smallFighterSpawnPoint.Get_y() * sin(GetRotationInRadians());
	rotatedSmallFighterSP_y = smallFighterSpawnPoint.Get_x() * sin(GetRotationInRadians()) + smallFighterSpawnPoint.Get_y() * cos(GetRotationInRadians());

	rotatedMedivacSP_x = medivacSpawnPoint.Get_x() * cos(GetRotationInRadians()) - medivacSpawnPoint.Get_y() * sin(GetRotationInRadians());
	rotatedMedivacSP_y = medivacSpawnPoint.Get_x() * sin(GetRotationInRadians()) + medivacSpawnPoint.Get_y() * cos(GetRotationInRadians());
}

void SpaceStation::SetShipSpawnPoints(int x1, int y1, int x2, int y2)
{
	smallFighterSpawnPoint.Set_x(x1);
	smallFighterSpawnPoint.Set_y(y1);
	medivacSpawnPoint.Set_x(x2);
	medivacSpawnPoint.Set_y(y2);
}

void SpaceStation::SpawnSmallFighter()
{
	SmallFighter * fighter = new SmallFighter(x + rotatedSmallFighterSP_x, y + rotatedSmallFighterSP_y);
	EnemyController::InsertNewEnemyShip(fighter);
}

void SpaceStation::SpawnMedivac()
{
	Medivac * medivac = new Medivac(x + rotatedMedivacSP_x, y + rotatedMedivacSP_y);
	EnemyController::InsertNewEnemyShip(medivac);
}