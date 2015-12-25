#pragma once

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

class LoadController
{
private:

public:
	int AmountOfTextures;
	TextureLoader * TexturesArray; // Table with our textures, where 0 is for player. There is need of texture position in table knownledge

	LoadController(int);

	void LoadTextures();
};