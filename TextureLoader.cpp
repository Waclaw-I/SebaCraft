#include "TextureLoader.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

TextureLoader::TextureLoader() {};


void TextureLoader::LoadTexture(string path)
{
	MyTexture.loadFromFile(path);
	x = MyTexture.getSize().x;
	y = MyTexture.getSize().y;
}

double TextureLoader::Get_x() { return x;}

double TextureLoader::Get_y() { return y;}