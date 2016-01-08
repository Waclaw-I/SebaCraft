#pragma once

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class LoadController
{
private:

public:

	static TextureLoader ShipTexturesArray[4]; // Table with our textures, where 0 is for player.
	static TextureLoader BulletTextureArray[1];
	static TextureLoader BackgroundTextureArray[2];


	static void LoadTextures();
};