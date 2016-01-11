#include "PlayerController.h"

using namespace sf;
using namespace std;


void PlayerController::Moving(Player * player)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->RotateLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->RotateRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->Accelerate();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->Break();
	}

	player->Move();
}

void PlayerController::Shooting(Player * player)
{
	if (Keyboard::isKeyPressed(Keyboard::Space) && (player->Get_TimeToShoot() >= player->Get_ShootingSpeed()))
	{
		player->ShootFromMainCannons();
	}
	player->SetTimeToShoot(0.0166);

}