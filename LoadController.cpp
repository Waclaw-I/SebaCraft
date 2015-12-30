#include "LoadController.h"
#include "TextureLoader.h"

TextureLoader LoadController::ShipTexturesArray[3]; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge
TextureLoader LoadController::BulletTextureArray[1];

void LoadController::LoadTextures()
{

		ShipTexturesArray[0].LoadTexture("Graphs\\Player\\BasicShip.png"); // We want to initialize all textures to prevent loading graphs during the game
		ShipTexturesArray[1].LoadTexture("Graphs\\Enemies\\Medivac.png");
		ShipTexturesArray[2].LoadTexture("Graphs\\Enemies\\SmallFighter.png");


		BulletTextureArray[0].LoadTexture("Graphs\\Bullets\\MachineGunBullet.png");
}
