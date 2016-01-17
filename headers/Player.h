#pragma once

#include "SpawnPoint.h"
#include "PlayerBullets.h"
#include "BulletController.h"
#include "DrawableObject.h"
#include "RotatingCannon.h"
#include <string>
using namespace std;

class RotatingCannon;

class Player : public DrawableObject
{

public:
	Player();
	~Player();

	void GainHealth(int);
	void GainEnergy(int);
	void GainCapacity(int);				// Adding values to the variables
	void Accelerate();
	void GainAcceleration(double);

	void SetBulletSpawnPoints(int, int, int, int);
	void Calculate_SP_Positions();

	void LooseHealth(int);
	void LooseEnergy(int);
	void LooseCapacity(int);			// Substracting values from the variables
	void Break();
	void LooseAcceleration(double);
	void Die();

	double Get_x_Position();				// methods for returning position to Displayer class
	double Get_y_Position();
	int GetSize_x();
	int GetSize_y();
	double Get_Rotation();
	double Get_RotationInRadians();
	double Get_RotationSpeed();
	double Get_ActualSpeed_x();
	double Get_ActualSpeed_y();
	bool Get_IfAlive();
	RotatingCannon& GetRotatingCannon();
	
	void SetTimeToShoot(double);


	void RotateLeft();
	void RotateRight();

	double Get_ShootingSpeed();
	double Get_TimeToShoot();

	void Move();

	void ShootFromMainCannons();
	void UpdateRotatingCannon();

private:

	string tag;

	int size_x;
	int size_y;

	int actualHealth; // actual health, energy and capacity
	int actualEnergy;
	int actualCapacity;
	double actualSpeed_x;
	double actualSpeed_y;
	double acceleration; // how fast can you gain more speed
	double rotationSpeed;

	SpawnPoint BulletSpawn1;
	SpawnPoint BulletSpawn2;

	RotatingCannon* rotatingCannon; 

	double rotatedSpawnPoint1_x; // we need those to spawn bullets properly
	double rotatedSpawnPoint1_y;
	double rotatedSpawnPoint2_x;
	double rotatedSpawnPoint2_y;

	double shootingSpeed;
	double timeToShoot;
	double damage;

	bool isAlive;
	static bool MainCannonOneShooted;

	int maxHealth;		// maximal amount at the moment. You can raise it by upgrades
	int maxEnergy;
	int maxCapacity;
	double maxSpeed; // we are in space though :P
	
	int level;		// Level of the ship. At this version we ll be able to buy one upgrade (at least I hope so)

	double x;
	double y;
	double rotation;



};