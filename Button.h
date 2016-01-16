#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:

	Button(std::string, int, float, float );

	sf::Text GetText();

	void SetColor(sf::Color);

private:

	sf::Text ourText;
	sf::Font font;
	int size;


};
