#pragma once

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class LoadController
{
private:

public:
	int AmountOfShipTextures;
	int AmountOfBulletTextures;

	TextureLoader * ShipTexturesArray; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge
	TextureLoader * BulletTextureArray;

	LoadController(int, int);

	~LoadController();

	void LoadTextures();
};