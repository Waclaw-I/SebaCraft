#include "SceneController.h"
#include <iostream>


int SceneController::sceneNumber = 0;

int SceneController::resolution_x = VideoMode::getDesktopMode().width;
int SceneController::resolution_y = VideoMode::getDesktopMode().height;

void SceneController::DisplayStartMenu(int x, int y)
{
	LoadController::LoadFonts();

	RenderWindow MenuWindow(VideoMode(x, y, 32), "SebaCraft Menu"/*, Style::Fullscreen*/); // main window.
	TextLabel start_Button("START", 65, 275, 100);
	TextLabel exit_Button("WYJSCIE", 65, 235, 400);


	while (MenuWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (MenuWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MenuWindow.close();
			if (zdarzenie.type == Event::Closed) MenuWindow.close();

			if (!MenuWindow.isOpen())
			{
				sceneNumber = 0;
				break;
			}

			if (start_Button.IsMouseOver(Mouse::getPosition(MenuWindow).x, Mouse::getPosition(MenuWindow).y))
			{
				start_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					MenuWindow.close();
					sceneNumber = 1;
					break;
				}
			}
				else start_Button.SetColor(sf::Color::White);

			if (exit_Button.IsMouseOver(Mouse::getPosition(MenuWindow).x, Mouse::getPosition(MenuWindow).y))
			{
				exit_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					MenuWindow.close();
					break;
				}
			}
				else exit_Button.SetColor(sf::Color::White);


		}
		MenuWindow.clear(sf::Color::Black);

		MenuWindow.draw(start_Button.GetText());
		MenuWindow.draw(exit_Button.GetText());

		MenuWindow.display();
	}
}

bool SceneController::DisplayPrologue()
{
	
	RenderWindow PrologueWindow(VideoMode::getDesktopMode(), "SebaCraft - Prologue", Style::Fullscreen); // text may not be centralized properly on other resolutions
	TextLabel Prologue1("TWOJ ZLY I NIEZWYKLE PRZYSTOJNY BRAT HANDSOMUS", 35, resolution_x / 2 - 580, resolution_y / 2 - 350);
	TextLabel Prologue2("KTORY ZESLAL CIE NA WYGNANIE W PRZESTRZEN... ", 35, resolution_x / 2 - 580, resolution_y / 2 - 295);
	TextLabel Prologue3("POD TWOJA NIEOBECNOSC ZBUDOWAL FABRYKI KLONOW", 35, resolution_x / 2 - 580, resolution_y / 2 - 240);
	TextLabel Prologue4("(SIEBIE SAMEGO OCZYWISCIE) ABY PRZEJAC WLADZE", 35, resolution_x / 2 - 580, resolution_y / 2 - 185);
	TextLabel Prologue5("I RAZ NA ZAWSZE POZBYC SIE BRZYDKICH LUDZI...", 35, resolution_x / 2 - 580, resolution_y / 2 - 130);
	TextLabel Prologue6("POWSTRZYMAJ JEGO ZLOWROGIE PLANY I JEGO EGO! ", 35, resolution_x / 2 - 580, resolution_y / 2 - 75);

	TextLabel Prologue7("            ZNISZCZ LABORATORIUM!            ", 60, resolution_x / 2 - 700, resolution_y / 2);

	TextLabel engage_Button("ENGAGE!", 65, resolution_x/2-155, resolution_y-200);


	while (PrologueWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (PrologueWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) PrologueWindow.close();
			if (zdarzenie.type == Event::Closed) PrologueWindow.close();

			if (engage_Button.IsMouseOver(Mouse::getPosition(PrologueWindow).x, Mouse::getPosition(PrologueWindow).y))
			{
				engage_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					PrologueWindow.close();
					return true; // start the game already!
				}
			}
			else engage_Button.SetColor(sf::Color::White);

		}
		PrologueWindow.clear(sf::Color::Black);
		// PUT IT INTO THE ARRAY IN SOME FREE TIME
		PrologueWindow.draw(engage_Button.GetText());
		PrologueWindow.draw(Prologue1.GetText());
		PrologueWindow.draw(Prologue2.GetText());
		PrologueWindow.draw(Prologue3.GetText());
		PrologueWindow.draw(Prologue4.GetText());
		PrologueWindow.draw(Prologue5.GetText());
		PrologueWindow.draw(Prologue6.GetText());
		PrologueWindow.draw(Prologue7.GetText());
		PrologueWindow.display();
	}
	return false;
}


void SceneController::DisplayVictory()
{
	RenderWindow VictoryWindow(VideoMode::getDesktopMode(), "SebaCraft - Victory!", Style::Fullscreen); // text may not be centralized properly on other resolutions
	TextLabel Epilogue1("    BEZ DOSTEPU DO ARMII SWOICH PRZYSTOJNIAKOW  ", 35, resolution_x / 2 - 580, resolution_y / 2 - 350);
	TextLabel Epilogue2("    HANDSOMUS ZOSTAL ZMUSZONY DO ODWROTU. CZY   ", 35, resolution_x / 2 - 580, resolution_y / 2 - 295);
	TextLabel Epilogue3("    BYLO TO JEDYNE LABORATORIUM? A MOZE JEST ICH", 35, resolution_x / 2 - 580, resolution_y / 2 - 240);
	TextLabel Epilogue4("    WIECEJ? TWOJA PODROZ DOPIERO SIE ZACZYNA!   ", 35, resolution_x / 2 - 580, resolution_y / 2 - 185);
	TextLabel Epilogue5("    (JEDNAK TWOJA, GRACZU, POKI CO SIE KONCZY) ", 35, resolution_x / 2 - 580, resolution_y / 2 - 130);
	TextLabel Epilogue6("    DO ZOBACZENIA W PELNOMETRAZOWEJ KAMPANII!  ", 35, resolution_x / 2 - 580, resolution_y / 2);

	TextLabel exit_Button("KONIEC!", 35, resolution_x / 2 - 80, resolution_y - 200);


	while (VictoryWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (VictoryWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) VictoryWindow.close();
			if (zdarzenie.type == Event::Closed) VictoryWindow.close();

			if (exit_Button.IsMouseOver(Mouse::getPosition(VictoryWindow).x, Mouse::getPosition(VictoryWindow).y))
			{
				exit_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					VictoryWindow.close();
				}
			}
			else exit_Button.SetColor(sf::Color::White);

		}
		VictoryWindow.clear(sf::Color::Black);

		VictoryWindow.draw(exit_Button.GetText());
		VictoryWindow.draw(Epilogue1.GetText());
		VictoryWindow.draw(Epilogue2.GetText());
		VictoryWindow.draw(Epilogue3.GetText());
		VictoryWindow.draw(Epilogue4.GetText());
		VictoryWindow.draw(Epilogue5.GetText());
		VictoryWindow.draw(Epilogue6.GetText());

		VictoryWindow.display();
	}
}

void SceneController::DisplayDefeat()
{
	LoadController::LoadFonts();
	RenderWindow DefeatWindow(VideoMode::getDesktopMode(), "SebaCraft - Defeat!", Style::Fullscreen); // text may not be centralized properly on other resolutions
	TextLabel Epilogue1("   TERAZ JUZ NIC NIE STOI NA DRODZE HANDSOMUSA. ", 35, resolution_x / 2 - 580, resolution_y / 2 - 350);
	TextLabel Epilogue2("   ZREALIZUJE ON SWOJ PLAN, POZBAWIAJAC SWIAT   ", 35, resolution_x / 2 - 580, resolution_y / 2 - 295);
	TextLabel Epilogue3("   ZEWNETRZNYCH NIEDOSKONALOSCI... LUDZKOSC     ", 35, resolution_x / 2 - 580, resolution_y / 2 - 240);
	TextLabel Epilogue4("   POTRZEBUJE BOHATEROW, TY JEDNAK MIALES SWOJA ", 35, resolution_x / 2 - 580, resolution_y / 2 - 185);
	TextLabel Epilogue5("   SZANSE! WRACAJ DO UKLADANIA PASJANSA, CZY COS", 35, resolution_x / 2 - 580, resolution_y / 2 - 130);
	TextLabel Epilogue6("   DO ZOBACZENIA W PELNOMETRAZOWEJ KAMPANII!  ", 35, resolution_x / 2 - 580, resolution_y / 2);

	TextLabel exit_Button("KONIEC!", 35, resolution_x / 2 - 80, resolution_y - 200);


	while (DefeatWindow.isOpen())
	{
		Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
		while (DefeatWindow.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) DefeatWindow.close();
			if (zdarzenie.type == Event::Closed) DefeatWindow.close();

			if (exit_Button.IsMouseOver(Mouse::getPosition(DefeatWindow).x, Mouse::getPosition(DefeatWindow).y))
			{
				exit_Button.SetColor(sf::Color::Red);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					DefeatWindow.close();
				}
			}
			else exit_Button.SetColor(sf::Color::White);

		}
		DefeatWindow.clear(sf::Color::Black);

		DefeatWindow.draw(exit_Button.GetText());
		DefeatWindow.draw(Epilogue1.GetText());
		DefeatWindow.draw(Epilogue2.GetText());
		DefeatWindow.draw(Epilogue3.GetText());
		DefeatWindow.draw(Epilogue4.GetText());
		DefeatWindow.draw(Epilogue5.GetText());
		DefeatWindow.draw(Epilogue6.GetText());

		DefeatWindow.display();
	}
}

