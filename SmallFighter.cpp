#include "SmallFighter.h"

SmallFighter::SmallFighter(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation) :
	EnemyShip(spawn_x, spawn_y, acc, m_health, m_speed, att_pow, fire_rate, rotation)
{
	MyGraph = new SpriteHolder(LoadController::ShipTexturesArray[2], LoadController::ShipTexturesArray[2].Get_x(), LoadController::ShipTexturesArray[2].Get_y(), rotation, 1);
	MyGraph->MySprite.setPosition(spawn_x, spawn_y);

	this->size_x = MyGraph->GetSize_x();
	this->size_x = MyGraph->GetSize_y();
}

SpriteHolder * SmallFighter::Get_MyGraph() { return MyGraph; }