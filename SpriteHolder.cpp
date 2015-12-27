#include "SpriteHolder.h"
#include "TextureLoader.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


SpriteHolder::SpriteHolder(TextureLoader & Texture, double x, double y, double rotation, double scale = 1 )
{
	MySprite.setTexture(Texture.MyTexture);
	this->x = x*scale;
	this->y = y*scale;
	this->rotation = rotation;
	this->scale = scale;



	this->x_center = this->x / 2;
	this->y_center = this->y / 2;

	MySprite.setOrigin(this->x_center, this->y_center);
	MySprite.scale(scale, scale);
}