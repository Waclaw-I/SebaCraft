#include "LoadController.h"
#include "TextureLoader.h"

#include <iostream>

TextureLoader LoadController::ShipTexturesArray[4]; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge
TextureLoader LoadController::BulletTextureArray[2];
TextureLoader LoadController::BackgroundTextureArray[2];
sf::Font * LoadController::FontsArray = new sf::Font[1];

void LoadController::LoadTextures()
{

		ShipTexturesArray[0].LoadTexture("Graphs/Player/BasicShip.png"); // We want to initialize all textures to prevent loading graphs during the game
		ShipTexturesArray[1].LoadTexture("Graphs/Enemies/Medivac.png");
		ShipTexturesArray[2].LoadTexture("Graphs/Enemies/SmallFighter.png");
		ShipTexturesArray[3].LoadTexture("Graphs/Enemies/SpaceStation.png");

		BulletTextureArray[0].LoadTexture("Graphs/Bullets/MachineGunBullet.png");
		BulletTextureArray[1].LoadTexture("Graphs/Bullets/SmallFighterBullet.png");


		BackgroundTextureArray[0].LoadTexture("Graphs/Background/background_cosmic.png");
		BackgroundTextureArray[1].LoadTexture("Graphs/Background/background_asteroids.png");

		
}

void LoadController::LoadFonts()
{
	FontsArray[0].loadFromFile("Fonts/Starcraft.otf");
}
