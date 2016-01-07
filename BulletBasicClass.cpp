#include "BulletBasicClass.h"

#include <iostream>
#include <cstdlib>

using namespace std;

BulletBasicClass::BulletBasicClass(double spawn_x, double spawn_y, int damage, double speed, double duration, double rotation)
{
	this->spawnPoint_x = spawn_x;
	this->spawnPoint_y = spawn_y;
	this->damage = damage;
	this->speed = speed;
	this->duration = duration;
	this->rotation = rotation;

	position_x = spawnPoint_x;
	position_y = spawnPoint_y;

	quality = rand() % 100;
}

double BulletBasicClass::GetPosition_x() { return position_x; }
double BulletBasicClass::GetPosition_y() { return position_y; }
int BulletBasicClass::GetQuality() { return quality; }



BulletBasicClass::~BulletBasicClass() {}

void BulletBasicClass::Move() {}
bool BulletBasicClass::Collision() { return false; }

double BulletBasicClass::GetDuration() { return duration; }
double BulletBasicClass::GetRotation() { return rotation; }

void BulletBasicClass::DecreaseDuration(double amount) { duration -= amount; }