#include "LoadController.h"
#include "TextureLoader.h"

TextureLoader LoadController::ShipTexturesArray[5]; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge
TextureLoader LoadController::BulletTextureArray[2];
TextureLoader LoadController::BackgroundTextureArray[2];

void LoadController::LoadTextures()
{

		ShipTexturesArray[0].LoadTexture("Graphs/Player/BasicShip.png"); // We want to initialize all textures to prevent loading graphs during the game
		ShipTexturesArray[1].LoadTexture("Graphs/Enemies/Medivac.png");
		ShipTexturesArray[2].LoadTexture("Graphs/Enemies/SmallFighter.png");
		ShipTexturesArray[3].LoadTexture("Graphs/Enemies/SpaceStation.png");
		ShipTexturesArray[4].LoadTexture("Graphs/Player/turret.png");

		BulletTextureArray[0].LoadTexture("Graphs/Bullets/MachineGunBullet.png");
		BulletTextureArray[1].LoadTexture("Graphs/Bullets/SmallFighterBullet.png");


		BackgroundTextureArray[0].LoadTexture("Graphs/Background/background_cosmic.png");
		BackgroundTextureArray[1].LoadTexture("Graphs/Background/background_asteroids.png");
}
