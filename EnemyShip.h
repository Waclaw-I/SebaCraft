#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>

class EnemyShip // this is our parent class of the enemy. Everything what every enemy should have.
{
protected:

	int actualHealth;
	double actualSpeed_x;
	double actualSpeed_y;
	double acceleration;

	double maxHealth;
	double maxSpeed;

	int attackPower;
	double fireRate;

	double x;
	double y;
	double rotation;
	double rotationSpeed;

	bool isAlive;


public:

	EnemyShip(int HP, double Acc, double RS, int MHP, double MS, int _x, int _y, double _rotation, int AP, double FR );

	double Get_x_Position();
	double Get_y_Position();
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