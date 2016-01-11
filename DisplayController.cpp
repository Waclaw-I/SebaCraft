#include "DisplayController.h"

#include <SFML/Graphics.hpp>


vector <SpriteHolder *>  DisplayController::ArrayOfSprites;

void DisplayController::InitializeLevel()
{
	SpriteHolder * Background1 = new SpriteHolder(LoadController::BackgroundTextureArray[0], LoadController::BackgroundTextureArray[0].Get_x(), LoadController::BackgroundTextureArray[0].Get_y(), 0, 1.2);
	SpriteHolder * Background2 = new SpriteHolder(LoadController::BackgroundTextureArray[1], LoadController::BackgroundTextureArray[1].Get_x(), LoadController::BackgroundTextureArray[1].Get_y(), 0, 0.5);

	Background1->MySprite.setPosition(0, 0);
	Background2->MySprite.setPosition(0, 0);

	InsertNewSprite(Background1);
	InsertNewSprite(Background2);
}

void DisplayController::InsertNewSprite(SpriteHolder * sprite)
{
	ArrayOfSprites.push_back(sprite);
}

void DisplayController::UpdatePlayerGraph(Player * player)
{
	player->GetLevelOneGraph()->MySprite.setPosition(player->Get_x_Position(), player->Get_y_Position());
	player->GetLevelOneGraph()->MySprite.setRotation(player->Get_Rotation());
}

void DisplayController::CheckIfDestroyed()
{
	for (int i = 0; i < ArrayOfSprites.size(); i++)
	{
		if (ArrayOfSprites[i]->Get_isLogicAlive() == false)
		{
			ArrayOfSprites.erase(ArrayOfSprites.begin() + i); // we just need to resize our array. Pointer is deleted in object destructor
		}
	}
}