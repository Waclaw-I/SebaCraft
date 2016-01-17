#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "LoadController.h"

class TextLabel
{
public:

	TextLabel(std::string, int, float, float );
	~TextLabel();

	sf::Text & GetText();

	void SetColor(sf::Color);

	float GetPosition_x();
	float GetPosition_y();
	void SetPosition_x(float);
	void SetPosition_y(float);
	float GetSize_x();
	float GetSize_y();

	void Hide();
	void Show();

	bool GetIsVisible();

	void UpdateHp(double, double); // actual and max health
	void UpdateTextPosition();

	bool IsMouseOver(float, float);

private:

	sf::Text ourText;
	int scale;

	float position_x;
	float position_y;
	float size_x;
	float size_y;

	bool isVisible;


};
