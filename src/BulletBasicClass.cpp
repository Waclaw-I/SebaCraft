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

void BulletBasicClass::Move() 
{
	if ((rotation >= 0) && (rotation < 90))					// +/+ quarter
	{
		position_x += speed *((90 - rotation) / 90);
		position_y += speed *(rotation / 90);
	}
	if ((rotation >= 90) && (rotation < 180))					// +/- quarter
	{
		position_x -= speed *((rotation - 90) / 90);
		position_y += speed *((180 - rotation) / 90);
	}
	if ((rotation >= 180) && (rotation < 270))					// -/- quarter
	{
		position_x -= speed *((270 - rotation) / 90);
		position_y -= speed *((rotation - 180) / 90);
	}
	if ((rotation >= 270) && (rotation < 360))					// -/+ quarter
	{
		position_x += speed *((rotation - 270) / 90);
		position_y -= speed *((360 - rotation) / 90);
	}
}
bool BulletBasicClass::Collision() { return false; }
bool BulletBasicClass::CollisionWithPlayer(Player *) { return false; }

double BulletBasicClass::GetDuration() { return duration; }
double BulletBasicClass::GetRotation() { return rotation; }

void BulletBasicClass::DecreaseDuration(double amount) { duration -= amount; }