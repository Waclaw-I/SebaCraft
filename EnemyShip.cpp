#include "EnemyShip.h"
#include "Player.h"

//using namespace std;
//#include <iostream>


double EnemyShip::Get_x_Position() { return x; }

double EnemyShip::Get_y_Position() { return y; }

int EnemyShip::GetSize_x() { return x; }
int EnemyShip::GetSize_y() { return y; }

double EnemyShip::Get_Rotation() { return rotation; }

double EnemyShip::Get_ActualSpeed_x() { return actualSpeed_x; }

double EnemyShip::Get_ActualSpeed_y() { return actualSpeed_y; }

bool EnemyShip::Get_IsAlive(){ return isAlive; }

void EnemyShip::LooseHealth(int amount) { actualHealth -= amount; }

EnemyShip::EnemyShip(int size_x, int size_y)
{
	tag = "Enemy";

	this->size_x = size_x;
	this->size_y = size_y;

	maxHealth = 100;
	maxSpeed = 1.5;

	actualHealth = maxHealth;
	actualSpeed_x = 0;
	actualSpeed_y = 0;

	acceleration = 0.1;

	fireRate = 0.2;
	attackPower = 1;

	rotation = 90;
	rotationSpeed = 5;

	x = 300;
	y = 300;


}

void EnemyShip::Die() { isAlive = false; }

void EnemyShip::Accelerate()
{
		if ((rotation >= 0) && (rotation <= 90))					// +/+ quarter
		{
			if (actualSpeed_x < maxSpeed)	actualSpeed_x += acceleration *((90 - rotation) / 90);
			if (actualSpeed_y < maxSpeed)	actualSpeed_y += acceleration*(rotation / 90);
		}
		if ((rotation >= 90) && (rotation <= 180))					// +/- quarter
		{
			if (actualSpeed_x > -maxSpeed)	actualSpeed_x -= acceleration *((rotation - 90) / 90);
			if (actualSpeed_y < maxSpeed)	actualSpeed_y += acceleration*((180 - rotation) / 90);
		}
		if ((rotation >= 180) && (rotation <= 270))					// -/- quarter
		{
			if (actualSpeed_x > -maxSpeed)	actualSpeed_x -= acceleration *((270 - rotation) / 90);
			if (actualSpeed_y > -maxSpeed)	actualSpeed_y -= acceleration *((rotation - 180) / 90);
		}
		if ((rotation >= 270) && (rotation <= 360))					// -/+ quarter
		{
			if (actualSpeed_x < maxSpeed)	actualSpeed_x += acceleration *((rotation - 270) / 90);
			if (actualSpeed_y > -maxSpeed)	actualSpeed_y -= acceleration *((360 - rotation) / 90);
		}
}

void EnemyShip::Move()
{
	x += actualSpeed_x;
	y += actualSpeed_y;
}

void EnemyShip::RotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;
}

void EnemyShip::RotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;
}

void EnemyShip::FollowPlayer(Player player)
{
	if (player.Get_IfAlive() == true)
	{
		double direction = atan2(this->y - player.Get_y_Position(), this->x - player.Get_x_Position()) * (180/3.14);
		direction += 180;

		rotation = direction;



	}

	Accelerate();


}
