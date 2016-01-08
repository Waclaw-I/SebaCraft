#include "Player.h"

#include <iostream>

bool Player::MainCannonOneShooted = false;

Player::Player(int size_x, int size_y) // I need to change the style of gathering this data
	: actualHealth(100), actualEnergy(200), actualCapacity(50), actualSpeed_x(0), actualSpeed_y(0), acceleration(0.1),
	rotationSpeed(2.5), maxHealth(100), maxEnergy(200), maxCapacity(50), maxSpeed(2.5), damage(5),
	level(1), x(0), y(0), rotation(0), shootingSpeed(0.12), timeToShoot(0), isAlive(true) // shooting in seconds
{
				// Player position in the game world
				// rotation which is needed to rotate the ship and to calculate the vector of thrust
	tag = "Player";

	this->size_x = size_x;
	this->size_y = size_y;

	SetBulletSpawnPoints(38, -16, 38, 17); // spawn points for bullets for this specific ship

	Calculate_SP_Positions(); // First time calculations. Later we ll use it during rotation manoeuvers
}

double Player::Get_x_Position() {return x;}

double Player::Get_y_Position() {return y;}

int Player::GetSize_x() { return size_x; }

int Player::GetSize_y() { return size_y; }

double Player::Get_Rotation() {return rotation;}

double Player::Get_RotationInRadians()
{
	return (rotation * (3.14 / 180));
}

double Player::Get_RotationSpeed() {return rotationSpeed;}

double Player::Get_ActualSpeed_x() {return actualSpeed_x;}

double Player::Get_ActualSpeed_y() {return actualSpeed_y;}

double Player::Get_ShootingSpeed() {return shootingSpeed;}

double Player::Get_TimeToShoot() {return timeToShoot;}

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

void Player::SetTimeToShoot(double amount) // this is our counter for delaying shots
{ 
	if (timeToShoot <= shootingSpeed) timeToShoot += amount;
	else timeToShoot = 0;
}

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

void Player::Calculate_SP_Positions() // we can rotate our sprite, so we have to calculate new position of spawn points for bullets
{
	rotatedSpawnPoint1_x = BulletSpawn1.Get_x() * cos(Get_RotationInRadians()) - BulletSpawn1.Get_y() * sin(Get_RotationInRadians());
	rotatedSpawnPoint1_y = BulletSpawn1.Get_x() * sin(Get_RotationInRadians()) + BulletSpawn1.Get_y() * cos(Get_RotationInRadians());

	rotatedSpawnPoint2_x = BulletSpawn2.Get_x() * cos(Get_RotationInRadians()) - BulletSpawn2.Get_y() * sin(Get_RotationInRadians());
	rotatedSpawnPoint2_y = BulletSpawn2.Get_x() * sin(Get_RotationInRadians()) + BulletSpawn2.Get_y() * cos(Get_RotationInRadians());
}


void Player::RotateLeft()
{
	if (rotation < 0.1) rotation = 360;
	rotation -= rotationSpeed;

	Calculate_SP_Positions();
}

void Player::RotateRight()
{
	if (rotation > 359.9) rotation = 0;
	rotation += rotationSpeed;

	Calculate_SP_Positions();
}

void Player::Move()
{
	x += actualSpeed_x;
	y += actualSpeed_y;
}

void Player::ShootFromMainCannons()
{
	if (MainCannonOneShooted == false) // we shoot one time from the first cannon and then from another one
	{
		PlayerBullets * bullet = new PlayerBullets(x + rotatedSpawnPoint1_x, y + rotatedSpawnPoint1_y, damage, 10, 2, rotation);
		MainCannonOneShooted = true;
		BulletController::InsertNewBullet(bullet);
	}
	else
	{
		PlayerBullets * bullet = new PlayerBullets(x + rotatedSpawnPoint2_x, y + rotatedSpawnPoint2_y, damage, 10, 2, rotation);
		MainCannonOneShooted = false;
		BulletController::InsertNewBullet(bullet);
	}
	
}