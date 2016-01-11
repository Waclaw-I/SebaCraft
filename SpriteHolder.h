#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TextureLoader;

class SpriteHolder
{

	friend class DisplayController;

private: // informations about size, not position in the game world!
	double hitboxSize_x;
	double hitboxSize_y;
	double graphSize_x;
	double graphSize_y;
	double rotation;
	double scale;

	double x_center;
	double y_center;

	bool isLogicAlive;

public:
	Sprite MySprite;

	double Get_hitboxSize_x();
	double Get_hitboxSize_y();
	double Get_graphSize_x();
	double Get_graphSize_y();
	double Get_rotation();
	double Get_size();
	double Get_x_center();
	double Get_y_center();

	bool Get_isLogicAlive();
	void LogicIsDead();


	



	SpriteHolder(TextureLoader &, double, double, double, double);
};