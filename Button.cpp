#include "Button.h"

#include <iostream>
using namespace std;

Button::Button(std::string text, int size, float x, float y)
{
	if (!this->font.loadFromFile("Fonts\\Starcraft.otf"))
	{
		cout << "Couldnt upload this font";
	}

	this->ourText.setString(text);
	this->ourText.setColor(sf::Color::White);
	this->size = size;

	ourText.setFont(this->font);
	ourText.setCharacterSize(size);

	ourText.setPosition(x, y);

}

sf::Text Button::GetText() { return ourText; }