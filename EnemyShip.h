#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>

class EnemyShip // this is our parent class of the enemy. Everything what every enemy should have.
{
protected:

	string tag;

	int actualHealth;
	double actualSpeed_x;
	double actualSpeed_y;
	double acceleration;

	double maxHealth;
	double maxSpeed;

	int attackPower;
	double fireRate;

	int size_x;
	int size_y;

	double x;
	double y;
	double rotation;
	double rotationSpeed;

	bool isAlive;


public:

	EnemyShip(int size_x, int size_y );

	double Get_x_Position();
	double Get_y_Position();
	int GetSize_x();
	int GetSize_y();
	double Get_Rotation();
	double Get_ActualSpeed_x();
	double Get_ActualSpeed_y();

	bool Get_IsAlive();


	void LooseHealth(int);
	void Accelerate();
	void RotateLeft();
	void RotateRight();
	void Die();
	void Move();

	void FollowPlayer(Player);
	void FollowAlly(EnemyShip);

};