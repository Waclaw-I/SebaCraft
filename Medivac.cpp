#include "Medivac.h"

#include <iostream>
using namespace std;


Medivac::Medivac(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation, double scale = 1) :
	EnemyShip(spawn_x, spawn_y, acc, m_health, m_speed, att_pow, fire_rate, rotation)
{
	MyGraph = new SpriteHolder(LoadController::ShipTexturesArray[1], LoadController::ShipTexturesArray[1].Get_x(), LoadController::ShipTexturesArray[1].Get_y(), rotation, scale);
	MyGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = MyGraph->Get_hitboxSize_x();
	this->size_y = MyGraph->Get_hitboxSize_y();

	accelerationDistance = 200; // Medivac will try to hide behind mainforce and heal his allies
}

Medivac::Medivac(double spawn_x, double spawn_y) : EnemyShip(spawn_x, spawn_y, 0.15, 100, 2, 1, 1, 90)
{
	MyGraph = new SpriteHolder(LoadController::ShipTexturesArray[1], LoadController::ShipTexturesArray[1].Get_x(), LoadController::ShipTexturesArray[1].Get_y(), rotation, 1);
	MyGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = MyGraph->Get_hitboxSize_x();
	this->size_y = MyGraph->Get_hitboxSize_y();

	accelerationDistance = 200;
}

Medivac::~Medivac()
{
	delete MyGraph;
}

SpriteHolder * Medivac::Get_MyGraph() { return MyGraph; }