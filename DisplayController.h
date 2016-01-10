#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>

#include "SpriteHolder.h"
#include "LoadController.h"
#include "EnemyController.h"
#include "BulletController.h"

#include "EnemyShip.h"
#include "SmallFighter.h"
#include "Medivac.h"
#include "SpaceStation.h"

class DisplayController
{
public:

	static vector <SpriteHolder *>  ArrayOfSprites;

	DisplayController(int, int);

	void DisplayGameScreen();


private:


};