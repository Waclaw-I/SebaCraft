#include "SpriteHolder.h"
#include "TextureLoader.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


SpriteHolder::SpriteHolder(TextureLoader & Texture, double x, double y, double rotation, double size = 1 )
{
	MySprite.setTexture(Texture.MyTexture);
	this->x = x*size;
	this->y = y*size;
	this->rotation = rotation;
	this->size = size;



	this->x_center = this->x / 2;
	this->y_center = this->y / 2;

	MySprite.setOrigin(this->x_center, this->y_center);
}