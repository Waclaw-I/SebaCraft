#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

class SceneController
{
public:

	static bool DisplayStartMenu(int, int); // x and y for window resolution

private:
	static int sceneNumber;
};