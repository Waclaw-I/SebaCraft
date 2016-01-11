#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>

#include "SpriteHolder.h"
#include "TextureLoader.h"
#include "Player.h"
#include "PlayerController.h"
#include "LoadController.h"
#include "BulletController.h"
#include "EnemyController.h"
#include "DisplayController.h"


#include "EnemyShip.h"
#include "SmallFighter.h"
#include "Medivac.h"
#include "SpaceStation.h"

#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

void Start();
void Update();

// only global variables that we need - main character and main threat.
Player * Sebamus;
SpaceStation * Station;
RenderWindow * MainWindow;
View OurCamera;

int main()
{
	
	Start();

	Station->SpawnSmallFighter();
	Station->SpawnMedivac();

	Clock timer;
	float accumulator = 0;
	float timeStep = 0.0166f; // 60FPS

	
	while (MainWindow->isOpen())
	{
		accumulator += timer.restart().asSeconds();

		if (accumulator >= timeStep)
		{

			Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
			while (MainWindow->pollEvent(zdarzenie))
			{
				if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MainWindow->close();
				if (zdarzenie.type == Event::Closed) MainWindow->close();
			}

			OurCamera.setCenter(Sebamus->Get_x_Position(), Sebamus->Get_y_Position()); // Camera
			MainWindow->setView(OurCamera);

			EnemyController::MoveEnemyShips(Sebamus); // we are moving ships towards the player

			PlayerController::Moving(Sebamus); // controls movements of the player
			PlayerController::Shooting(Sebamus);
			BulletController::MoveBullets();

			DisplayController::CheckIfDestroyed();
			DisplayController::UpdatePlayerGraph(Sebamus);

			MainWindow->clear();

			cout << DisplayController::ArrayOfSprites.size() << endl;

			for (int i = 0; i < DisplayController::ArrayOfSprites.size(); i++)
			{
				if (i == 0) DisplayController::ArrayOfSprites[0]->MySprite.setPosition(Sebamus->Get_x_Position(), Sebamus->Get_y_Position());
				if (i == 1) DisplayController::ArrayOfSprites[1]->MySprite.setPosition((Sebamus->Get_x_Position()* 0.8), (Sebamus->Get_y_Position() *0.8));

				MainWindow->draw(DisplayController::ArrayOfSprites[i]->MySprite);
			}

			MainWindow->display();
			accumulator -= timeStep;

		}
	}
	return 0;
}


void Start()
{
	LoadController::LoadTextures(); // these are just textures of our objects
	DisplayController::InitializeLevel(); // load and place background into the game world

	Sebamus = new Player();	// our HERO and all his logics
	Station = new SpaceStation(0.1, 2); // rotate speed and scale, our main enemy

	EnemyController::InsertNewEnemyShip(Station);

	DisplayController::InsertNewSprite(Station->Get_MyGraph());
	DisplayController::InsertNewSprite(Sebamus->GetLevelOneGraph());

	MainWindow = new RenderWindow(VideoMode(1366, 768, 32), "SebaCraft"/*, Style::Fullscreen*/); // main window.

	OurCamera = MainWindow->getDefaultView();
	OurCamera.setViewport(FloatRect(0, 0, 0.8, 0.8));
}
