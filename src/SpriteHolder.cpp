#include "SpriteHolder.h"
#include "TextureLoader.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


SpriteHolder::SpriteHolder(TextureLoader & Texture, double size_x, double size_y, double rotation, double scale)
{
	MySprite.setTexture(Texture.MyTexture);
	this->hitboxSize_x = size_x*scale*0.8; // magic number for cosmetic purpose only 
	this->hitboxSize_y = size_y*scale*0.8;
	this->graphSize_x = size_x*scale;
	this->graphSize_y = size_y*scale;
	this->rotation = rotation;
	this->scale = scale;



	this->x_center = (this->graphSize_x / 2);
	this->y_center = (this->graphSize_y / 2);

	MySprite.scale(scale, scale);
	MySprite.setOrigin(size_x/2, size_y/2);

	isLogicAlive = true;

}

SpriteHolder::~SpriteHolder() {}

double SpriteHolder::Get_hitboxSize_x() { return hitboxSize_x; }

double SpriteHolder::Get_hitboxSize_y() { return hitboxSize_y; }

double SpriteHolder::Get_graphSize_x() { return graphSize_x; }

double SpriteHolder::Get_graphSize_y() { return graphSize_y; }

double SpriteHolder::Get_rotation() { return rotation; }

double SpriteHolder::Get_size() { return scale; }

double SpriteHolder::Get_x_center() { return x_center; }

double SpriteHolder::Get_y_center() { return y_center; }

bool SpriteHolder::Get_isLogicAlive() { return isLogicAlive; }

void SpriteHolder::LogicIsDead() { isLogicAlive = false; }

