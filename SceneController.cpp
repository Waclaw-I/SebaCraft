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
		std::cout << "x: " << Mouse::getPosition().x << std::endl;
		std::cout << "y: " << Mouse::getPosition().y << std::endl;
		system("cls");
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (MenuWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MenuWindow.close();
			if (zdarzenie.type == Event::Closed) MenuWindow.close();

			if (Mouse::getPosition().x > 570 && Mouse::getPosition().x < 800)
				if (Mouse::getPosition().y > 230 && Mouse::getPosition().y < 280)
				{
					start_Button.SetColor(sf::Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						MenuWindow.close();
						return true; // start the game already!
					}
				}
				else start_Button.SetColor(sf::Color::White);

			if (Mouse::getPosition().x > 530 && Mouse::getPosition().x < 830)
				if (Mouse::getPosition().y > 530 && Mouse::getPosition().y < 570)
				{
					exit_Button.SetColor(sf::Color::Red);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						MenuWindow.close();
						return false; // nope, we close it.
					}
				}
					else exit_Button.SetColor(sf::Color::White);


		}

		MenuWindow.draw(start_Button.GetText());
		MenuWindow.draw(exit_Button.GetText());

		MenuWindow.display();
	}
		return false;
}