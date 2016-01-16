#pragma once

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class LoadController
{
private:

public:

	static TextureLoader ShipTexturesArray[4]; // Table with our textures, where 0 is for player.
	static TextureLoader BulletTextureArray[2];
	static TextureLoader BackgroundTextureArray[2];

	static sf::Font * FontsArray;


	static void LoadTextures();
	static void LoadFonts();
};