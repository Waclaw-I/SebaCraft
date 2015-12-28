#include "SpriteHolder.h"
#include "TextureLoader.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


SpriteHolder::SpriteHolder(TextureLoader & Texture, double size_x, double size_y, double rotation, double scale = 1 )
{
	MySprite.setTexture(Texture.MyTexture);
	this->size_x = size_x*scale;
	this->size_y = size_y*scale;
	this->rotation = rotation;
	this->scale = scale;



	this->x_center = this->size_x / 2;
	this->y_center = this->size_y / 2;

	MySprite.setOrigin(this->x_center, this->y_center);
	MySprite.scale(scale, scale);
}

double SpriteHolder::GetSize_x() { return size_x; }

double SpriteHolder::GetSize_y() { return size_y; }

double SpriteHolder::Get_rotation() { return rotation; }

double SpriteHolder::Get_size() { return scale; }

double SpriteHolder::Get_x_center() { return x_center; }

double SpriteHolder::Get_y_center() { return y_center; }