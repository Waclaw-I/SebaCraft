#include "SceneController.h"


int SceneController::sceneNumber = 0;

void SceneController::DisplayStartMenu(int x, int y)
{
	RenderWindow MenuWindow(VideoMode(x, y, 32), "SebaCraft Menu"/*, Style::Fullscreen*/); // main window.

	while (MenuWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (MenuWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MenuWindow.close();
			if (zdarzenie.type == Event::Closed) MenuWindow.close();
		}
	}
}