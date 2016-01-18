#include "Medivac.h"

#include <iostream>
using namespace std;


Medivac::Medivac(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation, double scale = 1) :
	EnemyShip(spawn_x, spawn_y, acc, m_health, m_speed, att_pow, fire_rate, rotation)
{
	tag = "Medivac";

	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[1], LoadController::ShipTexturesArray[1].Get_x(), LoadController::ShipTexturesArray[1].Get_y(), rotation, scale);
	myGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = myGraph->Get_hitboxSize_x();
	this->size_y = myGraph->Get_hitboxSize_y();

	accelerationDistance = 200; // Medivac will try to hide behind mainforce and heal his allies
	heightOfHpBar = (myGraph->Get_graphSize_y() / 2) + 10;
	widthOfHpBar = (myGraph->Get_graphSize_y() / 2);
}

Medivac::Medivac(double spawn_x, double spawn_y) : EnemyShip(spawn_x, spawn_y, 0.15, 70, 2, 1, 1, 90)
{
	myGraph = new SpriteHolder(LoadController::ShipTexturesArray[1], LoadController::ShipTexturesArray[1].Get_x(), LoadController::ShipTexturesArray[1].Get_y(), rotation, 1);
	myGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = myGraph->Get_hitboxSize_x();
	this->size_y = myGraph->Get_hitboxSize_y();

	accelerationDistance = 200;
	heightOfHpBar = (myGraph->Get_graphSize_y() / 2) + 10;
	widthOfHpBar = (myGraph->Get_graphSize_y() / 2);
}

Medivac::~Medivac(){}
