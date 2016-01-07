#include "SmallFighter.h"

#include <iostream>
using namespace std;

SmallFighter::SmallFighter(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation, double scale = 1) :
	EnemyShip(spawn_x, spawn_y, acc, m_health, m_speed, att_pow, fire_rate, rotation)
{
	MyGraph = new SpriteHolder(LoadController::ShipTexturesArray[2], LoadController::ShipTexturesArray[2].Get_x(), LoadController::ShipTexturesArray[2].Get_y(), rotation, scale);
	MyGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = MyGraph->GetSize_x();
	this->size_y = MyGraph->GetSize_y();

	accelerationDistance = 150; // our SmallFighter is supposed to sit on our back! He wont slow down until he gets this close to the Player
}

SmallFighter::~SmallFighter()
{
	cout << "Object of type SmallFighter has been destroyed" << endl;

	delete MyGraph;
}

SpriteHolder * SmallFighter::Get_MyGraph() { return MyGraph; }