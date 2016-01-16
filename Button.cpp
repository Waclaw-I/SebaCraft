#include "Button.h"

#include <iostream>
using namespace std;

Button::Button(std::string text, int size, float x, float y)
{
	if (!this->font.loadFromFile("Fonts/Starcraft.otf"))
	{
		cout << "Couldnt upload this font";
	}

	this->ourText.setString(text);
	this->ourText.setColor(sf::Color::White);
	this->scale = size;

	ourText.setFont(this->font);
	ourText.setCharacterSize(size);

	ourText.setPosition(x, y);

	this->position_x = ourText.getPosition().x;
	this->position_y = ourText.getPosition().y;

	this->size_x = ourText.getLocalBounds().width;
	this->size_y = ourText.getLocalBounds().height;


}

void Button::SetColor(sf::Color color)
{
	ourText.setColor(color);
}

bool Button::IsMouseOver(float mouse_x, float mouse_y)
{
	if (mouse_x > position_x && mouse_x < position_x + size_x)
		if (mouse_y > position_y && mouse_y < position_y + size_y) return true;

	return false;
		
}

float Button::GetPosition_x() { return position_x; }
float Button::GetPosition_y() { return position_y; }
float Button::GetSize_x() { return size_x; }
float Button::GetSize_y() { return size_y; }

sf::Text Button::GetText() { return ourText; }