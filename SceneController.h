#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include "Button.h"

using namespace sf;
using namespace std;

class SceneController
{
public:

	static void DisplayStartMenu(int, int); // x and y for window resolution
private:
	static int sceneNumber;
};