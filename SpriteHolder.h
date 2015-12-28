#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TextureLoader;

class SpriteHolder
{

	friend class DisplayController;

private: // informations about size, not position in the game world!
	double size_x;
	double size_y;
	double rotation;
	double scale;

	double x_center;
	double y_center;

public:
	Sprite MySprite;

	double GetSize_x();
	double GetSize_y();
	double Get_rotation();
	double Get_size();
	double Get_x_center();
	double Get_y_center();


	



	SpriteHolder(TextureLoader &, double, double, double, double);
};