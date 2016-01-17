#include "EnemyShip.h"
#include "Player.h"

using namespace std;
#include <iostream>

EnemyShip::EnemyShip(double spawn_x, double spawn_y, double acc, double m_health, double m_speed, int att_pow, double fire_rate, double rotation) :
	spawn_x(spawn_x), spawn_y(spawn_y), acceleration(acc), maxHealth(m_health), maxSpeed(m_speed), attackPower(att_pow),
	fireRate(fire_rate), rotation(rotation)
{
	tag = "Enemy";
	isAlive = true;

	actualHealth = maxHealth;

	actualSpeed_x = 0;
	actualSpeed_y = 0;

	rotationSpeed = 5; // its now working for now

	x = spawn_x;
	y = spawn_y;

	timeToShoot = 0;

	hpBar = new TextLabel(to_string(actualHealth) + "/" + to_string(maxHealth), 10, x, y);

	hpBar->UpdateHp(actualHealth, maxHealth);
	hpBar->SetColor(sf::Color::Green);
}

EnemyShip::~EnemyShip() { }


double EnemyShip::Get_x_Position() { return x; }

double EnemyShip::Get_y_Position() { return y; }

int EnemyShip::GetSize_x() { return size_x; }
int EnemyShip::GetSize_y() { return size_y; }

double EnemyShip::Get_Rotation() { return rotation; }

double EnemyShip::Get_RotationSpeed() { return rotationSpeed; }

double EnemyShip::Get_ActualSpeed_x() { return actualSpeed_x; }

double EnemyShip::Get_ActualSpeed_y() { return actualSpeed_y; }

double EnemyShip::GetActualHealth() { return actualHealth; }

double EnemyShip::GetRotationInRadians()
{
	return (rotation * (3.14 / 180));
}

bool EnemyShip::Get_IsAlive(){ return isAlive; }

void EnemyShip::UpdateHpBar()
{
	hpBar->SetPosition_x(x-widthOfHpBar);
	hpBar->SetPosition_y(y-heightOfHpBar);
	hpBar->UpdateTextPosition();
	hpBar->UpdateHp(actualHealth, maxHealth);

	if (actualHealth / maxHealth > 0.7) hpBar->SetColor(sf::Color::Green);
	if (actualHealth / maxHealth <= 0.7) hpBar->SetColor(sf::Color::Yellow);
	if (actualHealth / maxHealth <= 0.3) hpBar->SetColor(sf::Color::Red);
}


void EnemyShip::Die() { isAlive = false; }

void EnemyShip::LooseHealth(int amount) 
{ 
	actualHealth -= amount;
	if (actualHealth <= 0) Die();
}

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

void EnemyShip::Break()
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


void EnemyShip::Move()
{
	x += actualSpeed_x;
	y += actualSpeed_y;

	UpdateHpBar();
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

void EnemyShip::FollowPlayer(Player * player)
{
	if (player->Get_IfAlive() == true)
	{
		double direction = atan2(this->y - player->Get_y_Position(), this->x - player->Get_x_Position()) * (180/3.14);
		direction += 180;

		rotation = direction;
	}
	double distance = sqrt(pow(this->x - player->Get_x_Position(), 2) + pow(this->y - player->Get_y_Position(), 2));
	
	if (distance > accelerationDistance) Accelerate();
}

void EnemyShip::FollowAlly(EnemyShip * ally)
{
	if (ally->Get_IsAlive() == true)
	{
		double direction = atan2(this->y - ally->Get_y_Position(), this->x - ally->Get_x_Position()) * (180 / 3.14);
		direction += 180;

		rotation = direction;
	}
	double distance = sqrt(pow(this->x - ally->Get_x_Position(), 2) + pow(this->y - ally->Get_y_Position(), 2));

	if (distance > accelerationDistance) Accelerate();
}

void EnemyShip::Shoot(){}

void EnemyShip::CalculateSpawnPoints() {} // we can rotate our sprite, so we have to calculate new position of spawn points for bullets/ships

bool EnemyShip::SetTimeToShoot(double amount) // this is our counter for delaying shots
{ 
	if (timeToShoot <= fireRate) 
	{ 
		timeToShoot += amount;
		return false;
	}
	else 
	{
		timeToShoot = 0;
		return true;
	}
}