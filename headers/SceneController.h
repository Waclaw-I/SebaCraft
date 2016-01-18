#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TextLabel.h"


using namespace sf;

class SceneController
{
public:

	static int sceneNumber;

	static void DisplayStartMenu(int, int); // x and y for window resolution
	static bool DisplayPrologue();
	static void DisplayDefeat();
	static void DisplayVictory();

private:
	
	static int resolution_x;
	static int resolution_y;
};