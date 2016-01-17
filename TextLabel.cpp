#include "TextLabel.h"

#include <iostream>
using namespace std;

TextLabel::TextLabel(std::string text, int size, float x, float y)
{
	
	this->ourText.setString(text);
	this->ourText.setColor(sf::Color::White);
	this->scale = size;

	ourText.setFont(LoadController::FontsArray[0]);
	ourText.setCharacterSize(size);

	ourText.setPosition(x, y);

	this->position_x = ourText.getPosition().x;
	this->position_y = ourText.getPosition().y;

	this->size_x = ourText.getLocalBounds().width;
	this->size_y = ourText.getLocalBounds().height;

	isVisible = true;




}

TextLabel::~TextLabel(){}

void TextLabel::SetColor(sf::Color color)
{
	ourText.setColor(color);
}

bool TextLabel::IsMouseOver(float mouse_x, float mouse_y)
{
	cout << position_y << endl;
	if (mouse_x > position_x && mouse_x < position_x + size_x)
		if (mouse_y > position_y + 10 && mouse_y < position_y + size_y + 10) return true;

	return false;
		
}

float TextLabel::GetPosition_x() { return position_x; }
float TextLabel::GetPosition_y() { return position_y; }
float TextLabel::GetSize_x() { return size_x; }
float TextLabel::GetSize_y() { return size_y; }
bool TextLabel::GetIsVisible() { return isVisible; }

void TextLabel::Show() { isVisible = true; }
void TextLabel::Hide() { isVisible = false; }

void TextLabel::SetPosition_x(float x) { this->position_x = x; }
void TextLabel::SetPosition_y(float y) { this->position_y = y; }

void TextLabel::UpdateTextPosition()
{
	ourText.setPosition(position_x, position_y);
}

void TextLabel::UpdateHp(double _actual, double _max)
{
	string actualHp, maxHp;

	maxHp = to_string(_max);
	actualHp = to_string(_actual);

	maxHp.erase(3, maxHp.size() - 3);
	actualHp.erase(3, actualHp.size() - 3);
	ourText.setString(actualHp + "/" + maxHp);
}

sf::Text & TextLabel::GetText() { return ourText; }