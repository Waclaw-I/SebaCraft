#pragma once


class Player
{
private:
	int actualHealth; // actual health, energy and capacity
	int actualEnergy;
	int actualCapacity;
	double actualSpeed_x;
	double actualSpeed_y;
	double acceleration; // how fast can you gain more speed
	double rotationSpeed;

	bool isAlive;

	int maxHealth;		// maximal amount at the moment. You can raise it by upgrades
	int maxEnergy;
	int maxCapacity;
	double maxSpeed; // we are in space though :P
	
	int size;		// Size of the ship. At this version we ll be able to buy one upgrade (at least I hope so)

	double x;
	double y;
	double rotation;

public:
	Player();

	void GainHealth(int);
	void GainEnergy(int);
	void GainCapacity(int);				// Adding values to the variables
	void Accelerate();
	void GainAcceleration(double);

	void LooseHealth(int);
	void LooseEnergy(int);
	void LooseCapacity(int);			// Substracting values from the variables
	void Break();
	void LooseAcceleration(double);
	void Die();

	double Get_x_Position();				// methods for returning position to Displayer class
	double Get_y_Position();
	double Get_Rotation();
	double Get_RotationSpeed();
	double Get_ActualSpeed_x();
	double Get_ActualSpeed_y();
	bool Get_IfAlive();


	void RotateLeft();
	void RotateRight();

	void Move();
};