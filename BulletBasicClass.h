#pragma once

class BulletBasicClass
{

public:

	BulletBasicClass(double, double, int, double, double);

	virtual void Move(int);

protected:

	double position_x;
	double position_y;

	double spawnPoint_x;
	double spawnPoint_y;

	int damage;
	double speed;
	double duration;
};