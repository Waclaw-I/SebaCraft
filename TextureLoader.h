#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class SpriteLoader;

class TextureLoader
{
	friend class SpriteHolder;
	friend class LoadController;
private:
	Texture MyTexture;

	double x;
	double y;

public:
	TextureLoader();

	double Get_x();
	double Get_y();

	void LoadTexture(string);
};