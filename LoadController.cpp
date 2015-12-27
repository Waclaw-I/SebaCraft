#include "LoadController.h"
#include "TextureLoader.h"



LoadController::LoadController(int size) : AmountOfTextures(size)
{
	TexturesArray = new TextureLoader[AmountOfTextures];
}

void LoadController::LoadTextures()
{
	//for (int i = 0; i < AmountOfTextures; i++)
	//{
		TexturesArray[0].LoadTexture("Graphs\\Player\\BasicShip.png"); // We want to initialize all textures to prevent loading graphs during the game
		TexturesArray[1].LoadTexture("Graphs\\Enemies\\Medivac.png");
		TexturesArray[2].LoadTexture("Graphs\\Enemies\\SmallFighter.png");
	//}
}