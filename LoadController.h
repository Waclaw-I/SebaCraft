#pragma once

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class LoadController
{
private:

public:

	static TextureLoader ShipTexturesArray[3]; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge
	static TextureLoader BulletTextureArray[1];


	static void LoadTextures();
};