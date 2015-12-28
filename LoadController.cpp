#include "LoadController.h"
#include "TextureLoader.h"



LoadController::LoadController(int ShipAmount, int BulletAmount) : AmountOfShipTextures(ShipAmount), AmountOfBulletTextures(BulletAmount)
{
	ShipTexturesArray = new TextureLoader[AmountOfShipTextures];
	BulletTextureArray = new TextureLoader[AmountOfBulletTextures];
}

void LoadController::LoadTextures()
{

		ShipTexturesArray[0].LoadTexture("Graphs\\Player\\BasicShip.png"); // We want to initialize all textures to prevent loading graphs during the game
		ShipTexturesArray[1].LoadTexture("Graphs\\Enemies\\Medivac.png");
		ShipTexturesArray[2].LoadTexture("Graphs\\Enemies\\SmallFighter.png");


		BulletTextureArray[0].LoadTexture("Graphs\\Bullets\\MachineGunBullet.png"); // no spawnpoint 
}

LoadController::~LoadController()
{
	delete [] ShipTexturesArray;
	delete [] BulletTextureArray;
}