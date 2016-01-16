#pragma once

#include <SFML/Graphics.hpp>


#include "SpriteHolder.h"
#include "LoadController.h"
#include "EnemyController.h"
#include "DrawableObject.h"

class Player; // suddenly I have to redeclarate Player class


class DisplayController
{
public:

	static vector <DrawableObject *>  ArrayOfDrawableObjects;

	void static InitializeLevel();

	void static InsertNewDrawableObject(DrawableObject *);

	void static CheckIfDestroyed();

	void static UpdatePlayerGraph(Player *);



private:


};