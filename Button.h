#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:

	Button(std::string, int, float, float );

	sf::Text GetText();

	void SetColor(sf::Color);

	float GetPosition_x();
	float GetPosition_y();
	float GetSize_x();
	float GetSize_y();

	bool IsMouseOver(float, float);

private:

	sf::Text ourText;
	sf::Font font;
	int scale;

	float position_x;
	float position_y;
	float size_x;
	float size_y;


};
