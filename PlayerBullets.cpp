#include "PlayerBullets.h"

#include <iostream>

using namespace std;

PlayerBullets::PlayerBullets(double spawn_x, double spawn_y, int damage, double speed, double duration) : 
							BulletBasicClass(spawn_x, spawn_y, damage, speed, duration), tag("PlayerBullet") {}

void PlayerBullets::Move(int rotation) // temp
{
	position_x += 0.1;
	cout << "jestem pociskiem i sobie lece" << endl;
}