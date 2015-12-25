#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TextureLoader;

class SpriteHolder
{

	friend class DisplayController;

private: // informations about size, not position in the game world!
	double x;
	double y;
	double rotation;
	double size;

	double x_center;
	double y_center;

public:
	Sprite MySprite;

	double Get_x() { return x; }
	double Get_y() { return y; }
	double Get_rotation(){ return rotation; }
	double Get_size() { return size; }
	double Get_x_center() { return x_center; }
	double Get_y_center() { return y_center; }


	



	SpriteHolder(TextureLoader &, double, double, double, double);
};