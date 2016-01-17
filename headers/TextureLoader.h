#pragma once


#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class SpriteLoader;

class TextureLoader
{
	friend class SpriteHolder;
	friend class LoadController;



public:
	TextureLoader();

	double Get_x();
	double Get_y();

	void LoadTexture(string); // lokalizacja spawnpointow. To juz trzeba niestety wrzucac recznie przy tworzeniu sprite'a

private:
	Texture MyTexture;

	double x;
	double y;
};