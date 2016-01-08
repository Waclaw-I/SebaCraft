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

}

SpaceStation::~SpaceStation()
{
	delete MyGraph;
}

SpriteHolder * SpaceStation::Get_MyGraph() { return MyGraph; }