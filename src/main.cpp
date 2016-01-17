#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SpriteHolder.h"
#include "TextureLoader.h"
#include "Player.h"
#include "PlayerController.h"
#include "LoadController.h"
#include "BulletController.h"
#include "EnemyController.h"
#include "DisplayController.h"
#include "SpawnController.h"
#include "SceneController.h"


#include "EnemyShip.h"
#include "SmallFighter.h"
#include "Medivac.h"
#include "SpaceStation.h"

#include <iostream>

using namespace sf;
using namespace std;

void Start();
void Update();

bool GameEnds;

// only global variables that we need - main character and main threat.
Player * Sebamus;
SpaceStation * Station;
RenderWindow * MainWindow;
View OurCamera;

int main()
{
	GameEnds = false;
	bool state = SceneController::DisplayStartMenu(800, 600);
	
	if (state == true)
	{
		Start();
		Update();
	}
	else

	return 0;
}










void Start()
{
	LoadController::LoadTextures(); // these are just textures of our objects
	DisplayController::InitializeLevel(); // load and place background into the game world

	Sebamus = new Player();	// our HERO and all his logics
	Station = new SpaceStation(0.1, 2); // rotate speed and scale, our main enemy

	BulletController::player = Sebamus;

	EnemyController::InsertNewEnemyShip(Station);

	DisplayController::InsertNewDrawableObject(Station);
	DisplayController::InsertNewDrawableObject(Sebamus);
	DisplayController::InsertNewDrawableObject(&Sebamus->GetRotatingCannon());

	//MainWindow = new RenderWindow(VideoMode(1366, 768, 32), "SebaCraft", Style::Fullscreen); // main window.
	MainWindow = new RenderWindow(VideoMode::getDesktopMode(), "SebaCraft"/*, Style::Fullscreen*/); 

	OurCamera = MainWindow->getDefaultView();
	OurCamera.setViewport(FloatRect(0, 0, 1, 1));
}

void Update()
{
	

	Clock timer;
	float accumulator = 0;
	float timeStep = 0.0166f; // 60FPS


	while (MainWindow->isOpen() && !GameEnds)
	{
		accumulator += timer.restart().asSeconds();

		if (accumulator >= timeStep)
		{
			Event zdarzenie;		// escape controller, lol. I should put it inside GameController later
			while (MainWindow->pollEvent(zdarzenie) )
			{
				if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape) MainWindow->close();
				if (zdarzenie.type == Event::Closed) MainWindow->close();
			}

			OurCamera.setCenter(Sebamus->Get_x_Position(), Sebamus->Get_y_Position()); // Camera centralized on player
			MainWindow->setView(OurCamera);

			// ==================================LOGIC ======================================
			SpawnController::SpawnEnemies(Station);
			EnemyController::MoveEnemyShips(Sebamus); // we are moving ships towards the player

			PlayerController::Moving(Sebamus); // controls movements of the player
			PlayerController::Shooting(Sebamus);
			BulletController::MoveBullets();

			
			DisplayController::UpdatePlayerGraph(Sebamus);
			DisplayController::CheckIfDestroyed();

			if (Station->Get_IsAlive() == false) GameEnds = true;

			//==================DISPLAYING ON THE SCEEN STARTS HERE======================
			MainWindow->clear();

			for (int i = 0; i < DisplayController::ArrayOfDrawableObjects.size(); i++)
			{
				if (i == 0) DisplayController::ArrayOfDrawableObjects[0]->GetMyGraph()->MySprite.setPosition(Sebamus->Get_x_Position(), Sebamus->Get_y_Position());
				if (i == 1) DisplayController::ArrayOfDrawableObjects[1]->GetMyGraph()->MySprite.setPosition((Sebamus->Get_x_Position()* 0.8), (Sebamus->Get_y_Position() *0.8));

				MainWindow->draw(DisplayController::ArrayOfDrawableObjects[i]->GetMyGraph()->MySprite);
			}

			for (int i = 0; i < EnemyController::ArrayOfEnemies.size(); i++)
			{
				MainWindow->draw(EnemyController::ArrayOfEnemies[i]->GetHpBar()->GetText()); // our health bars
			}

			MainWindow->display();
			//============================== END =====================================

			accumulator -= timeStep;

		}
	}
}
