#pragma once

#include <SFML/Graphics.hpp>


#include "SpriteHolder.h"
#include "LoadController.h"
#include "EnemyController.h"

class Player; // suddenly I have to redeclarate Player class


class DisplayController
{
public:

	static vector <SpriteHolder *>  ArrayOfSprites;

	void static InitializeLevel();

	void static InsertNewSprite(SpriteHolder *);

	void static CheckIfDestroyed();

	void static UpdatePlayerGraph(Player *);



private:


};