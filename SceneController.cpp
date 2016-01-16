#include "SceneController.h"
#include <iostream>


int SceneController::sceneNumber = 0;

bool SceneController::DisplayStartMenu(int x, int y)
{
	RenderWindow MenuWindow(VideoMode(x, y, 32), "SebaCraft Menu"/*, Style::Fullscreen*/); // main window.
	Button start_Button("START", 65, 275, 100);
	Button exit_Button("WYJSCIE", 65, 235, 400);


	while (MenuWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (MenuWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MenuWindow.close();
			if (zdarzenie.type == Event::Closed) MenuWindow.close();

			if (start_Button.IsMouseOver(Mouse::getPosition(MenuWindow).x, Mouse::getPosition(MenuWindow).y))
			{
				start_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					MenuWindow.close();
					return true; // start the game already!
				}
			}
				else start_Button.SetColor(sf::Color::White);

			if (exit_Button.IsMouseOver(Mouse::getPosition(MenuWindow).x, Mouse::getPosition(MenuWindow).y))
			{
				exit_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					MenuWindow.close();
					return true; // start the game already!
				}
			}
				else exit_Button.SetColor(sf::Color::White);


		}
		MenuWindow.clear(sf::Color::Black);

		MenuWindow.draw(start_Button.GetText());
		MenuWindow.draw(exit_Button.GetText());

		MenuWindow.display();
	}
		return false;
}