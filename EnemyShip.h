#pragma once
#include "Player.h"

#include <SFML/Graphics.hpp>
#include <math.h>

class Player;



class EnemyShip // this is our parent class of the enemy. Everything what every enemy should have.
{

public:

	EnemyShip(double, double, double, double, double, int, double, double); // spawn_x, spawn_y, acc, m_health, m_speed, att_pow, firerate, rotation
	virtual ~EnemyShip();

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
	void Break();
	void RotateLeft();
	void RotateRight();
	void Die();
	void Move();

	virtual SpriteHolder * Get_MyGraph();

	void FollowPlayer(Player *);
	void FollowAlly(EnemyShip *);

protected:

	string tag;

	double spawn_x;
	double spawn_y;

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

	double accelerationDistance; // depends on type of ship. SmallFighters are supposed to get close

	bool isAlive;

	SpriteHolder * MyGraph; // we need that just to be able to override our Get_MyGraph method




};