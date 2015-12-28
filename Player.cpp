#include "Player.h"

#include <iostream>

Player::Player(int size_x, int size_y)
	: actualHealth(100), actualEnergy(200), actualCapacity(50), actualSpeed_x(0), actualSpeed_y(0), acceleration(0.1),
	rotationSpeed(2.5), maxHealth(100), maxEnergy(200), maxCapacity(50), maxSpeed(2.5),
	level(1), x(100), y(100), rotation(0), isAlive(true)
{
				// Player position in the game world
				// rotation which is needed to rotate the ship and to calculate the vector of thrust
	tag = "Player";

	this->size_x = size_x;
	this->size_y = size_y;

	SetBulletSpawnPoints(80, 8, 80, 41); // spawn points for bullets for this specific ship
}

double Player::Get_x_Position() {return x;}

double Player::Get_y_Position() {return y;}

int Player::GetSize_x() { return size_x; }

int Player::GetSize_y() { return size_y; }

double Player::Get_Rotation() {return rotation;}

double Player::Get_RotationSpeed() {return rotationSpeed;}

double Player::Get_ActualSpeed_x() {return actualSpeed_x;}

double Player::Get_ActualSpeed_y() {return actualSpeed_y;}

bool Player::Get_IfAlive() { return isAlive; }

void Player::GainHealth(int amount) {if (actualHealth < maxHealth) actualHealth += amount;}

void Player::GainEnergy(int amount) {if (actualEnergy < maxEnergy) actualEnergy += amount;}

void Player::GainCapacity(int amount) {if (actualCapacity < maxCapacity) actualCapacity += amount;}

void Player::GainAcceleration(double amount) {acceleration += amount;}

void Player::SetBulletSpawnPoints(int x1, int y1, int x2, int y2)
{
	BulletSpawn1.Set_x(x1);
	BulletSpawn1.Set_y(y1);
	BulletSpawn2.Set_x(x2);
	BulletSpawn2.Set_y(y2);
}

void Player::LooseHealth(int amount) {actualHealth -= amount;}

void Player::LooseEnergy(int amount) {if (actualEnergy > 0) actualEnergy -= amount;}

void Player::LooseCapacity(int amount) {if (actualCapacity > 0) actualCapacity -= amount;}

void Player::Die() { isAlive = false; }

void Player::Accelerate()
{

		if ((rotation >= 0) && (rotation <= 90))					// +/+ quarter
		{
			if (actualSpeed_x < maxSpeed)	actualSpeed_x += acceleration *((90 - rotation) / 90);
			if (actualSpeed_y < maxSpeed)	actualSpeed_y += acceleration*(rotation / 90);
		}
		if ((rotation >= 90) && (rotation <= 180))					// +/- quarter
		{
			if (actualSpeed_x > -maxSpeed)	actualSpeed_x -= acceleration *((rotation-90) / 90);
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




void Player::Break()
{
	if (actualSpeed_x > 0)
	{
		actualSpeed_x -= acceleration;
		if (actualSpeed_x < 0.001) actualSpeed_x = 0;
	}
	if (actualSpeed_y > 0)
	{
		actualSpeed_y -= acceleration;
		if (actualSpeed_y < 0.001) actualSpeed_y = 0;
	}
	if (actualSpeed_x < 0)
	{
		actualSpeed_x += acceleration;
		if (actualSpeed_x > -0.001) actualSpeed_x = 0;
	}
	if (actualSpeed_y < 0)
	{
		actualSpeed_y += acceleration;
		if (actualSpeed_y > -0.001) actualSpeed_y = 0;
	}
}

void Player::LooseAcceleration(double amount)
{
	acceleration -= amount;
}


void Player::RotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;
}

void Player::RotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;
}

void Player::Move()
{
	x += actualSpeed_x;
	y += actualSpeed_y;
}

void Player::ShootFromMainCannons()
{
	PlayerBullets * bullet = new PlayerBullets(BulletSpawn1.Get_x(), BulletSpawn1.Get_y(), 1, 2, 5); // to tez sie wykonuje
	BulletController::InsertNewBullet(bullet);
}