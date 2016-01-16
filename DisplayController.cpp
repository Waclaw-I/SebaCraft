#include "DisplayController.h"
#include "BulletController.h"

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


vector <DrawableObject *>  DisplayController::ArrayOfDrawableObjects;

void DisplayController::InitializeLevel()
{
	DrawableObject * Background1 = new DrawableObject();
	DrawableObject * Background2 = new DrawableObject();
	SpriteHolder * bg1 = new SpriteHolder(LoadController::BackgroundTextureArray[0], LoadController::BackgroundTextureArray[0].Get_x(), LoadController::BackgroundTextureArray[0].Get_y(), 0, 1.5);
	SpriteHolder * bg2 = new SpriteHolder(LoadController::BackgroundTextureArray[1], LoadController::BackgroundTextureArray[1].Get_x(), LoadController::BackgroundTextureArray[1].Get_y(), 0, 0.5);
	Background1->SetMyGraph(bg1);
	Background2->SetMyGraph(bg2);

	Background1->GetMyGraph()->MySprite.setPosition(0, 0);
	Background2->GetMyGraph()->MySprite.setPosition(0, 0);

	InsertNewDrawableObject(Background1);
	InsertNewDrawableObject(Background2);
}

void DisplayController::InsertNewDrawableObject(DrawableObject * object)
{
	ArrayOfDrawableObjects.push_back(object);
}

void DisplayController::UpdatePlayerGraph(Player * player)
{
	player->GetMyGraph()->MySprite.setPosition(player->Get_x_Position(), player->Get_y_Position());
	player->GetMyGraph()->MySprite.setRotation(player->Get_Rotation());
}

void DisplayController::CheckIfDestroyed()
{
	for (int i = 0; i < ArrayOfDrawableObjects.size(); i++)
	{
		if (ArrayOfDrawableObjects[i]->GetMyGraph()->Get_isLogicAlive() == false)
		{
			
			delete ArrayOfDrawableObjects[i];
			ArrayOfDrawableObjects.erase(ArrayOfDrawableObjects.begin() + i); // we just need to resize our array. Pointer is deleted in object destructor
		}
	}
}