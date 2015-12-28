#include "PlayerController.h"

using namespace sf;
using namespace std;


void PlayerController::Moving(Player & Sebamus)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Sebamus.RotateLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Sebamus.RotateRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Sebamus.Accelerate();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Sebamus.Break();
	}

	Sebamus.Move();
}

void PlayerController::Shooting(Player & Sebamus)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		Sebamus.ShootFromMainCannons(); // to sie wykonuje
	}
}