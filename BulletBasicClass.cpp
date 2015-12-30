#include "BulletBasicClass.h"

#include <iostream>

using namespace std;

BulletBasicClass::BulletBasicClass(double spawn_x, double spawn_y, int damage, double speed, double duration)
{
	this->spawnPoint_x = spawn_x;
	this->spawnPoint_y = spawn_y;
	this->damage = damage;
	this->speed = speed;
	this->duration = duration;

	position_x = spawnPoint_x;
	position_y = spawnPoint_y;
}

double BulletBasicClass::GetPosition_x() { return position_x; }
double BulletBasicClass::GetPosition_y() { return position_y; }

BulletBasicClass::~BulletBasicClass() {}

void BulletBasicClass::Move(int rotation) {}

double BulletBasicClass::GetDuration() { return duration; }